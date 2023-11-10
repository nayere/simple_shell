#include "shell.h"

/** Authored by Job Nayere */

/**
**_realloc -  Reallocates A Memory Block Using Malloc And Free
*@ptr: Pointer
*@old_size: Previous Size Of The Pointer
*@new_size: New Size Of The Pointer
*Return: Void Pointer Rellocated Memory
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *res;

if (new_size == old_size)
return (ptr);
if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}
res = malloc(new_size);
if (res == NULL)
return (NULL);
if (ptr == NULL)
{
fill_an_array(res, '\0', new_size);
free(ptr);
}
else
{
_memcpy(res, ptr, old_size);
free(ptr);
}
return (res);

}
/**
* free_all - Free Array Of Char Pointer And Char Pointer
* @input:Array Pointer
* @line:Char Pointer
* Return: Void
*/
void free_all(char **input, char *line)
{
	free(input);
	free(line);
	line = NULL;
	input = NULL;
}

/**
* _memcpy - Copy Byte From Source To Destination
* @dest: Destination Pointer
* @src: Source Pointer
* @n: Size (How Much You Will Copy)
*Return: Void Pointer
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
dest[i] = src[i];
}
return (dest);
}
/**
* fill_an_array - Fill An Array By Constant Byte
* @a:Void Pointer
* @n: Int
* @len:Length Int
*Return: Void Pointer
*/
void *fill_an_array(void *a, int n, unsigned int len)
{
char *p = a;
unsigned int i = 0;

while (i < len)
{
*p = n;
p++;
i++;
}
return (a);
}
/**
* _calloc -  Allocates Memory For An Array, Using Malloc.
* @size: Size
* Return: Void Pointer
*/
void *_calloc(unsigned int size)
{
char *c;
unsigned int i;

if (size == 0)
return (NULL);
c = malloc(size);
if (c == NULL)
return (NULL);
for (i = 0; i < size; i++)
{
c[i] = '\0';
}
return (c);
}
