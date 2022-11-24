/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Alpro2 (mskat22k) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

int idx, wlen;
char cw[101];

int eop(char str[])
{
    if (str[idx] == '$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void start(char str[])
{
    idx = 0;
    wlen = 0;

    while (str[idx] == ' ') // selama bertemu spasi atau koma, idx akan bertambah
    {
        idx++;
    }

    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    cw[wlen] = '\0';
}

void inc(char str[])
{
    wlen = 0;

    while (str[idx] == ' ') // selama bertemu spasi atau koma, idx akan bertambah
    {
        idx++;
    }

    while ((str[idx] != ' ') && (str[idx] != '$'))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    cw[wlen] = '\0';
}

int getlen()
{
    return wlen;
}

char *getcw()
{
    return cw;
}

int main()
{
    char pita[501];
    char key[50];

    scanf("%s", &key);
    scanf(" %500[^\n]s", &pita); // masukan pita

    // start(pita);
    // while (eop(pita) == 0)
    // {
    //     printf("%s", getcw());
    //     inc(pita);
    // }

    // printf("%s", getcw());
    char temp[501];
    char temp2[501];
    char output[100][501];
    int len;
    int n = 0;
    int i;
    int k = 0;
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
            i = 0;
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

    return 0;
}