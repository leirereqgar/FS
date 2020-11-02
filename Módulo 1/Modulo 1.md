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

# Práctica 3: Variables, alias, órdenes de búsqueda y guiones

## Ejercicio 3.1

Escriba, al menos, cinco variables de entorno junto con el valor que tienen

```shell
env
	SHELL=/usr/bin/zsh
	XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session1
	I3SOCK=/run/user/1000/i3/ipc-socket.608
	DESKTOP_SESSION=/usr/share/xsessions/i3
	GTK_MODULES=canberra-gtk-module
```

## Ejercicio 3.2

Ejecute las órdenes del cuadro e indique qué ocurre y cómo puede resolver la situación para que la variable NOMBRE se reconozca en el shell hijo.

```shell
NOMBRE=FS
echo $NOMBRE
bash
echo $NOMBRE
```

> Se soluciona exportanto la variable antes de cambiar de shell

```shell
export NOMBRE=FS
bash
echo $NOMBRE
```

## Ejercicio 3.3 

Compruebe qué ocurre en las expresiones del ejemplo anterior si se quitan las comillas dobles del final y se ponen después de los dos puntos. ¿Qué sucede si se sustituyen las comillas dobles por comillas simples?

```shell
echo "Los archivos que hay en el directorio son: $(ls -l)"
	Los archivos que hay en el directorio son: total 20
	drwxr-xr-x 2 leirereqgar leirereqgar 4096 Sep 25 18:33 Desktop
	-rw-r--r-- 1 leirereqgar leirereqgar 1372 Sep 29 11:36 DigiCertAssuredIDRootCA.crt
	drwxr-xr-x 7 leirereqgar leirereqgar 4096 Oct  8 17:24 Documents
	drwx------ 3 leirereqgar leirereqgar 4096 Oct 14 11:13 Downloads
	lrwxrwxrwx 1 leirereqgar leirereqgar   10 Jul  2 17:31 Games -> /opt/Games
	drwxr-xr-x 5 leirereqgar leirereqgar 4096 Oct  7 16:23 Pictures
echo "Los archivos que hay en el directorio son: `ls -l`"
```

```shell
echo "Los archivos que hay en el directorio son:" $(ls -l)
	Los archivos que hay en el directorio son: total 20 drwxr-xr-x 2 leirereqgar 			leirereqgar 4096 Sep 25 18:33 Desktop -rw-r--r-- 1 leirereqgar leirereqgar 1372 Sep 29 	   11:36 DigiCertAssuredIDRootCA.crt drwxr-xr-x 7 leirereqgar leirereqgar 4096 Oct 8 		17:24 Documents drwx------ 3 leirereqgar leirereqgar 4096 Oct 14 11:13 Downloads 		lrwxrwxrwx 1 leirereqgar leirereqgar 10 Jul 2 17:31 Games -> /opt/Games drwxr-xr-x 5 	 leirereqgar leirereqgar 4096 Oct 7 16:23 Pictures
echo 'Los archivos que hay en el directorio son: ls -l'
	Los archivos que hay en el directorio son: ls -l //La orden se muestra de forma literal
```

## Ejercicio 3.4

Pruebe la siguiente asignación:

```shell
numero=1
numero=$numero+1
echo $numero
```


¿Qué ha ocurrido?

> Imprime +1 porque no se ha usado expr

## Ejercicio 3.5

Construya un guion que acepte como argumento una cadena de texto (por ejemplo, su nombre) y
que visualice en pantalla la frase Hola y el nombre dado como argumento.

```sh
#!/bin/sh

printf "Hola $1\n"
```

## Ejercicio 3.6

Varíe el guion anterior para que admita una lista de nombres.

```sh
#!/bin/sh

printf "Hola $*\n"
```

## Ejercicio 3.7

Cree tres variables llamadas VAR1, VAR2 y VAR3 con los siguientes valores respectivamente “hola”, “adios” y “14”.
### a) 

Imprima los valores de las tres variables en tres columnas con 15 caracteres de ancho.

```shell
printf "%15q %15q %15d\n" $VAR1 $VAR2 $VAR3
                  hola           adios              14
```

### b) 

¿Son variables locales o globales?

> Locales

### c)

Borre la variable VAR2.

```shell
unset VAR2
```

### d)

Abra otra ventana de tipo terminal, ¿puede visualizar las dos variables restantes?

> No porque son variables locales

### e) 

Cree una variable de tipo vector con los valores iniciales de las tres variables.

```bash
vector=($VAR1 $VAR2 $VAR3)
```

### f) 

Muestre el segundo elemento del vector creado en el apartado e.

```bash
echo ${vector[1]}
```

## Ejercicio 3.8

Cree un alias que se llame ne (nombrado así para indicar el número de elementos) y que devuelva el número de archivos que existen en el directorio actual. ¿Qué cambiaría si queremos que haga lo mismo pero en el directorio home correspondiente al usuario que lo ejecuta?

```shell
alias ne='ls -l | wc -l'


alias ne='ls ~ -l | wc -l'
```

## Ejercicio 3.9

Indique la línea de orden necesaria para buscar todos los archivos a partir del directorio home de usuario ($HOME) que tengan un tamaño menor de un bloque. ¿Cómo la modificaría para que además imprima el resultado en un archivo que se cree dentro del directorio donde nos encontremos y que se llame archivosP?

```shell
find ~ -size -1

find ~ -size -1 > archivosP
```

## Ejercicio 3.10

Indique cómo buscaría todos aquellos archivos del directorio actual que contengan la palabra “ejemplo”.

```shell
grep ejemplo ./*
```

## Ejercicio 3.11 

Complete la información de find y grep utilizando para ello la orden man.

```shell
man find

man grep
```

## Ejercicio 3.12

Indique cómo buscaría si un usuario dispone de una cuenta en el sistema.

```shell
cat /etc/passwd | grep leirereqgar
```

## Ejercicio 3.13

Indique cómo contabilizar el número de ficheros de la propia cuenta de usuario que no tengan permiso de lectura para el resto de usuarios.

```shell
find ~ ! -perm -o+r | wc -l
```

## Ejercicio 3.14

Modifique el ejercicio 8 de forma que, en vez de un alias, sea un guion llamado numE el que devuelva el número de archivos que existen en el directorio que se le pase como argumento.

```bash
#!/bin/bash
# Titulo:       numE
# Fecha:        15/10/2020
# Autor:        Leire Requena Garcia
# Version:      1.0
# Descripción:  Cuenta el número de archivos del directorio
#               dado como primer argumento
# Opciones: ninguna
# Uso: ./numE directorio

ls -1 $1 | wc -l
```

# Práctica 4: Expresiones con variables y expresiones regulares

## Ejercicio 4.1

Utilizando una variable que contenga el valor entero 365 y otra que guarde el número del día actual del año en curso, realice la misma operación del ejemplo anterior usando cada una de las diversas formas de cálculo comentadas hasta el momento, es decir, utilizando expr, $(( ... )) y $[ ... ].

```shell
declare -i dias_anio=365
declare -i dia_actual=$(date +%j)

echo "Faltan $(( (dias_anio-dia_actual) / 7)) semanas hasta el fin de año"
echo "Faltan $[(dias_anio-dia_actual)/7] semanas hasta el fin de año"
```

## Ejercicio 4.2

Realice las siguientes operaciones para conocer el funcionamiento del operador de incremento como sufijo y como prefijo. Razone el resultado obtenido en cada una de ellas:

```shell
v=1 //Crear la variable
echo $v //Mostrar el valor sin ningún cambio
	1
echo $((v++))	//Muestra el valor y después lo incrementa
	1
echo $v
	2
echo $((++v)) //Incrementa el valor y después lo muestra
	3
echo $v
	3
```

## Ejercicio 4.3

Utilizando el operador de división, ponga un caso concreto donde se aprecie que la asignación abreviada es equivalente a la asignación completa, es decir, que `x/=y` equivale a `x=x/y`

```shell
x=10
y=2
echo $[x=x/y]
  5
echo $x
  5
```

```shell
x=10
y=2
echo $[x=/y]
  5
echo $x
  5
```

## Ejercicio 4.4

Compruebe qué ocurre si en el ejemplo anterior utiliza comillas dobles o simples para acotar todo lo
que sigue a la orden echo. ¿Qué sucede si se acota entre comillas dobles solamente la expresión aritmética que se quiere calcular?, ¿y si se usan comillas simples?

```shell
echo 6/5|bc -l
	1.20000000000000000000

echo "6/5|bc -l"
	 "6/5|bc -l"

echo '6/5|bc -l'
	 '6/5|bc -l'

echo "6/5"|bc -l
	1.20000000000000000000

echo '6/5'|bc -l
	1.20000000000000000000
```

## Ejercicio 4.5

Calcule con decimales el resultado de la expresión aritmética (3-2)/5. Escriba todas las expresiones que haya probado hasta dar con una respuesta válida. Utilizando una solución válida, compruebe qué sucede cuando la expresión aritmética se acota entre comillas dobles; ¿qué ocurre si se usan comillas simples?, ¿y si se ponen apóstrofos inversos?

```shell
echo (3-2)/5 | bc -l
	zsh: no matches found: (3-2)/5

echo $[(3-2)/5] | bc -l
	0

echo "(3-2)/5" | bc -l
	.20000000000000000000
	
echo '(3-2)/5' | bc -l
	.20000000000000000000
	
echo `(3-2)/5` | bc -l
	zsh: parse error near `/5'
	zsh: parse error in command substitution
```

## Ejercicio 4.6

Consulte la sintaxis completa de la orden `let` utilizando la orden de ayuda para las órdenes empotradas (`help let`) y tome nota de su sintaxis general.

```shell
let arg [arg ...]


```

>  Evalúa cada ARG como una expresión aritmética.  La evaluación se hace con enteros de longitud fija, sin revisar desbordamientos, aunque la la división por 0 se captura y se marca como un error.  La siguiente
> lista de operadores está agrupada en niveles de operadores de la misma prioridad.  Se muestran los niveles en orden de prioridad decreciente.

## Ejercicio 4.7

Con la orden `let` es posible realizar asignaciones múltiples y utilizar operadores que nosotros no hemos mencionado anteriormente. Ponga un ejemplo de asignación múltiple y, por otra parte, copie en un archivo el orden en el que se evalúan los operadores que admite. Apóyese a través de la ayuda que ofrece help `let`.

```shell
let a=1,b=2
echo "a es igual a $a y b es igual a $b".
	a es igual a 1 y b es igual a 2
```

> Prioridad en let

```
    id++, id--	post-incremento, post-decremento de variable
    ++id, --id	pre-incremento, pre-decremento de variable
    -, +		menos, más unario
    !, ~		negación lógica y basada en bits
    **		exponenciación
    *, /, %		multiplicación, división, residuo
    +, -		adición, sustracción
    <<, >>		desplazamientos de bits izquierdo y derecho
    <=, >=, <, >	comparación
    ==, !=		equivalencia, inequivalencia
    &		AND de bits
    ^		XOR de bits
    |		OR de bits
    &&		AND lógico
    ||		OR lógico
    expr ? expr : expr
    		operador condicional
    =, *=, /=, %=,
    +=, -=, <<=, >>=,
    &=, ^=, |=	asignación
```

## Ejercicio 4.8: 

Probad los siguientes ejemplos y escribir los resultados obtenidos con la evaluación de expresiones

```shell
echo ejemplo1
valor=6
if [ $valor = 3 ]; then echo si; else echo no; fi
	no
echo $valor
	6
```

```shell
echo ejemplo2
valor=5
if [ $valor = 3 ] && ls; then echo si; else echo no; fi
	no
echo $valor
	5
```

```shell
echo ejemplo3
valor=5
if [ $valor = 5 ] && ls; then echo si; else echo no; fi
	Desktop  DigiCertAssuredIDRootCA.crt  Documents  Downloads  Games  Pictures
	si
echo $valor
	5
```

```shell
echo ejemplo4
valor=6
if ((valor==3)); then echo si; else echo no; fi
	no
echo $valor
	6
```

```shell
echo ejemplo5
valor=5
if ((valor==3)) && ls; then echo si; else echo no; fi
	no
echo $valor
	5
```

```shell
echo ejemplo6
valor=5
if ((valor==5)) && ls; then echo si; else echo no; fi
	Desktop  DigiCertAssuredIDRootCA.crt  Documents  Downloads  Games  Pictures
	si
echo $valor
	5
```

```shell
echo ejemplo7
echo $((3>5))
	0
echo $?
	0
```

```shell
echo ejemplo8
((3>5))
echo $?
	1
```

```shell
echo ejemplo9
if ((3>5)); then echo 3 es mayor que 5; else echo 3 no es mayor que 5; fi
	3 no es mayor que 5
```

## Ejercicio 4.9

Haciendo uso de las órdenes conocidas hasta el momento, construya un guion que admita dos parámetros, que compare por separado si el primer parámetro que se le pasa es igual al segundo, o es menor, o es mayor, y que informe tanto del valor de cada uno de los parámetros como del resultado de cada una de las evaluaciones mostrando un 0 o un 1 según corresponda.

```sh
#!/bin/bash
# Titulo:       compara
# Fecha:        20/10/2020
# Autor:        Leire Requena Garcia
# Version:      1.0
# Descripción:  Compara los dos argumentos dados
# Opciones: ninguna
# Uso: compara <num1> <num2>

echo "El valor del primer parámetro es $1 y del segundo $2"

let mayor="$1 > $2"
let menor="$1 < $2"
let iguales="$1 == $2"

echo "¿$1 es mayor que $2?: $mayor"
echo "¿$1 es menor que $2?: $menor"
echo "¿$1 es igual que $2?: $iguales"
```

## Ejercicio 4.10

Usando `test`, construya un guion que admita como parámetro un nombre de archivo y realice las siguientes acciones: asignar a una variable el resultado de comprobar si el archivo dado como parámetro es plano y tiene permiso de ejecución sobre él; asignar a otra variable el resultado de comprobar si el archivo es un enlace simbólico; mostrar el valor de las dos variables anteriores con un mensaje que aclare su significado. 

Pruebe el guion ejecutándolo con `/bin/cat` y también con `/bin/rnano`.

```sh
#!/bin/bash
# Titulo:       comprueba
# Fecha:        20/10/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  Comprueba si el archivo es plano y tienes
#               permiso de ejecución sobre él o si es un enlace
#               simbólico
# Opciones: ninguna
# Uso: comprueba <archivo>

planoejecucion=`(test -f $1 && test -x $1) && echo "es" || echo "no es"`
enlacesimbolico=`test -h $1 && echo "es" || echo "no es"`

echo "El archivo $1 $planoejecucion un archivo plano ejecutable"
echo "El archivo $1 $enlacesimbolico un enlace simbólico"
```

```shell
./comprueba /bin/cat
	El archivo /bin/cat es un archivo plano ejecutable
	El archivo /bin/cat no es un enlace simbólico

./comprueba /bin/rnano
	El archivo /bin/rnano es un archivo plano ejecutable
	El archivo /bin/rnano es un enlace simbólico
```

## Ejercicio 4.11

Ejecute `help test` y anote qué otros operadores se pueden utilizar con la orden `test` y para qué sirven. Ponga un ejemplo de uso de la orden `test` comparando dos expresiones aritméticas y otro comparando dos cadenas de caracteres.

> -a archivo. Verdadero si el archivo existe.
> -t FD. Verdadero si FD está abierto en una terminal.
> -N archivo. Verdadero si el fichero ha sido modificado desde que se leyó.

## Ejercicio 4.12

Responda a los siguientes apartados:

### a)

Razone qué hace la siguiente orden: 

```shell
if test -f ./sesion5.pdf ; then printf "El archivo ./sesion5.pdf existe\n" ; fi
```

> Mira si en el directorio actual existe un archivo plano o regular llamado sesion5.pdf, y en el caso de que exista, imprime "El archivo ./sesion5.pdf existe" por pantalla, y deja un hueco.

### b)

Añada los cambios necesarios en la orden anterior para que también muestre un mensaje de aviso en caso
de no existir el archivo. (Recuerde que, para escribir de forma legible una orden que ocupe más de una
línea, puede utilizar el carácter “\” como final de cada línea que no sea la última.)

```shell
if test -f ./sesion5.pdf ; then printf "El archivo ./sesion5.pdf existe\n" ; else printf "El archivo ./sesion5.pdf no existe" fi
```

### c)

Sobre la solución anterior, añada un bloque elif para que, cuando no exista el archivo ./sesion5.pdf,
compruebe si el archivo /bin es un directorio. Ponga los mensajes adecuados para conocer el resultado
en cada caso posible.

```shell
if test -f ./sesion5.pdf ; then printf "El archivo ./sesion5.pdf existe\n" ; \
elif test -d /bin ; then print "/bin es un directorio y ./sesion5-pdf no existe" ; \
else printf "/bin no es un directorio y ./sesion5-pdf no existe" fi
```

### d)

Usando como base la solución del apartado anterior, construya un guion que sea capaz de hacer lo mismo
pero admitiendo como parámetros la ruta relativa del primer archivo a buscar y la ruta absoluta del
segundo. Pruébelo con los dos archivos del apartado anterior.

```bash
#!/bin/sh
# Titulo:      	existen
# Fecha:        22/10/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  Comprueba si el archivo es plano y si la siguiente ruta
#               es un directorio
# Opciones: ninguna
# Uso: existen <archivo> <directorio>

if [-f $1]; then printf "El archivo $1 existe\n" ;
elif [-d $2]; then printf "$2 es un directorio\n" ;
else printf "$1 no existe y $2 no es un directorio\n";
fi
```

## Ejercicio 4.13

Construya un guion que admita como argumento el nombre de un archivo o directorio y que
permita saber si somos el propietario del archivo y si tenemos permiso de lectura sobre él.

```sh
#!/bin/sh
# Titulo:      	propietario
# Fecha:        22/10/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  Comprueba si somos el propietario del archivo y si
#               tenemos permiso de lectura
# Opciones: ninguna
# Uso: propietario <archivo>

if [-O $1]; then
	if [-r $1]; then printf "Eres el propietario del archivo $1 y tienes permiso de lectura";
	else printf "Eres el propietario de $1 pero no tienes permiso de lectura";
	fi
elif [-r $1]; then printf "No eres el propietario de $1 pero si tienes permiso de lectura";
else printf "No eres el propietario de $1 ni tienes permiso de lectura";
fi
```

## Ejercicio 4.14

Escriba un guion que calcule si el número de días que faltan hasta fin de año es múltiplo de cinco o no, y que comunique el resultado de la evaluación. Modifique el guion anterior para que admita la opción -h de manera que, al ejecutarlo con esa opción, muestre información de para qué sirve el guion y cómo debe ejecutarse. 

El siguiente guion de ejemplo se puede utilizar para borrar el archivo temporal que se le dé como argumento. Si rm devuelve 0, se muestra el mensaje de confirmación del borrado; en caso contrario, se muestra el código de error. Como se puede apreciar, hemos utilizado la variable $LINENO que indica la línea actualmente en ejecución dentro del guion.

```shell
#!/bin/bash
declare -rx SCRIPT=${0##*/}		# donde SCRIPT contiene sólo el nombre del guión
								# ${var##Patron} actúa eliminando de $var aquella parte
								# que cumpla de $Patron desde el principio de $var
								# En este caso: elimina todo lo que precede al
								# último slash “/".
if rm ${1} ; then
	printf "%s\n" "$SCRIPT: archivo temporal borrado"
else
	STATUS=177
	printf "%s – código de finalizacion %d\n" \
	"$SCRIPT:$LINENO no es posible borrar archivo" $STATUS
fi 2> /dev/null
```

```sh
#!/bin/sh
# Titulo:      	diasrestantes
# Fecha:        22/10/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  Comprueba si los días que quedan hasta final de año
#               son múltiplo de 5
# Opciones: ninguna
# Uso: diasrestantes 

if [ "$1" = "-h" ];
	then printf "Este programa calcula si el número de días que faltan para \nfin de año es múltiplo de cinco. \nPara ejecultarlo, escriba ./numerodias \n";
else
	dias_restantes=$[365 -$(date +%j)]
	printf "Quedan $dias_restantes días para el fin de año y "
	
	if [ $[dias_restantes % 5] == 0 ]; 
		then echo "es múltiplo de 5";
	else echo "no es múltiplo de 5"; 
	fi;
fi
```

## Ejercicio 4.15

¿Qué pasa en el ejemplo anterior si eliminamos la redirección de la orden if?

> Se mostrarían ambos mensajes

## Ejercicio 4.16

Haciendo uso del mecanismo de cauces y de la orden echo, construya un guion que admita un argumento y que informe si el argumento dado es una única letra, en mayúsculas o en minúsculas, o es algo distinto de una única letra.

```sh
#!/bin/bash
# Titulo:       letra
# Fecha:        22/10/2020
# Autor:        Leire
# Version:      1.0
# Descripción: Informa si un argumento dado es una única letra o algo distinto
# Opciones: Ninguna
# Uso: letra <cosa>


if echo $1 | grep '^[a-Z]\{1\}$' 2> /dev/null ; then
   echo "Es una única letra";
else
   echo "Es algo distinto de una única letra";
```

## Ejercicio 4.17

Haciendo uso de expresiones regulares, escriba una orden que permita buscar en el árbol de directorios los nombres de los archivos que contengan al menos un dígito y la letra e. ¿Cómo sería la orden si quisiéramos obtener los nombres de los archivos que tengan la letra e y no contengan ni el 0 ni el 1?

```sh
find -regex '.*\([0-9]+.\*e+\).\*'
find -regex '.*e+.*' -and -not -regex '.*[01].*'
```

## Ejercicio 4.18

Utilizando la orden grep, exprese una forma alternativa de realizar lo mismo que con wc -l.

```sh
grep -c
```

