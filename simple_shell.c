#include "header.h"

/**
 * simple_shell - a shell progrm to run commands similar to bash
 * runs command collected from stdin
 */

void simple_shell(void)
{
	struct stat st;
	char *command;
	char **command_t;

	while (1)
	{
		term_write("Your command:");
		command = read_line();
		command_t = parsing_arg(command);
		if (stat(command_t[0], &st) == 0)
		{
			exec_process(command_t, command);
		}
		else
		{
			char array[9] = "/bin/";

			command_t[0] = _strcat(array, command_t[0]);
			exec_process(command_t, command);
		}
		free(command_t);
		free(command);
	}
}
