#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
/*int main(void0' - point of entry
 * no argument change to home directory
 * argument is "-", change to the previous directory
 */

void update_pwd_env_variable(const char *new_path) {
    char cwd[MAX_PATH_LENGTH];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        setenv("PWD", cwd, 1);
    }
}

void cd_command(const char *directory) {
    if (directory == NULL) {
        directory = getenv("HOME");
        if (directory == NULL) {
            write(2, "cd: No $HOME environment variable set.\n", 39);
            return;
        }
    } else if (strcmp(directory, "-") == 0) {
        directory = getenv("OLDPWD");
        if (directory == NULL) {
            write(2, "cd: OLDPWD not set.\n", 20);
            return;
        }
        write(1, directory, strlen(directory));
        write(1, "\n", 1);
    }

    char current_dir[MAX_PATH_LENGTH];
    if (getcwd(current_dir, sizeof(current_dir)) == NULL) {
        perror("cd");
        return;
    }

    if (chdir(directory) != 0) {
        perror("cd");
        return;
    }

    update_pwd_env_variable(directory);
    
    setenv("OLDPWD", current_dir, 1);
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 1;
    }

    if (argc == 1) {
        cd_command(NULL);
    } else {
        cd_command(argv[1]);
    }

    return 0;
}
