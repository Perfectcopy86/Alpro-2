/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Alpro2 (mskar22k) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include<stdio.h>
#include<string.h>

int indeks; // varibael indeks
char cc; 

void START(char pita[])
{
    indeks = 0;
    cc = pita[indeks];
}

void INC(char pita[])
{
    indeks++;
    cc = pita[indeks];
}

int EOP()
{
    if (cc == '$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ADV(char pita[])
{
    indeks++;
    cc = pita[indeks];
    while ((cc == ' ') && (EOP() == 0))
    {
        indeks++;
        cc = pita[indeks];
    }
}

char GETCC()
{
    return cc;
}

int main()
{
    int i, j;

    int k = 0;
    int idx = 0;
    int mod;
    char pita[101];
    int angka;
    char key;
    int len;

    scanf("%d", &angka);
    scanf(" %c", &key);
    char temp[101];

    scanf(" %100[^\n]s", &pita); // masukan pita

    START(pita);
    while (EOP() == 0)
    {
        temp[idx] = GETCC();
        // printf("%c", temp[idx]);
        idx++;

        ADV(pita);
    }

    // printf("%d\n", strlen(temp));
    int found = 0;
    int found2 =0;
    mod = strlen(temp) % angka;
    len = strlen(temp) - mod;
    int bagi;
    bagi = len / angka;
    char temp2[50][101];
    START(pita);
    for (i = 0; i < bagi; i++)
    {
        for (j = 0; j < angka; j++)
        {
            temp2[i][j] = GETCC();
            ADV(pita);
        }
        temp2[i][j] = '\0';
    }

    for (i = 0; i < bagi; i++)
    {
        for (j = 0; j < angka; j++)
        {
            if (temp2[i][j] == key)
            {
                found++;
                if (found > 0)
                {
                    found2++;
                    i++;
                }
            }
        }
        // printf("%s ", temp2[i]);
    }

    printf("%d", found2);

    return 0;
}