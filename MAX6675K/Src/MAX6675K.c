/*
 * MAX6675K.c
 *
 *  Created on: Aug 31, 2024
 *      Author: Semi Eren GOKYILDIZ
 */
#include "MAX6675K.h"

////////////////////////////////////-> USER SETTINGS
extern SPI_HandleTypeDef hspi1;          							//-> The SPI to be used must be included

//* Definitions *//
SPI_HandleTypeDef* hspix 	= &hspi1;
GPIO_TypeDef* CS_GPIO 		= GPIOA;
uint16_t CS_PIN             = GPIO_PIN_4;
////////////////////////////////////

uint8_t MAX6675_ReadRegisters(uint16_t* reg)
{
	HAL_StatusTypeDef HAL_Status = HAL_ERROR;
	uint8_t temperature[2] = {0};

	HAL_GPIO_WritePin(CS_GPIO, CS_PIN, GPIO_PIN_RESET);
	HAL_Status = HAL_SPI_Receive(hspix, temperature, 2, 100);
	HAL_GPIO_WritePin(CS_GPIO, CS_PIN, GPIO_PIN_SET);

	if(HAL_Status == HAL_OK)
	{
		if(temperature[1] & 0x04) return MAX6675_ERROR;            //->It must be 0

		*reg = (uint16_t)(temperature[1] >> 3);
		*reg |= (uint16_t)(temperature[0] << 5);

		return MAX6675_OK;
	}

	return MAX6675_ERROR;
}

float MAX6675_ReadTemperature(uint16_t reg)
{
	return reg * 0.25;
}
