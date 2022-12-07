#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
// ----- Declaración de funciones para ejecutar en la consola -----------
int funcion_clear(char **args);
int funcion_cd(char **args); 
int funcion_help(char **args);
int funcion_exit(char **args);
int funcion_ls(char **args);
int funcion_pause(char **args);
int funcion_echo(char **args);
int vexec(char **args, char **enve);

// ----- Declaración de array llamado de funcion-----------
char *array_str[] = {
  "clr",
  "cd",
  "help",
  "ls",
  "echo",
  "pause",
  "quit"
 
};
// ----- Declaración de array info----------
char *array_info[] = {
    "cd nos permite entrar a un directorio <cd parametro>",
    "exit nos finaliza la ejecución del porgrama <exit>",
    "clear nos permite limpiar la consola <clr>",
    "ls nos permite listar lo que hay en el directorio <dir>",
    "nos permite dar enter con <pause>",
    "echo nos permite hacer un echo <echo parametro>"
  };
// ----- Declaración de array de funciones-----------
int (*array_funciones[]) (char **) = {
  &funcion_clear,
  &funcion_cd,
  &funcion_help,
  &funcion_ls,
  &funcion_echo,
  &funcion_pause,
  &funcion_exit
 
};

int longitud_array_bit() {
  return sizeof(array_str) / sizeof(char *);
}

/**
 * Nos permite verificar si el argumento que entra es un directorio existente 
 * también si no envía ningun argumento lo solicitamos
 */
int funcion_cd(char **args)
{
  //preguntamos si el argumento es diferente de null o vacio
  if (args[1] != NULL && args[1] != "") {
    if (chdir(args[1]) != 0){ 
      printf("error: el directorio <%s> no existe \n",args[1]);   
    }
  } else {
      printf("especifica un argumento \"cd\"\n");
  }
  system("pwd");
  return 1;
}

/**
 * funcion de manual nos enseña los diferentes operaciones que podemos hacer en la consola
 */
int funcion_help(char **args)
{
  printf("Bienvenido a la shell personal\ntenemos los diferentes comandos:\n");
  int i;
  for (i = 0; i < longitud_array_bit()-1; i++) {
    printf("  %s\n", array_info[i]);
  }
  return 1;
}

/**
 * Funcion que nos permite salir de la consola
 */
int funcion_exit(char **args)
{
  return 0;
}

/**
 * Función para limpiar la consola
 */
 int funcion_clear(char **args)
{
  if(args[1] == "clear"){
    printf("Quieres decir clr");
  }else{
    system("clear");
  }
  return 1;
} 
/**
 * Función listar el directorio
 */
int funcion_ls(char **args)
{
  system("ls");
  return 1;
} 
/**
 * Función comentario
 */
int funcion_echo(char **args)
{
  if (args[1] == NULL || args[1] == "") {
     printf("especifica un argumento\n");
  }else{
      printf("%s\n",args[1]);
  }
  return 1;
} 

/**
 * Función pause
 */
int funcion_pause(char **args)
{
  system("exit");
  return 1;
} 

 
 

/**
 * Nos permite iniciar un programa y esperar que termine 
 */
/*int hilos_programa(char **args)
{
  //Declaramos el PID y su estado
  pid_t pid;
  int estado;
  //iniciamos el fork
  pid = fork(); 
  if (pid < 0) { 
    printf("error \n");
  } else if (pid == 0) {
    if (execvp(args[0], args) == -1) printf("error comando no existe\n");
    exit(EXIT_FAILURE);
  } else {
    //proceso ejecutando
    do {
      waitpid(pid, &estado, WUNTRACED);
    } while (!WIFEXITED(estado) && !WIFSIGNALED(estado));
  }
  return 1;
}/*


/**
 *vexec - function to create child process and execute correspondent
 *command
 *@args: double pointer pointing to string of arguments
 *@enve: enviroment inherited from parent process to use with execve
 *Return: exit status from child process
 */
int vexec(char **args, char **enve)
{
        pid_t pid;
        int status = 0;

        pid = fork();

        if (pid == -1)
        {
                perror("Error");
                return (1);
        }
        if (pid == 0)
        {

                if (execve(args[0], args, enve) == -1)
                {
                        perror("Error");
                }
                free(args);
        }
        wait(&status);
        if (WIFEXITED(status))
        {
                free(args);
                return (WEXITSTATUS(status));
        }
        free(args);
        return (0);
}

/**
 *  Verificamos si los comandos son iguales a los que tenemos si es así corralo
 */
int comando(char **args)
{
  int i;
  if (args[0] == NULL) return 1;
  for (i = 0; i < longitud_array_bit(); i++) {
    if (strcmp(args[0], array_str[i]) == 0) {
      return (*array_funciones[i])(args);
    }
  }
  /*return hilos_programa(args);*/
}


/**
 * se lee la linea de comando
 */
char *lectura(void)
{
  int bufsize = BUFSIZE;
  int posicion = 0;
  int var;
  char *buffer = malloc(sizeof(char) * bufsize);
  if (!buffer) {
    printf("error\n");
    exit(EXIT_FAILURE); 
  }
  while (1) {
    var = getchar(); //cadena de caracteres
    if (var == '\n') {
      buffer[posicion] = '\0';
      return buffer;
    }else if (var == EOF) {
      exit(EXIT_SUCCESS);
    } else {
      buffer[posicion] = var;
    }
    posicion++;
    if (posicion >= bufsize) {
      bufsize += BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        printf("error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


/**
 * Separa la cadena de comando en un programa y argumentos.
 */
char **split_linea(char *line)
{
  int bufsize = TOK_BUFSIZE, posicion = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;
  if (!tokens) {
    printf("error\n");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, TOK_DELIM);
  while (token != NULL) {
    tokens[posicion] = token;
    posicion++;
    if (posicion >= bufsize) {
      bufsize += TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        printf("error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, TOK_DELIM);
  }
  tokens[posicion] = NULL;
  return tokens;
}

int main(int argc, char **argv)
{

    char *linea;
    char **args;
    int estado;
    do {
	printf("$") ;   
      if(argv[1] != NULL){
        linea = argv[1];
      }else{
        linea = lectura();
      }
      args = split_linea(linea);
      estado = comando(args);
      free(linea);
      free(args);
    } while (estado);
    return EXIT_SUCCESS;
 
}
