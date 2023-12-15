#include "main.h"

/*---------------------------------------------------------------------------*/
		/*MAIN*/
/*---------------------------------------------------------------------------*/

/**
 * main - Entry point.
 *
 * Return: always 0.
*/
int main(void)
{
	char *command = NULL, *input = NULL, *match_PATH = NULL;
	size_t size_buff_input = 0;
	char *array_token[128];
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (((getline(&input, &size_buff_input, stdin)) == -1) || (input == NULL))
		{
			free(input);
			input = NULL;
			exit(EXIT_FAILURE);
		}
		command = get_cmd_line(input, array_token);
		if (command == NULL)
		{
			free(input);
			input = NULL;
			exit(EXIT_FAILURE);
		}
		if ((is_shell_cmd(command)) == 0)
		{
			match_PATH = is_valid_cmd(command);
			if(match_PATH != NULL)
				/*fonction exec*/;
			else
				/*error message*/;
		}
		free(input);
		input = NULL;
	}
	return (0);
}
