/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 soal 2 Alpro2 (deret322) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/


#include"header.h"
void hasil(int a, int b, int c, int d)
{
    int counter;//untuk menghitung berapa kali pengulangan
    counter = d;
    if(counter>0){
		printf("%d %d %d ", a, b, c);//output dengan spasi

        counter-=1;
        hasil(a, b*b, c+(b*b),counter);//memanggil prosedur rekursif

    }else if(counter==0)
    {
        printf("%d %d %d", a, b, c);//output tanpa spasi

        counter-=1;
        hasil(a, b*b, c+(b*b),counter);//memanggil prosedur rekursif
    }


}