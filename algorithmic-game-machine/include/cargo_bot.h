/**
 * cargo_bot.h
 *
 * Created on: Aug 1, 2018
 * Author: Bekir Bakar
 */
#ifndef CARGO_BOT_H
#define CARGO_BOT_H

#include <stdint.h>

#include "claw.h"

// Process Helpers
#define CONTINUE    1
#define FINISH      0
#define SAME        1
#define DIFFERENT   0

// The Game
typedef struct
{
    uint8_t boxPanel[CELL_LETTER_SIZE][CELL_NUMBER_SIZE];
    uint8_t gameGoal[CELL_LETTER_SIZE][CELL_NUMBER_SIZE];
    uint8_t userCommandCounter;
    uint8_t userCommands[100];
    bool gameOver;
    bool gameWin;
} Game;

Game cargoBot;

void matrixCopy(void *dest, void *src);

bool compareMatrices(uint8_t x[CELL_LETTER_SIZE][CELL_NUMBER_SIZE],
                     uint8_t y[CELL_LETTER_SIZE][CELL_NUMBER_SIZE]);

unsigned int checkGameStatus(void);

void playCargoBot(void);

#endif
