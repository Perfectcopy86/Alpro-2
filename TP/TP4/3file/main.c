/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP4 Alpro2 (SLN22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

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