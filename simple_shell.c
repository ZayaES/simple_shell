#include "header.h"

/**
 * simple_shell - runs command collected from stdin
 *
 * Return: void
 */

void simple_shell(void)
{
	char *command;
	char **command_t;

	while (1)
	{
		term_write("Your command:");
		command = read_line();
		command_t = parsing_arg(command);
		exec_process(command_t, command);
	}
}
