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
		/*STRUCT AND PROTOTYPE FILE : CALL_BY_MAIN*/
/*---------------------------------------------------------------------------*/

/**
 * struct shell_cmd - Structure of shell command integrate
 * @command: command integrate shell.
 * @func: Name of the function will call.
 */
typedef struct shell_cmd
{
	char *command;
	int (*func)(char *cmd);
} shell_cmd;

char *get_cmd_line(char *input, char *array_token[]);
int is_shell_cmd(char *command);
char *is_valid_cmd(char *command);
void exec_command(char *path, char *arr_tok[]);

/*---------------------------------------------------------------------------*/
		/*PROTOTYPE FILE : CALL_BY_FUNCT*/
/*---------------------------------------------------------------------------*/

	/*is_shell_cmd*/
/*-----------------------------------*/
void shell_env(char *);
void shell_exit(char *);

	/*is_valid_cmd*/
/*-----------------------------------*/
char *get_PATH(void);
char *is_here(char *path, char *exec);


#endif
