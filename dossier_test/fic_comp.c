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
			break;
		}
		i++;
	}
	return (i);
}
