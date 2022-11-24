/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP10 Alpro2 (PRAKATA) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

void start(char str[])
{
    idx = 0;
    wlen = 0;

    while (str[idx] == ' ' || str[idx] == ',') // selama bertemu spasi atau koma, idx akan bertambah
    {
        idx++;
    }

    while ((str[idx] != ',') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    cw[wlen] = '\0';
}

void reset()
{
    wlen = 0;
    cw[wlen] = '\0';
}

int eop(char str[])
{
    if (str[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inc(char str[])
{
    wlen = 0;

    while (str[idx] == ' ' || str[idx] == ',') // selama bertemu spasi atau koma, idx akan bertambah
    {
        idx++;
    }

    while ((str[idx] != ',') && (str[idx] != ';'))
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

void bubble(int n, char kata[][50])
{
    int i;
    int swap;
    char temp[101]; // tampung kata

    // metode bubble ascending
    do
    {
        swap = 0;

        for (i = 0; i < (n - 1); i++)
        {
            if ((strcmp(kata[i], kata[i + 1])) > 0)
            {

                strcpy(temp, kata[i]);
                strcpy(kata[i], kata[i + 1]);
                strcpy(kata[i + 1], temp);

                swap = 1;
            }
        }
    } while (swap == 1);
}