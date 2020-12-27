#!/bin/sh
# Titulo:       examn1
# Fecha:        22/12/2020
# Autor:        Leire Requena Garcia
# Version:      1.0
# Descripción:
#
# Opciones: ninguna
# Uso: ./examen1.sh

function ayuda {
	printf "\n./examen1.sh  --c  argumentos. Los argumentos pueden ser:"

	printf "\n\tfichero_fuente  fichero_destino  . Copia el fichero fuente en el distino     ó"

	printf "\n\tsolo directorio_destino (si no existe se crea).  Copia los ficheros planos del directorio de trabajo en el directorio_destino   ó"

	printf "\n./examen1.sh  --h   muestra esta ayuda en pantalla, ó"
	printf "\n./examen1,sh –sh argumento. El guión nos deberá mostrar los usuarios que están usando el tipo de Shell especificado como argumento. El argumento podrá ser: csh, o sh o bash.."
}

if (test $# -gt 4) || [[ "$1" == "--h" ]]; then
	ayuda

elif [[ "$1" == "--c" ]]; then
	if [ $# -eq 3 ]; then
		if [ -f $2 ]; then
			cp $2 $3
		else ayuda;
		fi
	elif [ $# -eq 2 ]; then
		mkdir -p $2
		cp $PWD/* $2
	fi
elif (test $# -eq 2) && [[ "$1" == "-sh" ]]; then
	echo `cat /etc/passwd | grep -oP '^.*'$2'$'| cut -d':' -f1echo cat /etc/passwd | grep -oP '^.*'$2'$'| cut -d':' -f1`
fi;
