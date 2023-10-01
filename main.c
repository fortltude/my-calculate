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
        double result = 0;
        char str2[20] = { " " };
        printf("please input Reverse Polish notation(input help to get help list£©:\n");





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
                printf("help list£º\n input quit to end\n input Ctrl+u to clean your inputs \n ¡ü¡ýsearch hisry inputs\n");

                goto AAA;
            }
            else if (m == '0')
            {
                result = calculate(&str2);



            }
            else
            {
                printf("\n ERROR \n");
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
        double result = 0;
        char str2[20] = { " " };
        printf("please input Reverse Polish notation(input help to get help list£©:\n");






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
                printf("help list£º\n input quit to end\n input Ctrl+u to clean your inputs \n ¡ü¡ý²ésearch htory inputs\n");

                goto AA;
            }
            else if (m == '0')
            {
                result = calculate(&str2);
                fprintf(file, "%f\n", result);


            }
            else
            {
                printf("\n ERROR \n");
                goto AA;
            }




        } while (1);
        free(str1);
        fclose(file);
        return 0;
    }


}