# pipex - Simulating Pipe Redirection

**pipex** is a **C** project designed to replicate the behavior of pipe redirection (`|`) in a Unix terminal environment. This program executes two commands with an input and output file, connecting the commands so that the output of the first command becomes the input of the second.

## Objective

The program must imitate the following shell command:
```bash
< input_file command1 | command2 > output_file
```

## Compilation

Para compilar el proyecto, ejecuta el comando `make` en la raíz del proyecto:

```bash
make
```

## Execution

```bash
./pipex input_file "command1" "command2" output_file
```
