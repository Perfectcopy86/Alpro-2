/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Alpro2 (mskar22k) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

int indeks; // varibael indeks
char cc;    // variable untuk karakter

void START(char pita[]); // memulai mesin
void INC(char pita[]);   // increment
int EOP();               // tanda mesin beres
void ADV(char pita[]);   // melewati spasi
char GETCC();            // mengambil karakter