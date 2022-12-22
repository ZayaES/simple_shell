#include "header.h"

/**
 * simple_shell - a shell progrm to run commands similar to bash
 * runs command collected from stdin
 */

void simple_shell(void)
{
	struct stat st;
	char *command = NULL;
	char **command_t = NULL;

	while (1)
	{
		term_write("($) ");
		command = read_line();
		command_t = parsing_arg(command);
		if (stat(command_t[0], &st) == 0)
			exec_process(command_t, command);
		else
		{
			eval_com(command_t, command);
		}
		free(command_t);
		free(command);
	}
}

/**
 * eval_com - evaluates command if path not specified
 * @f_com: command_t
 * @i_com: command
 * Return: void
 */

void eval_com(char **f_com, char *i_com)
{
	struct stat st;
	int i, j;
	char **path;
	char *cmcp = f_com[0];
	char *path_cp = malloc(25 * sizeof(char));

	path = malloc(6 * sizeof(*path));

	for (j = 0; j < 3; j++)
		path[j] = malloc(20 * sizeof(*path[j]));

	path[0] = "/usr/local/sbin/";
	path[1] = "/usr/local/bin/";
	path[2] = "/usr/sbin/";
	path[3] = "/usr/bin/";
	i = 0;
	while (path[i] != NULL)
	{
		strcpy(path_cp, path[i]);
		f_com[0] = strcat(path_cp, f_com[0]);
		if (stat(f_com[0], &st) == 0)
		{
			exec_process(f_com, i_com);
		break;
		}
		i++;
		f_com[0] = cmcp;
	}
		if (i > 3)
			exec_process(f_com, i_com);
	free(path);
	free(path_cp);
}
