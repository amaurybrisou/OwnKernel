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

void init_mm(void);