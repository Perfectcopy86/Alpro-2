/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP6 Alpro2 (MBL22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
	int i,j;
	int n;//jumlah inputan
	scanf("%d", &n);
	makanan ani[n];//bungkusan ani

	for(i=0; i<n; i++)
	{
		scanf("%s %d %lf", &ani[i].snack, &ani[i].harga, &ani[i].berat);//masukan user
	}

	int m;//jumlah inputan
	scanf("%d", &m);

	makanan toni[m];//bungkusan toni

	for(i=0; i<m; i++)
	{
		scanf("%s %d %lf", &toni[i].snack, &toni[i].harga, &toni[i].berat);//masukan user
	}

	int z;//jumlah inputan
	scanf("%d", &z);

	makanan budi[z];//bungkusan budi

	for(i=0; i<z; i++)
	{
		scanf("%s %d %lf", &budi[i].snack, &budi[i].harga, &budi[i].berat);//masukan user
	}

	int budget;//budget yg dipunya
	scanf("%d", &budget);

	char metode[10];//metode sorting
	scanf("%s", &metode);

	char sortby[10];//pilihan asc atau desc
	scanf("%s", &sortby);

	int hasil[n];//hasil kali harga * berat bungkusan ani
	int hasil2[m];//hasil kali harga * berat bungkusan toni
	int hasil3[z];//hasil kali harga * berat bungkusan budi
	//kode perhitungannya
	for (int i = 0; i < n; i++)
	{
		hasil[i]= ani[i].harga*ani[i].berat;
	}

	for (int i = 0; i < m; i++)
	{
		hasil2[i]= toni[i].harga*toni[i].berat;
	}

	for (int i = 0; i < z; i++)
	{
		hasil3[i]= budi[i].harga*budi[i].berat;
	}

	makanan arr12[n+m];//gabungan ani dan toni
	int hasil_kali12[n+m];//hasil kali ani toni
	makanan arr123[n+m+z];//gabungan ani, toni , dan budi
	int hasil_kali123[n+m+z];//hasil kali ani toni budi
	int hK123[n+m+z];//tampungan hasil kali

	//kode sesuai syarat metode sorting dan sortby asc atau desc nya
	if(strcmp(metode,"i")==0)
	{
		if(strcmp(sortby, "asc")==0)
		{
			insertaniasc(n, ani, hasil);
			inserttoniasc(m, toni, hasil2);
			merge_terurut(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			insertbudiasc(z, budi, hasil3);
			merge_terurut(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
		}else if(strcmp(sortby, "desc")==0)
		{
			insertanidesc(n, ani, hasil);
			inserttonidesc(m, toni, hasil2);
			merge_terurutdesc(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			insertbudidesc(z, budi, hasil3);
			merge_terurutdesc(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
		}
	}else if(strcmp(metode,"s")==0)
	{
		if(strcmp(sortby, "asc")==0)
		{
			selectaniasc(n, ani, hasil);
			selecttoniasc(m, toni, hasil2);
			merge_terurut(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			selectbudiasc(z, budi, hasil3);
			merge_terurut(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
		}else if(strcmp(sortby, "desc")==0)
		{
			selectanidesc(n, ani, hasil);
			selecttonidesc(m, toni, hasil2);
			merge_terurutdesc(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			selectbudidesc(z, budi, hasil3);
			merge_terurutdesc(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
		}
	}else if(strcmp(metode,"b")==0)
	{
		if(strcmp(sortby, "asc")==0)
		{
			bubbleaniasc(n, ani, hasil);
			bubbletoniasc(m, toni, hasil2);
			merge_terurut(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			bubblebudiasc(z, budi, hasil3);
			merge_terurut(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
		}else if(strcmp(sortby, "desc")==0)
		{
			bubbleanidesc(n, ani, hasil);
			bubbletonidesc(m, toni, hasil2);
			merge_terurutdesc(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			bubblebudidesc(z, budi, hasil3);
			merge_terurutdesc(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
		}
	}else if(strcmp(metode,"q")==0)
	{
		if(strcmp(sortby, "asc")==0)
		{
			quickaniasc(n, ani, 0, n-1, hasil);
	        //output1(n, ani, hasil);
			quicktoniasc(m, toni, 0, m-1, hasil2);
	        //output2(m, toni, hasil2);
			merge_terurut(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			quickbudiasc(z, budi, 0, z-1, hasil3);
			merge_terurut(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
			//output3(z, budi, hasil3);
		}else if(strcmp(sortby, "desc")==0)
		{
			quickanidesc(n, ani, 0, n-1, hasil);
	        //output1(n, ani, hasil);
			quicktonidesc(m, toni, 0, m-1, hasil2);
	        //output2(m, toni, hasil2);
			merge_terurutdesc(n, hasil, ani, m, hasil2, toni, hasil_kali12, arr12);
			quickbudidesc(z, budi, 0, z-1, hasil3);
			//output3(z, budi, hasil3);
			merge_terurutdesc(z, hasil3, budi, n+m, hasil_kali12, arr12, hasil_kali123, arr123);
		}

	}




	for(i=0; i<n+m+z; i++)
	{
		hK123[i] = hasil_kali123[i];
	}

	//output semua snack
	printf("Daftar Snack:\n");
	printf("-------------------------------\n");
	for(i=0; i<n+m+z; i++)
	{
		printf("%s %d\n", arr123[i].snack , hK123[i]);
	}
	printf("===============================\n");
	printf("snack yang dibeli:\n");
	printf("-------------------------------\n");
	beli( budget, hK123,  n,  m ,  z, arr123);//output snack yang dibeli



	return 0;


}