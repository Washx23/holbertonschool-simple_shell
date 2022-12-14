<h1> C - SIMPLE SHELL PROJECT </h1>

## DESCRIPTION
This is our end of trimester project, in wich we have to develop a simple shell, using C language.
A Shell is a program that takes commands from the keyboard and gives them to the operating system to perform.
### Holberton School Uruguay


<summary><h3> HOW TO INSTALL </summary></h3>
To use our shell you must use the following command
```
git clone https://github.com/Washx23/holbertonschool-simple_shell
```
<summary><h3> COMPILATION </summary></h3>
Our shell will be compiled this way:

        $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

<summary><h3> COMMANDS </summary></h3>
`./hsh` --> Run the shell
`exit`--> Close the shell

<summary><h3> GUIDE OF FILES & FUNCTIONS </summary></h3>

`shell.c` --> The main code of our shell

`main.c` --> The header file, include libraries and functions used

`stdfunctions.c` --> Standard functions

`functions.c` --> Functions created along the process

<summary><h3> TESTING </summary></h3>
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
<h3> FLOWCHAR</h3>
<img src="https://user-images.githubusercontent.com/113697466/207481006-99d4de81-23e5-471c-a67c-13f6c409594c.png">


<summary><h3> HELP </summary></h3>

It can be difficult to know how to approach a project. You’ve read resources and tried some examples, and now it’s time to apply what you know. Where do you start? The following framework can help you focus how you approach a project.

Read the steps below and think about how you would follow them for a task.

1. Read the task or challenge.
2. Rephrase it in your own words.
3. Verify expected behavior by getting example inputs and outputs.
4. Whiteboard your solution with words.
5. Walk through your solution with an example as if you were a machine. Do only what is written down. Correct your solution if needed.
6. Whiteboard your solution with pseudocode.
7. Walk through your solution with an example as if you were a machine. Do only what is written down. Correct your solution if needed.
8. Whiteboard your solution with code.
9. Walk through your solution with an example as if you were a machine. Do only what is written down. Correct your solution if needed.
10. Write your code on your computer. [Note: This is this first time you are using your computer! Only when you know exactly what to code.]
11. Test your code on your computer.
12. Debug if necessary.
13.You complete the task or challenge!
