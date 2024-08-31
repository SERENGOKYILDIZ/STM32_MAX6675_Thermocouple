/*
 * MAX6675K.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Semi Eren GOKYILDIZ
 */

#ifndef INC_MAX6675K_H_
#define INC_MAX6675K_H_

#include "main.h"

#define MAX6675_OK 		1
#define MAX6675_ERROR 	0

uint8_t MAX6675_ReadRegisters(uint16_t* reg);
float MAX6675_ReadTemperature(uint16_t reg);

#endif /* INC_MAX6675K_H_ */
