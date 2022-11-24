/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP4 Alpro2 (SLN22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"


void insertasc(int n, char judul[n][25], double waktu[n]){
	int i, j;
	char key[25];//untuk tampungan lagu
	double key2;//untuk tampungan durasi
	//metode insertion ascending lagu
	for(i = 1; i < n; i++){
		strcpy(key, judul[i]);
		key2= waktu[i];
		j = i-1;
		while(j >= 0 && strcmp(key, judul[j]) < 0){
			strcpy(judul[j+1], judul[j]);
			waktu[j+1]=waktu[j];
			j--;
		}
		strcpy(judul[j+1], key);
		waktu[j+1]=key2;
	}
	output(n, judul, waktu);//keluaran
}

void insertdsc(int n, char judul[n][25], double waktu[n])
{
	int i, j;
	char key[25];//untuk tampungan lagu
	double key2;//untuk tampungan durasi
	//metode insertion descending lagu
	for(i = 1; i < n; i++){
		strcpy(key, judul[i]);
		key2=waktu[i];
		j = i-1;
		while(j >= 0 && strcmp(key, judul[j]) > 0){
			strcpy(judul[j+1], judul[j]);
			waktu[j+1]=waktu[j];
			j--;
		}
		strcpy(judul[j+1], key);
		waktu[j+1]=key2;
	}
	output(n, judul, waktu);//keluaran
}

void insertdurasiasc(int n, double waktu[n], char judul[n][25]){
	int i, j;
	double key;//tampungan durasi
	char key2[25];//tampungan lagu
	//metode insertion ascending durasi
	for(i = 1; i < n; i++){
		key = waktu[i];
		strcpy(key2, judul[i]);
		j = i-1;
		while(j >= 0 && key < waktu[j]){
			waktu[j+1]= waktu[j];
			strcpy(judul[j+1], judul[j]);
			j--;
		}
		waktu[j+1]= key;
		strcpy(judul[j+1], key2);
	}
	output(n, judul, waktu);//keluaran
}

void insertdurasidsc(int n, double waktu[n], char judul[n][25]){
	int i, j;
	double key;//tampungan durasi
	char key2[25];//tampungan lagu
	//metode insertion descending durasi
	for(i = 1; i < n; i++){
		key = waktu[i];
		strcpy(key2, judul[i]);
		j = i-1;
		while(j >= 0 && key > waktu[j]){
			waktu[j+1]= waktu[j];
			strcpy(judul[j+1], judul[j]);
			j--;
		}
		waktu[j+1]= key;
		strcpy(judul[j+1], key2);
	}
	output(n, judul, waktu);//keluaran
}

void selectasc(int n, char judul[n][25], double waktu[n]){
	int i, j;
	char temp[25];//tampungan lagu
	double temp2;//tampungan durasi
	int min;
	//metode selection ascending lagu
	for(i = 0; i < n-1; i++){
		min=i;
		for(j = i+1; j < n; j++){
			if(strcmp(judul[min], judul[j])>0){
				min = j;
			}
		}
		strcpy(temp, judul[i]);
		temp2 = waktu[i];
		strcpy(judul[i], judul[min]);
		waktu[i]= waktu[min];
		strcpy(judul[min], temp);
		waktu[min]= temp2;
	}
	output(n, judul, waktu);//keluaran
}

void selectdsc(int n, char judul[n][25], double waktu[n])
{
	int i, j;
	char temp[25];//tampungan lagu
	double temp2;//tampungan durasi
	int min;
	//metode selection descending lagu
	for(i = 0; i < n-1; i++){
		min=i;
		for(j = i+1; j < n; j++){
			if(strcmp(judul[min], judul[j])<0){
				min = j;
			}
		}
		strcpy(temp, judul[i]);
		temp2 = waktu[i];
		strcpy(judul[i], judul[min]);
		waktu[i]= waktu[min];
		strcpy(judul[min], temp);
		waktu[min]= temp2;
	}
	output(n, judul, waktu);//keluaran
}

void selectdurasiasc(int n, double waktu[n], char judul[n][25]){
	int i, j;
	double temp;//tampungan durasi
	char temp2[25];//tampungan lagu
	int min;
	//metode selection ascending durasi
	for(i = 0; i < n-1; i++){
		min=i;
		for(j = i+1; j < n; j++){
			if(waktu[min]> waktu[j]){
				min = j;
			}
		}
		temp= waktu[i];
		strcpy(temp2, judul[i]);
		waktu[i]=waktu[min];
		strcpy(judul[i], judul[min]);
		waktu[min]= temp;
		strcpy(judul[min], temp2);

	}
	output(n, judul, waktu);//keluaran
}

void selectdurasidsc(int n, double waktu[n], char judul[n][25]){
	int i, j;
	double temp;//tampungan durasi
	char temp2[25];//tampungan lagu
	int min;
	//metode selection descending durasi
	for(i = 0; i < n-1; i++){
		min=i;
		for(j = i+1; j < n; j++){
			if(waktu[min]< waktu[j]){
				min = j;
			}
		}
		temp= waktu[i];
		strcpy(temp2, judul[i]);
		waktu[i]=waktu[min];
		strcpy(judul[i], judul[min]);
		waktu[min]= temp;
		strcpy(judul[min], temp2);
	}
	output(n, judul ,waktu);//keluaran
}


void output(int n, char judul[n][25], double waktu[n]){
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%.2f %s\n", waktu[i], judul[i]);//keluaran
	}
}