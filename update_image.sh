#!/bin/bash
echo "UPDATE IMAGE"
sudo losetup /dev/loop0 floppy.img
sudo mount -f /dev/loop0 /mnt
sudo cp kern/kernel /mnt/kernel
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
