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
	char *command = NULL, *src_input = NULL, *match_PATH = NULL;
	size_t size_buff_input = 0;
	char *array_token[128];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (((getline(&src_input, &size_buff_input, stdin)) <= 0)
		|| (src_input == NULL))
		{
			free(src_input);
			src_input = NULL;
			exit(EXIT_FAILURE);
		}
		command = get_cmd_line(src_input, array_token);
		if (command == NULL)
		{
			free(src_input);
			src_input = NULL;
			exit(EXIT_FAILURE);
		}
		if ((is_shell_cmd(command, src_input)) == 0)
		{
			match_PATH = is_valid_cmd(command);
			if(match_PATH != NULL)
			{
				/*fonction exec*/
				free(match_PATH);
				match_PATH = NULL;
			}
			else
				printf("error\n");
		}
		free(src_input);
		command = src_input = NULL;
	}
	return (0);
}
