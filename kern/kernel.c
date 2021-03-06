#include "lib/types.h"
#include "lib/malloc.h"
#include "lib/gdt.h"
#include "lib/screen.h"
#include "lib/io.h"
#include "lib/mm.h"
#include "lib/idt.h"
#include "lib/serial.h"

void init_pic(void);


int main(void);

void _start(void)
{
	kY = 16;
	kattr = 0x0E;

	/* Initialisation de la GDT et des segments */
	init_gdt();

	/* Initialisation du pointeur de pile %esp */
	asm("   movw $0x18, %ax \n \
                movw %ax, %ss \n \
                mov $0x20000, %sp");

	main();
}

int main(void)
{
	print("kernel : gdt loaded\n");

	init_idt();
	print("kernel : idt loaded\n");

	init_pic();
	print("kernel : pic configured\n");

	hide_cursor();

	/* Initialisation du TSS */
	asm("	movw $0x38, %ax \n \
		ltr %ax");
	print("kernel : tr loaded\n");

	/* Initialisation de la memoire */
	init_mm();
        print("kernel : paging enable\n");
        
	sti;
	print("kernel : interrupts enable\n");
            
        //init_serial();
        //print("kernel : serial port enable\n");
       // BochsConsolePrint("Bonjour\n");
	while (1);
}