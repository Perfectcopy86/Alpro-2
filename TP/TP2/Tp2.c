/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP2 Alpro2 (MBSB22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>


typedef struct
{
	char nama[50];//bungkusan untuk nama
	int nilai1;//bungkusan untuk nilai pertama
	int nilai2;//bungkusan untuk nilai kedua
	int nilai3;//bungkusan untuk nilai ketiga
}data;

typedef struct
{
    char ceknama[50];//bungkusan untuk cek nama
}cek;

void keluaransatu(int p, int q, data mahasiswa[][q] );//prosedur output bangku awal
void operasi(int p, int q, int r, data satu[][q], data dua[], data tiga[], data empat[], data lima[], data enam);
void keluarandua(int p, int q, data mahasiswa[][q] );//prosedur output bangku akhir

int main(){
	int i, j, k;
	int baris;
	int kolom;
	data temp;//bungkusan untuk tampungan
	int terpanjang[20];//variabel untuk menghitung kata terpanjang
	scanf("%d %d", &baris, &kolom);

	data mhswa[baris][kolom];

	for(i=0; i<baris; i++)
	{
		for(j=0; j<kolom; j++)
		{
			scanf("%s", &mhswa[i][j].nama);//input nama mahasiswa
			scanf("%d", &mhswa[i][j].nilai1);//input nilai
			scanf("%d", &mhswa[i][j].nilai2);//input nilai
			scanf("%d", &mhswa[i][j].nilai3);//input nilai
		}
	}

	cek name[50];
	i=0;
	int a=0;
	do{
		scanf("%s", name[i].ceknama);
		i++;
		a++;

	}while(strcmp(name[i-1].ceknama,"stop")!=0);//jika kata stop ada maka berhenti

	keluaransatu( baris, kolom, mhswa);//kelauran dari prosedur

	data kanan[(a-1)/2];//untuk nama bagian kanan
	data kiri[(a-1)/2];//untuk nama bagian kiri
	int hitung1=0;
	int hitung2=0;


	for(i=0; i<a-1; i++)
	{
		if(i%2==0)
		{
			strcpy(kiri[hitung1].nama, name[i].ceknama);//untuk yg kiri lalu di copy
			hitung1++;
		}else
		{
			strcpy(kanan[hitung2].nama, name[i].ceknama);//untuk yg kanan lalu di copy
			hitung2++;
		}
	}




	int jumlah[50][50];// untuk menghitung jumlah
    int rata[50][50];// untuk menghitung rata-rata
    //untuk menjumlahkan
	for(i=0; i<baris; i++)
	{
		for(j=0; j<kolom; j++)
		{
			jumlah[i][j]= mhswa[i][j].nilai1+ mhswa[i][j].nilai2+ mhswa[i][j].nilai3;
		}
	}
	//untuk rata rata
	for(i=0; i<baris; i++)
	{
		for(j=0; j<kolom; j++)
		{
		    rata[i][j]=jumlah[i][j]/3;
		}

	}



	data meankiri[(a-1)/2];//untuk nilai mean nama kiri
	data meankanan[(a-1)/2];//untuk nilai mean nama kanan

	for(i=0; i<(a-1)/2; i++)
	{
		for(j=0; j<baris; j++)
		{
			for(k=0; k<kolom; k++)
			{
				if(strcmp(kiri[i].nama, mhswa[j][k].nama)==0)
				{
					meankiri[i].nilai1 = rata[j][k];//menampung ke yg kiri
				}else if(strcmp(kanan[i].nama, mhswa[j][k].nama)==0)
				{
					meankanan[i].nilai1 = rata[j][k];//menampung ke yg kanan
				}
			}
		}
	}

	operasi(baris, kolom, a, mhswa, kiri, kanan, meankiri, meankanan, temp);//memanggil prosedur operasi

	keluarandua(baris, kolom, mhswa);//memanggil prosedur keluarandua

	return 0;
}

void keluaransatu(int p, int q, data mahasiswa[][q] )

{
    int i,j,k;
    int terpanjang[20];
    //kode mendapatkan kata terpanjang dari setiap kolom
    for(i=0; i<q; i++)
	{
		terpanjang[i]=0;
		for(j=0; j<p; j++)
		{
			if(strlen(mahasiswa[j][i].nama)>terpanjang[i])
			{
				terpanjang[i] = strlen(mahasiswa[j][i].nama);
			}
		}
	}
	//output posisi awal
	printf("Posisi Bangku Awal:\n");
	for(i=0;i<p;i++)
	{
  		for(j=0;j<q;j++)
  		{
  			if(j==q-1)
                {
                    printf("%s", mahasiswa[i][j].nama);//print karakter tanpa spasi

                }else
                {
                    printf("%s  ", mahasiswa[i][j].nama);//print karakter dengan spasi
                    for(k=0; k<terpanjang[j]-strlen(mahasiswa[i][j].nama); k++)
            	{

                	printf(" ");

            	}
                }


        }
  		printf("\n");
	}
	printf("\n");
}


void operasi(int p, int q, int r, data satu[][q], data dua[], data tiga[], data empat[], data lima[], data enam)//satu ganti mhswa, kiri dua, kanan tiga


{
    int i,j,k;

	int coord1[4];
	int coord2[4];
	//kode untuk menukar
	for(i=0; i<(r-1)/2; i++)
	{
		if(empat[i].nilai1>lima[i].nilai1)//jika yg kiri lebih besar dari yang kanan maka tukar posisi
		{


		for(j=0; j<p; j++)
		{
			for(k=0; k<q; k++)
			{
				if(strcmp(dua[i].nama, satu[j][k].nama)==0)
				{
					coord1[0] = j;
					coord1[1] = k;

				}else if(strcmp(tiga[i].nama, satu[j][k].nama)==0)
				{
					coord2[0] = j;
					coord2[1] = k;
				}
			}
		}
		enam = satu[coord1[0]][coord1[1]];
		satu[coord1[0]][coord1[1]] = satu[coord2[0]][coord2[1]];
		satu[coord2[0]][coord2[1]] = enam;
		}
	}




}

void keluarandua(int p, int q, data mahasiswa[][q] )
{
	int terpanjang[20];
	int i,j,k;
	//mencari kata terpanjang dari tiap kolom
	for(i=0; i<q; i++)
	{
		terpanjang[i]=0;
		for(j=0; j<p; j++)
		{
			if(strlen(mahasiswa[j][i].nama)>terpanjang[i])
			{
				terpanjang[i] = strlen(mahasiswa[j][i].nama);
			}
		}
	}


	//output posisi akhir
    printf("Posisi Bangku Akhir:\n");
	for(i=0;i<p;i++)
	{
  		for(j=0;j<q;j++)
  		{
  			if(j==q-1)
                {
                    printf("%s", mahasiswa[i][j].nama);//print karakter tanpa spasi

                }else
                {
                    printf("%s  ", mahasiswa[i][j].nama);//print karakter dengan spasi
                    for(k=0; k<terpanjang[j]-strlen(mahasiswa[i][j].nama); k++)
            	{

                	printf(" ");

            	}
                }


        }
  		printf("\n");
	}

}

