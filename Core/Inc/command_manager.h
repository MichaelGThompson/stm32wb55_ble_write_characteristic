/*
 * command_manager.h
 *
 *  Created on: Nov 9, 2026
 *      Author: mgt
 */

#ifndef INC_COMMAND_MANAGER_H_
#define INC_COMMAND_MANAGER_H_

#include <stdint.h>
#include <stdio.h>

typedef enum {
    CMD_OPTION_1 = 0,
    CMD_OPTION_2,
    CMD_OPTION_3,
	CMD_OPTION_4,
    CMD_MAX_OPTIONS /* Used for bounds checking */
} cmd_option_t;

typedef void (*cmd_handler_t)(void);

void handle_cmd_1(void);
void handle_cmd_2(void);
void handle_cmd_3(void);
void handle_cmd_4(void);

static const cmd_handler_t cmd_vtable[CMD_MAX_OPTIONS] = {
    [CMD_OPTION_1] = handle_cmd_1,
    [CMD_OPTION_2] = handle_cmd_2,
    [CMD_OPTION_3] = handle_cmd_3,
	[CMD_OPTION_4] = handle_cmd_4
};

void execute_command(cmd_option_t option);

#endif /* INC_COMMAND_MANAGER_H_ */
