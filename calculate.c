#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include "Stack.h"
#include"shift.h"
#include"calculate.h"

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
        char str2[50] = { " " };
        printf("请输入中缀表达式(输入help获取帮助）:\n");





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
                printf("帮助指南：\n输入quit退出程序\nCtrl+u清除表达式\n↑↓查看历史命令表达式\n");

                goto AAA;
            }
            else if (m == '0')
            {
                result = calculate(&str2);



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
        char E[] = { "Error" };
        char str2[50] = { " " };
        printf("请输入中缀表达式(输入help获取帮助）:\n");





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
                printf("帮助指南：\n输入quit退出程序\nCtrl+u清除表达式\n↑↓查看历史命令表达式\n");

                goto AA;
            }
            else if (m == '0')
            {
                result = calculate(&str2);
                if (result == 'E')
                {
                    fprintf(file, "%s\n", E);
                }
                else
                {
                    fprintf(file, "%f\n", result);
                }

            }
            else if (m == 'E')
            {

                fprintf(file, "%s\n", E);

            }




        } while (1);
        free(str1);
        fclose(file);
        return 0;
    }


}