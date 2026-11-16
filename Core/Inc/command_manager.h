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
#include <stddef.h>

typedef void (*command_handler_t)(void *arg);

typedef struct {
    uint8_t cmd_id;
	command_handler_t handler;
} cmd_entry_t;

void handle_cmd_10(void *arg);
void handle_cmd_20(void *arg);
void handle_cmd_30(void *arg);
void handle_cmd_40(void *arg);

static const cmd_entry_t cmd_table[] = {
    { 10, handle_cmd_10 },
    { 20, handle_cmd_20 },
    { 30, handle_cmd_30 },
    { 40, handle_cmd_40 }
};

#define CMD_COUNT (sizeof(cmd_table) / sizeof(cmd_table[0]))

void process_command(uint8_t cmd_id, void *arg);

#endif /* INC_COMMAND_MANAGER_H_ */
