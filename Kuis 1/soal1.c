/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 soal 1 Alpro2 (matdmat2) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>

typedef struct
{
	int pembilang;
	int penyebut;

}data;

typedef struct
{
	int pembilang2;
	int penyebut2;
}data2;

void operasi(int baris, int kolom, int a, int b, data matriks[][kolom], data2 matriks2[][b]);

int main()
{
	int i,j,k;
	int baris;
	int kolom;
	int a,b;


	scanf("%d %d", &baris, &kolom);
	data matriks[baris][kolom];

	for(i=0; i<baris; i++)
	{
		for(j=0; j<kolom; j++)
		{
			scanf("%d %d", &matriks[i][j].pembilang, &matriks[i][j].penyebut);
		}
	}

	scanf("%d %d", &a, &b);
	data2 matriks2[a][b];

	for(i=0; i<a; i++)
	{
		for(j=0; j<b; j++)
		{
			scanf("%d %d", &matriks2[i][j].pembilang2, &matriks2[i][j].penyebut2);
		}
	}

	int p,q;
	scanf("%d %d", &p, &q);

	int temp[p][q];


	

	operasi(baris, kolom, a, b, matriks, matriks2);









	return 0;
}

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
	printf("\n");
}
