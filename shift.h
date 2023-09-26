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
                if (e == '(')
                {
                    printf("表达式格式错误\n");
                    return 'E';
                }
                while ('(' != e)
                {
                    printf("%c ", e);
                    str2[j++] = e;
                    Pop(&s, &e);
                }
            }
            else if ('+' == c || '-' == c)
            {
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
                printf("\n出错：输入格式错误！\n");
                return 'E';
            }

            c = str1[i++];
        }

        while (StackLen(s))
        {
            Pop(&s, &e);
            printf("%c", e);
            str2[j++] = e;
        }
        str2[j] = '\n';
        return'0';

    }

    else return c;

}