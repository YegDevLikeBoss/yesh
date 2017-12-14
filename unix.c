#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.0.2.1412 alpha"
#define V "UNIX "

#define LIM 1000


#define OS "UNIX"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void init_loop();
void yesh_arrio();
int builtin();

int yesh_UNIX_appstart(/*char **args*/);
int k=1;

/*char **com = malloc(50 * sizeof(char*));*/

char *os;

const char ver[]=VERSION, space[2]=" ", usr_nam[]="user";
char /*usr_nam[20]="user",*/ line[LIM], *tocken, /*args,*/ *usr;

char *command, *arg0, *arg1, *arg2, *arg3, *arg4;

/*builtins*/
/*void yesh_chusr()
{
    usr=arg0;
}*/

/*int lsh_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {

    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {

    perror("lsh");
  } else {

    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}*/

int main(int argc, char *argv[])
{
    os=OS;
    printf("Yesh <version %s> for %s\nCopyright (C) Artyom Yeghoyan\n\n", ver, os);
    init_loop();
    return 1;
}

void init_loop()
{
    while (k)
    {
        printf("\t%s > > ", usr_nam);
        yesh_arrio();
        if (command==NULL)
            continue;
        if (!builtin())
            printf("%s is not recognized as internal or external command\n", command);
    }
}
void yesh_arrio()
{
    int i=0, k=0;
    while(k==0)
    {
        line[i] = getchar();
        if (line[i]=='\n')
        {
            line[i]='\0';
            k=1;
        }
        i++;
    }
    i=1;
    command=strtok(line, space);
    tocken=command;
    /*args[0]=command;*/
    while(tocken!=NULL&&i<7)
    {
        switch (i)
            {
                case 1:{arg0=strtok(NULL, space); tocken=arg0; /*printf("%s\n", arg0);*/ break;}
                case 2:{arg1=strtok(NULL, space); tocken=arg1; /*printf("%s\n", arg1);*/ break;}
                case 3:{arg2=strtok(NULL, space); tocken=arg2; /*printf("%s\n", arg2);*/ break;}
                case 4:{arg3=strtok(NULL, space); tocken=arg3; /*printf("%s\n", arg3);*/ break;}
                case 5:{arg4=strtok(NULL, space); tocken=arg4; /*printf("%s\n", arg4);*/ break;}
                default: {printf("\nFAULT maximum four arguments supported\n");}
            }
        i++;
    }
}

int builtin()
{
    if (!strcmp(command, "exit")) /*Exit handling*/
    {
        k=0;
        return 1;
    } else
    if (!strcmp(command, "help")) /*Help handling*/
    {
        printf("AA                            AA ##########    ####    ###    ###\nAAAA                        AAAA  ##      #  ##    ##   ##    ##\nAA  AA                    AA  AA  ##         ##         ##    ##\nAA    AA                AA    AA  #########    #####    ########\nAA      AA            AA      AA  ##               ##   ##    ##\nAA        AAAA    AAAA        AA  ##      #  ##    ##   ##    ##\n AA           AAAA           AA  ##########    ####    ###    ###\n  AA        AAAA  YEGHOYAN  AA\n   AA     AAA       SHELL  AA\n    AA AAA        %s   AA\n     AA                  AA\n      AAA              AAA\n        AAA          AAA\n          AAAA     AAAA\n            AAAAAAAAA\n              AAAA\n               AA\n\n", V);
        printf("v %s\nlegal commands:\n\n", ver);
        printf("exit\nhelp\nyesh OR about\ntell arg0 TO PRINT OUT arg0\nls -l\n");
        return 1;
    } else
    if ((!strcmp(command, "yesh"))||(!strcmp(command, "about")))
    {
        printf("AA                            AA ##########    ####    ###    ###\nAAAA                        AAAA  ##      #  ##    ##   ##    ##\nAA  AA                    AA  AA  ##         ##         ##    ##\nAA    AA                AA    AA  #########    #####    ########\nAA      AA            AA      AA  ##               ##   ##    ##\nAA        AAAA    AAAA        AA  ##      #  ##    ##   ##    ##\n AA           AAAA           AA  ##########    ####    ###    ###\n  AA        AAAA  YEGHOYAN  AA\n   AA     AAA       SHELL  AA\n    AA AAA        %s   AA\n     AA                  AA\n      AAA              AAA\n        AAA          AAA\n          AAAA     AAAA\n            AAAAAAAAA\n              AAAA\n               AA\n\n", V);
        printf("Yesh <version %s>\nCopyright (C) Artyom Yeghoyan\n\n", ver);
        return 1;
    } else
    /*if (!strcmp(command, "user")) Exit handling
    {
        yesh_chusr();
        return 1;
    } else*/
    if ((!strcmp(command, "ls"))&&(!strcmp(arg0, "-l")))
    {
        system("ls -l");
        return 1;
    } else
    if (!strcmp(command, "tell"))
    {
        printf("%s\n", arg0);
        return 1;
    } else
    {
        if (!strcmp(os, "Windows"))
            yesh_UNIX_appstart();
        return 1;
    }
    return 0;
}
int yesh_UNIX_appstart(/*char **args*/)
    {
    pid_t pid, wpid;
    int status;

    pid = fork();
    /* if (pid == 0) {*/
        /* Child process */
    /* if (execvp(args[0], args) == -1) {
        perror("lsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {*/
        /* Error forking */
    /* perror("lsh");
    } else {*/
        /* Parent process */
        do {
        wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    /*}*/

    return 1;
    }
