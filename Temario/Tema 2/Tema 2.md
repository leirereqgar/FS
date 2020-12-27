# Tema 2: Introducción a los sistemas operativos

## 2.1 Introducción

### 2.1.1 Funciones de los SO

Una plataforma hardware es un conjunto de recursos de procesamiento y dispositivos E/S. El SO operativo es una representación uniforme y abstracta de los recursos de un ordenador que son requeridos por las aplicaciones.

El SO es una interfaz rica entre las aplicaciones y el hardware que permite compartir los recursos y protegerlos. También actúa de intermediario entre el usuario y el hardware.

Un SO tiene que ser fácil de usar, eficiente y con una gran capacidad de evolución.

#### El SO como interfaz Usuario/Computadora

Presenta al usuario una máquina abstracta más fácil de programar que el hardware subyacente porque oculta su complejidad y trata igual a los diferentes objetos de bajo nivel.

Un programador de aplicaciones desarrolla más fácilmente en un lenguaje de programación de alto nivel (que accede por sí misma a la API del SO) que en lenguaje máquina.

#### El SO como interfaz Usuario/Computadora

Un SO proporciona normalmente utilidades en las siguientes áreas:

- **Desarrollo de software:** editores de texto, compiladores, enlazadores, depuradores de memoria y de código.
- **Ejecución de programas:** cargador de programas y ejecución de estos.
- **Acceso a dispositivos de E/S:** conjunto específico de instrucciones para cada dispositivo. Las llamadas al sistema resuelven estos accesos.

#### El SO como interfaz Usuario/Computadora

- **Acceso al sistema:** en sistemas compartidos o públicos, el SO controla el acceso y uso de los recursos del sistema.
- **Detección y respuesta a errores:** tratamiento de errores a nivel software (exceptions) y hardware (interruptions), minimizando impacto.
- **Contabilidad:** estadísticas de uso de los recursos y medida del rendimiento del sistema (benchmark).

> Una **excepción** es un evento síncrono inesperado generado por alguna condición que ocurre durante la ejecución de una instrucción.

#### Administrador de recursos

El SO necesita un mecanismo de control, sus funciones actúan igual que el resto del software, son programas ejecutados por el procesador; cede el control y depende del procesador para volver a retomarlo. 

Por tanto:

- El SO dirige el uso del procesador y el resto de los recursos.
- Controla la temporalización de la ejecución de los programas.
- Parte del código del SO está cargado en memoria principal (kernel y otros servicios que se estén usando). El resto de la memoria está ocupada por programas y datos de usuario.
- La asignación de la memoria principal la realizan el SO y el hardware de gestión de memoria del procesador.
- El SO decide cuándo un programa en ejecución puede usar un dispositivo de E/S y también el acceso y uso de los ficheros.
- El procesador es también un recurso.

### 2.1.2 Evolución de los SO

1. 40-50's - Procesamiento en serie de programas en lenguaje máquina.
2. 50-60's - Sistemas por lotes (batch): Primer SO el monitor residente. Poca interacción. Infrautilización de la CPU.
3. 60-70's - sistemas multiprogramados interactivos.
4. 70-xx's - aparecen los sistemas multiusuario.

#### Clasificación:

- Según el modo de trabajo: por lotes (batch) vs interactivo.
- Según el aprovechamiento de la CPU:
  - Uniprogramado vs multiprogramado.
  - Uniprocesador vs multiprocesador.
- Según el usuario: monousuario vs multiusuario.

## 2.2 Componentes de un SO multiprogramado

Un buen SO permite un uso eficiente del procesador y los dispositivos E/S a través de modo dual, interrupciones, excepciones y la protección de E/S, memoria y CPU.

Los primeros SO eran sistemas simples, el tener multiprogramación puede cargarse más de una aplicación a la vez, es necesario un algoritmo para gestionar la multiprogramación.

- **Proceso:** programa en ejecución, instancia de un programa ejecutándose en un procesador, unidad de actividad caracterizada por un flujo de ejecución, un estado actual y un conjunto de recursos del sistema asociados. Un proceso está formado por: un programa ejecutable, datos que necesita el SO para ejecutar el programa. Un proceso consta de (PCB):
  - Identificador de proceso PID.
  - Estado: situación en la que se encuentra el proceso en cada momento.
  - Prioridad: nivel propio frente a otros procesos.
  - Memoria: donde reside el programa y sus datos.
  - Contexto de ejecución: registros actuales del procesador.
  - Estado E/S: recursos del sistema que le han sido asignados.
  - Cuota: limitaciones a los recursos

### 2.2.1 Componentes de un SO multiprogramado

Esta implementación permite ver al proceso como una estructura de datos. El estado completo del proceso en un instante se almacena en el contexto (PC, PSW y SP).

Esta estructura permite el desarrollo de técnicas potentes que aseguren la coordinación y coperación entre los procesos. Se necesita un algoritmo que resuelva la coordinación y cooperación de procesos. Existen técnicas de planificación de la CPU.

El cambio de proceso puede ocurrir en cualquier instante en que el SO obtiene el control sobre el proceso en ejecución.

Un **quantum** es el tiempo máximo de uso del procesador.

Una **traza** de ejecución es un listado de la secuencia de instrucciones de programa que realiza el procesador para un proceso. Desde el punto de vista del procesador se entremezclan las trazas de ejecución de los procesos y las del código del sistema operativo.

#### Modelo de 5 estados

Este modelo trata de representar las actividades que el sistema operativo lleva a cabo sobre los procesos:

- Creación
- Terminación
- Multiprogramación

Para ello hace uso de cinco estados: ejecutándose, preparado (listo para ejecutar), bloqueado o esperando, nuevo y finalizado.

Las transiciones que un proceso puede hacer son las siguientes:

- Nuevo -> preparado: el PCB está creado y el programa está disponible en memoria.
- Ejecutándose -> finalizado: el proceso finaliza de forma normal o se aborta por el SO à causa de un error no recuperable.
- Preparado -> ejecutándose: el SO (planificador de CPU) selecciona un proceso para que se ejecute en el procesador.
- Ejecutándose -> bloqueado: el proceso solicita algo al SO y debe esperar.
- Ejecutándose -> preparado: un proceso ha alcanzado el máximo tiempo de ejecución ininterrumpida.
- Bloqueado -> preparado: se produce el evento por el que el SO bloqueó al proceso.
- Preparado / Bloqueado -> finalizado: terminación de un proceso por parte de otro.

## 2.3 Descripción y control de procesos.

Un proceso se describe mediante el PCB:

- **Identificadores:** del proceso, del proceso padre, del usuario...
- **Contexto:** de registros del procesador (PC, PSW, SP...)
- **Información para control del proceso:
  - Estado del proceso según el modelo de 5 estados.
  - Parámetros de planificación
  - Evento que mantiene al proceso bloqueado
  - Cómo acceder a la memoria que aloja el programa asociado al proceso: registros base y longitud.
  - Recursos usados por el proceso (dispositivos E/S, puertos...)

Al crear un proceso se le asigna un **identificador** único, un nuevo **PCB** y la **memoria** para el programa asociado. El PCB se inicializa con el PC en la dirección de comienzo del programa, el SP con la dirección de la pila del sistema, la memoria donde reside el programa y el resto de campos se inicializan a valores por omisión.

### 2.3.1 Cambio de procesos

Un proceso ejecutándose cambia a otro estado y un proceso preparado pasa a estar ejecutando, esto puede realizarse cuando el SO pueda ejecutarse y decida llevarlo a cabo; luego solamente pasará como resultado de: una interrupción, una excepción (evento síncrono inesperado) o una llamada al sistema

Al cambiar de contexto de un programa hay que:

1. Guardar los registros del procesador en el PCB del proceso actualmente ejecutando
2. Actualizar el campo de estado del proceso al nuevo estado al que pasa e insertar el PCB en la cola de bloqueados o bloqueados por eventos
3. Seleccionar un nuevo proceso del conjunto de los que se encuentran en estado preparado
4. Actualizar el estado del proceso seleccionado a ejecutándose y sacarlo de la lista de preparados.
5. Cargar los registros del procesador con la información de los registros almacenada en el PCB del proceso seleccionado

### 2.3.2 Cambio de modo

Se ejecuta una rutina del SO en el contexto del proceso que se encuentra ejecutándose. Puede realizarse siempre que el SO pueda ejecutarse y como resultado de: una interrupción, una excepción o una llamada al sistema.

Hay dos modos para el control de procesos:

- **Modo usuario** el programa de usuario se ejecuta en este modo solo se tiene acceso a: un subconjunto de los registros del procesador, un subconjunto del repertorio de instrucciones máquina y un área de la memoria.
- **Modo núcleo (kernel):** el programa SO que se ejecuta en este modo tiene acceso a todos los recursos de la máquina

El modo de ejecución cambia a modo kernel automáticamente por hardware por una interrupción, excepción o llamada al sistema. Seguidamente ejecuta la rutina del SO que corresponda al evento producido y finalmente, cuando termina la rutina, el hardware restaura automáticamente el modo de ejecución a modo usuario.

Para el cambio de modo se siguen los siguientes pasos:

1. El hardware guarda automáticamente como mínimo el PC y el PSW y cambia a modo kernel.
2. Se determina la rutina del SO que sea necesaria y se carga el PC con si dirección de comienzo.
3. Se ejecuta la rutina, puede que comienza guardando los registros del procesador y termine restaurando en el procesador la información de registros previamente salvada.
4. Volver de la rutina del SO: el hardware restaura automáticamente en el procesador la información del PC y PSW previamente guardados.

### 2.3.3 Llamadas al sistema

Es la forma en la que los programas del usuario se comunican con el SO en tiempo de ejecución. Son solicitudes de petición de servicio al SO.

Algunas llamadas al sistema son:

- Solicitudes E/S: manipulación de archivos y disco.
- Gestión de procesos: control de procesos y comunicaciones.
- Gestión de memoria: mantenimiento de la información.

Se implementan con una trampa o interrupción de software.

### 2.3.4 Hebras

Un proceso permite al SO controlar la asignación de los recursos necesarios para la ejecución de programas e intercalar la ejecución del programa asociado al proceso con otros programas.

Una hebra es una ejecución independiente de un proceso. Puede haber varias hebras en ejecución.

La hebra permite separar los recursos del proceso con su ejecución: la tarea se encarga de soportar todos los recursos necesarios y que cada una de las hebras permite la ejecución del programa de forma independiente del resto de hebras.

Las hebras por su característica de ejecución de programas tienen también 5 estados con los mismos nombres y funciones que los procesos.

Las ventajas de usar hebras y no procesos son:

- Menor tiempo de creación de una hebra en un proceso ya creado que crear un nuevo proceso.
- Menor tiempo de finalización que un proceso.
- Menor tiempo de cambio de contexto entre hebras del mismo proceso.
- Facilitan la comunicación entre hebras del mismo proceso.
- Permiten aprovechar las técnicas de programación concurrente y el multiprocesamiento simétrico.

## 2.4 Gestión básica de memoria

La gestión de memoria la realiza el SO y consiste en gestionar la jerarquía de memoria para cargar y descargar procesos hacia o desde la memoria principal.

El dispositivo de hardware Memory Management Unit-MMU transforma direcciones lógicas en direcciones físicas (tipos de direcciones).

Objetos de la gestión de memoria:

- Ofrecer a cada proceso un espacio de memoria lógica propio.
- Proporcionar protección entre los procesos.
- Permitir que los procesos compartan memoria.
- Maximizar el rendimiento del sistema.



