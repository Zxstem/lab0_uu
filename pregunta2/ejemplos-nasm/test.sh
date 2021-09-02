nasm -f elf64 getname.asm -o getname.o
ld getname.o -o getname

./getname
