#include <lib/kheap.h>

#include "lib/mm.h"

u32 kmalloc( u32 size, int align, u32 *phys)
{
    if( align == 1 && ((PD0_ADDR) & 0xFFFFF000) != 0x1000){
        PD0_ADDR & 0xFFFFF000;
        PD0_ADDR += 0x1000;
    }
    if(phys){
        *phys = PD0_ADDR;
    }
    u32 tmp = PD0_ADDR;
    tmp += size;
    return tmp;
}