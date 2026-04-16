#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"

void map_command(char *args[]) {

    if (strcmp(args[0], "list") == 0)
        args[0] = "ls";

    else if (strcmp(args[0], "type") == 0)
        args[0] = "cat";

    else if (strcmp(args[0], "space") == 0)
        args[0] = "du";

    else if (strcmp(args[0], "change") == 0)
        args[0] = "chmod";

    else if (strcmp(args[0], "archive") == 0)
        args[0] = "tar";

    else if (strcmp(args[0], "disk") == 0)
        args[0] = "df";

    else if (strcmp(args[0], "mem") == 0)
        args[0] = "free";

    else if (strcmp(args[0], "where") == 0)
        args[0] = "which";

    else if (strcmp(args[0], "proccount") == 0)
        args[0] = "ps";

    else if (strcmp(args[0], "killproc") == 0)
        args[0] = "kill";

    else if (strcmp(args[0], "name") == 0)
        args[0] = "whoami";

    else if (strcmp(args[0], "calendar") == 0)
        args[0] = "cal";

    else if (strcmp(args[0], "time") == 0)
        args[0] = "date";

    else if (strcmp(args[0], "runtime") == 0)
        args[0] = "uptime";

    else if (strcmp(args[0], "sfas") == 0) //search for a string (sfas)
        args[0] = "grep";
}

int handle_builtin(char *args[]) {

    // Change directory
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] != NULL) {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        } else {
            printf("Usage: cd <directory>\n");
        }
        return 1;
    }

    // Show available commands
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
        return 1;
    }

    return 0;
}
