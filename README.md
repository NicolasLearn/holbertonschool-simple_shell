# Simple Shell - 
A simple UNIX command line interpreter

## Table of Contents
* [Introduction](#Introduction)
  * What is Shell
* [Project Information](#Project-Information)
    * General requirements
    * Used functions
    * compilation
    * usage
    * style of coding
    * flowchart
* [Documentation](#Documentation)
    * Example
    * valgrind output
    * Files
* [Authors](#Authors)

### What is Shell

A **shell** is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program that is used for entering data into and displaying or printing data from, a computer or a computing system.

## Project Information
### General requirements

 * All your files will be compiled on `Ubuntu 20.04 LTS`
 * Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
 * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
 * No more than 5 functions per file
 * All your header files should be include guarded
 * This shell should not have any memory leaks

### Used functions

* all functions from string.h
* `isatty` (man 3 isatty)
* `malloc` (man 3 malloc)
* `free` (man 3 free)
* `fork` (man 2 fork)
* `execve` (man 2 execve)
* `wait` (man 2 wait)
* `exit` (man 3 exit)
* `strtok` (man 3 strtok)
* `perror` (man 3 perror)
* `printf` (man 3 printf)
* `fprintf` (man 3 fprintf)
* `strlen` (man 3 strlen)
* `strdup` (man 3 strdup)
* `strcpy` (man 3 strcpy)
* `strncmp` (man 3 strncmp)
* `strcmp` (man 3 strcmp)
* `strerror` (man 3 strerror)
* `getline` (man 3 getline)
* `access` (man 2 access)

### Compilation

Simply compile files in the repository with the following flags.
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh
```

## Usage

To use the shell execute the ***hsh*** file

## Style of coding

All files are written in C programming language

## Flowchart

<img src="https://files.slack.com/files-pri/T0423U1MW21-F06BV784XEU/flowchart_simple_shell.drawio__2_.png">
         <alt="Flowchart">

## Documentation

### EXAMPLES

**Example 1**

Interactive mode

```
$ /bin/ls
AUTHORS check_cmd_shell.c manip_string.c hsh main.c man_1_simple_shell  README.md main.h
$ ls -la
total 64
drwxr-xr-x  3 vscode vscode  4096 Dec 21 10:40 .
drwxr-xr-x 11 vscode vscode  4096 Dec 20 12:43 ..
-rw-r--r--  1 vscode vscode   139 Dec 20 12:43 AUTHORS.md
-rw-r--r--  1 vscode vscode  2723 Dec 20 12:43 check_cmd_shell.c
drwxr-xr-x  8 vscode vscode  4096 Dec 21 10:21 .git
-rwxr-xr-x  1 vscode vscode 17368 Dec 21 10:40 hsh
-rw-r--r--  1 vscode vscode  1142 Dec 20 12:43 main.c
-rw-r--r--  1 vscode vscode  1752 Dec 20 12:43 main.h
-rw-r--r--  1 vscode vscode  4158 Dec 20 12:43 manip_string.c
-rw-r--r--  1 vscode vscode  6068 Dec 21 10:39 README.md
```
**Example 2**

NON Interactive mode will display the same output as the interactive one

```
echo "/bin/ls" | ./hsh
AUTHORS check_cmd_shell.c  manip_string.c hsh main.c  man_1_simple_shell  README.md     main.h
```

### valgrind output

```
valgrind ./hsh
==821== Memcheck, a memory error detector
==821== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==821== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==821== Command: ./hsh
==821== 
$ ls
AUTHORS.md  check_cmd_shell.c  hsh  main.c  main.h  manip_string.c  README.md
$ ==821== 
==821== HEAP SUMMARY:
==821==     in use at exit: 0 bytes in 0 blocks
==821==   total heap usage: 10 allocs, 10 frees, 2,622 bytes allocated
==821== 
==821== All heap blocks were freed -- no leaks are possible
==821== 
==821== For lists of detected and suppressed errors, rerun with: -s
==821== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### Files

`main.c` :

* `Continuously` waits for user input.
* `Displays` a "$ " prompt if used in an interactive terminal.
* `Reads` a line of standard input (stdin).
* `Analyzes` the input line to extract a command and its arguments.
* `Checks` if the command is a valid shell command.
* `Executes` the command using the exec_command function if it is valid.
* `Repeats` this process in a loop until the program is stopped.

--------------------------------------------------------------------------

`manip_string.c` :

function : char *get_cmd_line(char *, char **);

* This code takes a character string as input, divides it into tokens separated by spaces, tabs, line breaks or carriage returns, stores these tokens in an array and returns the first token as a command.

function : char *is_valid_cmd(char *);

* This code checks whether a given command is valid by searching for it in the paths specified in the PATH environment variable.

function : char *get_PATH(void);

* This code seeks to retrieve the path to the directory containing executables from a program's environment variables. 

function : char *is_here(char *, char *);

* This code checks for the presence of an executable file at a specified path by combining the directory and file paths, then checks whether it is accessible at runtime before returning the full path.

function : is_path(char *, int );

* check if the first argument input is a path or command.

--------------------------------------------------------------------------

`check_cmd_shell.c` :

function : int is_shell_cmd(char *, char *);

* This code checks whether the command entered corresponds to a predefined shell command and executes it if it does, returning a verification flag (1 if the command is a shell command, otherwise 0).

function : void shell_env();

* The shell_env function displays system environment variables using a path through the global variable 'environ'.

function : void shell_exit(char *);

* The "shell_exit" function frees the memory allocated for the "input" pointer and exits the program with a successful status.

function : void exec_command(char *, char **);

* creates a child process to execute an external command with the specified arguments and waits for the command to finish executing before returning.

function : free_elem(char **);

* free element given in parameters.

## how we use shell:

shell display each time a command that we executed

the comand that most user excute in shell:          

|- ls        |to list files and directory            |
| :--------- | ------------------------------------: |
|- pwd       | print working directory               |
|- cat       | show you what we wrote in our file    |
|- env       | print the environment variable        |
|- exit      | shell will end and it gonna exit      |
