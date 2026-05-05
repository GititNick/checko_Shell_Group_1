# Project Prompt/Outline

Project 1: Develop a program to implement a shell named ‘checko’ on a Linux system. You can get a very simple shell from http://www.shsu.edu/~csc_tjm/fall2000/cs431/shell-lab.html  and https://brennan.io/2015/01/16/write-a-shell-in-c/.Your shell should accept and execute at least 15 basic commands typed by a user. You can get a list of Linux commands from https://files.fosswire.com/2007/08/fwunixref.pdf. You must use a new word representing each command. For example, the commands may include 
a)	list to show all the files in the current directory 
b)	type filename to display the contents of a file 
c)	change to change permissions of a file or directory 
d)	archive filenames to create tar archive of a set of files 
e)	space to show directory usage 
f)	mycommands to show a list of commands implemented in the shell


# Methodology
We will first set up the development environment by installing Ubuntu, GCC, and the terminal so that we can compile and run the program. Then, we'll use a loop that keeps taking user input until the user quits to make the basic shell structure. After that, we will use functions to break up the input into commands and arguments so that we can parse. We will use system calls like fork(), execvp(), and wait() to run commands in child processes. Next, we will connect at least 15 user-defined commands to the Linux operations that go with them. We will also add error handling to deal with bad inputs and commands. Lastly, we'll test the system during development and make improvements to the program to make sure that all the necessary features work as they should. 

# Results
The custom Linux shell was successfully developed and tested in an Ubuntu VM environment. The shell can parse user input, mapping user-defined commands to their corresponding Linux commands and execute them using system calls such as fork(), execvp(), and wait(). Throughout testing, the shell consistently accepted user input and executed commands correctly without errors or unexpected behavior. 

A total of more than 15 user-defined commands were implemented. These included file and directory operations such as list, type, change, and archive, system information commands such as time, calendar, runtime, disk, and mem, and process management commands such as proccount and killproc. Each command was tested with multiple inputs, and all produced the expected results. For example, the change command successfully modified file permissions, and the archive command correctly created .tar files containing selected files. 

The shell also supports argument passing and flag usage. This is demonstrated through the “sfas” (search for a string) command, which maps to grep and allows users to search for patterns within files. The command supports flags such as -i for case-insensitive searches, and testing confirmed that it correctly returns matching lines. Additionally, the “where” command, which maps to which, successfully identifies the location of system executables. These results confirm that the shell operates as intended and meets the functional requirements of the project. 

# Conclusion

This project provided valuable insight into how a command-line shell interacts with the operating system at a low level. By implementing a custom shell, we gained hands-on experience with process creation and management using fork(), execution of programs using execvp(), and synchronization using wait(). These concepts are fundamental to understanding how modern operating systems execute and manage processes. 

One of the main challenges encountered during development was correctly parsing user input and handling command arguments. Ensuring that user-defined commands were properly mapped to valid Linux commands required careful implementation. Debugging issues related to incorrect arguments, command execution failures, and pattern matching behavior, particularly with the sfas command, also required a deeper understanding of how Linux utilities interpret input, such as the difference between regular expressions and wildcard patterns. It took extra time to test each of these functions to ensure they worked as intended, which is why many test files were included in the GitHub repository as well.  

Due to time constraints, the shell relies on existing Linux utilities rather than implementing commands from scratch. A complete shell implementation would require recreating core functionalities such as file manipulation, process control, and text processing directly in C, instead of delegating execution to external programs through execvp(). This would involve significantly greater complexity, including managing input and output streams, implementing piping between commands, and building internal versions of common utilities. 

Despite these limitations, the project successfully demonstrates key operating system concepts and provides a functional abstraction layer over standard Linux commands. Future improvements could include adding support for pipes (|), background execution (&), improved error handling, and implementing selected commands natively within the shell. Likewise, if there was no limit to how long we had to work on this project, it would have been fun to implement even more commands or even commands that don’t exist yet for ease of use. Overall, this project provided a strong foundation for understanding how shells operate internally and how they interact with the underlying operating system. 
