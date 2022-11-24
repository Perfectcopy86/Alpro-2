/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP4 Alpro2 (SLN22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>


void insertasc(int n, char judul[n][25], double waktu[n]);//prosedur insert lagu ascending
void insertdsc(int n, char judul[n][25], double waktu[n]);//prosedur insert lagu descending
void insertdurasiasc(int n, double waktu[n], char judul[n][25]);//prosedur insert durasi ascending
void insertdurasidsc(int n, double waktu[n], char judul[n][25]);//prosedur insert durasi descending
void selectasc(int n, char judul[n][25], double waktu[n]);//prosedur select lagu ascending
void selectdsc(int n, char judul[n][25], double waktu[n]);//prosedur select lagu descending
void selectdurasiasc(int n, double waktu[n], char judul[n][25]);//prosedur select durasi ascending
void selectdurasidsc(int n, double waktu[n], char judul[n][25]);//prosedur select durasi descending
void output(int n, char judul[n][25], double waktu[n]);//prosedur untuk keluaran