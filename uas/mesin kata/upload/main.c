/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Alpro2 (mskat22k) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    char pita[501]; // VARIABEL UNTUK PITA
    char key[50];   // kata kunci

    scanf("%s", &key);
    scanf(" %500[^\n]s", &pita); // masukan pita

    char temp[501];        // tampungan
    char temp2[501];       // tampungan
    char output[100][501]; // hasil akhir
    int len;               // panjang kata kunci
    int n = 0;
    int i;
    int k = 0;
    len = strlen(key); // panjang kata kunci
    start(pita);
    while (eop(pita) == 0)
    {

        strcpy(temp, getcw()); // copy kata
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
                    strcpy(output[n], getcw()); // copy kata
                    n++;
                    i = getlen() - 1;
                }
            }
            i = 0;
            k = 0;
        }
        inc(pita);
    }

    // pengambilan kata sebelum dollar
    strcpy(temp2, getcw()); // copy kata
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
                strcpy(output[n], getcw()); // copy kata
                n++;
                i = getlen() - 1;
            }
        }

        k = 0;
    }

    // output hasil
    int z;
    for (z = 0; z < n; z++)
    {
        printf("%s\n", output[z]);
    }

    return 0;
}