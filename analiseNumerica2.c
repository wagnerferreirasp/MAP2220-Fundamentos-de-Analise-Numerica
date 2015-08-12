#include <stdio.h>
#include <stdlib.h>

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

        printf("Você digitou o comando %s\n",buf);

        if (buf[0]!=0)
            add_history(buf);
        getcwd(diretorio, sizeof(diretorio));
        sprintf(info, "[%s] ", diretorio);
    }

    free(buf);

    return 0;
}
