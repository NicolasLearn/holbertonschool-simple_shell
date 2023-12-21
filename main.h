#ifndef __MAIN_H__
#define __MAIN_H__

/*---------------------------------------------------------------------------*/
		/*LIBRAIRY*/
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/*---------------------------------------------------------------------------*/
		/*EXTERN VARIABLE*/
/*---------------------------------------------------------------------------*/

extern char **environ;
extern int errno;

/*---------------------------------------------------------------------------*/
		/*STRUCT AND PROTOTYPE FILE : CHECK_CMD_SHELL*/
/*---------------------------------------------------------------------------*/

/**
 * struct shell_cmd - Structure of shell command integrate
 * @command: command integrate shell.
 * @func: Name of the function will call.
 */
typedef struct shell_cmd
{
	char *command;
	void (*func)(char **);
} shell_cmd;

int is_shell_cmd(char *command, char **input);
void shell_exit(char **);
void shell_env(char **);
void exec_command(char *path, char *arr_tok[]);
void free_elem(char **elem);

/*---------------------------------------------------------------------------*/
		/*PROTOTYPE FILE : MANIP_STRING*/
/*---------------------------------------------------------------------------*/

char *get_cmd_line(char *input, char *array_token[]);
char *is_valid_cmd(char *command);
char *get_PATH(void);
char *is_here(char *path, char *exec);
int is_path(char *f_exec, int len);

#endif
