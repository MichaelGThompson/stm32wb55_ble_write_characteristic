#include "command_manager.h"
#include "main.h"

void handle_cmd_1(void) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);

	BSP_LED_On(LED_BLUE);
	BSP_LED_Off(LED_GREEN);
	BSP_LED_Off(LED_RED);
}

void handle_cmd_2(void) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);
	BSP_LED_Off(LED_BLUE);
	BSP_LED_On(LED_GREEN);
	BSP_LED_Off(LED_RED);
}

void handle_cmd_3(void) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, SET);
	BSP_LED_Off(LED_BLUE);
	BSP_LED_Off(LED_GREEN);
	BSP_LED_On(LED_RED);
}

void handle_cmd_4(void) {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);
	BSP_LED_Off(LED_BLUE);
	BSP_LED_Off(LED_GREEN);
	BSP_LED_Off(LED_RED);
}

void execute_command(cmd_option_t option) {
    if (option >= CMD_MAX_OPTIONS) {
        // Handle error
        printf("Error: Invalid command option!\n");
        return;
    }

    if (cmd_vtable[option] != NULL) {
        cmd_vtable[option]();
    }
}
