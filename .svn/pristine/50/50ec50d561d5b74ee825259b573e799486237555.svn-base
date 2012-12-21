/* C asm instruction mapping */


#define E9HACK 0xE9 /* Bochs port hack to communicate with host */

//outputs a character to the debug console
#define BochsConsolePrintChar(c) outb(E9HACK, c); 

//stops simulation and breaks into the debug console
#define BochsBreak() outw(0x8A00,0x8A00); outw(0x8A00,0x08AE0);

#define exit() asm volatile ("mov $1,%al ; xor  %bl,%bl; int  $0x80");

#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_COMMAND PIC1
#define PIC1_DATA (PIC1+1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA (PIC2+1)

#define PIC_EOI		0x20		/* End-of-interrupt command code */

//Bochs magic breakpoint
#define breakBochs asm("XCHG %BX, %BX");

/* desactive les interruptions */
#define cli asm("cli"::)

/* reactive les  interruptions */
#define sti asm("sti"::)

/* ecrit un octet sur un port */
#define outb(port,value) \
	asm volatile ("outb %%al, %%dx" :: "d" (port), "a" (value));

/* ecrit 2 octets (word) sur un port */
#define outw(port,value) \
	asm volatile ("outb %%ax, %%dx" :: "d" (port), "a" (value));


/* ecrit 0x20 sur un port */
#define outb_eoi(port,PIC_EOI) \
	asm volatile ("outb %%al, %%dx" :: "d" (port), "a" (value));

/* ecrit un octet sur un port et marque une temporisation */
#define outbp(port,value) \
	asm volatile ("outb %%al, %%dx; jmp 1f; 1:" :: "d" (port), "a" (value));

/* lit un octet sur un port */
#define inb(port) ({ 	\
	unsigned char _v; \
	asm volatile ("inb %%dx, %%al" : "=a" (_v) : "d" (port)); \
		_v;	\
})


//outputs a sentence to the debug console
void BochsConsolePrint(char *s);