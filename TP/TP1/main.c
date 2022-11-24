/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Alpro2 (MPP22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main(){
    int i,j,k;
    int baris, kolom;//variabel untuk baris dan kolom
    int jumputer;//variabel untuk jumlah putar


    scanf("%d\n %d", &baris, &kolom);//masukan user

    int matriks[baris][kolom];//variabel matriks awal
    int refleks[baris][kolom];//variable matriks yang direfleksikan
    int transpose[kolom][baris];//varibale matriks yang ditransposekan
    int rotasi[kolom][baris];//menampung transpose untuk dirotasi

    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            scanf("%d", &matriks[i][j]);//input angka/elemen matriks
        }
    }

operasi(baris,  kolom,  matriks,  refleks, transpose, rotasi);//menampilkan prosedur




    return 0;
}