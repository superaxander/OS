#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include "../../include/system.h"
#include "../../include/timer.h"
#include "../../include/irq.h"
#include "../../include/tty.h"

/* This will keep track of how many ticks that the system
*  has been running for */
volatile static unsigned timer_ticks = 0;
volatile static unsigned long long int timer_seconds = 0;

/* Handles the timer. In this case, it's very simple: We
*  increment the 'timer_ticks' variable every time the
*  timer fires. By default, the timer fires 18.222 times
*  per second. Why 18.222Hz? Some engineer at IBM must've
*  been smoking something funky */
void timer_handler(struct regs *r)
{
    /* Increment our 'tick count' */
    timer_ticks++;

    /* Every 18 clocks (approximately 1 second), we will
    *  display a message on the screen */
    if (timer_ticks % 18 == 0)
    {
        timer_ticks = 0;
        ++timer_seconds;
    }
    if (timer_seconds >= ULLONG_MAX){ //after 18,446,744,073,709,551,615 / 60 / 60 / 24 / 365 = 584942417355 years it will skip a sleep. I hope that won't be a problem lol
        timer_seconds = 0;
    }

}

/* Sets up the system clock by installing the timer handler
*  into IRQ0 */
void timer_install()
{
    irq_install_handler(0, (unsigned)timer_handler);
}

void timer_wait(int seconds)
{
    unsigned long long int target_time = timer_seconds + seconds;
    while(timer_seconds < target_time)
        __asm__ __volatile__("hlt");
}
