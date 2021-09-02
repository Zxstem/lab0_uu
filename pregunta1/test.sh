nasm -f elf32 -o asmMedia32.o asmMedia32.asm
gcc -m32 -march=i686 pregunta1.c asmMedia32.o -o p1
./p1 9 10 15 2