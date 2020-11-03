# Ejercicios adicionales de scripts

## 1. Escriba un script que se copie a sí mismo en un fichero llamado `backup.sh`; el  script  debe  copiarse  a  sí  mismo  incluso  si  previamente  fue  renombrado.

```sh
#!/bin/bash
# Titulo:       backup
# Fecha:        02/11/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  El script se copia a sí mismo en backup.sh
# Opciones:     Ninguna
# Uso:          ./backup.sh

cp $0 backup.sh
```

## 2. Realice un script que verifique si hay algún dispositivo pendrive conectado al  computador,  si  lo  está,  escriba  un  listado  de  los  dispositivos  montados actualmente de forma dinámica.



## 3. Escriba un script que mediante la orden `grep` elimine las líneas en blanco de otro script. 

```sh
#!/bin/bash
# Titulo:       lineas_blanco
# Fecha:        02/11/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  El script elimina las líneas en blanco de otro script
# Opciones:     Ninguna
# Uso:          ./lineas_blanco.sh <script>

grep -v '^$' $1 > $1
```

## 4. Escriba  un  script  que  mediante  la  orden  `grep`  elimine  los  comentarios  de otro script.

```sh
#!/bin/bash
# Titulo:       borracomentarios
# Fecha:        02/11/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  El script borra los comentarios de otro script
# Opciones:     Ninguna
# Uso:          ./borracomentarios.sh <script>

grep -v '^#'' $1 > $1
```

## 5. Combine  los  scripts  3  y  4  para  que  elimine  las  líneas  en  blanco  y  los comentarios.  ¿Habría más  formas  de  realizar  este  ejercicio?.

```sh
#!/bin/bash
# Titulo:       lineas_comentarios
# Fecha:        02/11/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  El script borra los comentarios y líneas en blanco de otro script
# Opciones:     Ninguna
# Uso:          ./lineas_comentarios.sh <script>


```

## 6. Escriba  un  script  que  devuelva  todos  los  usuarios  del  sistema.  Además imprima  una  lista  de  los  shells  utilizados  por  defecto  al arrancar  para  cada usuario

```sh
#!/bin/bash
# Titulo:       usuarios
# Fecha:        02/11/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  El script devuelva todos los usuarios y la lista de shells
#				por defecto al arrancar
# Opciones:     Ninguna
# Uso:          ./usuarios.sh
```

## 7. `lastlog` es  una  orden  que  devuelve  la  última  vez  que  se  inició  una  sesión. Realice  un  script  que  devuelva  a  qué  hora  el  usuario  que  ejecuta  el  script accedió al computador por última vez.

```sh
#!/bin/bash
# Titulo:       ultimaconexion
# Fecha:        02/11/2020
# Autor:        Leire
# Version:      1.0
# Descripción:  El script devuelve la última vez que se inición sesión con el usuario
#				actual
# Opciones:     Ninguna
# Uso:          ./ultimaconexion.sh

lastlog -user "$(whoami)"
```

## 8. Realice un script que, dado A, B y C como argumento resuelva la ecuación para x: Ax²+Bx + C=0.



## 9. Realice un script que permita compactar varios archivos en uno solo. Donde primer  argumento  sería  el  nombre  del  archivo  de  salida  y  el  resto  de argumentos  serían los  nombres  de  los  archivos  a  compactar.