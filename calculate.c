#include"calculate.h"
double calculate(char* str2, double* r)
{

    if (str2[0] != 'q')
    {
        Stackf sf;
        InitStackf(&sf);
        int jj = 0;
        int i = 0;
        char str3[MAXBUFFER];
        double m, n = 0;
        stack_clearf(&sf);

        while (str2[jj] != '\0')
        {
            while ((str2[jj] >= '0' && str2[jj] <= '9') || str2[jj] == '.' || (str2[jj + 1] >= '0' && str2[jj + 1] <= '9'))
            {
                str3[i++] = str2[jj++];
                str3[i] = '\0';
                if (i >= 25)
                {
                    printf("fail:single data too large£¡\n");
                    return -1;
                }




                if (str2[jj] == ' ')
                {
                    jj++;
                    m = atof(str3);

                    Pushf(&sf, m);


                    i = 0;

                }

            }
            switch (str2[jj++])
            {
            case '+':

                Popf(&sf, &n);
                Popf(&sf, &m);
                Pushf(&sf, (n + m));

                jj++;
                break;
            case'-':
                Popf(&sf, &n);
                Popf(&sf, &m);
                Pushf(&sf, m - n);

                jj++;
                break;
            case'*':

                Popf(&sf, &n);
                Popf(&sf, &m);
                Pushf(&sf, m * n);

                jj++;
                break;
            case'/':
                Popf(&sf, &n);
                Popf(&sf, &m);
                if (n != 0)
                {
                    Pushf(&sf, m / n);

                    jj++;
                }
                else
                {
                    printf("\nfail:devided by 0\n");
                    str2[0] = 'E';
                    return -1;
                }


                break;




            }

        }
        Popf(&sf, &m);

        write_history(m);

        printf("\n result£º%f\n", m);
        *r = m;

    }
    else
    {
        str2 = "quit";
        return 0;

    }

}