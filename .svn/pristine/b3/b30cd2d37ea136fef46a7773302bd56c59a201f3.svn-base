OBJ=floppy.img

all: $(OBJ) 

floppy.img: bootsect kernel
	cat boot/bootsect kern/kernel /dev/zero | dd of=floppy.img bs=512 count=2880

bootsect: 
	make -C boot

kernel: 
	make -C kern

clean:
	rm -f $(OBJ) *.o
	make -C boot clean
	make -C kern clean
