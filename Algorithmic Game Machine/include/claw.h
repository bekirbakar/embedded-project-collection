/**
 * claw.h
 *
 * Created on: Aug 1, 2018
 * Author: Bekir Bakar
 */
#ifndef CLAW_H
#define CLAW_H

// Led Panel
#define CELL_LETTER_SIZE    2
#define CELL_NUMBER_SIZE    3
#define NUMBER_LETTER_ZERO  0
#define CELL_UP     0
#define CELL_LEFT   0
#define CELL_A1 0
#define CELL_A2 1
#define CELL_A3 2
#define CELL_B1 0
#define CELL_B2 1
#define CELL_B3 2

// Claw Direction
#define RIGHT   6
#define LEFT    7
#define UP      8
#define DOWN    9

// Box Status
#define EMPTY       0
#define ANY         1
#define RED         2
#define GREEN       3
#define BLUE        4
#define UNCOLORED   5

#include <stdint.h>

// Claw
typedef struct
{
    unsigned int numberPosition;
    unsigned int letterPosition;
    uint8_t holding = 0;
} Transporter;

Transporter claw;

extern void goRight(void);

extern void goLeft(void);

extern void goUp(void);

extern void goDown(void);

extern void clawDefaultStatus(void);

extern void moveClaw(unsigned int direction);

extern void pickLed(unsigned int letter);

extern void dropLed(unsigned int letter);

#endif
