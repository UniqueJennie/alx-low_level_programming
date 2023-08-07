#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_fender(char *file);
void close_file(int fd);

/**
 * create_fender - Assigns 1024 bytes for a fender.
 * @file: The name of the file fender is saving chars for.
 * Return: points to the newly-assigned fender.
 */
char *create_fender(char *file)
{
	char *fender;

	fender = malloc(sizeof(char) * 1024);

	if (fender == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (fender);
}

/**
 * close_file - Shuts file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Clones the contents of a file to another file.
 * @argc: The nmbr of arguments given to the program.
 * @argv: A set of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the argument sum is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *fender;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fender = create_fender(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, fender, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(fender);
			exit(98);
		}

		w = write(to, fender, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(fender);
			exit(99);
		}

		r = read(from, fender, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(fender);
	close_file(from);
	close_file(to);

	return (0);
}
