/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP5 Alpro2 (SMN22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void bubbleasc(int n, char makanan[n][25], int kalori[n], int gram[n], double hasil[n])
{
	int i;
	int swap;
	int tempkal;//tampungan kalori
	int tempgram;//tampungan gram
    char temp[50];//tampungan makanan
    double temphasil;//tampungan hasil kalori per gram

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (n - 1); i++){
            if((hasil[i] > hasil[i + 1]))
            {
            	temphasil= hasil[i];
            	hasil[i]= hasil[i+1];
            	hasil[i+1]= temphasil;

            	tempkal= kalori[i];
            	kalori[i]= kalori[i+1];
            	kalori[i+1]= tempkal;

            	tempgram= gram[i];
            	gram[i]= gram[i+1];
            	gram[i+1]= tempgram;

                strcpy(temp, makanan[i]);
                strcpy(makanan[i], makanan[i+1]);
                strcpy(makanan[i+1], temp);

                swap = 1;
            }
        }
    }while(swap == 1);
    output(n, makanan, kalori, gram);//memanggil keluaran
}

void bubbledesc(int n, char makanan[n][25], int kalori[n], int gram[n], double hasil[n])
{
	int i;
	int swap;
	int tempkal;//tampungan kalori
	int tempgram;//tampungan gram
    char temp[50];//tampungan makanan
    double temphasil;//tampungan hasil kalori per gram

    //metode bubble descending
    do{
        swap = 0;

        for(i = 0; i < (n - 1); i++){
            if((hasil[i] < hasil[i + 1]))
            {
            	temphasil= hasil[i];
            	hasil[i]= hasil[i+1];
            	hasil[i+1]= temphasil;

            	tempkal= kalori[i];
            	kalori[i]= kalori[i+1];
            	kalori[i+1]= tempkal;

            	tempgram= gram[i];
            	gram[i]= gram[i+1];
            	gram[i+1]= tempgram;

                strcpy(temp, makanan[i]);
                strcpy(makanan[i], makanan[i+1]);
                strcpy(makanan[i+1], temp);

                swap = 1;
            }
        }
    }while(swap == 1);
    output(n, makanan, kalori, gram);//memanggil keluaran
}

void quickasc(int n, char makanan[n][25], int kalori[n], int gram[n], int left, int right, double hasil[n])
{
	int i,j;
	int tempkal;//tampungan kalori
	int tempgram;//tampungan gram
    char temp[50];//tampungan makanan
    double temphasil;//tampungan hasil kalori per gram
	i=left;
	j=right;
	//metode quick ascending
	double pivot = hasil[(left+right)/2];
	do{
		while((hasil[i]<pivot)&&(i<=j))
		{
			i++;
		}
		while((hasil[j]>pivot)&&(i<=j))
		{
			j--;
		}
		if(i<j)
		{
			temphasil= hasil[i];
            hasil[i]= hasil[j];
           	hasil[j]= temphasil;

           	tempkal= kalori[i];
           	kalori[i]= kalori[j];
           	kalori[j]= tempkal;

           	tempgram= gram[i];
           	gram[i]= gram[j];
           	gram[j]= tempgram;

           	strcpy(temp, makanan[i]);
            strcpy(makanan[i], makanan[j]);
       	    strcpy(makanan[j], temp);

			
			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quickasc(n,makanan, kalori, gram,left,j, hasil);
		}
		if((i<right)&&(i>left))
		{
			quickasc(n,makanan, kalori, gram,i,right, hasil);
		}


}

void quickdesc(int n, char makanan[n][25], int kalori[n], int gram[n], int left, int right, double hasil[n])
{
	int i,j;
	int tempkal;//tampungan kalori
	int tempgram;//tampungan gram
    char temp[50];//tampungan makanan
    double temphasil;//tampungan hasil kalori per gram
	i=left;
	j=right;
	//metode quick descending
	double pivot = hasil[(left+right)/2];
	do{
		while((hasil[i]>pivot)&&(i<=j))
		{
			i++;
		}
		while((hasil[j]<pivot)&&(i<=j))
		{
			j--;
		}
		if(i<j)
		{
			temphasil= hasil[i];
            hasil[i]= hasil[j];
           	hasil[j]= temphasil;

           	tempkal= kalori[i];
           	kalori[i]= kalori[j];
           	kalori[j]= tempkal;

           	tempgram= gram[i];
           	gram[i]= gram[j];
           	gram[j]= tempgram;

           	strcpy(temp, makanan[i]);
            strcpy(makanan[i], makanan[j]);
       	    strcpy(makanan[j], temp);

			
			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quickdesc(n,makanan, kalori, gram,i,right, hasil);
		}
		if((i<right)&&(i>left))
		{
			quickdesc(n,makanan, kalori, gram,left,j , hasil);
		}


}

int hitungdigit(int temp)
{
    int digit=0;//variabel untuk menghitung jumlah digit

    while(temp>0)
        {
            digit++;
            temp=temp/10;

        }
        //printf("%d\n", digit);
        return digit;
}

void output(int n, char makanan[n][25], int kalori[n], int gram[n])
{
	int i,j,k;
    int terpanjang;
	int len;//jumlah huruf per string 
    terpanjang=0;
    int terbesar = 0;//

	for(i=0; i<n; i++)
	{
		len = strlen(makanan[i]);
			if(len>terpanjang)
			{
				terpanjang = len;
			}
	}

	for(i=0; i<n; i++)
	{
			if(kalori[i]>terbesar)
			{
				terbesar = kalori[i];
			}
	}

	//printf("%d\n", terbesar);
	int digitterbesar =0;//digit terbesar
	int digit[n];

	while (terbesar>0)
	{
		terbesar= terbesar/10;
		digitterbesar++;

	}
	//printf("%d\n", digitterbesar);

	int tampung[n];
    for(i=0; i<n; i++)
    {
        tampung[i]= hitungdigit(kalori[i]);

	//hitungdigit(kalori);
    }

 //    for(i=0; i<n; i++)
 //    {
 //        printf("%d\n",tampung[i]);

	// //hitungdigit(kalori);
 //    }

	for(i = 0; i < n; i++)
	{

		printf("%s  ", makanan[i]);//keluaran makanan

		for(j=0; j<terpanjang-strlen(makanan[i]); j++)
            {
                printf(" ");//spasi agar rata
            }
            printf("%d  ", kalori[i]);
            for(j=0; j<digitterbesar-tampung[i]; j++)
            {
                printf(" ");//spasi agar rata untuk angka
            }
            printf("%d", gram[i]);
            printf("\n");

	}


}