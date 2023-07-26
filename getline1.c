#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h> 

/* Created getline function
 * int main (void) - entry point
 * <unist.h> for read() and write()
 * 1st loop -fills buffer when empty
 * 2nd loop - reallocates memory
 * 3rd loop - line termination
  */

ssize_t custom_getline(char **line) {
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0;
    static int buffer_size = 0;

    int ch;
    ssize_t len = 0;

    if (line == NULL) {
        return -1;
    }

    *line = NULL;

    while (1) {
        if (buffer_pos == buffer_size) {
            buffer_size = read(0, buffer, BUFFER_SIZE);
            buffer_pos = 0;

            if (buffer_size = {
                return len;
            } else if (buffer_size < 0) {
                return -1;
            }
        }

        ch = buffer[buffer_pos++];
        if (ch == '\n' || ch == EOF) {
            break;
        } 
        char *temp = (char *)realloc(*line, len + 1);
        if (!temp) {
            free(*line);
            write(2, "Memory allocation failed.\n", 26);
            return -1;
        }
        *line = temp;

        (*line)[len++] = ch;
    }

    if (len > 0) {
        char *temp = (char *)realloc(*line, len + 1);
        if (!temp) {
            free(*line);
            write(2, "Memory allocation failed.\n", 26);
            return -1;
        }
        *line = temp;
    } else {
        *line = (char *)malloc(1);
    }
    (*line)[len] = '\0';

    return len;
}

int main(void) {
    char *line = NULL;
    ssize_t length;

    write(1, "Enter a line of text: ", 22);
    length = custom_getline(&line);

    if (length > 0) {
        write(1, "Line: ", 6);
        write(1, line, length);
        write(1, "\n", 1);
    } else if (length == 0) {
        write(1, "Empty line.\n", 12);
    } else {
        write(2, "Error reading input.\n", 21);
    }

    free(line);
    return 0;
}
