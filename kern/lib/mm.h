/* 
 * File:   mm.h
 * Author: erol
 *
 * Created on 1 juillet 2012, 18:35
 */
#include "types.h"

#define	PAGING_FLAG	0x80000000	/* CR0 - bit 31 */

#define PD0_ADDR 0x20000	/* addr. page directory kernel */
#define PT0_ADDR 0x21000	/* addr. page table[0] kernel */


/* define page entry field(s)*/
typedef struct page
{
    u32 p;
    u32 rw;
    u32 dpl;
    u32 frame;
    
} page_entry;

/* 1024 pages = 1 table entry */
typedef struct page_table
{
    page_entry pages[1024];
    
} page_table_entry;

/* 1024 table_entries = 1 page_directory_entry*/
typedef struct page_directory
{
    page_table_entry *tables[1024];
    
    u32 page_table_physical_adress[1024];
    
    u32 directory_physical_adress;
    
} page_directory_entry;


page_directory_entry *current_dir;
void init_mm(void);
void switch_mm(page_directory_entry* page_d);