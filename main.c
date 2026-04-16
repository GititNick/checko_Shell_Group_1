#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "commands.h"

#define INPUT_SIZE 1024
#define MAX_ARGS 100

int main() {
    char input[INPUT_SIZE];
    char *args[MAX_ARGS];
    char cwd[PATH_MAX];

    while (1) {
        printf("checko> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue;
        }

        int i = 0;
        char *token = strtok(input, " ");
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        if (strcmp(args[0], "mycommands") == 0) {
            printf("Available commands:\n\n");
            printf("list -> ls\n");
            printf("type -> cat\n");
            printf("space -> du\n");
            printf("change -> chmod\n");
            printf("archive -> tar\n");
            printf("disk -> df\n");
            printf("mem -> free\n");
            printf("where -> which\n");
            printf("proccount -> ps\n");
            printf("killproc -> kill\n");
            printf("name -> whoami\n");
            printf("calendar -> cal\n");
            printf("time -> date\n");
            printf("runtime -> uptime\n");
            printf("sfas -> grep\n");
            printf("mycommands -> show this list\n\n");
            printf("builtin commands:\n\n");
            printf("cd -> change directory\n");
            printf("exit -> exit shell\n");
            continue;
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                printf("cd: missing argument\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("cd");
                } else {
                    if (getcwd(cwd, sizeof(cwd)) != NULL) {
                        printf("%s\n", cwd);
                    }
                }
            }
            continue;
        }

        if (strcmp(args[0], "./checko") == 0 || strcmp(args[0], "checko") == 0) {
            printf("Cannot launch checko from inside checko\n");
            continue;
        }

        map_command(args);

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("Error");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
