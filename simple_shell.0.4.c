#include <stdio.h>
#include <stdlib.h>

/**
 * _argument - point of entry
 * @ac: commandline argument
 * Return: terminates a program
 *
 */
int _argument(int  ac)
{
        if (ac > 1)
        {
                perror("Error: This is an error message, exit\n");
                exit(1);
        }
        exit(0);
}
