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

/* switch processor in paging memory mode ( must be called after ini_mm )*/
void switch_mm( page_directory_entry *page_d) {
//    current_dir = page_d;
//    asm("	mov %0, %%eax    \n \
//                mov %%eax, %%cr3 \n \
//                mov %%cr0, %%eax \n \
//                or %1, %%eax     \n \
//                mov %%eax, %%cr0" ::"i"(&page_d->directory_physical_adress), "i"(PAGING_FLAG));

}
    

/* create a mapping so that virtual addr = physical addr on 4MB containing IDR, GDT, Kernel Code Segment, */
void init_mm(void) {

    
//    page_directory_entry *kernel_page_directory; /* kernel page directory */
//    u32 page_addr;
//    int i;
//    
    /* Creation du Page Directory */
//    kernel_page_directory->directory_physical_adress = ( end & 0xFFFF000 );
//    kernel_page_directory->page_table_physical_adress[0] = ( end & 0xFFFF000 );
//    
//    
//    kernel_page_directory->tables[0] != (u32*) 0x3;
//            
//    for (i = 1; i < 1024; i++)
//       kernel_page_directory->tables[i] = 0; /* supervisor level, read/write, not present */
//
//    
//    *kernel_page_directory->page_table_physical_adress = ((end + 0x1000) & 0xFFFF000);
//    page_addr = 0;
//    for (i = 0; i < 1024; i++) {
//        kernel_page_directory->page_table_physical_adress[i] = page_addr;
//        kernel_page_directory->page_table_physical_adress[i] |= 3; // P = 1, U/S = 1, U/W = 0
//        page_addr += 0x1000;
//    }
//    
//    switch_mm(kernel_page_directory);
    

}


        