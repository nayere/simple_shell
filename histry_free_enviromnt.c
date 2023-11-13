#include "shell.h"
/**
 * history - Fill using input
 * @input: User Input
 *
 * Return: int
 */
int history(char *input)
{
	char *file = ".shell_history";
	ssize_t ff;
	ssize_t w;
	int len = 0;

	if (!file)
		return (-1);

	ff = open(file, O_CREAT | O_RDWR | O_APPEND, 00600);

	if (ff < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(ff, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_env - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
