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
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (((getline(&src_input, &size_buff_input, stdin)) <= 0) || (src_input == NULL))
		{
			free(src_input);
			src_input = NULL;
			exit(EXIT_FAILURE);
		}
		printf("src before = %s", src_input);
		printf("----------------------\n");
		command = get_cmd_line(src_input, array_token);
		printf("src after = [%s]\ncommand : [%s]\n", src_input, command);
		printf("----------------------\n");
		for (i = 0; array_token[i]; i++)
			printf("[%d][%s]\n", i, array_token[i]);
		printf("----------------------\n");
		if (command == NULL)
		{
			free(src_input);
			src_input = NULL;
			exit(EXIT_FAILURE);
		}
		if ((is_shell_cmd(command)) == 0)
		{
			match_PATH = is_valid_cmd(command);
			if(match_PATH != NULL)
			{
				printf("Trouvé : [%s]\n", match_PATH);
				free(match_PATH);
				match_PATH = NULL;
			}
			else
				printf("Pas Trouvé [%s]\n", command);
		}
		printf("---------------------------------------------------------\n");
		printf("---------------------------------------------------------\n");
		i = 0;
		free(src_input);
		src_input = NULL;
	}
	return (0);
}
