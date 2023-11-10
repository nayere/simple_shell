#include "shell.h"

/** Authored By Job Nayere */

/**
 * history_dis - Display History Of User Input Simple Shell
 * @c:Parsed Command
 * @s:Statue Of Last Excute
 * Return: 0 Succes -1 Fail
 */
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".shell_history";
	FILE *ff;
	char *line = NULL;
	size_t len = 0;
	int n = 0;
	char *ch;

	ff = fopen(filename, "r");
	if (ff == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, ff)) != -1)
	{
		n++;
		ch = _itoa(n);
		PRINTER(ch);
		free(ch);
		PRINTER(" ");
		PRINTER(line);

	}
	if (line)
		free(line);
	fclose(ff);
	return (0);
}
/**
 * print_echo - Excute Normal Echo
 * @input: Parsed Command
 * Return: int
 */
int print_echo(char **input)
{
	int status;
	pid_t mypid;

	mypid = fork();
	if (mypid == 0)
	{
	if (execve("/bin/echo", input, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (mypid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(mypid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
