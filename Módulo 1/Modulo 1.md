# Práctica 1: Órdenes básicas de UNIX/Linux

## Ejercicio 1.1 
Cree el siguiente árbol de directorios a partir de un directorio de su cuenta de usuario. Indique también cómo sería posible crear toda esa estructura de directorios mediante una única orden (mire las opciones de la orden de creación de directorios mediante man mkdir). Posteriormente realice las siguientes acciones:

```shell
mkdir ejercicio1 ejercicio1/Ejer1 ejercicio1/Ejer1/Ejer21 ejercicio1/Ejer2 ejercicio1/Ejer3
```

### a) 
En Ejer1 cree los archivos arch100.txt, filetags.txt, practFS.ext y robet201.me.

```shell
touch ejercicio1/Ejer1/arch100.txt ejercicio1/Ejer1/filetags.txt ejercicio1/Ejer1/practFS.ext ejercicio1/Ejer1/robet201.me
```

### b) 
En Ejer21 cree los archivos robet202.me, ejer11sol.txt y blue.me.

```shell
touch ejercicio1/Ejer1/Ejer21/robet202.me ejercicio1/Ejer1/Ejer21/ejer11sol.txt ejercicio1/Ejer1/Ejer21/blue.me
```

### c) 
En Ejer2 cree los archivos ejer2arch.txt, ejer2filetags.txt y readme2.pdf.

```shell
touch ejercicio1/Ejer2/ejer2arch.txt ejercicio1/Ejer2/ejer2filetags.txt ejercicio1/Ejer2/readme2.pdf
```

### d) 

En Ejer3 cree los archivos ejer3arch.txt, ejer3filetags.txt y readme3.pdf.

``` shell
touch ejercicio1/Ejer3/ejer3arch.txt ejercicio1/Ejer3/ejer3filetags.txt ejercicio1/Ejer3/readme3.pdf
```

### e) 

¿Podrían realizarse las acciones anteriores empleando una única orden? Indique cómo.

> Colocando todos los path de los archivos detrás del touch

## Ejercicio 1.2

Situados en el directorio ejercicio1 creado anteriormente, realice las siguientes acciones:

### a) 

Mueva el directorio Ejer21 al directorio Ejer2.

```shell
mv Ejer1/Ejer21 Ejer2
```

### b)

Copie los archivos de Ejer1 cuya extensión tenga una x al directorio Ejer3.

```shell
cp Ejer1/*.*x* Ejer3
```

### c) 

Si estamos situado en el directorio Ejer2 y ejecutamos la orden `ls -la ../Ejer3/*arch*`, ¿qué
archivo/s, en su caso, debería mostrar?

> Todos los archivos de Ejer3 que tengan arch en alguna parte de su nombre

## Ejercicio 1.3. 

Si estamos situados en el directorio Ejer2, indique la orden necesaria para listar sólo los nombres de todos los archivos del directorio padre.

```shell
ls -a ../*
```

## Ejercicio 2.4. 

Liste los archivos que estén en su directorio actual y fíjese en alguno que no disponga de la fecha y hora actualizada, es decir, la hora actual y el día de hoy. Ejecute la orden touch sobre dicho archivo y observe qué sucede sobre la fecha del citado archivo cuando se vuelva a listar.

```shell
ls -la
	total 4
	4 drwxr-xr-x 2 leirereqgar leirereqgar 4096 Sep 29 11:59 Ejer21
	0 -rw-r--r-- 1 leirereqgar leirereqgar    0 Sep 29 12:00 ejer2arch.txt
	0 -rw-r--r-- 1 leirereqgar leirereqgar    0 Sep 29 12:00 ejer2filetags.txt
	0 -rw-r--r-- 1 leirereqgar leirereqgar    0 Sep 29 12:00 readme2.pdf
touch ejer21
ls -la
	total 12
	drwxr-xr-x 3 leirereqgar leirereqgar 4096 Sep 29 12:04 .
	drwxr-xr-x 5 leirereqgar leirereqgar 4096 Sep 29 11:57 ..
	drwxr-xr-x 2 leirereqgar leirereqgar 4096 Sep 29 12:12 Ejer21
	-rw-r--r-- 1 leirereqgar leirereqgar    0 Sep 29 12:00 ejer2arch.txt
	-rw-r--r-- 1 leirereqgar leirereqgar    0 Sep 29 12:00 ejer2filetags.txt
	-rw-r--r-- 1 leirereqgar leirereqgar    0 Sep 29 12:00 readme2.pdf
```

> Se actualiza la fecha y hora del archivo

## Ejercicio 2.5. 

La organización del espacio en directorios es fundamental para poder localizar fácilmente aquello que estemos buscando. En ese sentido, realice las siguientes acciones dentro de su directorio home (es el
directorio por defecto sobre el que trabajamos al entrar en el sistema):

### a) 

Obtenga en nombre de camino absoluto (pathname absoluto) de su directorio home. ¿Es el mismo que el
de su compañero/a?

```shell
pwd
```

> No es el mismo

### b)

Cree un directorio para cada asignatura en la que se van a realizar prácticas de laboratorio y, dentro de
cada directorio, nuevos directorios para cada una de las prácticas realizadas hasta el momento.

```shell
mkdir -p FS/"Práctica 1" FP/"Sesión 1"
```

### c) 

Dentro del directorio de la asignatura fundamentos del software (llamado FS) y dentro del directorio creado para esta práctica, copie los archivos hosts y passwd que se encuentran dentro del directorio /etc.

```shell
cp /etc/{hosts, passwd} *Ruta de FS*
```

### d) 

Muestre el contenido de cada uno de los archivos.

```shell
cat hosts
cat passwd
```

## Ejercicio 1.6. 

Situados en algún lugar de su directorio principal de usuario (directorio HOME), cree los directorios siguientes: Sesion.1, Sesion.10, Sesion.2, Sesion.3, Sesion.4, Sesion.27, Prueba.1 y Sintaxis.2 y realice las siguientes tareas:

```shell
mkdir Sesion.1 Sesion.10 Sesion.2 Sesion.3 Sesion.4 Sesion.27 Prueba.1 Sintaxis.2
```

### a)

Borre el directorio Sesion.4

```shell
rmdir Sesion.4
```

### b)

Liste todos aquellos directorios que empiecen por Sesion. y a continuación tenga un único carácter

```shell
ls Sesion.?
```

### c)

Liste aquellos directorios cuyos nombres terminen en .1

```shell
ls *.1
```

### d)

Liste aquellos directorios cuyos nombres terminen en .1 o .2

```shell 
ls *.{1,2}
```

### e)

Liste aquellos directorios cuyos nombres contengan los caracteres si

```shell
ls *si*
```

### f)

Liste aquellos directorios cuyos nombres contengan los caracteres si y terminen en .2

```shell
ls *si*.2
```

## Ejercicio 1.7. 

Desplacémonos hasta el directorio /bin, genere los siguientes listados de archivos (siempre de la forma más compacta y utilizando los metacaracteres apropiados):

```shell
cd /bin
```

### a)

Todos los archivos que contengan solo cuatro caracteres en su nombre

```shell
ls ????
```

### b)

Todos los archivos que comiencen por los caracteres d,f

```shell
ls {d,f}*
```

### c)

Todos los archivos que comiencen por las parejas de caracteres sa, se, ad

```shell
ls {sa,se,ad}*
```

### d)

Todos los archivos que comiencen por t y acaben en r

```shell
ls t*r
```

## Ejercicio 1.8. 

Liste todos los archivos que comiencen por tem y terminen por .gz o .zip :

### a) 

De tu directorio HOME.

```shell
ls ~/tem*.{gz,zip}
```

### b) 

Del directorio actual.

```shell
ls tem*.{gz,zip}
```

### c) 

¿Hay alguna diferencia en el resultado de su ejecución? Razone la respuesta.

> No porque mi directorio actual es el home si cambiase de directorio el resultado sería distinto si hubiese archivos que cumpliesen esas condiciones (en mi caso no los hay)

## Ejercicio 1.9. 

Muestre del contenido de un archivo regular que contenga texto:

### a)

Las 10 primeras líneas.

```shell
head *nombre archivo*
```

### b) 

Las 5 últimas líneas.

```shell
tail -5 *nombre archivo*
```

## Ejercicio 1.10. 

Cree un archivo empleando para ello cualquier editor de textos y escriba en el mismo varias palabras en diferentes líneas. A continuación trate de mostrar su contenido de manera ordenada empleando diversos criterios de ordenación.

```shell
gedit ejemplo
	patata
	lechuga
	romero
	pimienta
	alcachofa
	tomate
sort ejemplo //Orden alfabético
	alcachofa
	lechuga
	patata
	pimienta
	romero
	tomate
sort -r ejemplo //Orden alfabético inverso
	tomate
	romero
	pimienta
	patata
	lechuga
	alcachofa
sort -R ejemplo //Orden aleatorio
	romero
	lechuga
	tomate
	alcachofa
	pimienta
	patata
```

## Ejercicio 1.11. 

¿Cómo podría ver el contenido de todos los archivos del directorio actual que terminen en .txt o .c?

```shell
cat *.{txt,c}
```

# Práctica 2: Permisos y redirecciones

## Ejercicio 2.1

Se debe utilizar solamente una vez la orden chmod en cada apartado. Los cambios se harán en un archivo concreto del directorio de trabajo (salvo que se indique otra cosa). Cambiaremos uno o varios permisos en cada apartado (independientemente de que el archivo ya tenga o no dichos permisos) y comprobaremos que funciona correctamente:

### a)

Dar permiso de ejecución al “resto de usuarios”.

```shell
chmod o+x archivo
```

### b)

Dar permiso de escritura y ejecución al “grupo”.

```shell
chmod g+wx archivo
```

### c)

Quitar el permiso de lectura al “grupo” y al “resto de usuarios”.

```shell
chmod go-r archivo
```

### d)

Dar permiso de ejecución al “propietario” y permiso de escritura el “resto de usuarios”.

```shell
chmod u+x,o+w archivo
```

### e)

Dar permiso de ejecución al “grupo” de todos los archivos cuyo nombre comience con la letra “e”. Nota: Si no hay más de dos archivos que cumplan esa condición, se deberán crear archivos que empiecen con “e” y/o modificar el nombre de archivos ya existentes para que cumplan esa condición.

```shell
chmod g+x e*
```

## Ejercicio 2.2

Utilizando solamente las órdenes de la práctica anterior y los metacaracteres de redirección de salida:

### a)

Cree un archivo llamado ej31 , que contendrá el nombre de los archivos del directorio padre del directorio de trabajo.

```shell
ls ../* > ej31
```

### b)

Cree un archivo llamado ej32 , que contendrá las dos últimas líneas del archivo creado en el ejercicio anterior.

```shell
tail -2 ej31 > ej32
```

### c)

Añada al final del archivo ej32 , el contenido del archivo ej31.

```shell
cat ej31 >> ej32
```

## Ejercicio 2.3

Utilizando el metacarácter de creación de cauces y sin utilizar la orden cd:

### a)

Muestre por pantalla el listado (en formato largo) de los últimos 6 archivos del directorio /etc.

```shell
ls -l /etc | tail -6
```

### b)

La orden wc muestra por pantalla el número de líneas, palabras y bytes de un archivo (consulta la orden man para conocer más sobre ella). Utilizando dicha orden, muestre por pantalla el número de caracteres (sólo ese número) de los archivos del directorio de trabajo que comiencen por los caracteres “e” o “f”.

```shell
cat {e,f}* | wc -m
```

## Ejercicio 2.4

Resuelva cada uno de los siguientes apartados.

### a)

Cree un archivo llamado ejercicio1, que contenga las 17 últimas líneas del texto que proporciona la orden man para la orden chmod (se debe hacer en una única línea de órdenes y sin utilizar el metacarácter “;” ).

```shell
man chmod | tail -17 > ejercicio1
```

### b)

Al final del archivo ejercicio1, añada la ruta completa del directorio de trabajo actual.

```shell
pwd >> ejercicio1
```

### c)

Usando la combinación de órdenes mediante paréntesis, cree un archivo llamado ejercicio3 que contendrá el listado de usuarios conectados al sistema (orden who) y la lista de archivos del directorio actual.

```shell
(who ; ls) > ejercicio3
```

### d)

Añada, al final del archivo ejercicio3, el número de líneas, palabras y caracteres del archivo ejercicio1. Asegúrese de que, por ejemplo, si no existiera ejercicio1, los mensajes de error también se añadieran al final de ejercicio3.

```shell
wc ejercicio1 &>> ejercicio3
```

### e)

Con una sola orden chmod, cambie los permisos de los archivos ejercicio1 y ejercicio3, de forma que se quite el permiso de lectura al “grupo” y se dé permiso de ejecución a las tres categorías de usuarios.

```shell
chmod g-r, a+x ejercicio1 ejercicio3
```