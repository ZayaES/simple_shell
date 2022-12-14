#include "header.h"

/**
 * exec_process - execution of process
 * @path: argument tokenized
 * @line: argument without tokenize
 * Return: void
 */
void exec_process(char **path, char *line)
{
	pid_t pid = 0;
	int status = 0;
	int ver_exe;

	pid = fork();
	if (pid == 0)
	{
		ver_exe = execve(path[0], path, NULL);
		if (ver_exe == -1)
			perror("hsh");
	}
	else if (pid < 0)
	{
		free(line);
		perror("hsh");
	}
	else
		wait(&status);
}

/**
 * parsing_arg - tokenize and analize the argument
 *
 * @line: argument without tokenize
 *
 * Return: char double pointer of the token
 */
char **parsing_arg(char *line)
{
	int bufsize = BUFSIZE;
	int pos = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	token = NULL;
	if (!tokens)
	{
		free(tokens);
	}
	token = strtok(line, "  \n");
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		if (pos >=  bufsize)
		{
			if (!tokens)
			{
				free(tokens);
			}
		}
		token = strtok(NULL, " \n");
	}
	tokens[pos] = NULL;
	return (tokens);
}

/**
 * read_line - print the line
 *
 * Return: pointer of type char in the input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters = 0;

	characters = getline(&line, &bufsize, stdin);

	if (characters == -1)
	{
		perror("hsh");
		free(line);
		exit(-1);
	}
	return (line);
}

/**
 * term_write - writes to terminal
 * @out: string to print to terminal
 * Return: No of chars printed
 */

int term_write(char *out)
{
	int count;

	count = write(1, out, strlen(out));
	if (count < 0)
	{
		perror("hsh");
	}
	return (count);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (pair_ptr = *my_environ, name_cpy = name;
		     *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);

}
