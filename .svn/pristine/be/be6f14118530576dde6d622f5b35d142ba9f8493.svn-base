#include "lib/io.h"

void init_pic(void)
{
	/* Initialisation de ICW1 */
	outb(PIC1_COMMAND, 0x11);
	outb(PIC2_COMMAND, 0x11);

	/* Initialisation de ICW2 */
	outb(PIC1_DATA, 0x20);	/* vecteur de depart = 32 */
	outb(PIC2_DATA, 0x70);	/* vecteur de depart = 96 */

	/* Initialisation de ICW3 */
	outb(PIC1_DATA, 0x04);
	outb(PIC2_DATA, 0x02);

	/* Initialisation de ICW4 */
	outb(PIC1_DATA, 0x01);
	outb(PIC2_DATA, 0x01);

	/* masquage des interruptions */
	outb(PIC1_DATA, 0x0);
	outb(PIC2_DATA, 0x0);
}
