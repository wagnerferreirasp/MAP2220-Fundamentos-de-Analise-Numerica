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

    getcwd(diretorio, sizeof(diretorio));
    sprintf(info, "[%s] ", diretorio);
    while((buf = readline(info))!=NULL)
    {
        if (strcmp(buf,"quit")==0)
            break;
        if (strcmp(buf,"pwd")==0) {
            /*Spawn a child to run the program.*/
            pid_t pid = fork();
            if (pid==0) { /* child process */
                execv("/bin/pwd",NULL);
                exit(127); /* only if execv fails */
            }
            else { /* pid!=0; parent process */
                waitpid(pid,0,0); /* wait for child to exit */
            }
        }

        printf("Você digitou o comando %s\n",buf);

        if (buf[0]!=0)
            add_history(buf);
        getcwd(diretorio, sizeof(diretorio));
        sprintf(info, "[%s] ", diretorio);
    }

    free(buf);


    return 0;
}
