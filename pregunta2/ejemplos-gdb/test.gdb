# con esta sentencia se indica el archivo de salida 
# para poder ver los resultados
set logging file output.txt

# para que las salidas de print se vean bien
set print pretty on

# para que las salidas de los comandos se registren
set logging on

# para evitar que gdb haga preguntas y\n
set pagination off

# fijar el argumento del programa
set args 10

# indicar el archivo que se va a depurar
file helloworld

# fijar un breakpoint en main
b main

# fijar un breakpoint donde se imprime la cadena de texto
b 20

# hook previo para echo
define hook-echo
echo <<<---
end

# hook posterior para echo
define hookpost-echo
echo --->>>\n
end

# definimos un comando de nombre log 
# que muestra el valor de su primer argumento
define log
	printf "counter value is %d\n", $arg0
end

# aqui empieza el programa
echo INICIO

# empezar a correr el programa
r

# para que continue porque hay breakpoints
c

# aqui empieza el bucle
echo BUCLE

# para que repita log y continue
# mientras que la variable cont del programa 
# es mayor que uno
while(cont > 1)
	log cont
	c
end

# aqui termina
echo FIN 

# gracias
