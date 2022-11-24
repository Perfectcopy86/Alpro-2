/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP8 Alpro2 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char judul[50];     // variabel untuk judul film
    char sutradara[50]; // variabel untuk sutradara
    char genre[50];     // variabel untuk genre
    char bioskop[50];   // variabel untuk bioskop
} film;

typedef struct
{
    char str1[50]; // varibel untuk kode
    char str2[50]; // variabel untuk nama yg ditampilkan
} code;

int read(int k, char string[101], code data2[3][51]);           // fungsi read
void search(int z, code data2[][51], int m, char neangan2[50]); // prosedur search
void list(film data[51], code data2[3][51]);                    // prosedur list film
void menumencari(film data[51], code data2[3][51]);             // prosedur mencari kode