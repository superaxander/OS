#ifndef __SYSTEM_H__
#define __SYSTEM_H__ 1
#include <stddef.h>

void* memcpy(unsigned char *dest, const unsigned char *src, int count);
void* memset(unsigned char *dest, unsigned char val, int count);
unsigned short* memsetw(unsigned short *dest, unsigned short val, int count);
size_t strlen(const char *str);
unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, unsigned char _data);
void itoa(int n, char s[]);
void reverse(char s[]);
extern void restore_interrupts();
#endif