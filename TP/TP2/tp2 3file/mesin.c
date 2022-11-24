/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Alpro2 (MBSB22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/



#include "header.h"




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

