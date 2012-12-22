/*
 * mm.c
 *
 *  Created on: 15 avr. 2012
 *      Author: erol
 */
#include "lib/mm.h"
#include "lib/types.h"
#include "lib/screen.h"
#include "lib/io.h"

/* create a mapping so that virtual addr = physical addr on 4MB containing IDR, GDT, Kernel Code Segment, */
void init_mm(void) {


    u32 *kernel_page_directory; /* kernel page directory */
    u32 *kernel_page_table; /* kernel page directory */
    u32 page_addr;
    int i;

    /* Creation du Page Directory */
    kernel_page_directory = (u32 *) PD0_ADDR;
    kernel_page_directory[0] = PT0_ADDR;

    kernel_page_directory[0] |= 3;

    for (i = 1; i < 1024; i++) {
        kernel_page_directory[i] = 0; /* supervisor level, read/write, not present */
    }

    kernel_page_table = (u32 *) PT0_ADDR;
    page_addr = 0;
    for (i = 0; i < 1024; i++) {
        kernel_page_table[i] = page_addr;
        kernel_page_table[i] |= 3; // P = 1, U/S = 1, U/W = 0
        page_addr += 4096;
    }

    asm("mov %0, %%eax    \n \
         mov %%eax, %%cr3 \n \
         mov %%cr0, %%eax \n \
         or %1, %%eax     \n \
         mov %%eax, %%cr0" ::"i"(PD0_ADDR), "i"(PAGING_FLAG));

}


