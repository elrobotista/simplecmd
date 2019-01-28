#include "utils.h"

#include <string.h>

int16_t find_char(char ch, char* raw_string) {
   uint16_t i = 0;
   int32_t idx = -1;
   for (i = 0; i < strlen(raw_string); i++) {
      if (raw_string[i] == ch) {
         idx = i;
         break;
      }
   }
   return idx;

}