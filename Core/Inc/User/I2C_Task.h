/*
 * I2C_Task.h
 *
 *  Created on: May 11, 2021
 *      Author: tom hsieh
 */

#ifndef INC_USER_I2C_TASK_H_
#define INC_USER_I2C_TASK_H_

#include <stdint.h>

//
volatile uint8_t i2c_rec_cnt;
//
volatile uint8_t i2c_rec_data[20];

// I2C slave task.
void I2C_Slave_Task( void );

#endif /* INC_USER_I2C_TASK_H_ */
