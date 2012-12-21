#include <lib/kheap.h>

#include "lib/mm.h"

u32 kmalloc( u32 size, int align, u32 *phys)
{
    if( align == 1 && ((end) & 0xFFFFF000) != 0x1000){
        end & 0xFFFFF000;
        end += 0x1000;
    }
    if(phys){
        *phys = end;
    }
    u32 tmp = end;
    tmp += size;
    return tmp;
}