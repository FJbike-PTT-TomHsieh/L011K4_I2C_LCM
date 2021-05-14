/*
 * LCM_Task.c
 *
 *  Created on: May 11, 2021
 *      Author: Tom Hsieh
 */

#include <stm32l0xx.h>
#include "LCM_Task.h"
#include "I2C_Task.h"

// LCM initialize.
void LCM_Init( void )
{
	// Power on delay.
	// - ABout 100ms.
	lcm_delay = 10;
	while( lcm_delay )
	{
	}
	// Output low.
	// RS - PA8.
	// RW - PA9.
	// E - PA10.
	GPIOA->BSRR = 0x07000000;
	// Function.
	// - 2 line.
	// - 5 x 7 dots a word.
	// - 8 bit data.
	LCM_Cmd_Out( 0x38 );
	LCM_Cmd_Out( 0x38 );
	LCM_Cmd_Out( 0x38 );
	LCM_Cmd_Out( 0x38 );
	// Display.
	// - Display on.
	// - Cursor off.
	LCM_Cmd_Out( 0x0c );
	// Entry.
	// - Increment.
	LCM_Cmd_Out( 0x06 );
	// Display clear.
	LCM_Cmd_Out( 0x01 );

	// Test only.
	//LCM_Data_Out( 'A' );
}

// LCM command out.
void LCM_Cmd_Out( uint8_t cmd )
{
	GPIOA->BSRR = 0x01000000; 	// RS = 0.
	GPIOA->BSRR = 0x02000000; 	// RW = 0.
	__NOP();
	GPIOA->BSRR = 0x00000400; 	// E = 1.
	GPIOA->BSRR = 0x00ff0000;
	GPIOA->BSRR = cmd;			// LCM command.
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	GPIOA->BSRR = 0x04000000; 	// E = 0;
	__NOP();
	GPIOA->BSRR = 0x00000200; 	// RW = 1.
	GPIOA->BSRR = 0x00000100; 	// RS = 1.

	lcm_delay = 2;
	// Block wait.
	while( lcm_delay )
	{
	}
}

// LCM data out.
void LCM_Data_Out( uint8_t data )
{
	GPIOA->BSRR = 0x00000100; 	// RS = 1.
	GPIOA->BSRR = 0x02000000; 	// RW = 0.
	__NOP();
	GPIOA->BSRR = 0x00000400; 	// E = 1.
	GPIOA->BSRR = 0x00ff0000;
	GPIOA->BSRR = data;			// LCM data.
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	GPIOA->BSRR = 0x04000000; 	// E = 0;
	__NOP();
	GPIOA->BSRR = 0x00000200; 	// RW = 1.
	GPIOA->BSRR = 0x00000100; 	// RS = 1.

	lcm_delay = 2;
	// Block wait.
	while( lcm_delay )
	{
	}
}

// LCM task.
void LCM_Task( void )
{
	uint8_t temp1;
	uint8_t temp3;

	// Delay count check.
	if( lcm_delay )
	{
		// Not done.
		return;
	}

	// Check text draw count.
	if( lcm_text_cnt == 0 )
	{
		// Empty, do not draw.
		return;
	}

	switch( lcm_task_cnt )
	{
		case 0:
			// Clear index.
			lcm_text_index = 0;
			// Next task.
			++lcm_task_cnt;
			break;

		case 1:
			// Cursor return home.
			LCM_Cmd_Out( 0x02 );
			// Next task.
			++lcm_task_cnt;
			break;

		case 2:
			// Send display data.
			temp1 = lcm_text_old[ lcm_text_index ];
			temp3 = lcm_text[ lcm_text_index ];
			// Display data Change, show new data.
			if( temp3 != temp1 )
			{
				// Keep current data as old data.
				lcm_text_old[ lcm_text_index ] = temp3;

				LCM_Data_Out( temp3 );
			}
			else
			{
				LCM_Cmd_Out( 0x14 );
			}

			// Next data.
			++lcm_text_index;
			--lcm_text_cnt;

			// Line carry.
			if( lcm_text_index == LINE_WORD )
			{
				// Next task.
				++lcm_task_cnt;
			}
			break;

		case 3:
			// Cursor return home.
			LCM_Cmd_Out( 0xc0 );
			// Next task.
			lcm_task_cnt = 2;
			break;
	}
}

// Update from I2C.
void LCM_I2C_Update( void )
{

}
