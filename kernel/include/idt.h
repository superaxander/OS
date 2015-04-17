#ifndef __IDT_H__
#define __IDT_H__ 1

void idt_install(void);
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

#endif