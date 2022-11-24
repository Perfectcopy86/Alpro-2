/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP5 Alpro2 (SMN22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
	int i,j,n;
	scanf("%d", &n);
	char makanan[n][25];//variabel makanan
	int kalori[n];//variabel kalori
	int gram[n];//variabel gram
	char metode[5];//variabel metode buccle atau quick
	char sortby[5];//variabel asc atau desc
	double hasil[n];//variabel kalori per gram

	for(i=0; i<n; i++)
	{
		scanf("%s %d %d", &makanan[i], &kalori[i], &gram[i]);//inputan user
	}

	scanf("%s", &metode);//inputan user
	scanf("%s", &sortby);//inputan user


	for(i=0; i<n; i++)
	{
		hasil[i]= kalori[i]/(gram[i]*1.0);//menghitung kalori per gram
	}


	//keluaran sesuai syarat yang telah ditentukan
	if(strcmp(metode, "b")==0)
	{
	    if(strcmp(sortby, "a")==0)
	    {
	    	printf("Daftar Menu Makanan :\n");
            bubbleasc(n, makanan, kalori, gram, hasil);
	    }else if (strcmp(sortby, "d")==0)
	    {
	    	printf("Daftar Menu Makanan :\n");
	        bubbledesc(n, makanan, kalori, gram, hasil);
	    }
	}else if(strcmp(metode, "q")==0)
	{
		if(strcmp(sortby, "a")==0)
	    {
	    	printf("Daftar Menu Makanan :\n");
            quickasc(n, makanan, kalori, gram, 0, n-1, hasil);
            output(n, makanan, kalori, gram);
	    }else if(strcmp(sortby, "d")==0)
	    {
	    	printf("Daftar Menu Makanan :\n");
	    	quickdesc(n, makanan, kalori, gram, 0, n-1, hasil);
            output(n, makanan, kalori, gram);
	    }
	}



	return 0;
}