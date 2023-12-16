#include "main.h"

/*---------------------------------------------------------------------------*/
		/*GET_CMD_LINE*/
/*---------------------------------------------------------------------------*/

char *get_cmd_line(char *input, char *array_token[])
{
	int index = 0;
	char *token = NULL, *command = NULL;
	const char *delim = " \t\n\r";

	token = strtok(input, "\n");
	printf("valeur premier token : [%s]\n", token);
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

int is_shell_cmd(char *command)
{
	shell_cmd array_cmd_shell[] = {
		{"env", NULL},
		{"exit", NULL},
		{"-1", NULL},
		{NULL, NULL}
	};
	int i = 0;

	while (array_cmd_shell[i].command != NULL)
	{
		if (strcmp(command, array_cmd_shell[i].command) == 0)
		{
			printf("Trouvé : %s\n", array_cmd_shell[i].command);
			printf("----------------------\n");
			break;
		}
		i++;
	}
	return (0);
}

/*---------------------------------------------------------------------------*/
		/*IS_VALID_CMD*/
/*---------------------------------------------------------------------------*/

char *is_valid_cmd(char *command)
{
	char *PATH = NULL, *token = NULL, *match_path = NULL;
	char *array_token_path[128];
	int index = 0;

	PATH = get_PATH();
	printf("PATH : [%s]\n", PATH);
	printf("----------------------\n");
	if (PATH != NULL)
	{
		token = strtok(PATH, ":");
		while (token != NULL)
		{
			array_token_path[index] = token;
			token = strtok(NULL, ":");
			printf("array_path[%d] : [%s]\n", index, array_token_path[index]);
			index++;
		}
		printf("----------------------\n");
		printf("command : [%s]\n", command);
		printf("----------------------\n");
		array_token_path[index] = NULL;
		for (index = 0; array_token_path[index]; index++)
		{
			match_path = is_here(array_token_path[index], command);
			if (match_path != NULL)
			{
				printf("match : [%s]\n", match_path);
				break;
			}
			free(match_path);
			match_path = NULL;
		}
	}
	free(PATH);
	PATH = NULL;
	return (match_path);
}

/*---------------------------------------------------------------------------*/
		/*GET_PATH*/
/*---------------------------------------------------------------------------*/

/**
 * get_PATH - get PATH from the environment
 *
 * Return: pointer to the string PATH or NULL on failure
 */
char *get_PATH(void)
{
	int index = 0;
	char *PATH = NULL;

	while (environ[index] != NULL)
	{
		if (strncmp(environ[index], "PATH", 4) == 0)
		{
			PATH = strdup(&environ[index][5]);
			break;
		}
		index++;
	}
	return (PATH);
}

/*---------------------------------------------------------------------------*/
		/*IS_HERE*/
/*---------------------------------------------------------------------------*/

/**
 *
*/
char *is_here(char *path, char *exec)
{
	size_t len_path = 0, len_exec = 0;
	char *try_path = NULL;

	len_path = strlen(path);
	len_exec = strlen(exec);
	try_path = malloc((sizeof(char) * (len_path + len_exec)) + 1);
	if (try_path != NULL)
	{
		strcpy(try_path, path);
		try_path[len_path] = '/';
		strcat(try_path, exec);
		if ((access(try_path, X_OK)) != 0)
			try_path = NULL;
	}
	return (try_path);
}
