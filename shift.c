#include"shift.h"
char shift(char* str1, char* str2)
{
    int j = 0;
    Stack s;
    char c;
    char e;
    int i = 0;
    InitStack(&s);
    stack_clear(&s);

    c = str1[i++];

    if (c >= '0' && c <= '9' || c == '+' || c == '-' || c == '(')
    {




        while (c != '\0')
        {
            while (c >= '0' && c <= '9' || '.' == c)
            {
                printf("%c", c);
                str2[j++] = c;
                c = str1[i++];
                if ((c < '0' || c>'9') && c != '.')
                {
                    printf(" ");
                    str2[j++] = ' ';
                }
            }

            if (')' == c)
            {
                Pop(&s, &e);
                if (e == '(' && str1[i - 2] == '(')
                {

                    return 'E';
                }
                while ('(' != e)
                {
                    printf("%c ", e);
                    str2[j++] = e;
                    str2[j++] = ' ';
                    Pop(&s, &e);
                }
            }
            else if ('+' == c || '-' == c)
            {

                if (str1[i - 2] == '(' || i - 2 < 0)
                {
                    printf("0 ");
                    str2[j++] = '0';
                    str2[j++] = ' ';

                }
                if (!StackLen(s))
                {
                    Push(&s, c);
                }
                else
                {
                    do
                    {
                        Pop(&s, &e);
                        if ('(' == e)
                        {
                            Push(&s, e);
                        }
                        else
                        {
                            printf("%c ", e);
                            str2[j++] = e;
                            str2[j++] = ' ';
                        }
                    } while (StackLen(s) && '(' != e);
                    Push(&s, c);
                }
            }
            else if ('*' == c || '/' == c || '(' == c)
            {
                Push(&s, c);
            }
            else if ('\0' == c)
            {
                break;
            }
            else if (' ' == c)
            {
                c = str1[i++];
                continue;
            }
            else
            {

                return 'E';
            }

            c = str1[i++];
        }

        while (StackLen(s))
        {
            Pop(&s, &e);
            printf("%c ", e);
            str2[j++] = e;
            str2[j++] = ' ';
        }

        str2[j] = '\0';
        return'0';

    }

    else return c;

}