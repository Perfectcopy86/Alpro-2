/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Evaluasi Tugas Masa Depan Alpro2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char kode[100];   // string kode
    char driver[100]; // string nama driver
    char negara[100]; // string asal negara
    char team[100];   // string nama team
    char mesin[100];  // string mesin yang digunakan
} f1;

char cc[100];    // tampungan kata yang sedang dicek pada pita
int idx;         // cek indeks dari pita inputan
int panjangkata; // tampungan panjang kata

void start(char pita[]); // mulai cek pita
void inc(char pita[]);   // maju satu kata pada pita
int getlen();            // untukdapatkan panjang kata yang sedang ditampung
char *getcw();           // untuk dapatkan kata yang sedang ditampung
int eop(char pita[]);    // pengecek apakah kata inputan telah selesai

int choose(char pita[]); // fungsi untuk mengecek inputan dari user

void entri(char pita[], f1 data[]); // prosedur untuk memasukkan data dari pita

void ubah(char pita[], f1 data[]); // prosedur untuk mengubah data

void hapus(char pita[], f1 data[]); // prosedur untuk menghapus data

void tampil(char pita[], f1 data[]); // prosedur untuk menampilkan data
