/**
 * cargo_bot.c
 *
 * Created on: Aug 1, 2018
 * Author: Bekir Bakar
 */
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "../include/io.h"
#include "../include/cargo_bot.h"

void matrixCopy(void *dest, void *src)
{
    memcpy(dest, src, CELL_NUMBER_SIZE * CELL_LETTER_SIZE * sizeof(uint8_t));
}

bool compareMatrices(
    uint8_t x[CELL_LETTER_SIZE][CELL_NUMBER_SIZE],
    uint8_t y[CELL_LETTER_SIZE][CELL_NUMBER_SIZE])
{
    for (uint8_t letter = 0; letter < CELL_LETTER_SIZE; letter++)
    {
        for (uint8_t number = 0; number < CELL_NUMBER_SIZE; number++)
        {
            if (x[letter][number] != y[letter][number])
            {
                return DIFFERENT;
            }
        }
    }

    return SAME;
}

unsigned int checkGameStatus()
{
    if (claw.letterPosition > CELL_LETTER_SIZE ||
        claw.numberPosition > CELL_NUMBER_SIZE)
    {
        cargoBot.gameOver = true;
        return FINISH;
    }

    if (claw.letterPosition < NUMBER_LETTER_ZERO ||
        claw.numberPosition < NUMBER_LETTER_ZERO)
    {
        cargoBot.gameOver = true;
        return FINISH;
    }

    if (compareMatrices(cargoBot.boxPanel, cargoBot.gameGoal) == SAME)
    {
        cargoBot.gameOver = false;
        cargoBot.gameWin = true;
    }

    return CONTINUE;
}

void playCargoBot()
{
    // Initialize Cargo Bot Variables
    cargoBot.gameOver = false;
    cargoBot.gameWin = false;
    cargoBot.userCommandCounter = 0;

    // Cargo101
    unsigned int cargo101Start[3][2] = {{0, 0}, {0, 0}, {1, 0}};
    unsigned int cargo101End[3][2] = {{0, 0}, {0, 0}, {0, 1}};

    // Set Matrices
    matrixCopy(*cargoBot.boxPanel, *cargo101Start);
    matrixCopy(*cargoBot.gameGoal, *cargo101End);

    // Read Commands
    do
    {
        if (command != RELEASED)
        {
            cargoBot.userCommands[cargoBot.userCommandCounter] = command;
            cargoBot.userCommandCounter++;
            command = RELEASED;
        }
        else
        {
        }
    } while (command != COMMAND_PLAY);

    // Apply Commands on Claw
    clawDefaultStatus();

    for (int commandIndex = 0; commandIndex < cargoBot.userCommandCounter;
         commandIndex++)
    {
        if (cargoBot.userCommands[commandIndex] == COMMAND_PROG1)
        {
            moveClaw(cargoBot.userCommands[0]);
            commandIndex = 0;
        }
        else
        {
            moveClaw(cargoBot.userCommands[commandIndex]);
        }

        const uint8_t status = checkGameStatus();
        commandsToPanel();
        if (status == FINISH)
        {
            break;
        }
    }
}
