#include "lib/types.h"
#include "lib/screen.h"
#include "lib/io.h"
#include "lib/kbd.h"
#include "lib/mm.h"
#include "lib/serial.h"
#include "lib/malloc.h"

void isr_default_int(void){
	print("Default interrupt\n");
        exit();
}

void isr_clock_int(void){
	static int tic = 0;
	static int sec = 0;

	tic++;
	if(tic %100 == 0){
		sec++;
		tic = 0;
		print("Clock\n");
	}
}

void isr_GP_exc(void) /*general protection fault handler */
{
	print("GP fault\n");
	while (1);
}

void isr_PF_exc(void)
{
	u32 faulting_addr;
	u32 eip;

 	asm(" 	movl 60(%%ebp), %%eax; \
    		mov %%eax, %0;         \
		mov %%cr2, %%eax;      \
		mov %%eax, %1": "=m"(eip), "=m"(faulting_addr): );

	print("#PF\n");
	dump((uchar *) &faulting_addr, 4);
	dump((uchar *) &eip, 4);

	asm("hlt");
}

void isr_kbd_int(void){
    uchar i;
    static int lshift_enable;
    static int rshift_enable;
    static int alt_enable;
    static int ctrl_enable;

    do {
            i = inb(0x64);
    } while ((i & 0x01) == 0);

    i = inb(0x60);
    i--;

    //// putcar('\n'); dump(&i, 1); putcar(' ');

    if (i < 0x80) {         /* touche enfoncee */
            switch (i) {
            case 0x29:
                    lshift_enable = 1;
                    break;
            case 0x35:
                    rshift_enable = 1;
                    break;
            case 0x1C:
                    ctrl_enable = 1;
                    break;
            case 0x37:
                    alt_enable = 1;
                    break;
            default:
                    putcar(kbdmap[i * 4 + (lshift_enable || rshift_enable)]);
            }
    } else {                /* touche relachee */
            i -= 0x80;
            switch (i) {
            case 0x29:
                    lshift_enable = 0;
                    break;
            case 0x35:
                    rshift_enable = 0;
                    break;
            case 0x1C:
                    ctrl_enable = 0;
                    break;
            case 0x37:
                    alt_enable = 0;
                    break;
            }
    }

    show_cursor();
}

void isr_serial_int(void){
    u32 b;
    b = read_serial();
    print("Serial Interrupt");
    write_char_serial('s');
}

void isr_nic_int(void){
    print("Nic Interrupt");
    write_serial("NIC");
}