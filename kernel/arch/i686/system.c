#include "../../include/system.h"

void *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

void *memset(unsigned char *dest, unsigned char val, int count)
{
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short* memsetw(unsigned short *dest, unsigned short val, int count)
{
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

size_t strlen(const char *str)
{
    size_t retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void itoa(int n, char s[])//from K&R2
{
   int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
   i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
   if (sign < 0)
       s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}
void reverse(char s[])//from K&R too
{
   int i, j;
   char c;

   for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
       c = s[i];
       s[i] = s[j];
       s[j] = c;
   }
}