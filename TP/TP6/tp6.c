/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP6 Alpro2 (MBL22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char snack[50];
	int harga;
	double berat;
}makanan;

void insertaniasc(int n, makanan ani[n], int hasil[n]);
void inserttoniasc(int m, makanan toni[m], int hasil2[m]);
void insertbudiasc(int z, makanan budi[z], int hasil3[z]);
void insertanidesc(int n, makanan ani[n], int hasil[n]);
void inserttonidesc(int m, makanan toni[m], int hasil2[m]);
void insertbudidesc(int z, makanan budi[z], int hasil3[z]);
void selectaniasc(int n, makanan ani[n], int hasil[n]);
void selecttoniasc(int m, makanan toni[m], int hasil2[m]);
void selectbudiasc(int z, makanan budi[z], int hasil3[z]);
void selectanidesc(int n, makanan ani[n], int hasil[n]);
void selecttonidesc(int m, makanan toni[m], int hasil2[m]);
void selectbudidesc(int z, makanan budi[z], int hasil3[z]);
void bubbleaniasc(int n, makanan ani[n], int hasil[n]);
void bubbletoniasc(int m, makanan toni[m], int hasil2[m]);
void bubblebudiasc(int z, makanan budi[z], int hasil3[z]);
void bubbleanidesc(int n, makanan ani[n], int hasil[n]);
void bubbletonidesc(int m, makanan toni[m], int hasil2[m]);
void bubblebudidesc(int z, makanan budi[z], int hasil3[z]);
void quickaniasc(int n, makanan ani[n], int left, int right, int hasil[n]);
void quicktoniasc(int m, makanan toni[m], int left, int right, int hasil2[m]);
void quickbudiasc(int z, makanan budi[z], int left, int right, int hasil3[z]);
void quickanidesc(int n, makanan ani[n], int left, int right, int hasil[n]);
void quicktonidesc(int m, makanan toni[m], int left, int right, int hasil2[m]);
void quickbudidesc(int z, makanan budi[z], int left, int right, int hasil3[z]);
void merge_terurut(int n, int hasil[], makanan ani[], int m, int hasil2[], makanan toni[], int hasil3[], makanan budi[]);
void merge_terurutdesc(int n, int hasil[], makanan ani[], int m, int hasil2[], makanan toni[], int hasil3[], makanan budi[]);
void beli(int budget,int hK123[], int n, int m , int z, makanan arr123[]);

int main()
{
	int i,j;
	int n;
	scanf("%d", &n);
	makanan ani[n];

	for(i=0; i<n; i++)
	{
		scanf("%s %d %lf", &ani[i].snack, &ani[i].harga, &ani[i].berat);
	}

	int m;
	scanf("%d", &m);

	makanan toni[m];

	for(i=0; i<m; i++)
	{
		scanf("%s %d %lf", &toni[i].snack, &toni[i].harga, &toni[i].berat);
	}

	int z;
	scanf("%d", &z);

	makanan budi[z];

	for(i=0; i<z; i++)
	{
		scanf("%s %d %lf", &budi[i].snack, &budi[i].harga, &budi[i].berat);
	}

	int budget;
	scanf("%d", &budget);

	char metode[10];
	scanf("%s", &metode);

	char sortby[10];
	scanf("%s", &sortby);

	int hasil[n];
	int hasil2[m];
	int hasil3[z];

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

	makanan arr12[n+m];
	int hasil_kali12[n+m];
	makanan arr123[n+m+z];
	int hasil_kali123[n+m+z];
	int hK123[n+m+z];

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


	printf("Daftar Snack:\n");
	printf("-------------------------------\n");
	for(i=0; i<n+m+z; i++)
	{
		printf("%s %d\n", arr123[i].snack , hK123[i]);
	}
	printf("===============================\n");
	printf("snack yang dibeli:\n");
	printf("-------------------------------\n");
	beli( budget, hK123,  n,  m ,  z, arr123);



	return 0;


}


void insertaniasc(int n, makanan ani[n], int hasil[n])
{
	int i, j;
	int key;
	char key2[25];

	for(i = 1; i < n; i++){
		key = hasil[i];
		strcpy(key2, ani[i].snack);
		j = i-1;
		while(j >= 0 && key < hasil[j]){
			hasil[j+1]= hasil[j];
			strcpy(ani[j+1].snack, ani[j].snack);
			j--;
		}
		hasil[j+1]= key;
		strcpy(ani[j+1].snack, key2);
	}
	//output1(n, ani, hasil);//keluaran
}

void inserttoniasc(int m, makanan toni[m], int hasil2[m])
{
	int i, j;
	int key;
	char key2[25];

	for(i = 1; i < m; i++){
		key = hasil2[i];
		strcpy(key2, toni[i].snack);
		j = i-1;
		while(j >= 0 && key < hasil2[j]){
			hasil2[j+1]= hasil2[j];
			strcpy(toni[j+1].snack, toni[j].snack);
			j--;
		}
		hasil2[j+1]= key;
		strcpy(toni[j+1].snack, key2);
	}
	//output2(m, toni, hasil2);//keluaran
}

void insertbudiasc(int z, makanan budi[z], int hasil3[z])
{
	int i, j;
	int key;
	char key2[25];

	for(i = 1; i < z; i++){
		key = hasil3[i];
		strcpy(key2, budi[i].snack);
		j = i-1;
		while(j >= 0 && key < hasil3[j]){
			hasil3[j+1]= hasil3[j];
			strcpy(budi[j+1].snack, budi[j].snack);
			j--;
		}
		hasil3[j+1]= key;
		strcpy(budi[j+1].snack, key2);
	}
	//output3(z, budi, hasil3);//keluaran
}


void insertanidesc(int n, makanan ani[n], int hasil[n])
{
	int i, j;
	int key;
	char key2[25];

	for(i = 1; i < n; i++){
		key = hasil[i];
		strcpy(key2, ani[i].snack);
		j = i-1;
		while(j >= 0 && key > hasil[j]){
			hasil[j+1]= hasil[j];
			strcpy(ani[j+1].snack, ani[j].snack);
			j--;
		}
		hasil[j+1]= key;
		strcpy(ani[j+1].snack, key2);
	}
	//output1(n, ani, hasil);//keluaran
}

void inserttonidesc(int m, makanan toni[m], int hasil2[m])
{
	int i, j;
	int key;
	char key2[25];

	for(i = 1; i < m; i++){
		key = hasil2[i];
		strcpy(key2, toni[i].snack);
		j = i-1;
		while(j >= 0 && key > hasil2[j]){
			hasil2[j+1]= hasil2[j];
			strcpy(toni[j+1].snack, toni[j].snack);
			j--;
		}
		hasil2[j+1]= key;
		strcpy(toni[j+1].snack, key2);
	}
	//output2(m, toni, hasil2);//keluaran
}

void insertbudidesc(int z, makanan budi[z], int hasil3[z])
{
	int i, j;
	int key;
	char key2[25];

	for(i = 1; i < z; i++){
		key = hasil3[i];
		strcpy(key2, budi[i].snack);
		j = i-1;
		while(j >= 0 && key > hasil3[j]){
			hasil3[j+1]= hasil3[j];
			strcpy(budi[j+1].snack, budi[j].snack);
			j--;
		}
		hasil3[j+1]= key;
		strcpy(budi[j+1].snack, key2);
	}
	//output3(z, budi, hasil3);//keluaran
}

void selectaniasc(int n, makanan ani[n], int hasil[n])
{
	int i, j;
	char temp[25];
	int temp2;
	int min;
	//metode selection ascending
	for(i = 0; i < n-1; i++){
		min=i;
		for(j = i+1; j < n; j++){
			if(hasil[min]> hasil[j]){
				min = j;
			}
		}
		strcpy(temp, ani[i].snack);
		temp2 = hasil[i];
		strcpy(ani[i].snack, ani[min].snack);
		hasil[i]= hasil[min];
		strcpy(ani[min].snack, temp);
		hasil[min]= temp2;
	}
	//output1(n, ani, hasil);//keluaran
}

void selecttoniasc(int m, makanan toni[m], int hasil2[m])
{
	int i, j;
	char temp[25];
	int temp2;
	int min;
	//metode selection ascending
	for(i = 0; i < m-1; i++){
		min=i;
		for(j = i+1; j < m; j++){
			if(hasil2[min]> hasil2[j]){
				min = j;
			}
		}
		strcpy(temp, toni[i].snack);
		temp2 = hasil2[i];
		strcpy(toni[i].snack, toni[min].snack);
		hasil2[i]= hasil2[min];
		strcpy(toni[min].snack, temp);
		hasil2[min]= temp2;
	}
	//output2(m, toni, hasil2);//keluaran
}

void selectbudiasc(int z, makanan budi[z], int hasil3[z])
{
	int i, j;
	char temp[25];
	int temp2;
	int min;
	//metode selection ascending
	for(i = 0; i < z-1; i++){
		min=i;
		for(j = i+1; j < z; j++){
			if(hasil3[min]> hasil3[j]){
				min = j;
			}
		}
		strcpy(temp, budi[i].snack);
		temp2 = hasil3[i];
		strcpy(budi[i].snack, budi[min].snack);
		hasil3[i]= hasil3[min];
		strcpy(budi[min].snack, temp);
		hasil3[min]= temp2;
	}
	//output3(z, budi, hasil3);//keluaran
}

void selectanidesc(int n, makanan ani[n], int hasil[n])
{
	int i, j;
	char temp[25];
	int temp2;
	int min;
	//metode selection ascending
	for(i = 0; i < n-1; i++){
		min=i;
		for(j = i+1; j < n; j++){
			if(hasil[min]< hasil[j]){
				min = j;
			}
		}
		strcpy(temp, ani[i].snack);
		temp2 = hasil[i];
		strcpy(ani[i].snack, ani[min].snack);
		hasil[i]= hasil[min];
		strcpy(ani[min].snack, temp);
		hasil[min]= temp2;
	}
	//output1(n, ani, hasil);//keluaran
}

void selecttonidesc(int m, makanan toni[m], int hasil2[m])
{
	int i, j;
	char temp[25];
	int temp2;
	int min;
	//metode selection ascending
	for(i = 0; i < m-1; i++){
		min=i;
		for(j = i+1; j < m; j++){
			if(hasil2[min]< hasil2[j]){
				min = j;
			}
		}
		strcpy(temp, toni[i].snack);
		temp2 = hasil2[i];
		strcpy(toni[i].snack, toni[min].snack);
		hasil2[i]= hasil2[min];
		strcpy(toni[min].snack, temp);
		hasil2[min]= temp2;
	}
	//output2(m, toni, hasil2);//keluaran
}

void selectbudidesc(int z, makanan budi[z], int hasil3[z])
{
	int i, j;
	char temp[25];
	int temp2;
	int min;
	//metode selection ascending
	for(i = 0; i < z-1; i++){
		min=i;
		for(j = i+1; j < z; j++){
			if(hasil3[min]< hasil3[j]){
				min = j;
			}
		}
		strcpy(temp, budi[i].snack);
		temp2 = hasil3[i];
		strcpy(budi[i].snack, budi[min].snack);
		hasil3[i]= hasil3[min];
		strcpy(budi[min].snack, temp);
		hasil3[min]= temp2;
	}
	//output3(z, budi, hasil3);//keluaran
}

void bubbleaniasc(int n, makanan ani[n], int hasil[n])
{
	int i;
	int swap;
    char temp[50];
    int temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (n - 1); i++){
            if((hasil[i] > hasil[i + 1]))
            {
            	temphasil= hasil[i];
            	hasil[i]= hasil[i+1];
            	hasil[i+1]= temphasil;

                strcpy(temp, ani[i].snack);
                strcpy(ani[i].snack, ani[i+1].snack);
                strcpy(ani[i+1].snack, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	//output1(n, ani, hasil);//memanggil keluaran
}



void bubbletoniasc(int m, makanan toni[m], int hasil2[m])
{
	int i;
	int swap;
    char temp[50];
    int temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (m - 1); i++){
            if((hasil2[i] > hasil2[i + 1]))
            {
            	temphasil= hasil2[i];
            	hasil2[i]= hasil2[i+1];
            	hasil2[i+1]= temphasil;

                strcpy(temp, toni[i].snack);
                strcpy(toni[i].snack, toni[i+1].snack);
                strcpy(toni[i+1].snack, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	//output2(m, toni, hasil2);//memanggil keluaran
}

void bubblebudiasc(int z, makanan budi[z], int hasil3[z])
{
	int i;
	int swap;
    char temp[50];
    int temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (z - 1); i++){
            if((hasil3[i] > hasil3[i + 1]))
            {
            	temphasil= hasil3[i];
            	hasil3[i]= hasil3[i+1];
            	hasil3[i+1]= temphasil;

                strcpy(temp, budi[i].snack);
                strcpy(budi[i].snack, budi[i+1].snack);
                strcpy(budi[i+1].snack, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	//output3(z, budi, hasil3);//memanggil keluaran
}

void bubbleanidesc(int n, makanan ani[n], int hasil[n])
{
	int i;
	int swap;
    char temp[50];
    int temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (n - 1); i++){
            if((hasil[i] < hasil[i + 1]))
            {
            	temphasil= hasil[i];
            	hasil[i]= hasil[i+1];
            	hasil[i+1]= temphasil;

                strcpy(temp, ani[i].snack);
                strcpy(ani[i].snack, ani[i+1].snack);
                strcpy(ani[i+1].snack, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	//output1(n, ani, hasil);//memanggil keluaran
}



void bubbletonidesc(int m, makanan toni[m], int hasil2[m])
{
	int i;
	int swap;
    char temp[50];
    int temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (m - 1); i++){
            if((hasil2[i] < hasil2[i + 1]))
            {
            	temphasil= hasil2[i];
            	hasil2[i]= hasil2[i+1];
            	hasil2[i+1]= temphasil;

                strcpy(temp, toni[i].snack);
                strcpy(toni[i].snack, toni[i+1].snack);
                strcpy(toni[i+1].snack, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	//output2(m, toni, hasil2);//memanggil keluaran
}

void bubblebudidesc(int z, makanan budi[z], int hasil3[z])
{
	int i;
	int swap;
    char temp[50];
    int temphasil;

    //metode bubble ascending
    do{
        swap = 0;

        for(i = 0; i < (z - 1); i++){
            if((hasil3[i] < hasil3[i + 1]))
            {
            	temphasil= hasil3[i];
            	hasil3[i]= hasil3[i+1];
            	hasil3[i+1]= temphasil;

                strcpy(temp, budi[i].snack);
                strcpy(budi[i].snack, budi[i+1].snack);
                strcpy(budi[i+1].snack, temp);

                swap = 1;
            }
        }
    }while(swap == 1);
	//output3(z, budi, hasil3);//memanggil keluaran
}

void quickaniasc(int n, makanan ani[n], int left, int right, int hasil[n])
{
	int i,j;
    char temp[50];
	int temp2;
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
			temp2= hasil[i];
            hasil[i]= hasil[j];
           	hasil[j]= temp2;

           	strcpy(temp, ani[i].snack);
            strcpy(ani[i].snack, ani[j].snack);
       	    strcpy(ani[j].snack, temp);

			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quickaniasc(n,ani,left,j, hasil);
		}
		if((i<right)&&(i>left))
		{
			quickaniasc(n,ani,i,right, hasil);
		}

}

void quicktoniasc(int m, makanan toni[m], int left, int right, int hasil2[m])
{
	int i,j;
    char temp[50];
	int temp2;
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
			temp2= hasil2[i];
            hasil2[i]= hasil2[j];
           	hasil2[j]= temp2;

           	strcpy(temp, toni[i].snack);
            strcpy(toni[i].snack, toni[j].snack);
       	    strcpy(toni[j].snack, temp);

			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quicktoniasc(m,toni,left,j, hasil2);
		}
		if((i<right)&&(i>left))
		{
			quicktoniasc(m,toni,i,right, hasil2);
		}

}

void quickbudiasc(int z, makanan budi[z], int left, int right, int hasil3[z])
{
	int i,j;
    char temp[50];
	int temp2;
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
			temp2= hasil3[i];
            hasil3[i]= hasil3[j];
           	hasil3[j]= temp2;

           	strcpy(temp, budi[i].snack);
            strcpy(budi[i].snack, budi[j].snack);
       	    strcpy(budi[j].snack, temp);

			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quickbudiasc(z,budi,left,j, hasil3);
		}
		if((i<right)&&(i>left))
		{
			quickbudiasc(z,budi,i,right, hasil3);
		}

}

void quickanidesc(int n, makanan ani[n], int left, int right, int hasil[n])
{
	int i,j;
    char temp[50];
	int temp2;
	i=left;
	j=right;
	//metode quick ascending
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
			temp2= hasil[i];
            hasil[i]= hasil[j];
           	hasil[j]= temp2;

           	strcpy(temp, ani[i].snack);
            strcpy(ani[i].snack, ani[j].snack);
       	    strcpy(ani[j].snack, temp);

			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quickanidesc(n,ani,left,j, hasil);
		}
		if((i<right)&&(i>left))
		{
			quickanidesc(n,ani,i,right, hasil);
		}

}

void quicktonidesc(int m, makanan toni[m], int left, int right, int hasil2[m])
{
	int i,j;
    char temp[50];
	int temp2;
	i=left;
	j=right;
	//metode quick ascending
	double pivot = hasil2[(left+right)/2];
	do{
		while((hasil2[i]>pivot)&&(i<=j))
		{
			i++;
		}
		while((hasil2[j]<pivot)&&(i<=j))
		{
			j--;
		}
		if(i<j)
		{
			temp2= hasil2[i];
            hasil2[i]= hasil2[j];
           	hasil2[j]= temp2;

           	strcpy(temp, toni[i].snack);
            strcpy(toni[i].snack, toni[j].snack);
       	    strcpy(toni[j].snack, temp);

			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quicktonidesc(m,toni,left,j, hasil2);
		}
		if((i<right)&&(i>left))
		{
			quicktonidesc(m,toni,i,right, hasil2);
		}

}

void quickbudidesc(int z, makanan budi[z], int left, int right, int hasil3[z])
{
	int i,j;
    char temp[50];
	int temp2;
	i=left;
	j=right;
	//metode quick ascending
	double pivot = hasil3[(left+right)/2];
	do{
		while((hasil3[i]>pivot)&&(i<=j))
		{
			i++;
		}
		while((hasil3[j]<pivot)&&(i<=j))
		{
			j--;
		}
		if(i<j)
		{
			temp2= hasil3[i];
            hasil3[i]= hasil3[j];
           	hasil3[j]= temp2;

           	strcpy(temp, budi[i].snack);
            strcpy(budi[i].snack, budi[j].snack);
       	    strcpy(budi[j].snack, temp);

			i++;
			j--;
		}
	}while(i<j);

		if((left<j)&&(j<right))
		{
			quickbudidesc(z,budi,left,j, hasil3);
		}
		if((i<right)&&(i>left))
		{
			quickbudidesc(z,budi,i,right, hasil3);
		}

}

// void output1(int n, makanan ani[n], int hasil[n]){
// 	int i;

// 	for(i = 0; i < n; i++)
// 	{
// 		printf("%s %.d\n", ani[i].snack, hasil[i]);//keluaran
// 	}
// }

// void output2(int m, makanan toni[m], int hasil2[m]){
// 	int i;

// 	for(i = 0; i < m; i++)
// 	{
// 		printf("%s %d\n", toni[i].snack, hasil2[i]);//keluaran
// 	}
// }

// void output3(int z, makanan budi[z], int hasil3[z]){
// 	int i;

// 	for(i = 0; i < z; i++)
// 	{
// 		printf("%s %d\n", budi[i].snack, hasil3[i]);//keluaran
// 	}
// }


void merge_terurut(int n, int hasil[], makanan ani[], int m, int hasil2[], makanan toni[], int hasil3[], makanan budi[])
{
   int i = 0, j = 0;
   int hitung = 0, temp;

   while((i < n) && (j < m)){
      if(hasil[i] < hasil2[j]){
         hasil3[hitung] = hasil[i];

         strcpy(budi[hitung].snack, ani[i].snack);
         
         i++, hitung++;
      }else if(hasil[i] > hasil2[j]){
         hasil3[hitung] = hasil2[j];

         strcpy(budi[hitung].snack, toni[j].snack);
         
         j++, hitung++;
      }else{
         hasil3[hitung] = hasil[i];

         strcpy(budi[hitung].snack, ani[i].snack);
         
         i++, hitung++;

         hasil3[hitung] = hasil2[j];

         strcpy(budi[hitung].snack, toni[j].snack);
         
         j++, hitung++;
      }
   }

   if(i < n){
      for(temp = i; temp < n; temp++){
         hasil3[hitung] = hasil[temp];

         strcpy(budi[hitung].snack, ani[temp].snack);
         
         hitung++;
      }
   }

   if(j < m){
      for(temp = j; temp < m; temp++){
         hasil3[hitung] = hasil2[temp];

         strcpy(budi[hitung].snack, toni[temp].snack);
         
         hitung++;
      }
   }
}

void merge_terurutdesc(int n, int hasil[], makanan ani[], int m, int hasil2[], makanan toni[], int hasil3[], makanan budi[])
{
   int i = 0, j = 0;
   int hitung = 0, temp;

   while((i < n) && (j < m)){
      if(hasil[i] > hasil2[j]){
         hasil3[hitung] = hasil[i];

         strcpy(budi[hitung].snack, ani[i].snack);
         
         i++, hitung++;
      }else if(hasil[i] < hasil2[j]){
         hasil3[hitung] = hasil2[j];

         strcpy(budi[hitung].snack, toni[j].snack);
         
         j++, hitung++;
      }else{
         hasil3[hitung] = hasil[i];

         strcpy(budi[hitung].snack, ani[i].snack);
         
         i++, hitung++;

         hasil3[hitung] = hasil2[j];

         strcpy(budi[hitung].snack, toni[j].snack);
         
         j++, hitung++;
      }
   }

   if(i < n){
      for(temp = i; temp < n; temp++){
         hasil3[hitung] = hasil[temp];

         strcpy(budi[hitung].snack, ani[temp].snack);
         
         hitung++;
      }
   }

   if(j < m){
      for(temp = j; temp < m; temp++){
         hasil3[hitung] = hasil2[temp];

         strcpy(budi[hitung].snack, toni[temp].snack);
         
         hitung++;
      }
   }
}

void beli(int budget,int hK123[], int n, int m , int z, makanan arr123[])
{
	int i;
	int temp = 0 ;
	int total = 0; 
	int sisabudget=0;
	temp = budget;
	if(budget>hK123[i])
	{
	i=0;
	while(hK123[i] <=temp && i<n+m+z)
	{
	    temp -= hK123[i];
        total += hK123[i];
		printf("%s %d\n", arr123[i].snack, hK123[i]);
		i++;
	}
	}else if(budget<hK123[i])
	{
		printf("tidak ada snack yang dibeli\n");
	}

	printf("===============================\n");

	sisabudget = budget-total;

	printf("total pengeluaran : Rp. %d\n", total);
	printf("sisa budget       : Rp. %d\n", sisabudget);
	printf("===============================\n");

}
