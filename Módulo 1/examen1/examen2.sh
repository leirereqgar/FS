#!/bin/bash
# Titulo:       examen2
# Fecha:        03/11/2020
# Autor:        Leire Requena Garcia
# Version:      1.0
# Descripción:  Busca los archivos de etc cuyo propietario sea el root, no se ha modificado en la última semana,
#		no tiene en el nombre las letras e, a, p y tienen permiso de lectura para otros
# Opciones:     Ninguna
# Uso:          ./examen2

find /etc -user root -ctime 7 -name "*[^eap]*.[^eap]*" -perm -o=r
