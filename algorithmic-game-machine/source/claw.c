/**
 * claw.c
 *
 * Created on: Aug 1, 2018
 * Author: Bekir Bakar
 */
#include "../include/claw.h"
#include "../include/cargo_bot.h"

void clawDefaultStatus()
{
    claw.numberPosition = CELL_UP;
    claw.letterPosition = CELL_LEFT;
    claw.holding = EMPTY;
}

void goRight()
{
    claw.letterPosition += 1;
}

void goLeft()
{
    claw.letterPosition -= 1;
}

void goUp()
{
    claw.numberPosition = CELL_UP;
}

void goDown()
{
    if (claw.holding == EMPTY)
    {
        pickLed(claw.numberPosition);
    }
    else
    {
        dropLed(claw.numberPosition);
    }
}

void pickLed(unsigned int letter)
{
    for (int number = 0; number < CELL_NUMBER_SIZE; number++)
    {
        const uint8_t boxStatus = cargoBot.boxPanel[letter][number];
        if (boxStatus != EMPTY)
        {
            cargoBot.boxPanel[letter][number] = EMPTY;
            claw.holding = boxStatus;
            goUp();
            break;
        }
    }
}

void dropLed(unsigned int letter)
{
    for (int number = 1; number < CELL_NUMBER_SIZE; number++)
    {
        const int boxStatus = cargoBot.boxPanel[letter][number];
        if (boxStatus == EMPTY)
        {
            cargoBot.boxPanel[letter][number] = claw.holding;
            claw.holding = EMPTY;
            goUp();
            break;
        }
    }
}

void moveClaw(unsigned int direction)
{
    switch (direction)
    {
    case RIGHT:
        goRight();
        break;
    case LEFT:
        goLeft();
        break;
    case UP:
        goUp();
        break;
    case DOWN:
        goDown();
        break;
    default:
        clawDefaultStatus();
        break;
    }
}
