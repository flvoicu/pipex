# pipex - Simulación de la Redirección de Tuberías en Shell

**pipex** es un proyecto en **C** diseñado para replicar el comportamiento de la redirección de tuberías (`|`) en un entorno de terminal Unix. Este programa ejecuta dos comandos con un archivo de entrada y de salida, y conecta los comandos de forma que la salida del primero sea la entrada del segundo.

## Objetivo

El programa debe imitar el siguiente comando de shell:
```bash
< archivo_in comando1 | comando2 > archivo_out
```

## Compilación

Para compilar el proyecto, ejecuta el comando `make` en la raíz del proyecto:

```bash
make
```

## Ejecución

```bash
./pipex archivo_in "comando1" "comando2" archivo_out
```