/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP3 Alpro2 (PBV212) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/


#include "header.h"

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