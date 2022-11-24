/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Evaluasi Tugas Masa Depan Alpro2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    int masukan = 0; // int penyimpanan inputan dari user, apakah ENTRI, UBAH, HAPUS, TAMPIL, atau SELESAI
    char pita[250];  // string penampung inputan pita sebanyak 250 karakter
    f1 data[200];    // deklarasi tipe data terstruktur penyimpan data

    printf("<< Selamat Datang di DBMS Terjemahan Rasyid >>\n");
    printf("Versi 1.0\n");
    // perulangan sampai program diminta untuk berhenti
    do
    {
        printf("\ndbms Rasyid> ");
        scanf(" %249[^\n]s", &pita); // meminta user memasukkan kata ke pita
        masukan = choose(pita);      // melakukan pengecekan pada inputan pita
        if (masukan == 1)
        {
            entri(pita, data); // masuk ke ENTRI
        }
        else if (masukan == 2)
        {
            hapus(pita, data); // masuk ke HAPUS
        }
        else if (masukan == 3)
        {
            ubah(pita, data); // masuk ke UBAH
        }
        else if (masukan == 4)
        {
            tampil(pita, data); // masuk ke TAMPIL
        }
    } while (masukan != 5); // Program keluar/selesai
    printf("Hatur Nuhun, #FerrariMasterBlan #Champion\n");
    return 0;
}
