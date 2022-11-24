/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP3 Alpro2 (PBV212) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/


#include <stdio.h>

int fungsi(int a, int b, int z);//fungsi mencari jumlah virus

int main()
{
	int baris;//variabel untuk banyak yang di cek

	scanf("%d", &baris);// inputan user untuk banyak nya yang akan dicari
	int a[baris];//virus di jam ke 0
	int b[baris];//virus di jam ke 1
	int z[baris];//virus di jam yang ingin dicari
	int i;


	for(i=0;i<baris;i++)
	{
		scanf("%d", &a[i]);//inputan user
		scanf("%d", &b[i]);//inputan user
		scanf("%d", &z[i]);//inputan user
	}
	for(i=0; i<baris;i++)
    {
		printf("%d\n", fungsi(a[i],b[i],z[i]));//memanggil fungsi
    }
	return 0;
}

int fungsi(int a, int b, int z)
{
	int jummak;//variabel untuk menampung virus yang ingin dicari pada jam ke x

	if(z==0)//jika yg dicari pada jam ke nol, maka yg di ambil variabel a 
	{
		return a;
	}else if(z==1)//jika yg dicari pada jam ke nol, maka yg di ambil variabel b
	{
		return b;
	}else
	{
		jummak = 2*fungsi(a,b,z-1)+((fungsi(a,b,z-2)*fungsi(a,b,z-2)));//jika yg dicari pada jam yg diinginkan, maka sesuai rumus yg ada di cspc
		return jummak;
	}

}
