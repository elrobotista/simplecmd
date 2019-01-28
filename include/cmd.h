#ifndef CMD_H
#define CMD_H
#include <stdint.h>

/* MACROS */
#define CMD_NAME_LEN_MAX (32)
#define ARG_NAME_LEN_MAX (16)
#define RAW_STR_LEN_MAX (64)

#define CMD_TABLE_END {{0x00, 0x00}, (void*)0}

/* TYPEDEFS */
typedef struct Command {
   char cmd_name[CMD_NAME_LEN_MAX];
   void(*callback)(int32_t arg);
} Command_s;

/* FUNCTION PROTOTYPES */
int8_t read_cmd(char* raw_string, char* cmd_name, char* arg);

int16_t Cmd_Run(char* raw_str, const Command_s* cmd_table);

extern void pwmfreq_callback(int32_t freq_hz);

extern void pwmdc_callback(int32_t dc);


#endif