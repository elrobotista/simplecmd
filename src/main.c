#include "utils.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "cmd.h"

// This main functions as simple tests to verify library is working correctly.
// It also doubles as example :)
// Replace your main's application and include appropriate headers :).

const Command_s CmdTable[] = {
    {"pwmfreq", pwmfreq_callback},
    {"pwmdc",   pwmdc_callback},

    /* Keep this element last always.
      Used to calculate table size!*/
    CMD_TABLE_END,
};

void pwmfreq_callback(int32_t freq_hz) {
   assert(freq_hz == 1200);
}

void pwmdc_callback(int32_t dc) {
   assert(dc == 97);
   return;
}

void TEST_find_char(void) {
   printf("Running TEST_find_char... ");
   char test_str1[] = "0123456";
   uint16_t i;
   int16_t ret;
   for (i = 0; i < strlen(test_str1); ++i) {
      ret = find_char(test_str1[i], test_str1);
      assert(test_str1[i] == test_str1[ret]);
   }
   ret = find_char(' ', test_str1);
   assert(ret == -1);
   printf("OK.\n\r");
}

void TEST_read_cmd(void) {
   printf("Running TEST_read_cmd...");
   char test_str1[] = "pwmfreq 1200";
   
   char name[CMD_NAME_LEN_MAX];
   char arg[ARG_NAME_LEN_MAX];

   read_cmd(test_str1, name, arg);

   assert(!strcmp(name, "pwmfreq"));
   assert(!strcmp(arg, "1200"));

   printf("OK.\n\r");
}

void TEST_cmd_run(void) {
   printf("Running TEST_cmd_run...");
   char test_str1[] = "pwmfreq 1200";
   char test_str2[] = "pwmdc 97";
   char test_str3[] = "invalid 000";
   assert(!Cmd_Run(test_str1, CmdTable));
   assert(!Cmd_Run(test_str2, CmdTable));
   assert(Cmd_Run(test_str3, CmdTable) == -1);
   printf("OK.\n\r");
}

int main(void) {
   TEST_find_char();
   TEST_read_cmd();
   TEST_cmd_run();
   return 0;
}