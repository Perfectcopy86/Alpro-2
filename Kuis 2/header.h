/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Alpro2 (kngmdk22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];   // variabel untuk nama makanan
    int harga;       // variabel untuk harga makanan
    char tempat[50]; // variabel untuk tempat penjualan
    int kalori;      // variabel untuk kalori
} makanan;

void bubbleasc(int n, makanan data[]);              // sorting bubble ascending untuk harga
void output1(int n, makanan data[]);                // hanya untuk tes
void bubbledesc(int n, makanan data[]);             // sorting bubble descending untuk kalori
void cariharga(makanan data[], int n, int ygcari);  // metode search untuk harga
void carikalori(makanan data[], int n, int ygcari); // metode search untuk kalori