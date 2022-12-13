#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
/* Prototype punctions */
char ** split_line(char *line);
char ** get_path(void);
char ** paste_command(char ** tokens);
void exe(char ** buftok);
char * _getenv(char * envi);
extern char ** environ;
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int free_grid(char **grid);
void *_calloc(unsigned int nmemb, unsigned int size);
#endif
