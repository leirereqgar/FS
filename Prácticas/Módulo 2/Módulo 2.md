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

## Ejercicio 7.10

Con la siguiente especificación de módulos escriba un archivo denominado `makefilePolaca` que automatice el proceso de compilación del programa final de acuerdo a la siguiente descripción:
Compilador: `gcc` o `g++`
Archivos cabecera: `calc.h`  (ubicado en un subdirectorio denominado cabeceras)
Archivos fuente: `main.c stack.c getop.c getch.c`
Nombre del programa ejecutable: `calculadoraPolaca`
Además, debe incluir una regla denominada `borrar`, sin dependencias, cuya funcionalidad sea la de eliminar los archivos objeto y el programa ejecutable.

```makefile
CC=gcc
CPPFLAGS=-c -Wall -I./includes
SOURCE_MODULES=main.c stack.c getop.c getch.c 
OBJECT_MODULES=$(SOURCE_MODULES:.cpp=.o)
EXECUTABLE=calculadoraPolaca

all: borrar $(OBJECT_MODULES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJETC_MODULES)
	$(CC) $^ -o $€

.o: .cpp
	$(CC) $(CPPFLAGS) $< -o $@

borrar:
	rm calculadoraPolaca *.o
```

# Práctica 8: Depuración de programas

## Ejercicio 8.1

Compile los archivos `main.cpp factorial.cpp hello.cpp` y genere un ejecutable con el nombre `ejemplo8.1`. Lance `gdb` con dicho ejemplo y ejecútelo dentro del depurador. Describa la información que ofrece.

> Para que tenga información para la compilación hay que añadir `-g` como opción al compilador

```shell
g++ -g main.cpp hello.cpp factorial.cpp -o ejemplo8.1
gdb ejemplo8.1
```

> La salida después de ejecutar `run` dentro del intérprete es:
>
> ```shell
> (gdb) run
> Starting program: /home/leirereqgar/Documents/UGR/1ºinformática/1º Cuatrimestre/Fundamentos del Software/2º Matrícula/Prácticas/FS/Prácticas/Módulo 2/Práctica 8/ejemplo8.1 
> Hello World!
> The factorial of 7 is 5040
> [Inferior 1 (process 9373) exited normally]
> ```
>
> Lo que indica que el programa termina correctamente su ejecución sin ningún fallo

## Ejercicio 8.2.

Usando la orden `list` muestre el código del programa principal y el de la función factorial utilizados en el `ejercicio8.1` (para ello utilice la orden `help list`).

```shell
(gdb) list 1,12
1	#include <iostream>
2	#include "functions.h"
3	
4	using namespace std;
5	
6	int main(){
7	   print_hello();
8	   cout << endl;
9	   cout << "The factorial of 7 is " << factorial(7) << endl;
10	   return 0;
11	}
(gdb) list factorial(int)
1	#include "functions.h"
2	
3	int factorial(int n){
4	   if(n!=1){
5		return(n * factorial(n-1));
6	   }
7	   else return 1;
8	}
```

## Ejercicio 8.3.

Ponga un punto de ruptura asociado a cada línea del programa fuente `mainsesion09a.cpp`donde aparezca el comentario `/* break */`. Muestre información de todas las variables que se estén usando
cada vez que en la depuración se detenga la ejecución. Muestre la información del contador de programa mediante `$pc` y el de la pila con `$sp`.

```shell
g++ -g mainsesion09.cpp -o mainsesion09
gdb mainsesion09
```
> Listamos el código para ver cuántos comentarios con `/*break*/`
```shell
(gdb) list 1,55
1	#include <iostream>
2	/*
3	Este programa trata mantener dos variables, la primera 
4	realiza la multiplicación de valores.
5	La segunda ...
6	*/
7	
8	/* Incrementa en 2 una variable */
9	int cuenta (int y)
10	{
11	  int tmp;
12	
13	  tmp = y + 2; 
14	
15	  /* break */
16	
17	  return tmp;
18	}
19	
20	/* Calcula la multiplicación de dos números */
21	int multiplica (int x, int y)
22	{
23	  int final;
24	  int i;
25	
26	  final = 0;
27	  for (i = 0; i < x; i ++)
28	  {
29	     /* break */
30	     final = final + y;
31	  }
32	
33	  return final;
34	}
35	
36	int main (void)
37	{
38	  int final1;
39	  int final2;
40	  int i;
41	
42	  /* break */
43	  final1 = multiplica(3, 2);
44	
45	
46	  for (i = 0; i < 100; i ++)
47	     /* break */
48	     final2 = cuenta(i);
49	
50	  std::cout << final1 << "\n";
51	
52	  return 0;
53	}
```

> Los comentarios están en las líneas 15,29,42,47, ejecutaremos `break` en esas líneas:

```shell
(gdb) break 15
Breakpoint 1 at 0x555555555179: file mainsesion09a.cpp, line 17.
(gdb) break 29
Breakpoint 2 at 0x55555555519e: file mainsesion09a.cpp, line 30.
(gdb) break 42
Breakpoint 3 at 0x5555555551b7: file mainsesion09a.cpp, line 43.
(gdb) break 47
Breakpoint 4 at 0x5555555551d6: file mainsesion09a.cpp, line 48.
```

> Ejecutamos el programa, este parará en los breakpoints y mostraremos las variables que nos piden:

```shell
(gdb) run
Starting program: /home/leirereqgar/Documents/UGR/1ºinformática/1º Cuatrimestre/Fundamentos del Software/2º Matrícula/Prácticas/FS/Prácticas/Módulo 2/Práctica 8/mainsesion09a 

Breakpoint 3, main () at mainsesion09a.cpp:43
43	  final1 = multiplica(3, 2);
(gdb) info locals
final1 = 0
final2 = 0
i = 32767
(gdb) p/x $pc
$1 = 0x5555555551b7
(gdb) x/i $pc
=> 0x5555555551b7 <main()+8>:	mov    $0x2,%esi
(gdb) p/x $cp
$2 = 0x0

(gdb) next

Breakpoint 2, multiplica (x=3, y=2) at mainsesion09a.cpp:30
30	     final = final + y;
(gdb) info locals
final = 0
i = 0
(gdb) p/x $pc
$3 = 0x55555555519e
(gdb) x/i $pc
=> 0x55555555519e <_Z10multiplicaii+32>:	mov    -0x18(%rbp),%eax
(gdb) p/x $sp
$4 = 0x7fffffffdbd0
// Aquí saldrá varias veces el segundo break con distintos valores en final e i según vaya avanzando el bucle

(gdb) next
Breakpoint 4, main () at mainsesion09a.cpp:48
48	     final2 = cuenta(i);
(gdb) info locals
final1 = 6
final2 = 0
i = 0
(gdb) p/x $pc
$5 = 0x5555555551d6
(gdb) x/i $pc
=> 0x5555555551d6 <main()+39>:	mov    -0xc(%rbp),%eax
(gdb) p/x $sp
$6 = 0x7fffffffdbe0

(gdb) next

Breakpoint 1, cuenta (y=0) at mainsesion09a.cpp:17
17	  return tmp;
(gdb) info locals
tmp = 2
(gdb) p/x $pc
$7 = 0x555555555179
(gdb) x/i $pc
=> 0x555555555179 <_Z6cuentai+16>:	mov    -0x4(%rbp),%eax
(gdb) p/x $sp
$8 = 0x7fffffffdbd0
```

> Hay que repetir los pasos hasta llegar al final del programa

## Ejercicio 8.4.

Indique las órdenes necesarias para ver el valor de las variables `final1` y `final2` del programa generado en el ejercicio anterior en los puntos de ruptura correspondientes tras un par de iteraciones en el bucle for. Indique la orden para obtener el código ensamblador de la zona depurada.

```shell
(gdb) break 47
Breakpoint 1 at 0x11d6: file mainsesion09a.cpp, line 48.
(gdb) run
Starting program: /home/leirereqgar/Documents/UGR/1ºinformática/1º Cuatrimestre/Fundamentos del Software/2º Matrícula/Prácticas/FS/Prácticas/Módulo 2/Práctica 8/mainsesion09a 

Breakpoint 1, main () at mainsesion09a.cpp:48
48	     final2 = cuenta(i);
(gdb) continue
Continuing.

Breakpoint 1, main () at mainsesion09a.cpp:48
48	     final2 = cuenta(i);
(gdb) info locals
final1 = 6
final2 = 2
i = 1

(gdb) disassemble
Dump of assembler code for function main():
   0x00005555555551af <+0>:	push   %rbp
   0x00005555555551b0 <+1>:	mov    %rsp,%rbp
   0x00005555555551b3 <+4>:	sub    $0x10,%rsp
   0x00005555555551b7 <+8>:	mov    $0x2,%esi
   0x00005555555551bc <+13>:	mov    $0x3,%edi
   0x00005555555551c1 <+18>:	call   0x55555555517e <_Z10multiplicaii>
   0x00005555555551c6 <+23>:	mov    %eax,-0x8(%rbp)
   0x00005555555551c9 <+26>:	movl   $0x0,-0xc(%rbp)
   0x00005555555551d0 <+33>:	cmpl   $0x63,-0xc(%rbp)
   0x00005555555551d4 <+37>:	jg     0x5555555551e9 <main()+58>
=> 0x00005555555551d6 <+39>:	mov    -0xc(%rbp),%eax
   0x00005555555551d9 <+42>:	mov    %eax,%edi
   0x00005555555551db <+44>:	call   0x555555555169 <_Z6cuentai>
   0x00005555555551e0 <+49>:	mov    %eax,-0x4(%rbp)
   0x00005555555551e3 <+52>:	addl   $0x1,-0xc(%rbp)
   0x00005555555551e7 <+56>:	jmp    0x5555555551d0 <main()+33>
   0x00005555555551e9 <+58>:	mov    -0x8(%rbp),%eax
   0x00005555555551ec <+61>:	mov    %eax,%esi
   0x00005555555551ee <+63>:	lea    0x2e8b(%rip),%rdi        # 0x555555558080 <_ZSt4cout@@GLIBCXX_3.4>
   0x00005555555551f5 <+70>:	call   0x555555555060 <_ZNSolsEi@plt>
   0x00005555555551fa <+75>:	lea    0xe04(%rip),%rsi        # 0x555555556005
   0x0000555555555201 <+82>:	mov    %rax,%rdi
   0x0000555555555204 <+85>:	call   0x555555555040 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
   0x0000555555555209 <+90>:	mov    $0x0,%eax
   0x000055555555520e <+95>:	leave  
   0x000055555555520f <+96>:	ret    
End of assembler dump.
```

## Ejemplo 8.5.

Considerando la depuración de los ejercicios anteriores, elimine todos los puntos de ruptura salvo el primero.

```shell
(gdb) info breakpoints
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000001179 in cuenta(int) at mainsesion09a.cpp:17
2       breakpoint     keep y   0x000000000000119e in multiplica(int, int) 
                                                   at mainsesion09a.cpp:30
3       breakpoint     keep y   0x00000000000011b7 in main() at mainsesion09a.cpp:43
4       breakpoint     keep y   0x00000000000011d6 in main() at mainsesion09a.cpp:48
(gdb) delete breakpoints 2 3 4
(gdb) info breakpoints
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000001179 in cuenta(int) at mainsesion09a.cpp:17
```

## Ejemplo 8.6.

Realice las acciones del ejercicio 8.3 y las del ejercicio 8.5 en un guion y ejecútelas de nuevo mediante la opción -x de gdb. ¿Sabría decir qué hace este programa con la variable final2?

```
break 15
run
info locals
p/x $pc
x/i $pc
p/x $ps
x/i $ps
break 29
n
info locals
p/x $pc
x/i $pc
p/x $ps
x/i $ps
break 42
n
info locals
p/x $pc
x/i $pc
p/x $ps
x/i $ps
break 47
delete breakpoint 2 3 4
```

> `final2` guarda los valores de la función `cuenta(i)` 

## Ejercicio 8.7.

Realice la depuración del programa ejecutable obtenido a partir del archivo fuente `ejsesion09a.cpp`. Utilizando `gdb`, trate de averiguar qué sucede y por qué no funciona. Intente arreglar el programa.

```
(gdb) list
21	{
22	  int i;
23	  int tmp;
24	
25	  tmp = 0;
26	  for (i = 0; i < n; i ++)
27	     suma(tmp, vector[i]);
28	
29	  printf ("Suma = %d\n", tmp);
30	
(gdb) break 27
Breakpoint 1 at 0x555555555188: file ejsesion09a.cpp, line 27.
(gdb) run
Starting program: /home/leirereqgar/Documents/UGR/1ºinformática/1º Cuatrimestre/Fundamentos del Software/2º Matrícula/Prácticas/FS/Prácticas/Módulo 2/Práctica 8/ejsesion09a 

Breakpoint 1, sumatoria (vector=0x7fffffffdba0, n=17) at ejsesion09a.cpp:27
27	     suma(tmp, vector[i]);
(gdb) info locals
i = 0
tmp = 0
(gdb) c
Continuing.

Breakpoint 1, sumatoria (vector=0x7fffffffdba0, n=17) at ejsesion09a.cpp:27
27	     suma(tmp, vector[i]);
(gdb) info locals
i = 1
tmp = 0
```

> `tmp` permanece en 0 porque no se le asigna el valor que devuelve `suma`

## Ejercicio 8.8. 

Compile el programa `mainsesion09b.cpp` y genere un ejecutable con el nombre `ejemplo9.8`.
Ejecute `gdb` con dicho ejemplo y realice una ejecución depurada mediante la orden `run`. Añada un punto de ruptura (breakpoint) en la línea donde se invoca a la función cuenta (se puede realizar tal y como se muestra en el ejemplo anterior o mediante el número de línea donde aparezca la llamada a esa función). Realice 10 pasos de ejecución con `step` y otros 10 con `next`. Comente las diferencias.

```shell
(gdb) break cuenta
Breakpoint 1 at 0x1170: file mainsesion09a.cpp, line 13.
(gdb) run
Starting program: /home/leirereqgar/Documents/UGR/1ºinformática/1º Cuatrimestre/Fundamentos del Software/2º Matrícula/Prácticas/FS/Prácticas/Módulo 2/Práctica 8/ejemplo9.8 

Breakpoint 1, cuenta (y=0) at mainsesion09a.cpp:13
13	  tmp = y + 2; 
(gdb) s
17	  return tmp;
(gdb) s
18	}
(gdb) 
main () at mainsesion09a.cpp:46
46	  for (i = 0; i < 100; i ++)
(gdb) 
48	     final2 = cuenta(i);
(gdb) 

Breakpoint 1, cuenta (y=1) at mainsesion09a.cpp:13
13	  tmp = y + 2; 
(gdb) 
17	  return tmp;
(gdb) 
18	}
(gdb) 
main () at mainsesion09a.cpp:46
46	  for (i = 0; i < 100; i ++)
(gdb) 
48	     final2 = cuenta(i);
(gdb) 

Breakpoint 1, cuenta (y=2) at mainsesion09a.cpp:13
13	  tmp = y + 2; 
(gdb) n
17	  return tmp;
(gdb) 
18	}
(gdb) 
main () at mainsesion09a.cpp:46
46	  for (i = 0; i < 100; i ++)
(gdb) 
48	     final2 = cuenta(i);
(gdb) 

Breakpoint 1, cuenta (y=3) at mainsesion09a.cpp:13
13	  tmp = y + 2; 
(gdb) 
17	  return tmp;
(gdb) 
18	}
(gdb) 
main () at mainsesion09a.cpp:46
46	  for (i = 0; i < 100; i ++)
(gdb) 
48	     final2 = cuenta(i);
(gdb) 

Breakpoint 1, cuenta (y=4) at mainsesion09a.cpp:13
13	  tmp = y + 2; 
```

> `next` ejecuta la siguiente línea del programa sin entrar en cada una de las líneas de una función y `step` ejecuta una a una las instrucciones de la función

## Ejercicio 8.9. 

Depure el programa generado en el ejercicio anterior. Introduzca un punto de ruptura (breakpoint)
dentro de la función cuenta. Usando la orden info frame, muestre la información del marco actual y del marco superior; vuelva al marco inicial y compruebe si ha cambiado algo.

```shell
(gdb) break cuenta
Breakpoint 2 at 0x555555555170: file mainsesion09a.cpp, line 13.
(gdb) run
Starting program: /home/leirereqgar/Documents/UGR/1ºinformática/1º Cuatrimestre/Fundamentos del Software/2º Matrícula/Prácticas/FS/Prácticas/Módulo 2/Práctica 8/ej9.8 

Breakpoint 2, cuenta (y=0) at mainsesion09a.cpp:13
13	  tmp = y + 2; 
(gdb) info frame
Stack level 0, frame at 0x7fffffffdbf0:
 rip = 0x555555555170 in cuenta (mainsesion09a.cpp:13); saved rip = 0x5555555551e0
 called by frame at 0x7fffffffdc10
 source language c++.
 Arglist at 0x7fffffffdbe0, args: y=0
 Locals at 0x7fffffffdbe0, Previous frame's sp is 0x7fffffffdbf0
 Saved registers:
  rbp at 0x7fffffffdbe0, rip at 0x7fffffffdbe8
(gdb) up
#1  0x00005555555551e0 in main () at mainsesion09a.cpp:48
48	     final2 = cuenta(i);
(gdb) info frame
Stack level 1, frame at 0x7fffffffdc10:
 rip = 0x5555555551e0 in main (mainsesion09a.cpp:48); saved rip = 0x7ffff7abc152
 caller of frame at 0x7fffffffdbf0
 source language c++.
 Arglist at 0x7fffffffdc00, args: 
 Locals at 0x7fffffffdc00, Previous frame's sp is 0x7fffffffdc10
 Saved registers:
  rbp at 0x7fffffffdc00, rip at 0x7fffffffdc08
(gdb) down
#0  cuenta (y=0) at mainsesion09a.cpp:13
13	  tmp = y + 2; 
(gdb) info frame
Stack level 0, frame at 0x7fffffffdbf0:
 rip = 0x555555555170 in cuenta (mainsesion09a.cpp:13); saved rip = 0x5555555551e0
 called by frame at 0x7fffffffdc10
 source language c++.
 Arglist at 0x7fffffffdbe0, args: y=0
 Locals at 0x7fffffffdbe0, Previous frame's sp is 0x7fffffffdbf0
 Saved registers:
  rbp at 0x7fffffffdbe0, rip at 0x7fffffffdbe8
```

> La información no cambia

## Ejercicio 8.10.

Ponga un punto de ruptura en la línea 30 del programa utilizado en el ejercicio anterior (función multiplica) de tal forma que el programa se detenga cuando la variable final tenga como valor 8. Compruebe si se detiene o no y explique por qué.

```shell
(gdb) break if final == 8
```

> No se detiene porque la función multiplica se llama con 3 y 2, y este es el que fija el número de repeticiones del bucle, por tanto el valor máximo que alcanza es 6. 

## Ejercicio 8.11.

Pruebe el ejemplo anterior, ejecute después un `continue` y muestre el valor de la variable `tmp`. Todo haría indicar que el valor debiera ser 12 y sin embargo no es así, explique por qué.

```shell
(gdb) break 10
Breakpoint 1 at 0x1170: file mainsesion09b.cpp, line 13.
(gdb) run
Starting program: /home/leirereqgar/Documents/UGR/1ºinformática/1º Cuatrimestre/Fundamentos del Software/2º Matrícula/Prácticas/FS/Prácticas/Módulo 2/Práctica 8/mainsesion09b 

Breakpoint 1, cuenta (y=0) at mainsesion09b.cpp:13
13	  tmp = y + 2; 
(gdb) print tmp
$1 = 3
(gdb) set variable tmp=10
(gdb) print tmp
$2 = 10
(gdb) c
Continuing.

Breakpoint 1, cuenta (y=1) at mainsesion09b.cpp:13
13	  tmp = y + 2; 
(gdb) print tmp
$3 = 2
```

> `tmp` es una variable local de cuenta, cada vez que se llama a la función se reinicializa a y+2 dónde y es un parámetro de la función; aunque cambiemos el valor a 10, la nueva llamada lo fijará a y+2

## Ejercicio 8.12.

Busque cualquier programa escrito en C++ que cumpla los requisitos para poderlo depurar utilizando la orden `attach`. Compílelo usando el flag de depuración, ejecútelo en una Shell en segundo plano y, en otra Shell, ejecute el depurador con el programa que se está ejecutando en estos momentos en la shell anterior. Utilice las órdenes de gdb para hacer que el programa que se está ejecutando se detenga en algún lugar y posteriormente se pueda continuar su ejecución. Escriba todos los pasos que haya realizado.

```shell
g++ -g ejsesion10.cpp -o ej1
./ej1 &
gdb
(gdb) attach 3619
kill
```



## Ejercicio 8.13.

Utilizando las órdenes de depuración de gdb, corrija el error del programa ecuacionSegundoGrado.cpp. Escriba todos los pasos que haya realizado. Pruebe a depurarlo usando `attach`.