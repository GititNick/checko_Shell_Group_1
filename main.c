#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "commands.h"

#define MAX_INPUT 1024

void parse_input(char *input, char *args[]) {
    int i = 0;
    args[i] = strtok(input, " \n");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \n");
    }
}

int main() {
    char input[MAX_INPUT];
    char *args[100];

    while (1) {
        printf("checko> ");
        fgets(input, MAX_INPUT, stdin);

        if (strcmp(input, "exit\n") == 0)
            break;

        parse_input(input, args);

        // -------- THIS IS THE IMPORTANT PART --------
        if (args[0] == NULL) continue;

        if (handle_builtin(args)) continue;

        map_command(args);
        // ------------------------------------------

        pid_t pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("Error");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
