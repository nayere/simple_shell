#include "shell.h"

/**
 * parse_cmd - Parse Line Of Input
 * @input:User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int n, bufsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (n = 0; token; n++)
	{
		tokens[n] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[n] = NULL;

	return (tokens);
}
