/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Alpro2 (mskat22k) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

int indeks; // varibael indeks
char cc;    // variable untuk karakter

int idx, wlen;
char cw[101]; // variabel current word

void start(char str[]); // prosedur start
void reset();           // prosedur reset
int eop(char str[]);    // fungsi eop atau untuk berhenti
void inc(char str[]);   // prosedur increment
int getlen();           // fungsi ambil panjang kata
char *getcw();          // fungsi ambil kata