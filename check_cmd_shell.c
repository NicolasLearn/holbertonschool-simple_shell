#include "main.h"

/*---------------------------------------------------------------------------*/
		/*IS_SHELL_CMD*/
/*---------------------------------------------------------------------------*/

/**
 * is_shell_cmd - Check to know if command is a shell command.
 * If success, call the function matched at the command.
 *
 * @command: Pointer to the string to be checked.
 * @input: Pointer to src_input. Necessary for exit.
 *
 * Return: 1 if command exist. 0 if not.
*/
int is_shell_cmd(char *command, char **input)
{
	shell_cmd array_cmd_shell[] = {
		{"env", shell_env},
		{"exit", shell_exit},
		{NULL, NULL}
	};
	int i = 0, is_check = 0;

	while (array_cmd_shell[i].command != NULL)
	{
		if (strcmp(command, array_cmd_shell[i].command) == 0)
		{
			array_cmd_shell[i].func(input);
			is_check = 1;
			break;
		}
		i++;
	}
	return (is_check);
}

/*-----------------------------------------------------------------*/
			/*SHELL_ENV*/
/*-----------------------------------------------------------------*/

/**
 * shell_env - Print the variable environ.
 * @input: Argument unused.
*/
void shell_env(__attribute__((unused)) char **input)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}

/*-----------------------------------------------------------------*/
			/*SHELL_EXIT*/
/*-----------------------------------------------------------------*/

/**
 * shell_exit - Exits the function properly.
 * @input: Command got with dynamic memory allocation (getline), must free.
*/
void shell_exit(char **input)
{
	free_elem(input);
	exit(EXIT_SUCCESS);
}

/*---------------------------------------------------------------------------*/
		/*EXEC_COMMAND*/
/*---------------------------------------------------------------------------*/

/**
 * exec_command - Create child processus, and exec command in this process.
 *
 * @path: Pointer to the string with the good PATH.
 * @arr_tok: Array of string, wich contain the input in form of token.
*/
void exec_command(char *path, char *arr_tok[])
{
	pid_t child_pid;
	int wait_status;

	child_pid = fork();
	if (child_pid == -1)
	{
		fprintf(stderr, "Problem fork().\nERR %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(path, arr_tok, environ);
		fprintf(stderr, "Problem execve().\nERR %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
		wait(&wait_status);
}

/*---------------------------------------------------------------------------*/
		/*FREE_ELEM*/
/*---------------------------------------------------------------------------*/

/**
 * free_elem - free element given in paramater.
 * @elem: pointer to the element to be free.
*/
void free_elem(char **elem)
{
	free(*elem);
	*elem = NULL;
}
