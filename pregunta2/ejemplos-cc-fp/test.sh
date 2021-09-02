nasm -f elf64 -o asmFloatInnerProd.o asmFloatInnerProd.asm
gcc -O0 floatInnerProd.c asmFloatInnerProd.o -o floatInnerProd -lm

