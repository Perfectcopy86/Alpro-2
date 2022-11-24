/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 soal 2 Alpro2 (deret322) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>


void hasil(int a, int b, int c, int d);

int main()
{
	int h,i,j,d;

	scanf("%d %d %d", &h, &i, &j);
	scanf("%d", &d);

	hasil(h,i,j,d);

	return 0;
}

void hasil(int a, int b, int c, int d)
{
    int counter;
    counter = d;
    if(counter>0){
		printf("%d %d %d", a, b, c);

    }else if(counter>0)
    {
        printf("%d %d %d ", a, b, c);
        hasil(a, b*b, c+(b*b),d);

    }

}
