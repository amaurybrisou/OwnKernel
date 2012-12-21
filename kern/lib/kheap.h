#ifndef __KHEAP_H
#define __KHEAP_H

#include "types.h"
#include "mm.h"

u32 kmalloc(u32 size, int align, u32 *phys);

#endif __KHEAP_H
