OBJ=kernel
CC=gcc -Wall -Ilib/ -m32

all: $(OBJ) 

kernel: kernel.o screen.o lib.o gdt.o idt.o interrupt.o int.o pic.o syscalls.o mm.o serial.o io.o
	ld --oformat binary -Ttext 1000 -melf_i386 $^ -o $@

int.o: int.asm
	nasm -f elf32 -o $@ $^ 


.o: .c 
	$(CC) -c $^

clean:
	rm -f $(OBJ) *.o
