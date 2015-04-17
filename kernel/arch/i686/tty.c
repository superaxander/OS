#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../../include/tty.h"
#include "../../include/vga.h"
#include "../../include/system.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
bool terminal_do_scroll = true;

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}

void terminal_set_pos(size_t x, size_t y)
{
  terminal_row = y;
  terminal_column = x;
}

void terminal_enable_scroll(bool on)
{
  terminal_do_scroll = on;
}

void terminal_scroll(void)
{
  if(!terminal_do_scroll){
    return;
  }
  for (size_t i=0;i<(VGA_HEIGHT*VGA_WIDTH);i++)
  {
      if(i<(VGA_HEIGHT*VGA_WIDTH-1)&&i>((VGA_HEIGHT-1)*VGA_WIDTH+1)){
          terminal_buffer[i] = make_vgaentry(' ', terminal_color);
      }else{
          terminal_buffer[i] = terminal_buffer[VGA_WIDTH+i];
      }
  }
  terminal_row = VGA_HEIGHT-1;
}

void terminal_setcolor(uint8_t fg, uint8_t bg)
{
	terminal_color = make_color(fg, bg);
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c)
{
    if(c=='\n'){
        terminal_column = 0;
		if ( ++terminal_row == VGA_HEIGHT )
		{
			terminal_scroll();
		}
    }else{
        terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
        if ( ++terminal_column == VGA_WIDTH )
        {
            terminal_column = 0;
            if ( ++terminal_row == VGA_HEIGHT )
            {
                terminal_scroll();
            }
        }
    }
}

void terminal_write(const char* data, size_t size)
{
	for ( size_t i = 0; i < size; i++ )
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data)
{
	terminal_write(data, strlen(data));
}
