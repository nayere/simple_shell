#include "shell.h"

/* By Nayere Job */

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @count:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int count, char **argv)
{
	char *ch;

	PRINTER(argv[0]);
	PRINTER(": ");
	ch = _itoa(count);
	PRINTER(ch);
	free(ch);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": input not found\n");
}
