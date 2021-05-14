/*
 * I2C_Slave_Task.c
 *
 *  Created on: May 11, 2021
 *      Author: tom hsieh
 */

#include <stm32l0xx.h>
#include "I2C_Task.h"
#include "LCM_Task.h"

// I2C slave task.
void I2C_Slave_Task( void )
{
	uint32_t temp;

	// Check address match interrupt flag bit.
	temp = I2C1->ISR;
	temp &= 0x00000008;
	if( temp == 0x00000008 )
	{
		// Address match.
		// Clear interrupt flag bit.
		I2C1->ICR = 0x00000008;
		// Clear received count.
		i2c_rec_cnt = 0;
		// Clear LCM update count.
		lcm_text_cnt = 0;
	}

	// Stop interrupt check.
	temp = I2C1->ISR;
	temp &= 0x00000020;
	if( temp == 0x00000020  )
	{
		// Clear interrupt flag bit.
		I2C1->ICR = 0x00000020;
		// Set LCM update count.
		lcm_text_cnt = i2c_rec_cnt;
		// Reset LCM task count.
		lcm_task_cnt = 0;
	}

	// RXNE interrupt check.
	temp = I2C1->ISR;
	temp &= 0x00000004;
	if( temp == 0x00000004 )
	{
		// Receive data from master.
		// Clear interrupt flag bit.
		I2C1->ICR = 0x00000004;

		// Keep received data, and clear interrupt flag bit.
		lcm_text[ i2c_rec_cnt ] = I2C1->RXDR;
		// From received next data.
		if(i2c_rec_cnt < 16  )
		{
			// Increase count.
			++i2c_rec_cnt;
			// Return ACK.
			I2C1->CR2 &= 0xffffefff;
		}
		else
		{
			// Return NACK.
			I2C1->CR2 |= 0x00008000;
		}

	}

}
