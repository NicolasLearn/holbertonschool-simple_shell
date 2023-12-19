#include "main.h"

/*---------------------------------------------------------------------------*/
		/*GET_CMD_LINE*/
/*---------------------------------------------------------------------------*/

/**
 * get_cmd_line - Creating token of each word from the input,
 * and return first token (command).
 *
 * @input: Pointer to the not NULL string got with getline().
 * @array_token: Adress of array of string wich will contain at each index
 * each token create from of the input.
 *
 * Return: pointer to the command (first argument). Or NULL if failed.
*/
char *get_cmd_line(char *input, char *array_token[])
{
	int index = 0;
	char *token = NULL, *command = NULL;
	const char *delim = " \t\n\r";

	token = strtok(input, "\n");
	token = strtok(token, delim);
	command = token;
	while (token != NULL)
	{
		array_token[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	array_token[index] = NULL;
	return (command);
}

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
int is_shell_cmd(char *command, char *input)
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

/*---------------------------------------------------------------------------*/
		/*IS_VALID_CMD*/
/*---------------------------------------------------------------------------*/

/**
 * is_valid_cmd - Check if command is a file executable in PATH variable
 * get from the environment.
 *
 * @command: Pointer to the string to be checked.
 *
 * Return: Pointer to the string of matched PATH. Or NULL if not.
 *
 * Description: The variable "match_path", was got with malloc().
 * Don't forget : free(match_path)!
*/
char *is_valid_cmd(char *command)
{
	char *PATH = NULL, *token = NULL, *match_path = NULL;
	char *array_token_path[128];
	int index = 0;

	PATH = get_PATH();
	if (PATH != NULL)
	{
		token = strtok(PATH, ":");
		while (token != NULL)
		{
			array_token_path[index] = token;
			token = strtok(NULL, ":");
			index++;
		}
		array_token_path[index] = NULL;
		for (index = 0; array_token_path[index]; index++)
		{
			match_path = is_here(array_token_path[index], command);
			if (match_path != NULL)
				break;
		}
	}
	free(PATH);
	PATH = NULL;
	return (match_path);
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
		perror("error:");
		return;
	}
	else if (child_pid == 0)
	{
		execve(path, arr_tok, environ);
		exit(EXIT_SUCCESS);
	}
	else
		wait(&wait_status);
}
