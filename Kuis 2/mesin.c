/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Alpro2 (kngmdk22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void bubbleasc(int n, makanan data[])
{
    int i;
    int swap;
    char temp[50];  // tampungan untuk nama
    char temp2[50]; // tampungan untuk tempat
    int tempharga;  // tampungan untuk harga
    int tempkalori; // tampungan untuk kalori

    // metode bubble ascending
    do
    {
        swap = 0;

        for (i = 0; i < (n - 1); i++)
        {
            if ((data[i].harga > data[i + 1].harga))
            {
                tempharga = data[i].harga;
                data[i].harga = data[i + 1].harga;
                data[i + 1].harga = tempharga;

                tempkalori = data[i].kalori;
                data[i].kalori = data[i + 1].kalori;
                data[i + 1].kalori = tempkalori;

                strcpy(temp, data[i].nama);
                strcpy(data[i].nama, data[i + 1].nama);
                strcpy(data[i + 1].nama, temp);

                strcpy(temp2, data[i].tempat);
                strcpy(data[i].tempat, data[i + 1].tempat);
                strcpy(data[i + 1].tempat, temp2);

                swap = 1;
            }
        }
    } while (swap == 1);
    // output1(n, data); // memanggil keluaran
}

void output1(int n, makanan data[n])
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%s %d %s %d\n", data[i].nama, data[i].harga, data[i].tempat, data[i].kalori); // keluaran
    }
}

void bubbledesc(int n, makanan data[])
{
    int i;
    int swap;
    char temp[50];  // tampungan untuk nama
    char temp2[50]; // tampungan untuk tempat
    int tempharga;  // tampungan untuk harga
    int tempkalori; // tampungan untuk kalori

    // metode bubble descending
    do
    {
        swap = 0;

        for (i = 0; i < (n - 1); i++)
        {
            if ((data[i].kalori < data[i + 1].kalori))
            {
                tempharga = data[i].harga;
                data[i].harga = data[i + 1].harga;
                data[i + 1].harga = tempharga;

                tempkalori = data[i].kalori;
                data[i].kalori = data[i + 1].kalori;
                data[i + 1].kalori = tempkalori;

                strcpy(temp, data[i].nama);
                strcpy(data[i].nama, data[i + 1].nama);
                strcpy(data[i + 1].nama, temp);

                strcpy(temp2, data[i].tempat);
                strcpy(data[i].tempat, data[i + 1].tempat);
                strcpy(data[i + 1].tempat, temp2);

                swap = 1;
            }
        }
    } while (swap == 1);
    // output1(n, data); // memanggil keluaran
}

void cariharga(makanan data[], int n, int ygcari)
{
    int i = 0;
    int k = 0;
    int found = 0;
    // kode untuk melakukan search metode binary
    while ((i <= n) && (found == 0))
    {
        k = (int)((i + n) / 2);
        if (data[k].harga == ygcari)
        {
            // keluaran apabila sesuai syarat
            printf("nama makanan: %s\n", data[k].nama);
            printf("harga: %d\n", data[k].harga);
            printf("tempat penjualan: %s\n", data[k].tempat);
            printf("persen kalori: %d\n", data[k].kalori);
            found = 1;
        }
        else
        {
            if (data[k].harga > ygcari)
            {
                n = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }
    }
    if (found == 0)
    {
        printf("tidak ditemukan\n"); // tidak sesuai syarat
    }
}

void carikalori(makanan data[], int n, int ygcari)
{
    int i = 0;
    int k = 0;
    int found = 0;
    // kode untuk melakukan search metode binary
    while ((i <= n) && (found == 0))
    {
        k = (int)((i + n) / 2);
        if (data[k].kalori == ygcari)
        {
            // keluaran apabila sesuai syarat
            printf("nama makanan: %s\n", data[k].nama);
            printf("harga: %d\n", data[k].harga);
            printf("tempat penjualan: %s\n", data[k].tempat);
            printf("persen kalori: %d\n", data[k].kalori);
            found = 1;
        }
        else
        {
            if (data[k].kalori < ygcari)
            {
                n = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }
    }
    if (found == 0)
    {
        printf("tidak ditemukan\n"); // tidak sesuai syarat
    }
}