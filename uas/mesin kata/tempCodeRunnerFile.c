int len;
    len = strlen(key);
    start(pita);
    while (eop(pita) == 0)
    {

        strcpy(temp, getcw());
        if (getlen() >= len)
        {
            for (i = 0; i < getlen(); i++)
            {
                if (temp[i] == key[k])
                {
                    k++;
                }
                else if (temp[i] == key[0])
                {
                    k = 1;
                }
                else
                {
                    k = 0;
                }
                if (key[k] == '\0')
                {
                    strcpy(output[n], getcw());
                    n++;
                    i = getlen() - 1;
                }
            }

            k = 0;
        }
        inc(pita);
    }

    strcpy(temp2, getcw());
    if (getlen() >= len)
    {
        for (i = 0; i < getlen(); i++)
        {
            if (temp[i] == key[k])
            {
                k++;
            }
            else if (temp[i] == key[0])
            {
                k = 1;
            }
            else
            {
                k = 0;
            }
            if (key[k] == '\0')
            {
                strcpy(output[n], getcw());
                n++;
                i = getlen() - 1;
            }
        }

        k = 0;
    }

    int z;
    for (z = 0; z < n; z++)
    {
        printf("%s\n", output[z]);
    }