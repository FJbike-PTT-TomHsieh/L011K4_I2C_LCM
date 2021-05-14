/*
 * LCM_Task.h
 *
 *  Created on: May 11, 2021
 *      Author: Tom Hsieh
 */

#ifndef INC_USER_LCM_TASK_H_
#define INC_USER_LCM_TASK_H_

#include <stdint.h>

// Word count a line of the LCM.
#define LINE_WORD 8


// Task dispatch count.
volatile uint8_t lcm_task_cnt;
// LCM update character.
volatile uint8_t lcm_text[17];
// LCM update character old.
volatile uint8_t lcm_text_old[16];
// LCM update character counter.
volatile uint8_t lcm_text_cnt;
// LCM update data index.
volatile uint8_t lcm_text_index;

// Delay count.
volatile uint32_t lcm_delay;


// LCM initialize.
void LCM_Init( void );
// LCM command out.
void LCM_Cmd_Out( uint8_t cmd );
// LCM data out.
void LCM_Data_Out( uint8_t data );
// LCM task.
void LCM_Task( void );
// Update from I2C.
void LCM_I2C_Update( void );

#endif /* INC_USER_LCM_TASK_H_ */
