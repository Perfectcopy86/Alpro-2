/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP5 Alpro2 (SMN22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>


void bubbleasc(int n, char makanan[n][25], int kalori[n], int gram[n], double hasil[n]);//prosedur bubble ascending
void bubbledesc(int n, char makanan[n][25], int kalori[n], int gram[n], double hasil[n]);//prosedur bubble descending
void quickasc(int n, char makanan[n][25], int kalori[n], int gram[n], int left, int right, double hasil[n]);//prosedur quick ascending
void quickdesc(int n, char makanan[n][25], int kalori[n], int gram[n], int left, int right, double hasil[n]);//prosedur quick descending
int hitungdigit(int temp);//fungsi digit untuk membuat spasi
void output(int n, char makanan[n][25], int kalori[n], int gram[n]);//keluaran