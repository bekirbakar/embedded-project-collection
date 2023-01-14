/**
 * io.h
 *
 * Created on: Aug 1, 2018
 * Author: Bekir Bakar
 */
#ifndef IO_H
#define IO_H

#include <cstdint>

#include "stm32f1xx_hal.h"
#include "stm32f100xb.h"

// Input-output
#define ON      1
#define OFF     0
#define PRESSED     1
#define RELEASED    0

#define CELL_A1_PORT GPIOC
#define CELL_A2_PORT GPIOA
#define CELL_A3_PORT GPIOB
#define CELL_B1_PORT GPIOB
#define CELL_B2_PORT GPIOB
#define CELL_B3_PORT GPIOC

#define CELL_A1_PIN GPIO_PIN_4
#define CELL_A2_PIN GPIO_PIN_7
#define CELL_A3_PIN GPIO_PIN_0
#define CELL_B1_PIN GPIO_PIN_2
#define CELL_B2_PIN GPIO_PIN_1
#define CELL_B3_PIN GPIO_PIN_5

// Commands
#define COMMAND_LEFT    10
#define COMMAND_RIGHT   11
#define COMMAND_DOWN    12
#define COMMAND_PLAY    13
#define COMMAND_PROG1   14
#define COMMAND_PROG2   15

#define COMMAND_LEFT_PORT   GPIOB
#define COMMAND_RIGHT_PORT  GPIOB
#define COMMAND_DOWN_PORT   GPIOB
#define COMMAND_PLAY_PORT   GPIOB
#define COMMAND_PROG_PORT   GPIOB
#define COMMAND_PROG2_PORT  GPIOB

#define COMMAND_LEFT_PIN    GPIO_PIN_13
#define COMMAND_RIGHT_PIN   GPIO_PIN_14
#define COMMAND_DOWN_PIN    GPIO_PIN_12
#define COMMAND_PLAY_PIN    GPIO_PIN_15
#define COMMAND_PROG_PIN    0
#define COMMAND_PROG2_PIN   0

unsigned int command;

void ledToggle(GPIO_TypeDef *port, int pin);

void ledOnOff(GPIO_TypeDef *port, int pin, int state);

void commandsToPanel();

int readButton(GPIO_TypeDef *port, uint16_t pin);

#endif
