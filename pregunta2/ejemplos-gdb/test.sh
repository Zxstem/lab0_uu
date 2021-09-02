nasm -f elf64 -g ejemplo_gdb.asm -o ejemplo_gdb.o
gcc -O0 helloworld.c ejemplo_gdb.o -o preg -lm

./ejemplo_gdb