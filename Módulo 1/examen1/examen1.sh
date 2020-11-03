#!/bin/bash
# Titulo:       examen1
# Fecha:        03/11/2020
# Autor:        Leire Requena Garcia
# Version:      1.0
# Descripción:  
# Opciones:     Ninguna
# Uso:          ./examen1.sh cadenaCaracteres

if test $# -eq 1; then 
	ls *$1* 

	echo "El número de archivos es: $(ls *$1* | wc -l)"

	echo "El tamaño total en caracteres de estos archivos es: $(wc -m *$1* | tail -1)";

elif test $# -eq 2; then
	if test -f $1; then
		if test -f $2; then
			test -f $2 && cat $1 >> $2 || cp $1 $2;
		elif test -d $2; then
			cp $1 $2/$1`date +%Y-%m-%d`;
		fi;
	else echo "El primer argumento no es un archivo plano.";
	fi;
else printf "\n Este script contiene el ejercicio 1 del primer examen de prácticas, sesiones 1 hasta la 4"
	printf "\n Las soluciones de los apartados a, b, c y d están recogidas en este script\n"
	printf "\t Para el apartado a ejecutar de la siguiente forma: ./examen1.sh cadenaCaracteres.\n \t Se imprimirán todos los archivos con cadenaCaracteres en el nombre, el número de archivos que son y el tamaño total de los archivos en caracteres\n"
	printf "\t Para el apartado b ejecutar: ./examen1.sh nombreArchivo1 nombreArchivo2\n \t Si no existe el archivo nombreArchivo2, se creará y copia el archivo nombreArchivo1 en el archivo nombreArchivo2. Si ya existe el archivo nombreArchivo2, entonces se le añade al final del archivo nombreArchivo2 el contenido del archivo nombrearchivo1"
	printf "\t Para el apartado c ejecutar: ./examen1.sh nombreArchivo1 Directorio\n \t Copia el archivo nombreArchivo1 en el directorio nombreDirectorio con el siguiente nombre: nombreArchivo1_AAA-MM-DD, donde  AAAA-MM-DD es la fecha cuando se ejecuta el guión"
	printf "\t En cualquier otro caso que sea ejecutado el guión ./examen1.sh, Deberá imprimir sobre el terminal el texto que contiene los apartados (a) hasta el (d), que servirá de ayuda.\n"
fi;
