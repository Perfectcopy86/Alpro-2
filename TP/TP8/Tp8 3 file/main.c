/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP8 Alpro2 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    film data[51];
    code data2[3][51];
    int m;
    int k;
    int p;
    int menu;
    do
    {

        printf("Masukan Perintah menu:\n1. Lihat daftar list Film\n2. Search\n3. Ga jadi deh\n0. Keluar Program\n");
        scanf("%d", &menu);
        if (menu == 1) // menampilkan list film
        {
            list(data, data2);
            system("pause"); // memberi pause ketika ingin menjalankan perintah lain
            system("cls");   // menghapus yg sudah dijalankan
        }
        else if (menu == 2) // melakukan search yang diinginkan
        {
            printf("input yang ingin dicari(sutradara,genre,bioskop).Gunakan huruf kecil semua!\n");
            menumencari(data, data2);
            system("pause"); // memberi pause ketika ingin menjalankan perintah lain
            system("cls");   // menghapus yg sudah dijalankan
        }
        else if (menu == 3) // ga jadi melakukan perintah
        {
            printf("Oh Yaudah\n");
            system("pause"); // memberi pause ketika ingin menjalankan perintah lain
            system("cls");   // menghapus yg sudah dijalankan
        }

    } while (menu != 0);
    return 0;
}