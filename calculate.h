double calculate(char* str2)
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

        while (str2[jj] != '\n')
        {
            while ((str2[jj] >= '0' && str2[jj] <= '9') || str2[jj] == '.')
            {
                str3[i++] = str2[jj++];
                str3[i] = '\0';
                if (i >= 20)
                {
                    printf("fail:单个数据过大！\n");
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

                break;
            case'-':
                Popf(&sf, &n);
                Popf(&sf, &m);
                Pushf(&sf, m - n);

                break;
            case'*':

                Popf(&sf, &n);
                Popf(&sf, &m);
                Pushf(&sf, m * n);

                break;
            case'/':
                Popf(&sf, &n);
                Popf(&sf, &m);
                if (n != 0)
                {
                    Pushf(&sf, m / n);
                }
                else
                {
                    printf("\nfail:除数为0\n");
                    return 'E';
                }


                break;




            }

        }
        Popf(&sf, &m);

        write_history(m);

        printf("\n最终的计算结果为：%f\n", m);
        return m;
    }
    else

    {
        str2 = "quit";
        return 0;
    }

}