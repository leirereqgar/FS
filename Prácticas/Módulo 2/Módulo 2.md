Las órdenes del makefile hay que tabularlas con hard tab

# Práctica 7: Compilación y depuración de programas

## Ejercicio 7.1.

Pruebe a comentar en el archivo fuente `main.cpp` la directiva de procesamiento `#include "functions.h"`. La línea quedaría así: `//#include "functions.h"`. Pruebe a generar ahora el módulo objeto con la orden de compilación mostrada anteriormente. ¿Qué ha ocurrido?

```shell
g++ main.cpp
    main.cpp: In function ‘int main()’:
    main.cpp:7:5: error: ‘print_hello’ was not declared in this scope
        7 |     print_hello();
          |     ^~~~~~~~~~~
    main.cpp:9:41: error: ‘factorial’ was not declared in this scope
        9 |     cout << "The factorial of 7 is " << factorial(7) << endl;
```

> Al comentar el include las funciones `print_hello()` y `factorial()` no se encuentran porque la biblioteca ya no está incluida en el programa

## Ejercicio 7.2.

Explique por qué el enlazador no ha podido generar el programa archivo ejecutable `programa2` del ejemplo anterior y, sin embargo, ¿por qué sí hemos podido generar el módulo `main2.o`?

> El archivo `main2.cpp` se usan funciones de `libmates.a`, entonces hay que enlazar específicamente con esa biblioteca:
>
> ```shell
> g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates
> ```
>
> La opción -L permite especificar dónde tiene g++ que buscar las bibliotecas necesarias (solo las que están entre comillas). Como tenemos que enlazar una biblioteca usamos -l para que busque la biblioteca con raíz mates, prefijo lib y sufijo .a, es decir, `libmates.a`

## Ejercicio 7.3. 

Explique por qué la orden g++ previa ha fallado. Explique los tipos de errores que ha encontrado.

```shell
$ mkdir includes
$ mv *.h includes
$ rm *.o programa2
$ g++ -L./ -o programa2 main2.cpp factorial.cpp hello.cpp -lmates
    main2.cpp:2:23: error: functions.h: No such file or directory
    main2.cpp:3:19: error: mates.h: No such file or directory
    main2.cpp: In function ‘int main()’:
    main2.cpp:8: error: ‘print_hello’ was not declared in this scope
    main2.cpp:10: error: ‘factorial’ was not declared in this scope
    main2.cpp:11: error: ‘print_sin’ was not declared in this scope
    main2.cpp:12: error: ‘print_cos’ was not declared in this scope
    main2.cpp:13: error: ‘print_tan’ was not declared in this scope
    factorial.cpp:1:23: error: functions.h: No such file or directory
    hello.cpp:2:23: error: functions.h: No such file or directory
```

> El problema es que `functions.h` y `mates.h` se han movido al directorio `includes` y no los encuentra en el directorio actual, para solucionarlo tenemos que incluir la opción `-I` con el nombre del directorio dónde se encuentran:
>
> ```shell
> g++ -I./includes -L./ -o programa2 main2.cpp factorial.cpp hello.cpp -lmates
> ```

## Ejercicio 7.4.

Copie el contenido del makefile previo a un archivo llamado makefileE ubicado en el mismo directorio en el que están los archivos de código fuente .cpp. Pruebe a modificar distintos archivos .cpp (puede hacerlo usando la orden touch sobre uno o varios de esos archivos) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden make. ¿Se genera siempre la misma secuencia de órdenes cuando los archivos han sido modificados que cuando no? ¿A qué cree puede deberse tal comportamiento?

```makefile
# Nombre archivo: makefileE
# Uso: make –f makefileE
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

programa2: main2.o factorial.o hello.o libmates.a
	g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates

main2.o: main2.cpp
	g++ -I./includes -c main2.cpp

factorial.o: factorial.cpp
	g++ -I./includes -c factorial.cpp

hello.o: hello.cpp
	g++ -I./includes -c hello.cpp

libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o

sin.o: sin.cpp
	g++ -I./includes -c sin.cpp

cos.o: cos.cpp
	g++ -I./includes -c cos.cpp

tan.o: tan.cpp
	g++ -I./includes -c tan.cpp
```

> La orden `make` produce una salida distinta dependiendo de los archivos que hayan cambiado desde la última vez que se ejecutó, así si solo cambiamos 1 no tiene que volver a compilar todos.
> La primera vez que ejecutamos sale una salida parecida a esta:
>
> ```shell
> ➜ make -f makefileF 
> g++ -I./includes -c main2.cpp
> g++ -I./includes -c factorial.cpp
> g++ -I./includes -c hello.cpp
> g++ -I./includes -c sin.cpp
> g++ -I./includes -c cos.cpp
> g++ -I./includes -c tan.cpp
> ar -rvs libmates.a sin.o cos.o tan.o
> r - sin.o
> r - cos.o
> r - tan.o
> g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates
> ```
> Si hacemos touch a alguno de ellos y volvemos a ejecutar detectará los que se han actualizado y sólo ejecutará las ordenes que tengan como dependencia ese archivo:
>
> ```shell
> ➜ touch main2.cpp 
> ➜ make -f makefileF
>     g++ -I./includes -c main2.cpp
>     g++ -L./ -o programa2 main2.o factorial.o hello.o -lmates
> ```

## Ejercicio 7.5.

Obtener un nuevo `makefileF` a partir del `makefile` del ejercicio anterior que incluya además las dependencias sobre los archivos de cabecera. Pruebe a modificar cualquier archivo de cabecera (usando la orden `touch`) y compruebe la secuencia de instrucciones que se muestra en el terminal al ejecutarse la orden `make`.

> ```makefile
> # Nombre archivo: makefile
> # Uso: make 
> # Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
> #              que utiliza el programa2.
> 
> LIB_DIR=./
> 
> programa2: main2.o factorial.o hello.o libmates.a
> 	g++ -L./ -o programa2 main.o factorial.o hello.o libmates.a
> 
> main2.o: main2.cpp ./includes/functions.h ./includes/mates.h 
> 	g++ -I./includes -c main2.cpp
> 
> factorial.o: factorial.cpp ./includes/functions.h
> 	g++ -I./includes -c factorial.cpp
> 
> hello.o: hello.cpp ./includes/functions.h
> 	g++ -I./includes -c hello.cpp
> 
> libmates.a: sin.o cos.o tan.o
> 	ar -rvs libmates.a sin.o cos.o tan.o
> 
> sin.o: sin.cpp ./includes/mates.h
> 	g++ -I./includes -c sin.cpp
> 
> cos.o: cos.cpp ./includes/mates.h
> 	g++ -I./includes -c cos.cpp
> 
> tan.o: tan.cpp ./includes/mates.h
> 	g++ -I./includes -c tan.cpp
> 
> cleanAll: cleanObj cleanLib
> 	rm programa2
> 
> cleanObj:
> 	rm main2.o factorial.o hello.o
> 
> cleanLib:
> 	rm sin.o cos.o tan.o libmates.a
> ```
>
> Se han añadido `function.h` y `mates.h` como nuevas dependencias y la opción `-I./includes` en `g++`. Si modificamos algún archivo se ejecutarán todas las órdenes que lo incluyen como dempendencia:
>
> ```shell
> ➜ touch includes/mates.h 
> ➜ make -f makefileF
>     g++ -I./includes -c main2.cpp
>     g++ -I./includes -c sin.cpp
>     g++ -I./includes -c cos.cpp
>     g++ -I./includes -c tan.cpp
>     ar -rvs libmates.a sin.o cos.o tan.o
>     r - sin.o
>     r - cos.o
>     r - tan.o
>     g++ -L./ -o programa2 main2.o factorial.o hello.o libmates.a
> ```

## Ejercicio 7.6.

Usando como base el archivo makefileG, sustituya la línea de orden de la regla cuyo objetivo es programa2 por otra en la que se use alguna de las variables especiales y cuya ejecución sea equivalente.

```makefile
# Nombre archivo: makefileG
# Uso: make –f makefileG
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

# Variable que indica el compilador que se va a utilizar
CC=g++
# Variable que indica el directorio en donde se encuentran los archivos de cabecera
INCLUDE_DIR= ./includes
# Variable que indica el directorio en donde se encuentran las bibliotecas
LIB_DIR= ./

programa2: main2.o factorial.o hello.o libmates.a
	$(CC) -L$(LIB_DIR) -o $@ $^
main2.o: main2.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

factorial.o: factorial.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

hello.o: hello.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a $^

sin.o: sin.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

cos.o: cos.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

tan.o: tan.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<
```

## Ejercicio 7.7.

Utilizando como base el archivo makefileG y los archivos fuente asociados, realice los cambios que considere oportunos para que, en la construcción de la biblioteca estática libmates.a, este archivo pase a estar en un subdirectorio denominado libs y se pueda enlazar correctamente con el resto de archivos objeto.

```makefile
# Nombre archivo: makefileG
# Uso: make –f makefileG
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

# Variable que indica el compilador que se va a utilizar
CC=g++
# Variable que indica el directorio en donde se encuentran los archivos de cabecera
INCLUDE_DIR= ./includes
# Variable que indica el directorio en donde se encuentran las bibliotecas
LIB_DIR= ./libs

programa2: main2.o factorial.o hello.o libmates.a
	$(CC) -L$(LIB_DIR) -o $@ $^
main2.o: main2.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

factorial.o: factorial.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

hello.o: hello.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

$(LIB_DIR)/libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a $^

sin.o: sin.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

cos.o: cos.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

tan.o: tan.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<
```

## Ejercicio 7.8.

Busque la variable predefinida de `make` que almacena la utilidad del sistema que permite construir bibliotecas. Recuerde que la orden para construir una biblioteca estática a partir de una serie de archivos objeto es ar (puede usar la orden `grep` para filtrar el contenido; no vaya a leer línea a línea toda la salida). Usando el archivo makefileG, sustituya la orden ar por su variable correspondiente.

> La variable es `AR`

```makefile
# Nombre archivo: makefileG
# Uso: make –f makefileG
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

# Variable que indica el compilador que se va a utilizar
CC=g++
# Variable que indica el directorio en donde se encuentran los archivos de cabecera
INCLUDE_DIR= ./includes
# Variable que indica el directorio en donde se encuentran las bibliotecas
LIB_DIR= ./libs

programa2: main2.o factorial.o hello.o libmates.a
	$(CC) -L$(LIB_DIR) -o $@ $^
main2.o: main2.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

factorial.o: factorial.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

hello.o: hello.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

$(LIB_DIR)/libmates.a: sin.o cos.o tan.o
	$(AR) -rvs libmates.a $^

sin.o: sin.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

cos.o: cos.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<

tan.o: tan.cpp
	$(CC) -I$(INCLUDE_DIR) -c $<
```

## Ejercicio 7.9.

Dado el siguiente archivo makefile, explique las dependencias que existen y para qué sirve cada una de las líneas del mismo. Enumere las órdenes que se van a ejecutar a consecuencia de invocar la utilidad `make` sobre este archivo.

```makefile
# Nombre archivo: makefileH
# Uso: make -f makefileH
# Descripción: Mantiene todas las dependencias entre los módulos que utiliza el
# programa1.


CC=g++
CPPFLAGS=-c -Wall -I./includes
SOURCE_MODULES=main.cpp factorial.cpp hello.cpp 
OBJECT_MODULES=$(SOURCE_MODULES:.cpp=.o)
EXECUTABLE=programa1


all: $(OBJECT_MODULES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECT_MODULES)
	$(CC) $^ -o $@

.o: .cpp 
	$(CC) $(CPPFLAGS) $< -o $@
```

> Con este makefile todos los cpp son necesarios para crear los objetos y todos los objetos son necesarios para el ejecutable, por tanto se ejecutará un `g++ -c` para cada objeto y un `g++ -o` para el ejecutable























