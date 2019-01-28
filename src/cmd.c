#include "cmd.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>

const char SpaceChar = 0x20;
const char NullChar = 0x00;

/* CONST DEFS */


/*
 * char* cmd_name: Pointer to the memory address where the @cmd_name will be stored.
 * char* arg_name: Pointer to the memory address where the @arg will be stored.
 * char* raw_string: Pointer to the @raw_string to be parsed.
 * returns: value of 0 if parsed correctly, -1 otherwise.
 */
int8_t read_cmd(char* raw_string, char* cmd_name, char* arg) {
   int err = -1;
   int32_t i = 0;
   size_t slen = strlen(raw_string);
   i = find_char(SpaceChar, raw_string);
   if (i > 0) {
      // Copy command name from raw_string into cmd_name.
      memcpy(cmd_name, raw_string, i);
      // In C, strings have to be null-terminated.
      cmd_name[i] = NullChar;
      // Now, copy the argument from raw_string into arg.
      // i + 1 acconts for skipping SpaceChar.
      memcpy(arg, &raw_string[i + 1], (slen - i));
      arg[slen - i + 1] = NullChar;
      err = 0;
   }
   else {
      // Handle Error: invalid command.
      err = -1;
   }
   return err;
}

int16_t Cmd_Run(char* raw_str, const Command_s* cmd_table) {
   int16_t err = -1;
   uint16_t i = 0;
   char cmd_name[CMD_NAME_LEN_MAX] = { 0 };
   char arg[ARG_NAME_LEN_MAX] = { 0 };
   int32_t arg_val;
   read_cmd(raw_str, cmd_name, arg);
   for (i = 0; (cmd_table[i].callback != NULL); ++i) {
      if (strcmp(cmd_name, cmd_table[i].cmd_name) == 0) {
         arg_val = strtol(arg, NULL, 10);
         cmd_table[i].callback(arg_val);
         err = 0;
         break;
      }
   }
   return err;
}

