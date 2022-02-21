/**
 * io.c
 *
 * Created on: Aug 1, 2018
 * Author: Bekir Bakar
 */
#include <stdint.h>

#include "io.h"
#include "cargo_bot.h"

void ledToggle(GPIO_TypeDef *port, int pin)
{
    for (int counter = 0; counter < 5; counter++)
    {
        HAL_GPIO_WritePin(port, pin, SET);
        HAL_Delay(100);
        HAL_GPIO_WritePin(port, pin, RESET);
        HAL_Delay(100);
    }
}

void ledOnOff(GPIO_TypeDef *port, int pin, int state)
{
    HAL_GPIO_WritePin(port, pin, state);
}

int readButton(GPIO_TypeDef *port, uint16_t pin)
{
    return HAL_GPIO_ReadPin(port, pin);
}

void commandsToPanel()
{
    HAL_GPIO_WritePin(CELL_A1_PORT, CELL_A1_PIN, cargobot.boxPanel[0][0]);
    HAL_GPIO_WritePin(CELL_A2_PORT, CELL_A2_PIN, cargobot.boxPanel[1][0]);
    HAL_GPIO_WritePin(CELL_A3_PORT, CELL_A3_PIN, cargobot.boxPanel[2][0]);
    HAL_GPIO_WritePin(CELL_B1_PORT, CELL_B1_PIN, cargobot.boxPanel[0][1]);
    HAL_GPIO_WritePin(CELL_B2_PORT, CELL_B2_PIN, cargobot.boxPanel[1][1]);
    HAL_GPIO_WritePin(CELL_B3_PORT, CELL_B3_PIN, cargobot.boxPanel[2][1]);
}
