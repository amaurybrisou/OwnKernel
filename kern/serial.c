#include "lib/io.h"
#include "lib/serial.h"

/* COM1 */
 
void init_serial(void) {
   outb(PORT + 1, 0x00);    // Disable all interrupts
   outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   outb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   outb(PORT + 1, 0x00);    //                  (hi byte)
   outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
   outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}

/* read data */
int serial_received(void) {
   return inb(PORT + 5) & 1;
}
 
char read_serial(void) {
   while (serial_received() == 0);
 
   return inb(PORT);
}


/* send data */
int is_transmit_empty(void) {
   return inb(PORT + 5) & 0x20;
}
 
void write_char_serial(char a) {
   while (is_transmit_empty() == 0);
   outb(PORT,a);
}

void write_serial(char* a) {
   while (is_transmit_empty() == 0);
   do {
        outb(PORT,*a);
        a++;
   } while( *a != "\x0F");
}