/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 soal 1 Alpro2 (matdmat2) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void operasi(int baris, int kolom, int a, int b, data matriks[][kolom], data2 matriks2[][b])
{
	int i,j;
	for(i=0; i<baris; i++)
	{
		for(j=0; j<kolom; j++)
		{
			printf("%d %d\n", matriks[i][j].pembilang, matriks[i][j].penyebut);
		}
	}

	for(i=0; i<a; i++)
	{
		for(j=0; j<b; j++)
		{
			printf("%d %d\n", matriks2[i][j].pembilang2, matriks2[i][j].penyebut2);
		}
	}

}