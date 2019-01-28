# simplecmd
Control your microcontroller via serial (string) commands.

Usage is really simple. It goes something like this:

```c
#include <stdio.h>
#include <stdint.h>
#include "cmd.h"

void pwmfreq_callback(int32_t freq_hz) {
   printf("Hey! got request to update PWM Frequency to: %d hertz.\n\r", freq_hz);
   return;
}

void pwmdc_callback(int32_t dc) {
   printf("Hey! got request to update PWM Duty Cycle to: %d percent.\n\r", dc);
   return;
}

int main(void) {

	char str_buff[RAW_STR_LEN_MAX];

	const Command_s CmdTable[] = {
	    {"pwmfreq", pwmfreq_callback},
	    {"pwmdc",   pwmdc_callback},

	    /* Keep this element last always.
	      Used to find where table ends!*/
	    CMD_TABLE_END,
	};


	while(1) {

		// This is where you would replace this scanf function, by the call to whatever
		// interface sends you the string to process. serial.readString() in arduino,
		// for example :)

		scanf("%s", str_buf);
		Cmd_Run(str_buf, CmdTable);
	}
	
	return 0;
}
```

Have fun!
