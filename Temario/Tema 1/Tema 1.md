# Tema 1: Sistema de cómputo

## 1.1 Componentes de un sistema de cómputo

### Definiciones

- **Informática:** conjunto de conocimientos científicos y técnicas que hacen posible el tratamiento automático de la información mediante ordenadores.
- **Ordenador:** máquina electrónica dotada de una memoria de gran capacidad y métodos de tratamiento de la información, capaz de resolver problemas aritméticos y lógicos gracias a la utilización de programas.
- **Información:** elementos que procesa un ordenador.

El ordenador admite datos a través de sus elementos de entrada, los transforma ejecutando un programa almacenado y envía los resultados a través de sus elementos de salida.

### Unidades de medida

Byte 						= 2³ bits 	= 8 bits
Kilobyte (KB) 		 = 2¹⁰			= 1024 Bytes
Megabytes (MB)	= 2²⁰ Bytes
Gigabytes (GB) 	  = 2³⁰ Bytes
Terabytes (TB) 	   = 2⁴⁰ Bytes



**Bit:** elemento más pequeño de información. Es un único dígito en un número binario (0 o 1). El bit codifica la información:

n = número de bits para codificar

m = número de elementos codificados
$$
m=2^n; n\geq log_2(m)=3.32*log_{10}(m)
$$

### Representación interna

Un **sistema de numeración** es un conjunto de dígitos que nos sirven para representar ciertas cantidades.

Todo número se expresa por un conjunto de cifras, cada una con un valor que depende de: 

- La cifra
- La posición que ocupa dentro del número

> Definición de **dígito** número que puede expresarse mediante concatenaciones de cifras, y que en el sistema de numeración decimal es alguno de los comprendidos entre el cero y el nueve, ambos inclusive. En el sistema de numeracion binaria es el cero o el uno y en la numeración hexadecimal al variar entre cero y quince, se usan números (0-9) y letras (A-F)

**Sistema de representacion:** decimal, binario, octal, hexadecimal, romano...

*Como pasar de sistemas de representación y la codificación de caracteres en las diapositivas*

#### Codificación

- **Eficiencia de un código (T):** representa la bondad de un código

$$
T=\frac{m}{2^n} ; con 0\leq t\leq 1
$$

- **Redundancia de un código (R):** mide la inversa de la eficiencia y se expresa en tanto por ciento
$$
R=(1-T)*100
$$

### Datos

Una **instrucción** es un conjunto de símbolos insertados en una secuencia estructurada o específica que el procesador interpreta y ejecuta.

Los **datos** son los símbolos que representan hechos, condiciones, situaciones o valores. Elementos de información.

## 1.2 Capa Hardware

- **Firmware:** es parte del hardware de los dispositivos, también es software (microcódigo) que viene de fábrica.

- El **procesador** tiene varias funciones

  - Interpretar y ejecutar instrucciones
  - Realizar cálculos aritmético-lógicos sobre los datos
  - Comunicarse con otras partes del sistema para gobernar el ordenador.

  Está compuesto por la unidad de control y la unidad arimético-lógica

### Unidad de control

Se encarga de interpretar y ejecutar instrucciones para ello detecta señales de estado, capta las instrucciones de la memoria y genera señales de control. Además se comunica con otras partes del sistema para controlar el ordenador.

La velocidad del ordenador la termina el reloj o generador de pulsos de la UC, que produce señales eléctricas que marcan los pasos de cada acción. El tiempo de ciclo es el periodo de esa señal.

La velocidad del relok se mide en GHz, siendo equivalente a mil millones de ciclos por segundo.

### Unidad Aritmético-Lógica

Realiza cálculos ariméticos y lógicos sobre los datos, para ello utiliza los registros (pequeñas memorias de gran velocidad) para almecenar resultados inmediatos.

Se compone de:

- Circuito operacional
- Banco de registros
- Registro acumulador
- Registro de estado

### Memoria principal

Se usa para almacenar las instrucciones de los programas para ejecutarlos; almacena los datos usados por los programas y almacena los resultados intermedios.

Hay dos tipos RAM y ROM.

Se estructura con:

- Celdas (posiciones de memoria)
- Identificación de la celda (posición de memoria)

La RAM se caracteriza por ser de acceso directo: cada posición o palabra de memoria tiene una sola dirección, la informaicón es recuperada muy rápidamente, la lectura es no destructiva y la escritura si y es una memoria volátil, sin suministro eléctrico se pierden los datos.

### Ejecución de instrucciones

Para procesar una instruccion se necesitan dos pasos:

1. El procesador lee (busca, fetch) instrucciones de la memoria, una por vez
2. El procesador ejecuta cada instrucción

La ejecución de un programa consiste en repetir el proceso de búsqueda y ejecución de instrucciones.

Un **ciclo de instrucción** es el procesamiento requerido por una sola instrucción.

### Técnicas de cominicaciones E/S

¿Qué suceda cuando un programa queire comunicarse con algún dispositivos E/S? (Son muy lentos)

Hay tres técnicas para llevar a cabo las operaciones E/S.

#### E/S Programada

1. El procesador encuentra una instrucción con la E/S y se genera una orden al módulo E/S correspondiente.
2. El procesador comprueba periódicamente el estado de la ejecución del módulo E/S hasta que haya finalizado la operación.

![](/home/leirereqgar/Pictures/Screenshots/Screen 2020-10-22 17:27:56.png)

El problema es que el procesador espera demasiado a que acabe el módulo y el sistema se degrada, para solucionarlo tenemos que permitir que el procesador pueda continuar con trabajo útil mientras se atienda la E/S.

#### E/S dirigida por interrupciones

Una interrupción es un evento que interrumpe el flujo normal de la ejecución producido por un elemento externo al procesador. Es un evento asíncrono.

![](/home/leirereqgar/Pictures/Screenshots/Screen 2020-10-22 17:29:41.png)

El problema viene que en las transferencias grandes de memoria a dispositivo o viceversa hay un gran uso del procesador. Se soluciona con el acceso directo a memoria.

#### Acceso Directo a Memoria

En un solo mandato se genera todo lo necesario para realizar la transferencia de información de memoria al dispositivo o viceversa. La realiza un módulo separado que se conceta al bus del sistema o incluida en un módulo E/S. Es útil cuando el procesador desea leer o escribir un bloque de datos.

### Protección Hardware

Los dispositivos de E/S son recursos que tienen que estar protegidos, para ello las instrucciones máquina que acceden a esos dispositivos no pueden ejecutarse en modo usuario, son privilegiadas. Cualquier acceso a los dispositivos desde un programa de usuario se hará mediante peticiones al SO.

#### Protección de memoria

Cada programa  en ejecución tiene que tener un espacio de memoria; hay que proteger esa zona de memoria y la memoria en la que está el código del sistema operativo.

##### Funcionamiento en modo dual

Para impedir que el programa acceda a la zona de memoria donde están los vectores de interrupciones o los modifique tendrá diferentes modos de ejecución de instrucciones:

- **Instrucciones privilegiadas (modo supervisor/kernel):** aquellas cuya ejecución puede interferir en la de un programa cualquiera o programa del SO.
- **Instrucciones no privilegiadas (modo usuario):** aquellas cuya ejecución no presenta ningún problema de seguridad para el resto de programas.

## 1.3 Software

El software son los programas de aplicación y los sistemas operativos que según sus funciones se clasifican en:

- **Software de sistema:** programas que sirven para interactuar con el sistema, teniendo control sobre el hardware y dando soporte a otros programas.
- **Software de aplicaciones:** programas diseñados para los usuarios para poder realizar tareas específicas en el ordenador.
- **Software de utilidad:** programas especiales que sirven para revisar aspectos del funcionamiento del sistema.

### Clasificación del software

#### Software propietario

Se refiere a cualquier programa informático en el que los usuarios tienen limitadas las posibilidades de usarlo, modificarlo o redistribuirlo o que su código fuente no está disponible o su acceso está restringido.

#### Software libre

Puede ser distribuido, modificado, copiado y usado. Debe estar acompañado del código fuente para hacer efectivas las libertades que lo caracterizan.

> Las licencias están en el pdf

## 1.4 El sistema operativo

Un SO es un programa o conjunto de programas que controla la ejecución de los programas de aplicación y actúa como interfaz entre el usuario de una computadora y el hardware de la misma.

Es conveniente que sea fácil de usar, sea eficiente (hay que repartir los recursos entre todos los programas) y tiene que evolucionar fácilmente por las actualizaciones de hardware, para mejorar y/o aportar nuevos servicios y resolver los fallos que tenga.

## 1.5 Utilidades del sistema

Son un conjunto de programas de servicio que se pueden considerara una ampliación del SO:

- Compactación de discos
- Compresión de datos
- Gestión de comunicaciones
- Navegadores de internet
- Respaldo de seguridad
- Recuperación de archivos eliminados
- Antivirus
- Salvapantallas
- Interfaz gráfica
