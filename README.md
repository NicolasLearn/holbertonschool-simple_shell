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
* [Documentation](#Documentation)
    * Testing
    * Files
* [Authors](#Authors)

### What is Shell

A **shell** is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program that is used for entering data into and displaying or printing data from, a computer or a computing system.

## Project Information
### General requirements

 * Allowed editors: vi, vim, emacs
 * All your files will be compiled on `Ubuntu 14.04 LTS`
 * Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
 * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
 * No more than 5 functions per file
 * All your header files should be include guarded
 * This shell should not have any memory leaks

### Used functions

* all functions from string.h
* `isatty` (man 3 isatty)
* `free` (man 3 free)
* `fork` (man 2 fork)
* `execve` (man 2 execve)
* `wait` (man 2 wait)
* `exit` (man 3 exit)
* `strtok` (man 3 strtok)
* `perror` (man 3 perror)
* `printf` (man 3 printf)
* `getline` (man 3 getline)

### Compilation

Simply compile files in the repository with the following flags.
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh
```

## Usage

To use the shell execute the ***hsh*** file

## Style of coding

All files are written in C programming language

## Documantation
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

`check_cmd_shell.c` :

function : int is_shell_cmd(char *, char *);

* This code checks whether the command entered corresponds to a predefined shell command and executes it if it does, returning a verification flag (1 if the command is a shell command, otherwise 0).

function : void shell_env();

* The shell_env function displays system environment variables using a path through the global variable 'environ'.

function : void shell_exit(char *);

* The "shell_exit" function frees the memory allocated for the "input" pointer and exits the program with a successful status.

function : void exec_command(char *, char **);

* creates a child process to execute an external command with the specified arguments and waits for the command to finish executing before returning.
