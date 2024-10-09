[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=16007378&assignment_repo_type=AssignmentRepo)
# Ejemplo filtros de Jack en C++

Este ejemplo construye una aplicación que utiliza Jack y filtros generados 
en Octave, para filtrar el audio en tiempo real.

## Dependencias

Requiere C++ en su estándar del 2020 (g++ 12, clang 14).

En derivados de debian (ubuntu, etc):

     sudo apt install jackd2 libjack-jackd2-dev qjackctl build-essential meson ninja-build jack-tools libsndfile1-dev libsndfile1 libboost-all-dev libbenchmark-dev
     
Jack requiere que su usuario pertenezca al grupo audio, o de otro modo
no tendrá privilegios para el procesamiento demandante en tiempo
real...

     sudo usermod -aG audio <su usuario>

Tambien requiere Octave y el paquete signal.

## Generacion de filtros por Octave

Para construir los filtros la primera vez utilice en Octave

     design_filters

## Construcción

Para construir los ejemplos la primera vez utilice

     meson setup builddir
     cd builddir
     ninja


Si requiere reconstruir todo, utilice

     meson setup --wipe builddir
     cd builddir
     ninja

o si solo requiere reconfigurar por haber agregado otro archivo:

    meson --reconfigure builddir

## Benckmark

Para medir el desempeño de la funcion concreta, lo mejor es usar herramientas de
benchmarking, como Google Benchmark. Se puede agregar un benchmark.cpp con la prueba,
como el incluido en la solucion. Para optimizar el codigo a velocidad y construir todo,
se usa lo siguiente

     meson setup debugoptimized --buildtype=debugoptimized --optimization=3
     cd debugoptimized
     ninja benchmark_tarea3

Para compilar la prueba se usa

     ./benchmark_tarea3

## Latencia y tamaño de bloque

Para reducir la latencia por medio del tamaño del "periodo" (esto es,
el número de "frames" que cada ciclo de procesamiento recibe, en
QjackCtl, en Settings, se indica en Frames/Period.  Eso es un
parámetro del servidor de Jack y no lo puede controlar la aplicación
como tal.
