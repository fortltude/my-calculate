#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>

#define CLOSE "\001\033[0m\002"
#define BLOD  "\001\033[1m\002"
#define BEGIN(x,y) "\001\033["#x";"#y"m\002"

int main(int argc, char* argv[])
{
    if (argc != 3 || strcmp(argv[1], "-t") != 0)
    {

        char* str1;
        char m;
        double r = 0;
        char str2[100] = { " " };
        printf("please input Reverse Polish notation(input help to get help list��:\n");





        do
        {




        AAA:str1 = readline(BEGIN(49, 34)"Myshell $ "CLOSE);

            add_history(str1);

            m = shift(str1, &str2);

            if (m == 'q')
            {

                break;
            }
            else if (m == 'h')
            {
                printf("help list��\n input quit to end\n input Ctrl+u to clean your inputs \n ����search history inputs\n");

                goto AAA;
            }
            else if (m == '0')
            {
                calculate(&str2, &r);



            }
            else
            {
                printf("ERROR\n");
                goto AAA;
            }







        } while (1);
        free(str1);

        return 0;



    }
    else
    {

        char* filename = argv[2];
        FILE* file = fopen(filename, "w");
        char* str1;
        char m;
        double r = 0;
        char str2[100] = { " " };
        printf("please input Reverse Polish notation(input help to get help list��:\n");






        do
        {




        AA:str1 = readline(BEGIN(49, 34)"Myshell $ "CLOSE);

            add_history(str1);



            m = shift(str1, &str2);

            if (m == 'q')
            {

                break;
            }
            else if (m == 'h')
            {
                printf("help list��\n input quit to end\n input Ctrl+u to clean your inputs \n ������search h history inputs\n");

                goto AA;
            }
            else if (m == '0')
            {
                calculate(&str2, &r);
                if (str2[0] == 'E')
                {
                    fprintf(file, "ERROR\n");
                }
                else
                {
                    fprintf(file, "%f\n", r);
                }

            }
            else
            {
                printf("ERROR\n");
                fprintf(file, "ERROR\n");
                goto AA;
            }




        } while (1);
        free(str1);
        fclose(file);
        return 0;
    }


}