/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Alpro2 (MBSB22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>


typedef struct
{
	char nama[50];//bungkusan untuk nama
	int nilai1;//bungkusan untuk nilai pertama
	int nilai2;//bungkusan untuk nilai kedua
	int nilai3;//bungkusan untuk nilai ketiga
}data;

typedef struct
{
    char ceknama[50];//bungkusan untuk cek nama
}cek;

void keluaransatu(int p, int q, data mahasiswa[][q] );//prosedur output bangku awal
void operasi(int p, int q, int r, data satu[][q], data dua[], data tiga[], data empat[], data lima[], data enam);
void keluarandua(int p, int q, data mahasiswa[][q] );//prosedur output bangku akhir