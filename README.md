<h1> C - SIMPLE SHELL PROJECT </h1>

## DESCRIPTION
This is our end of trimester project, in wich we have to develop a simple shell, using C language.
A Shell is a program that takes commands from the keyboard and gives them to the operating system to perform.
### Holberton School Uruguay


### How to Install
To use our shell you must use the following command
```
git clone https://github.com/Washx23/holbertonschool-simple_shell
```
## COMPILATION
Our shell will be compiled this way:

        $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## COMMANDS
`./hsh` --> Run the shell
`exit`--> Close the shell

## GUIDE OF FILES & FUNCTIONS
`shell.c` --> The main code of our shell
`main.c` --> The header file, include libraries and functions used
`stdfunctions.c` --> Standard functions
`functions.c` --> Functions created along the process

## TESTING
Our shell should work like this in interactive mode:

        $ ./hsh
        ($) /bin/ls
        hsh main.c shell.c
        ($)
        ($) exit
        $

But also in non-interactive mode:

        $ echo "/bin/ls" | ./hsh
        hsh main.c shell.c test_ls_2
        $
        $ cat test_ls_2
        /bin/ls
        /bin/ls
        $
        $ cat test_ls_2 | ./hsh
        hsh main.c shell.c test_ls_2
        hsh main.c shell.c test_ls_2
        $
