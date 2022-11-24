/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 soal 2 Alpro2 (deret322) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include"header.h"
int main()
{
	int h,i,j,d;

	scanf("%d %d %d", &h, &i, &j);//inputan user 3 angka
	scanf("%d", &d);//inputan berapa kali ngulang

	hasil(h,i,j,d);//memanggil prosedur rekursif
	printf("\n");

	return 0;
}