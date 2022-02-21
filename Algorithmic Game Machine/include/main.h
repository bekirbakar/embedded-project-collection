/**
 * main.h
 *
 * Created on: Aug 1, 2018
 * Author: Bekir Bakar
 */
#ifndef MAIN_H
#define MAIN_H

#define Led_A2_Pin              GPIO_PIN_7
#define Led_A2_GPIO_Port        GPIOA
#define Led_A1_Pin              GPIO_PIN_4
#define Led_A1_GPIO_Port        GPIOC
#define Led_B3_Pin              GPIO_PIN_5
#define Led_B3_GPIO_Port        GPIOC
#define Led_A3_Pin              GPIO_PIN_0
#define Led_A3_GPIO_Port        GPIOB
#define Led_B2_Pin              GPIO_PIN_1
#define Led_B2_GPIO_Port        GPIOB
#define Led_B1_Pin              GPIO_PIN_2
#define Led_B1_GPIO_Port        GPIOB
#define Button_Down_Pin         GPIO_PIN_12
#define Button_Down_GPIO_Port   GPIOB
#define Button_Left_Pin         GPIO_PIN_13
#define Button_Left_GPIO_Port   GPIOB
#define Button_Right_Pin        GPIO_PIN_14
#define Button_Right_GPIO_Port  GPIOB
#define Button_Play_Pin         GPIO_PIN_15
#define Button_Play_GPIO_Port   GPIOB
#define Servo_Letter_Pin        GPIO_PIN_6
#define Servo_Letter_GPIO_Port  GPIOC
#define Servo_Number_Pin        GPIO_PIN_7
#define Servo_Number_GPIO_Port  GPIOC

#ifdef __cplusplus
extern "C"
{
#endif
    void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif
