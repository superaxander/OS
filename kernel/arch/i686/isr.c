#include <stddef.h>
#include <stdint.h>
#include "../../include/tty.h"
#include "../../include/isr.h"
#include "../../include/idt.h"
#include "../../include/system.h"


extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void isr31();

void isr_install()
{
  idt_set_gate(0, (unsigned)isr0, 0x08, 0x8E);
  idt_set_gate(1, (unsigned)isr1, 0x08, 0x8E);
  idt_set_gate(2, (unsigned)isr2, 0x08, 0x8E);
  idt_set_gate(3, (unsigned)isr3, 0x08, 0x8E);
  idt_set_gate(4, (unsigned)isr4, 0x08, 0x8E);
  idt_set_gate(5, (unsigned)isr5, 0x08, 0x8E);
  idt_set_gate(6, (unsigned)isr6, 0x08, 0x8E);
  idt_set_gate(7, (unsigned)isr7, 0x08, 0x8E);
  idt_set_gate(8, (unsigned)isr8, 0x08, 0x8E);
  idt_set_gate(9, (unsigned)isr9, 0x08, 0x8E);
  idt_set_gate(10, (unsigned)isr10, 0x08, 0x8E);
  idt_set_gate(11, (unsigned)isr11, 0x08, 0x8E);
  idt_set_gate(12, (unsigned)isr12, 0x08, 0x8E);
  idt_set_gate(13, (unsigned)isr13, 0x08, 0x8E);
  idt_set_gate(14, (unsigned)isr14, 0x08, 0x8E);
  idt_set_gate(15, (unsigned)isr15, 0x08, 0x8E);
  idt_set_gate(16, (unsigned)isr16, 0x08, 0x8E);
  idt_set_gate(17, (unsigned)isr17, 0x08, 0x8E);
  idt_set_gate(18, (unsigned)isr18, 0x08, 0x8E);
  idt_set_gate(19, (unsigned)isr19, 0x08, 0x8E);
  idt_set_gate(20, (unsigned)isr20, 0x08, 0x8E);
  idt_set_gate(21, (unsigned)isr21, 0x08, 0x8E);
  idt_set_gate(22, (unsigned)isr22, 0x08, 0x8E);
  idt_set_gate(23, (unsigned)isr23, 0x08, 0x8E);
  idt_set_gate(24, (unsigned)isr24, 0x08, 0x8E);
  idt_set_gate(25, (unsigned)isr25, 0x08, 0x8E);
  idt_set_gate(26, (unsigned)isr26, 0x08, 0x8E);
  idt_set_gate(27, (unsigned)isr27, 0x08, 0x8E);
  idt_set_gate(28, (unsigned)isr28, 0x08, 0x8E);
  idt_set_gate(29, (unsigned)isr29, 0x08, 0x8E);
  idt_set_gate(30, (unsigned)isr30, 0x08, 0x8E);
  idt_set_gate(31, (unsigned)isr31, 0x08, 0x8E);
}

char *exception_messages[32] =
{
  "Division By Zero",
  "Debug",
  "Non Maskable Interupt",
  "Breakpoint",
  "Into Detected Overflow",
  "Out of Bounds",
  "Invalid Opcode",
  "No Coprocessor",
  "Double Fault",
  "Coprocessor Segment Overrun",
  "Bad TSS",
  "Segement Not Present",
  "Stack Fault",
  "General Protection Fault",
  "Page Fault",
  "Unknown Interrupt",
  "Coprocessor Fault",
  "Alignment Check",
  "Machine Check",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
  "Reserved",
};

void fault_handler(struct regs *r)
{
  char err_code[128];
  itoa(r->err_code, err_code);
  /* Is this a fault whose number is from 0 to 31? */
  if (r->int_no < 32)
  {
    /* Display the description for the Exception that occurred.
    *  In this tutorial, we will simply halt the system using an
    *  infinite loop */
    terminal_writestring(exception_messages[r->int_no]);
    terminal_writestring(" Exception. System Halted!\n");
    switch(r->int_no)
    {
      default:
        terminal_writestring("No error code\n");
        break;
      case 8:
        terminal_writestring("Error code: ");
        terminal_writestring(err_code);
        break;
      case 10:
        terminal_writestring("Error code: ");
        terminal_writestring(err_code);
        break;
      case 11:
        terminal_writestring("Error code: ");
        terminal_writestring(err_code);
        break;
      case 12:
        terminal_writestring("Error code: ");
        terminal_writestring(err_code);
        break;
      case 13:
        terminal_writestring("Error code: ");
        terminal_writestring(err_code);
        break;
      case 14:
        terminal_writestring("Error code: ");
        terminal_writestring(err_code);
        break;
    }
    for (;;);
  }
}