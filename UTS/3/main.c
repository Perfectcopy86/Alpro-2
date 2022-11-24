/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UTS Alpro2 (migor22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
	char metode[10];
	scanf("%s", &metode);

	int i,j;
	int n;
	scanf("%d", &n);

	kangminyak suplier1[n];

	for(i=0; i<n; i++)
	{
		scanf("%s %lf %lf %lf", &suplier1[i].migor, &suplier1[i].kalori, &suplier1[i].lemak, &suplier1[i].harga );
	}


	int m;
	scanf("%d", &m);

	kangminyak suplier2[m];

	for(i=0; i<m; i++)
	{
		scanf("%s %lf %lf %lf", &suplier2[i].migor, &suplier2[i].kalori, &suplier2[i].lemak, &suplier2[i].harga );
	}

	int z;
	scanf("%d", &z);

	kangminyak suplier3[z];

	for(i=0; i<z; i++)
	{
		scanf("%s %lf %lf %lf", &suplier3[i].migor, &suplier3[i].kalori, &suplier3[i].lemak, &suplier3[i].harga );
	}

	//pembagian
	double hasil[n];
	double hasil2[m];
	double hasil3[z];
	for (int i = 0; i < n; i++)
	{
		hasil[i]= suplier1[i].harga/(suplier1[i].kalori+suplier1[i].lemak);
	}

	for (int i = 0; i < m; i++)
	{
		hasil2[i]= suplier2[i].harga/(suplier2[i].kalori+suplier2[i].lemak);
	}

	for (int i = 0; i < z; i++)
	{
		hasil3[i]= suplier3[i].harga/(suplier3[i].kalori+suplier3[i].lemak);
	}

	kangminyak temp[n+m];
	kangminyak tempakhir[n+m+z];

	


	printf("Per Supplier:\n");
	if(strcmp(metode, "is")==0)
	{
		insertsup1(n, suplier1, hasil);
		printf("\n");
		insertsup2(m, suplier2, hasil2);
		printf("\n");
		insertsup3(z, suplier3, hasil3);
	}else if(strcmp(metode, "ss")==0)
	{
		selectsup1(n, suplier1, hasil);
		printf("\n");
		selectsup2(m, suplier2, hasil2);
		printf("\n");
		selectsup3(z, suplier3, hasil3);
	}else if(strcmp(metode, "bs")==0)
	{
		bubblesup1(n, suplier1, hasil);
		printf("\n");
		bubblesup2(m, suplier2, hasil2);
		printf("\n");
		bubblesup3(z, suplier3, hasil3);
	}else if(strcmp(metode, "qs")==0)
	{
		quicksup1(n, suplier1, 0, n-1, hasil);
        output1(n, suplier1, hasil);
		printf("\n");
		quicksup2(m, suplier2, 0, m-1, hasil2);
        output2(m, suplier2, hasil2);
		printf("\n");
		quicksup3(z, suplier3, 0, z-1, hasil3);
		output3(z, suplier3, hasil3);
	}



	return 0;
}