/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Alpro2 (kngmdk22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    int i, n;
    scanf("%d", &n);
    makanan data[n]; // memanggil struct
    // inputan user
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %s %d", &data[i].nama, &data[i].harga, &data[i].tempat, &data[i].kalori);
    }

    // for (i = 0; i < n; i++)
    // {
    // 	printf("%s %d %s %d\n", data[i].nama, data[i].harga, data[i].tempat, data[i].kalori);
    // }

    char metode[10];      // memilih metode harga atau kalori
    scanf("%s", &metode); // inputan

    int ygcari; // integer yg dicari
    scanf("%d", &ygcari);

    // printf("%s\n%d\n", metode, ygcari);

    // print sesuai syarat
    if (strcmp(metode, "harga") == 0)
    {
        bubbleasc(n, data); // panggil sorting untuk nanti binary search
        cariharga(data, n, ygcari);
    }
    else if (strcmp(metode, "kalori") == 0)
    {
        bubbledesc(n, data); // panggil sorting untuk nanti binary search
        carikalori(data, n, ygcari);
    }

    return 0;
}