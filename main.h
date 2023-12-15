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
	int (*func)(char *cmd);
} shell_cmd;

int is_shell_cmd(char *command);

/*---------------------------------------------------------------------------*/
		/*PROTOTYPE FILE : MANIP_STRING*/
/*---------------------------------------------------------------------------*/

char *get_cmd_line(char *input, char *array_token[]);
int is_valid_cmd(char *command);

#endif
