OwnKernel
=========
Amaury 19/12/2012


I use bochs compiled from scratch in order to use debugger and other functionality

then Install libgtk2.0-dev and nasm before configuring bochs.

i use at least --enable-debugger --enable-debugger-gui --with-x to configure bochs package

Make sure you have export LIBS env var brefore configuring bochs, export LIBS=`pkg-config gtk+-2.0 --cflags`

then make


at last sudo make install




