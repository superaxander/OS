#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "include/system.h"
#include "include/tty.h"
#include "include/gdt.h"
#include "include/idt.h"
#include "include/isr.h"
#include "include/irq.h"

uint8_t mk_color(int fg, int bg)
{
    return fg | bg << 4;
}

/* This is a very simple main() function. All it does is sit in an
*  infinite loop. This will be like our 'idle' loop */
void main()
{
    //char zero[128];
    terminal_initialize();
    terminal_writestring("Loaded!\n");
    //install gdt
    gdt_install();
    terminal_writestring("GDT installed!\n");
    //install idt
    idt_install();
    terminal_writestring("IDT installed!\n");
    isr_install();
    terminal_writestring("ISR's installed\n");
    irq_install();
    terminal_writestring("IRQ's installed\n");


    /*
    while(true){
        terminal_setcolor(mk_color(++fg%16, 0));
        terminal_writestring("Hello World How are you today?\n");
    }*/

    /* ...and leave this loop in. There is an endless loop in
    *  'start.asm' also, if you accidentally delete this next line */
    for (;;);
}