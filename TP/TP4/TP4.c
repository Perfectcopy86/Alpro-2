/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP4 Alpro2 (SLN22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void insertasc(int n, char judul[n][25], double waktu[n]);//prosedur insert lagu ascending
void insertdsc(int n, char judul[n][25], double waktu[n]);//prosedur insert lagu descending
void insertdurasiasc(int n, double waktu[n], char judul[n][25]);//prosedur insert durasi ascending
void insertdurasidsc(int n, double waktu[n], char judul[n][25]);//prosedur insert durasi descending
void selectasc(int n, char judul[n][25], double waktu[n]);//prosedur select lagu ascending
void selectdsc(int n, char judul[n][25], double waktu[n]);//prosedur select lagu descending
void selectdurasiasc(int n, double waktu[n], char judul[n][25]);//prosedur select durasi ascending
void selectdurasidsc(int n, double waktu[n], char judul[n][25]);//prosedur select durasi descending
void output(int n, char judul[n][25], double waktu[n]);//prosedur untuk keluaran



int main()
{
	int n;
	int i,j;
	scanf("%d", &n);
	char judul[n][25];//variabel untuk judul lagu
	int menit[n];//variabel menghitung menit saja
	double detik[n];//variabel menghitung detik saja
	double waktu[n];//variabel durasi lagu
	char jenis[10];//memilih metode insert /select
	char sortby[10];//memilih asc atau desc
	char pilih[10];//memilih lagu atau durasi

	for(i=0; i<n; i++)
	{
		scanf("%s %lf", &judul[i], &waktu[i]);//inputan user
		menit[i]= waktu[i];//memasukan waktu ke menit
		detik[i]= ((waktu[i]-menit[i])*100);//mengambil detiknya saja lalu dikali 100 agar koma hilang


	}


	scanf("%s", &jenis);//inputan user
	scanf("%s", &sortby);//inputan user
	scanf("%s", &pilih);//inputan user

	// for(i=0; i<n; i++)
	// {
	// 	printf("%d %lf\n", menit[i], detik[i]);
	// }

	int totmenit=0;//menghitung total menit
	float totdetik=0;//menghitung total detik
	//perpindahan variabel
	for(i=0; i<n; i++)
	{
		totmenit+=menit[i];
		totdetik+=detik[i];


	}
	//membuat float jadi int agar bisa di mod
	int second;
	second=totdetik;

	
	printf("Playlist (%dm %ds) :\n", totmenit+(second/60), second % 60);//keluaran total durasi
	//keluaran sesuai syarat yang diminta
	if(strcmp(jenis, "insertion")==0){
		if(strcmp(sortby, "asc")==0){

			if(strcmp(pilih, "judul")==0)
			{
				insertasc(n, judul, waktu);
			}else if(strcmp(pilih, "durasi")==0)
			{
				insertdurasiasc(n, waktu, judul);
			}
		}else if(strcmp(sortby, "desc")==0)
		{
			if(strcmp(pilih, "judul")==0)
			{
				insertdsc(n, judul, waktu);
			}else if(strcmp(pilih, "durasi")==0)
			{
				insertdurasidsc(n, waktu, judul);
			}

		}


	}
	else if(strcmp(jenis, "selection")==0){
		if(strcmp(sortby, "asc")==0){
			if(strcmp(pilih, "judul")==0)
			{
				selectasc(n, judul, waktu);
			}else if(strcmp(pilih, "durasi")==0)
			{
				selectdurasiasc(n, waktu, judul);
			}

		}else if(strcmp(sortby, "desc")==0)
		{
			if(strcmp(pilih, "judul")==0)
			{
				selectdsc(n, judul, waktu);
			}else if(strcmp(pilih, "durasi")==0)
			{
				selectdurasidsc(n, waktu, judul);
			}

		}
	}


	return 0;
}

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
