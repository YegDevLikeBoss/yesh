#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.0.1.1012 alpha"

#define LIM 1000

#ifdef __WINNT__
    #define AA "Windows"
#elif __linux__
    #define AA "Linux"
#else
    #define AA "Not detected"
#endif


void init_loop();
void yesh_arrio();
int builtin();

int k=1;

char *os;

const char ver[]=VERSION, space[2]=" ", usr_nam[]="user";
char /*usr_nam[20]="user",*/ line[LIM], *tocken, **args, *usr;

char *command, *arg0, *arg1, *arg2, *arg3, *arg4;

/*builtins*/
/*void yesh_chusr()
{
    usr=arg0;
}*/

int main(int argc, char *argv[])
{
    os=AA;
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
    /*printf("%s\n", command);*/
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
        printf("AA      AA AAAAAAAAAA     AAA    AA      AA \n AA    AA  AA       A   AA   AA  AA      AA \n  AA  AA   AA          AA     AA AA      AA \n   AAAA    AAAAAAAAAA   AAA      AAAAAAAAAA \n    AA     AA             AAAA   AA      AA \n   AA      AA       A         AA AA      AA \n  AA       AAAAAAAAAA  AA    AA  AA      AA \n AA                      AAAA\n\n");
        printf("v %s\nlegal commands:\n\n", ver);
        printf("exit\nhelp\nyesh OR about\ntell arg0 TO PRINT OUT arg0\nls -l\n");
        return 1;
    } else
    if ((!strcmp(command, "yesh"))||(!strcmp(command, "about")))
    {
        printf("AA      AA AAAAAAAAAA     AAA    AA      AA \n AA    AA  AA       A   AA   AA  AA      AA \n  AA  AA   AA          AA     AA AA      AA \n   AAAA    AAAAAAAAAA   AAA      AAAAAAAAAA \n    AA     AA             AAAA   AA      AA \n   AA      AA       A         AA AA      AA \n  AA       AAAAAAAAAA  AA    AA  AA      AA \n AA                      AAAA\n\n");
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
    }
    return 0;
}
