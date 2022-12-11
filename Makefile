CC= gcc	#compiler
VAL= valgrind
RM=rm -f	#remove files
SRC= *.c	#files to be compiled
NAME= hsh	#executable name
VALFULL= --leak-check=full
VALALL= --show-leak-kinds=all
VALLYES= --track-origins=yes
CFLAGS= -Wall -Werror -Wextra -pedantic -std=gnu89 	#compiler flags
compil:	#compilation
	$(CC) $(CFLAGS) $(SRC) -g -o $(NAME)
clean:	#delete the executable file
	$(RM) $(NAME)
run: $(NAME)	#run the executable
	./$(NAME)
full: $(NAME)
	$(VAL) $(VALFULL) -s ./$(NAME)
all: $(NAME)
	$(VAL) $(VALALL) $(VALFULL) $(VALLYES) -s ./$(NAME)
re: clean all	#recompile
mem1: compil all
mem2: compil full
