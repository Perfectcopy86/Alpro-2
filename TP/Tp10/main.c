/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP10 Alpro2 (PRAKATA) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    int i;
    int k = 0;           // penanda kata palsu
    int a = 0;           // penanda jika tidak ada kata asli
    int b = 0;           // penanda jika tidak ada kata dicurigai
    int c = 0;           // penanda jika tidak ada kata palsu
    char pita[101];      // variabel pita
    char key;            // variabel huruf kunci
    int angka;           // variabel kunci panjang kata
    char temp[101];      // tampungan untuk getcw
    char palsu[101];     // kata palsu ditampung disini
    char asli[25][50];   // kata asli ditampung disini
    char curiga[25][50]; // kata dicurigai ditampung disini

    scanf(" %c %d", &key, &angka); // inputan user

    scanf(" %100[^\n]s", &pita); // inputan user

    start(pita);
    while (eop(pita) == 0)
    {
        getcw();
        strcpy(temp, getcw());                       // menampung getcw ke variabel temp
        if ((temp[0] == key) && (getlen() == angka)) // jika sesuai kunci maka masuk ke kata palsu
        {
            strcpy(palsu, getcw());
            k++;
            c++;
        }
        else if (k == 0) // jika sesuai syarat maka akan masuk ke kata asli
        {
            strcpy(asli[a], getcw());
            a++;
        }
        else if (k >= 1) // jika kata palsu sudah ditemukan maka akan masuk ke kata dicurigai
        {
            strcpy(curiga[b], getcw());
            b++;
        }
        inc(pita);
    }

    // kata terakhir sebelum ";" tidak masuk, nah maka di buat lagi agar kata tersebut masuk
    getcw();
    strcpy(temp, getcw());
    if ((temp[0] == key) && (getlen() == angka))
    {
        strcpy(palsu, getcw());
        k++;
        c++;
    }
    else if (k == 0)
    {
        strcpy(asli[a], getcw());
        a++;
    }
    else if (k >= 1)
    {
        strcpy(curiga[b], getcw());
        b++;
    }

    // output sesuai yang diminta
    printf("KATA ASLI\n");
    if (a == 0)
    {
        printf("- TIDAK ADA.\n");
    }
    else
    {
        bubble(a, asli); // memanggil sorting
        for (i = 0; i < a; i++)
        {
            printf("- %s\n", asli[i]);
        }
    }

    printf("\n");
    printf("KATA PALSU\n");
    if (c == 0)
    {
        printf("- TIDAK ADA.\n");
    }
    else
    {
        printf("- %s\n", palsu);
    }

    printf("\n");
    printf("KATA DICURIGAI\n");
    if (b == 0)
    {
        printf("- TIDAK ADA.\n");
    }
    else
    {
        bubble(b, curiga); // memanggil sorting
        for (i = 0; i < b; i++)
        {
            printf("- %s\n", curiga[i]);
        }
    }

    return 0;
}