#include "lib/io.h"
#include "lib/serial.h"
#include "lib/screen.h"

void BochsConsolePrint(char *s){
   while (is_transmit_empty() == 0);
   do {
        outb(E9HACK ,*s);
        s++;
   } while( *s != 0);
}

