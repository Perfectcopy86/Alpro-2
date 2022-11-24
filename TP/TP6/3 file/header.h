/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP6 Alpro2 (MBL22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char snack[50];//variabel nama makanan snack
	int harga;//variabel harga snack
	double berat;//variabel berat snack
}makanan;
//metode insertion asc dan desc
void insertaniasc(int n, makanan ani[n], int hasil[n]);
void inserttoniasc(int m, makanan toni[m], int hasil2[m]);
void insertbudiasc(int z, makanan budi[z], int hasil3[z]);
void insertanidesc(int n, makanan ani[n], int hasil[n]);
void inserttonidesc(int m, makanan toni[m], int hasil2[m]);
void insertbudidesc(int z, makanan budi[z], int hasil3[z]);
//metode selection asc dan desc
void selectaniasc(int n, makanan ani[n], int hasil[n]);
void selecttoniasc(int m, makanan toni[m], int hasil2[m]);
void selectbudiasc(int z, makanan budi[z], int hasil3[z]);
void selectanidesc(int n, makanan ani[n], int hasil[n]);
void selecttonidesc(int m, makanan toni[m], int hasil2[m]);
void selectbudidesc(int z, makanan budi[z], int hasil3[z]);
//metode bubble asc dan desc
void bubbleaniasc(int n, makanan ani[n], int hasil[n]);
void bubbletoniasc(int m, makanan toni[m], int hasil2[m]);
void bubblebudiasc(int z, makanan budi[z], int hasil3[z]);
void bubbleanidesc(int n, makanan ani[n], int hasil[n]);
void bubbletonidesc(int m, makanan toni[m], int hasil2[m]);
void bubblebudidesc(int z, makanan budi[z], int hasil3[z]);
//metode quicsort asc dan desc
void quickaniasc(int n, makanan ani[n], int left, int right, int hasil[n]);
void quicktoniasc(int m, makanan toni[m], int left, int right, int hasil2[m]);
void quickbudiasc(int z, makanan budi[z], int left, int right, int hasil3[z]);
void quickanidesc(int n, makanan ani[n], int left, int right, int hasil[n]);
void quicktonidesc(int m, makanan toni[m], int left, int right, int hasil2[m]);
void quickbudidesc(int z, makanan budi[z], int left, int right, int hasil3[z]);
//metode merge terurut asc dan desc
void merge_terurut(int n, int hasil[], makanan ani[], int m, int hasil2[], makanan toni[], int hasil3[], makanan budi[]);
void merge_terurutdesc(int n, int hasil[], makanan ani[], int m, int hasil2[], makanan toni[], int hasil3[], makanan budi[]);
//hitung dan keluaran snack yg dibeli
void beli(int budget,int hK123[], int n, int m , int z, makanan arr123[]);