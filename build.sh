#!/bin/bash
echo "Assembling start.asm"
nasm -f elf -o build/start.o kernel/arch/i686/start.asm

echo "Compiling includes"
i686-elf-gcc -c kernel/arch/i686/system.c -o build/system.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c kernel/arch/i686/tty.c -o build/tty.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c kernel/arch/i686/gdt.c -o build/gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c kernel/arch/i686/idt.c -o build/idt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

echo "Compiling kernel.c"
i686-elf-gcc -c kernel/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

echo "Linking binaries together"
i686-elf-gcc -T link.ld -o build/kernel.bin -ffreestanding -O2 -nostdlib build/kernel.o build/start.o build/system.o build/tty.o build/gdt.o build/idt.o -lgcc

echo "Creating iso"
cp build/kernel.bin isodir/boot/kernel.bin
grub-mkrescue -o build/os.iso isodir

echo "Cleaning up"
rm build/*.o
rm build/*.bin
