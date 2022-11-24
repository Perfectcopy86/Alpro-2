/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UTS Alpro2 (migor22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"


void insertsup1(int n, kangminyak suplier1[n],  double hasil[n]){
	int i, j;
	double key;
	double keykal;
	double keylem;
	double keyhar;
	char key2[25];

	for(i = 1; i < n; i++){
		key = hasil[i];
		keykal = suplier1[i].kalori;
		keylem = suplier1[i].lemak;
		keyhar = suplier1[i].harga;
		strcpy(key2, suplier1[i].migor);
		j = i-1;
		while(j >= 0 && key < hasil[j]){
			hasil[j+1]= hasil[j];
			suplier1[j+1].kalori=suplier1[j].kalori;
			suplier1[j+1].lemak=suplier1[j].lemak;
			suplier1[j+1].harga=suplier1[j].harga;
			strcpy(suplier1[j+1].migor, suplier1[j].migor);
			j--;
		}
		hasil[j+1]= key;
		suplier1[j+1].kalori=keykal;
		suplier1[j+1].lemak=keylem;
		suplier1[j+1].harga = keyhar;

		strcpy(suplier1[j+1].migor, key2);
	}
	output1(n, suplier1, hasil);//keluaran
}

void insertsup2(int m, kangminyak suplier2[m],  double hasil2[m]){
	int i, j;
	double key;
	double keykal;
	double keylem;
	double keyhar;
	char key2[25];

	for(i = 1; i < m; i++){
		key = hasil2[i];
		keykal = suplier2[i].kalori;
		keylem = suplier2[i].lemak;
		keyhar = suplier2[i].harga;
		strcpy(key2, suplier2[i].migor);
		j = i-1;
		while(j >= 0 && key < hasil2[j]){
			hasil2[j+1]= hasil2[j];
			suplier2[j+1].kalori=suplier2[j].kalori;
			suplier2[j+1].lemak=suplier2[j].lemak;
			suplier2[j+1].harga=suplier2[j].harga;
			strcpy(suplier2[j+1].migor, suplier2[j].migor);
			j--;
		}
		hasil2[j+1]= key;
		suplier2[j+1].kalori=keykal;
		suplier2[j+1].lemak=keylem;
		suplier2[j+1].harga = keyhar;
		strcpy(suplier2[j+1].migor, key2);
	}
	output2(m, suplier2, hasil2);//keluaran
}

void insertsup3(int z, kangminyak suplier3[z],  double hasil3[z]){
	int i, j;
	double key;
	double keykal;
	double keylem;
	double keyhar;
	char key2[25];

	for(i = 1; i < z; i++){
		key = hasil3[i];
		keykal = suplier3[i].kalori;
		keylem = suplier3[i].lemak;
		keyhar = suplier3[i].harga;
		strcpy(key2, suplier3[i].migor);
		j = i-1;
		while(j >= 0 && key < hasil3[j]){
			hasil3[j+1]= hasil3[j];
			suplier3[j+1].kalori=suplier3[j].kalori;
			suplier3[j+1].lemak=suplier3[j].lemak;
			suplier3[j+1].harga=suplier3[j].harga;
			strcpy(suplier3[j+1].migor, suplier3[j].migor);
			j--;
		}
		hasil3[j+1]= key;
		suplier3[j+1].kalori=keykal;
		suplier3[j+1].lemak=keylem;
		suplier3[j+1].harga = keyhar;
		strcpy(suplier3[j+1].migor, key2);
	}
	output3(z, suplier3, hasil3);//keluaran
}

void output1(int n, kangminyak suplier1[n], double hasil[n]){
	int i;
	printf("Supplier 1:\n");
	for(i = 0; i < n; i++)
	{
		printf("%s %.lf %.lf %.lf - %.2lf\n", suplier1[i].migor, suplier1[i].kalori, suplier1[i].lemak, suplier1[i].harga, hasil[i]);//keluaran
	}
}

void output2(int m, kangminyak suplier2[m], double hasil2[m]){
	int i;
	printf("Supplier 2:\n");
	for(i = 0; i < m; i++)
	{
		printf("%s %.lf %.lf %.lf - %.2lf\n", suplier2[i].migor, suplier2[i].kalori, suplier2[i].lemak, suplier2[i].harga, hasil2[i]);//keluaran
	}
}

void output3(int z, kangminyak suplier3[z], double hasil3[z]){
	int i;
	printf("Supplier 3:\n");
	for(i = 0; i < z; i++)
	{
		printf("%s %.lf %.lf %.lf - %.2lf\n", suplier3[i].migor, suplier3[i].kalori, suplier3[i].lemak, suplier3[i].harga, hasil3[i]);//keluaran
	}
}

void selectsup1(int n, kangminyak suplier1[n], double hasil[n]){
	int i, j;
	double temp;
	double keykal;
	double keylem;
	double keyhar;
	char temp2[25];
	int min;
	//metode selection ascending durasi
	for(i = 0; i < n-1; i++){
		min=i;
		for(j = i+1; j < n; j++){
			if(hasil[min]> hasil[j]){
				min = j;
			}
		}
		temp= hasil[i];
		keykal= suplier1[i].kalori;
		keylem= suplier1[i].lemak;
		keyhar= suplier1[i].harga;
		strcpy(temp2, suplier1[i].migor);
		hasil[i]=hasil[min];
		suplier1[i].kalori= suplier1[min].kalori;
		suplier1[i].lemak= suplier1[min].lemak;
		suplier1[i].harga= suplier1[min].harga;
		strcpy(suplier1[i].migor, suplier1[min].migor);

		hasil[min]= temp;
		suplier1[min].kalori=keykal;
		suplier1[min].lemak=keylem;
		suplier1[min].harga=keyhar;
		strcpy(suplier1[min].migor, temp2);

	}
	output1(n, suplier1, hasil);//keluaran
}

void selectsup2(int m, kangminyak suplier2[m], double hasil2[m]){
	int i, j;
	double temp;
	double keykal;
	double keylem;
	double keyhar;
	char temp2[25];
	int min;
	//metode selection ascending durasi
	for(i = 0; i < m-1; i++){
		min=i;
		for(j = i+1; j < m; j++){
			if(hasil2[min]> hasil2[j]){
				min = j;
			}
		}
		temp= hasil2[i];
		keykal= suplier2[i].kalori;
		keylem= suplier2[i].lemak;
		keyhar= suplier2[i].harga;
		strcpy(temp2, suplier2[i].migor);
		hasil2[i]=hasil2[min];
		suplier2[i].kalori= suplier2[min].kalori;
		suplier2[i].lemak= suplier2[min].lemak;
		suplier2[i].harga= suplier2[min].harga;
		strcpy(suplier2[i].migor, suplier2[min].migor);
		hasil2[min]= temp;
		suplier2[min].kalori=keykal;
		suplier2[min].lemak=keylem;
		suplier2[min].harga=keyhar;
		strcpy(suplier2[min].migor, temp2);

	}
	output2(m, suplier2, hasil2);//keluaran
}

void selectsup3(int z, kangminyak suplier3[z], double hasil3[z]){
	int i, j;
	double temp;
	double keykal;
	double keylem;
	double keyhar;
	char temp2[25];
	int min;
	//metode selection ascending durasi
	for(i = 0; i < z-1; i++){
		min=i;
		for(j = i+1; j < z; j++){
			if(hasil3[min]> hasil3[j]){
				min = j;
			}
		}
		temp= hasil3[i];
		keykal= suplier3[i].kalori;
		keylem= suplier3[i].lemak;
		keyhar= suplier3[i].harga;
		strcpy(temp2, suplier3[i].migor);
		hasil3[i]=hasil3[min];
		suplier3[i].kalori= suplier3[min].kalori;
		suplier3[i].lemak= suplier3[min].lemak;
		suplier3[i].harga= suplier3[min].harga;
		strcpy(suplier3[i].migor, suplier3[min].migor);
		hasil3[min]= temp;
		suplier3[min].kalori=keykal;
		suplier3[min].lemak=keylem;
		suplier3[min].harga=keyhar;
		strcpy(suplier3[min].migor, temp2);

	}
	output3(z, suplier3, hasil3);//keluaran
}


void bubblesup1(int n, kangminyak suplier1[n], double hasil[n])
{
	int i;
	int swap;
	double keykal;
	double keylem;
	double keyhar;
    char temp[50];
    double temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (n - 1); i++){
            if((hasil[i] > hasil[i + 1]))
            {
            	temphasil= hasil[i];
            	hasil[i]= hasil[i+1];
            	hasil[i+1]= temphasil;

            	keykal=suplier1[i].kalori;
            	suplier1[i].kalori= suplier1[i+1].kalori;
            	suplier1[i+1].kalori=keykal;

            	keylem=suplier1[i].lemak;
            	suplier1[i].lemak= suplier1[i+1].lemak;
            	suplier1[i+1].lemak= keylem;

            	keyhar=suplier1[i].harga;
            	suplier1[i].harga=suplier1[i+1].harga;
            	suplier1[i+1].harga=keyhar;


                strcpy(temp, suplier1[i].migor);
                strcpy(suplier1[i].migor, suplier1[i+1].migor);
                strcpy(suplier1[i+1].migor, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	output1(n, suplier1, hasil);//memanggil keluaran
}

void bubblesup2(int m, kangminyak suplier2[m], double hasil2[m])
{
	int i;
	int swap;
	double keykal;
	double keylem;
	double keyhar;
    char temp[50];
    double temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (m - 1); i++){
            if((hasil2[i] > hasil2[i + 1]))
            {
            	temphasil= hasil2[i];
            	hasil2[i]= hasil2[i+1];
            	hasil2[i+1]= temphasil;

            	keykal=suplier2[i].kalori;
            	suplier2[i].kalori= suplier2[i+1].kalori;
            	suplier2[i+1].kalori=keykal;

            	keylem=suplier2[i].lemak;
            	suplier2[i].lemak= suplier2[i+1].lemak;
            	suplier2[i+1].lemak= keylem;

            	keyhar=suplier2[i].harga;
            	suplier2[i].harga=suplier2[i+1].harga;
            	suplier2[i+1].harga=keyhar;


                strcpy(temp, suplier2[i].migor);
                strcpy(suplier2[i].migor, suplier2[i+1].migor);
                strcpy(suplier2[i+1].migor, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	output2(m, suplier2, hasil2);//memanggil keluaran
}

void bubblesup3(int z, kangminyak suplier3[z], double hasil3[z])
{
	int i;
	int swap;
	double keykal;
	double keylem;
	double keyhar;
    char temp[50];
    double temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (z - 1); i++){
            if((hasil3[i] > hasil3[i + 1]))
            {
            	temphasil= hasil3[i];
            	hasil3[i]= hasil3[i+1];
            	hasil3[i+1]= temphasil;

            	keykal=suplier3[i].kalori;
            	suplier3[i].kalori= suplier3[i+1].kalori;
            	suplier3[i+1].kalori=keykal;

            	keylem=suplier3[i].lemak;
            	suplier3[i].lemak= suplier3[i+1].lemak;
            	suplier3[i+1].lemak= keylem;

            	keyhar=suplier3[i].harga;
            	suplier3[i].harga=suplier3[i+1].harga;
            	suplier3[i+1].harga=keyhar;


                strcpy(temp, suplier3[i].migor);
                strcpy(suplier3[i].migor, suplier3[i+1].migor);
                strcpy(suplier3[i+1].migor, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	output3(z, suplier3, hasil3);//memanggil keluaran
}


void quicksup1(int n, kangminyak suplier1[n], int left, int right, double hasil[n])
{
	int i,j;
    char temp[50];
    double keykal;
	double keylem;
	double keyhar;
    double temphasil;
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

           		keykal=suplier1[i].kalori;
            	suplier1[i].kalori= suplier1[j].kalori;
            	suplier1[j].kalori=keykal;

            	keylem=suplier1[i].lemak;
            	suplier1[i].lemak= suplier1[j].lemak;
            	suplier1[j].lemak= keylem;

            	keyhar=suplier1[i].harga;
            	suplier1[i].harga=suplier1[j].harga;
            	suplier1[j].harga=keyhar;



           	strcpy(temp, suplier1[i].migor);
            strcpy(suplier1[i].migor, suplier1[j].migor);
       	    strcpy(suplier1[j].migor, temp);


			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quicksup1(n,suplier1,left,j, hasil);
		}
		if((i<right)&&(i>left))
		{
			quicksup1(n,suplier1,i,right, hasil);
		}

}

void quicksup2(int m, kangminyak suplier2[m], int left, int right, double hasil2[m])
{
	int i,j;
    char temp[50];
    double keykal;
	double keylem;
	double keyhar;
    double temphasil;
	i=left;
	j=right;
	//metode quick ascending
	double pivot = hasil2[(left+right)/2];
	do{
		while((hasil2[i]<pivot)&&(i<=j))
		{
			i++;
		}
		while((hasil2[j]>pivot)&&(i<=j))
		{
			j--;
		}
		if(i<j)
		{
			temphasil= hasil2[i];
            hasil2[i]= hasil2[j];
           	hasil2[j]= temphasil;

           		keykal=suplier2[i].kalori;
            	suplier2[i].kalori= suplier2[j].kalori;
            	suplier2[j].kalori=keykal;

            	keylem=suplier2[i].lemak;
            	suplier2[i].lemak= suplier2[j].lemak;
            	suplier2[j].lemak= keylem;

            	keyhar=suplier2[i].harga;
            	suplier2[i].harga=suplier2[j].harga;
            	suplier2[j].harga=keyhar;

           	strcpy(temp, suplier2[i].migor);
            strcpy(suplier2[i].migor, suplier2[j].migor);
       	    strcpy(suplier2[j].migor, temp);


			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quicksup2(m,suplier2,left,j, hasil2);
		}
		if((i<right)&&(i>left))
		{
			quicksup2(m,suplier2,i,right, hasil2);
		}

}

void quicksup3(int z, kangminyak suplier3[z], int left, int right, double hasil3[z])
{
	int i,j;
    char temp[50];
    double keykal;
	double keylem;
	double keyhar;
    double temphasil;
	i=left;
	j=right;
	//metode quick ascending
	double pivot = hasil3[(left+right)/2];
	do{
		while((hasil3[i]<pivot)&&(i<=j))
		{
			i++;
		}
		while((hasil3[j]>pivot)&&(i<=j))
		{
			j--;
		}
		if(i<j)
		{
			temphasil= hasil3[i];
            hasil3[i]= hasil3[j];
           	hasil3[j]= temphasil;

           		keykal=suplier3[i].kalori;
            	suplier3[i].kalori= suplier3[j].kalori;
            	suplier3[j].kalori=keykal;

            	keylem=suplier3[i].lemak;
            	suplier3[i].lemak= suplier3[j].lemak;
            	suplier3[j].lemak= keylem;

            	keyhar=suplier3[i].harga;
            	suplier3[i].harga=suplier3[j].harga;
            	suplier3[j].harga=keyhar;

           	strcpy(temp, suplier3[i].migor);
            strcpy(suplier3[i].migor, suplier3[j].migor);
       	    strcpy(suplier3[j].migor, temp);


			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quicksup3(z,suplier3,left,j, hasil3);
		}
		if((i<right)&&(i>left))
		{
			quicksup3(z,suplier3,i,right, hasil3);
		}

}


// void merge_terurut(int n, int m, kangminyak suplier1[n], kangminyak suplier2[m]){
// 	i = 0, j = 0;
// 	int count = 0, remainder;

// 	while((i < n) && (j < m)){
// 		if(strcmp(arr1[i], arr2[j]) < 0){
// 			strcpy(arr3[count], arr1[i]);
// 			i++, count++;
// 		}else if(strcmp(arr1[i], arr2[j]) > 0){
// 			strcpy(arr3[count], arr2[j]);
// 			j++, count++;
// 		}else{
// 			strcpy(arr3[count], arr1[i]);
// 			i++, count++;

// 			strcpy(arr3[count], arr2[j]);
// 			j++, count++;
// 		}
// 	}

// 	if(i < n){
// 		for(remainder = i; remainder < n; remainder++){
// 			strcpy(arr3[count], arr1[remainder]);
// 			count++;
// 		}
// 	}

// 	if(j < m){
// 		for(remainder = j; remainder < m; remainder++){
// 			strcpy(arr3[count], arr2[remainder]);
// 			count++;
// 		}
// 	}
// }