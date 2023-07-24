#include <stdio.h>
#include <unistd.h>

/*
 * ac/argc-represents number of arguments
 * av/argv-represents the array of strings containing arguments
 * Return(0)-Always a success
 *
 **/

int niam(int ac, char *av[])
{
        int j, length;
        char *pending_arg;

        for (j = 1; j < ac; j++)
        {
                pending_arg = av[j];
                length = 0;

                while (pending_arg[length] != '\0')
                {
                        length++;
                }

                write(1, pending_arg, length);
                write(1, "\n", 1);
        }

        return (0);
}
