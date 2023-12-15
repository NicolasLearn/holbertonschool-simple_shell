#include "main.h"

/*---------------------------------------------------------------------------*/
		/*GET_CMD_LINE*/
/*---------------------------------------------------------------------------*/

char *get_cmd_line(char *input, char *array_token[])
{
	int i = 0;
	char *token, *command_buf = NULL;
	const char *delim = " \t\n\r";

	token = strtok(input, "\n");
	token = strtok(token, delim);
	command_buf = token;
	while (token != NULL)
	{
		array_token[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	array_token[i] = NULL;
	return (command_buf);
}

/*---------------------------------------------------------------------------*/
		/*GET_CMD_LINE*/
/*---------------------------------------------------------------------------*/

int is_valid_cmd(char *command)
{

}
