# Problema 1 (5 puntos):
- La función `asmMedia32.asm` calcula la media aritmética de los números almacenados en un arreglo de **N** elementos que se encuentran en memoria. Revisar los comentarios en el archivo para más detalle. 

- Para verificar el funcionamiento de su código, ejecute lo siguiente lo siguiente en un Terminal de Linux.
```shell
sh test.sh
```
- Si todo esta correcto debería observar un mensaje como el siguiente en la línea de comandos (Terminal).
```shell
9       10      15      2
La media del arreglo es: 9 
```
- Si desea cambiar los valores del arreglo, luego de ejecutado el comando `sh test.sh`, ejecute lo siguiente en la línea de comandos (Terminal). Reemplazar `numX` por números enteros aleatorios. Puede ingresar un número variable de números.
```shell
./p1 num1 num2 num3 num4 num5 ... 
```
- Por ejemplo:
```shell
./p1 1 2 3 4 5 6 10  
```

> **NOTA: en caso no se pueda compilar el código, debe instalar el paquete gcc-multilib**
```shell
sudo apt install gcc-multilib
```