#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "include/system.h"
#include "include/tty.h"

uint8_t mk_color(int fg, int bg)
{
    return fg | bg << 4;
}

/* This is a very simple main() function. All it does is sit in an
*  infinite loop. This will be like our 'idle' loop */
void main()
{
    int fg = 0;
    int bg = 0;
    terminal_initialize();
    while(true){
        terminal_setcolor(mk_color(++fg%16, 0));
        terminal_writestring("Hello World How are you today?\n");
    }

    /* ...and leave this loop in. There is an endless loop in
    *  'start.asm' also, if you accidentally delete this next line */
    for (;;);
}