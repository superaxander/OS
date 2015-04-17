#ifndef __IRQ_H__
#define __IRQ_H__ 1
void irq_install(void);
void irq_install_handler(int irq, void (*handler)(struct regs *r));
void irq_uninstall_handler(int irq);
#endif