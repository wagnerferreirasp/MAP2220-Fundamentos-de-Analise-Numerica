#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
    char *buf;
    char diretorio[1024];
    rl_bind_key('\t',rl_abort);//disable auto-complete
    char info[2048];
    char comando[1024];
    char args[][1024];
    int arg_c = 0;

    getcwd(diretorio, sizeof(diretorio));
    sprintf(info, "[%s] ", diretorio);
    buf = readline(info);

    if (buf != NULL) {
        //sscanf(buf, "$s", comando);
        comando = strtok(buf," "); /// VERIFICAR ISSO!! (se o usuario mandar só o comando?)
        while (buf != NULL) {
            args[arg_c++] = buf;
            buf = strtok(NULL, " ");
        }
    }
    while(buf != NULL)
    {
        if (strcmp(comando,"quit") == 0)
            break;
        if (strcmp(comando,"pwd") == 0) {
            /*Spawn a child to run the program.*/
            pid_t pid = fork();
            if (pid==0) { /* child process */
                static char *argv[] = {"/bin/pwd"};
                execv("/bin/pwd", argv);
                exit(127); /* only if execv fails */
            }
            else { /* pid!=0; parent process */
                waitpid(pid,0,0); /* wait for child to exit */
            }
        }
        if (strcmp(comando,"cd") == 0) {
            /*Spawn a child to run the program.*/
            pid_t pid = fork();
            if (pid==0) { /* child process */
                static char *argv[] = {"/bin/pwd"};
                execv("/bin/pwd", argv);
                exit(127); /* only if execv fails */
            }
            else { /* pid!=0; parent process */
                waitpid(pid,0,0); /* wait for child to exit */
            }
        }

        printf("Você digitou o comando %s\n",comando);

        if (buf[0]!=0)
            add_history(buf);
        getcwd(diretorio, sizeof(diretorio));
        sprintf(info, "[%s] ", diretorio);
        buf = readline(info);
    }

    free(buf);


    return 0;
}


/*
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="cd abc";
  char * pch;
  char * pch2;
  //printf ("cd abc",str);
  pch = strtok(str," ");
  printf ("%s\n",pch);
  if (pch != NULL) {
    pch2 = strtok(NULL, " ");
    printf ("%s %s\n%s\n",pch, pch2, str);
  }

  return 0;
}
*/
