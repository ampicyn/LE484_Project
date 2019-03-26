#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
// exported global variables
extern int Button_Status;
#define R_ON()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET)
#define R_OFF()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET)

#define Y_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET)
#define Y_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET)

#define G_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET)
#define G_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET)

#define W_ON()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET)
#define W_OFF()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET)

#define DW_ON()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET)
#define DW_OFF()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET)

#define MODE_READ()     (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == SET)
#define MIN_G()     (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == SET)
#define WALK_INTERVAL()     (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5) == SET)
#define CONSTANT   99
// Function prototype
void BSP_Init(void);
void Signal_Pass(void);
void Signal_Block(void);
void Signal_Flash(void);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_H */