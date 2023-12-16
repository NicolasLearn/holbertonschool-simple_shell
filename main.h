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

/*---------------------------------------------------------------------------*/
		/*EXTERN VARIABLE*/
/*---------------------------------------------------------------------------*/

extern char **environ;

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
	void (*func)(char *);
} shell_cmd;

int is_shell_cmd(char *command, char *input);
void shell_exit(char *);
void shell_env(char *);
void my_exec(char *path, char *arr_tok[]);

/*---------------------------------------------------------------------------*/
		/*PROTOTYPE FILE : MANIP_STRING*/
/*---------------------------------------------------------------------------*/

char *get_cmd_line(char *input, char *array_token[]);
char *is_valid_cmd(char *command);
char *get_PATH(void);
char *is_here(char *path, char *exec);

#endif
