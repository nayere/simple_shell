#include "shell.h"

/**
* set_env - set environment variable
* @var: name of variable
* @val: value assigned to variable
*
* Return: int
*/
int set_env(char *var, char *val)
{
if (setenv(var, val, 1) != 0)
{
fprintf(stderr, "Failure to set env variable %s\n", var);
return (1);
}
return (0);
}
/**
* unset_env - deletes env variable
* @var: variable to be deleted
*
* Return: int
*/
int unset_env(char *var)
{
if (unsetenv(var) != 0)
{
fprintf(stderr, "Failed to unset variable %s\n", var);
return (1);
}
return (0);
}
/** Authored by Job Nayere */
