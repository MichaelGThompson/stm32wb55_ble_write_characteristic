#include "command_manager.h"
#include "main.h"

void handle_cmd_10(void *arg) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);

	BSP_LED_On(LED_BLUE);
	BSP_LED_Off(LED_GREEN);
	BSP_LED_Off(LED_RED);
}

void handle_cmd_20(void *arg) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);
	BSP_LED_Off(LED_BLUE);
	BSP_LED_On(LED_GREEN);
	BSP_LED_Off(LED_RED);
}

void handle_cmd_30(void *arg) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, SET);
	BSP_LED_Off(LED_BLUE);
	BSP_LED_Off(LED_GREEN);
	BSP_LED_On(LED_RED);
}

void handle_cmd_40(void *arg) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);
	BSP_LED_Off(LED_BLUE);
	BSP_LED_Off(LED_GREEN);
	BSP_LED_Off(LED_RED);
}

void process_command(uint8_t cmd_id, void *arg) {
    for (size_t i = 0; i < CMD_COUNT; i++) {
        if (cmd_table[i].cmd_id == cmd_id) {
            cmd_table[i].handler(arg);
            return;
        }
    }
}
