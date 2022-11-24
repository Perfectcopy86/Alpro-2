/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Alpro2 (MPP22) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"



void operasi(int baris, int kolom, int matriks[baris][kolom], int refleks[baris][kolom], int transpose[kolom][baris], int rotasi[kolom][baris])
{
    int i,j,k,jumputer;
    //kode untuk merefleksikan matriks ke bawah
    k=0;
    for(i=baris-1; i>=0; i--)
    {

        for(j=0; j<kolom; j++)
        {
            refleks[k][j]= matriks[i][j];

        }
        k++;
    }
    // printf("\nhasil refleksi\n");
    // for(i=0; i<baris; i++)
    // {
    //     for(j=0; j<kolom; j++)
    //     {
    //         printf("%d ", refleks[i][j]);
    //     }
    //     printf("\n");
    // }


    //kode untuk mentransposekan dari hasil refleksi
    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            transpose[j][i]= refleks[i][j];
        }
    }

    //  printf("\nhasil transpose\n");
    // for(i=0; i<kolom; i++)
    // {
    //     for(j=0; j<baris; j++)
    //     {
    //         printf("%d ", transpose[i][j]);
    //     }
    //     printf("\n");
    // }



    //printf("\n");
    int hasil=0;
    //kode menampung hasil penjumlahan dari kolom terakhir
    for(i=0; i<kolom; i++)
    {
        for(j=baris-1; j<baris; j++)
        {
            hasil += transpose[i][j];
        }
    }

    jumputer = hasil % 4;//rumus untuk menentukan jumlah putaran

    //jika hasil kolom yg dijumlahkan genap
    if(hasil % 2 == 0 )
    {

        if(jumputer==0)//tidak ada putaran
        {
            for(i=0; i<kolom; i++)
            {
                for(j=0; j<baris; j++)
                {
                    if(j<kolom-1)
                {
                    rotasi[i][j]=transpose[i][j];
                    printf("%d ", rotasi[i][j]);//print karakter dengan spasi
                }else if(j==kolom-1)
                {
                    rotasi[i][j]=transpose[i][j];
                    printf("%d", rotasi[i][j]);//print karakter tanpa spasi
                }
                }
                printf("\n");
            }

        }else if(jumputer==2)//putaran ke kanan sebanyak 2 kali
         {
            if( baris == kolom)
            {
                for(i=baris-1; i>=0; i--)
                {
                    for(j=kolom-1; j>=0; j--)
                    {
                        if(j>=1)
                        {
                            rotasi[i][j]=transpose[i][j];
                            printf("%d ", rotasi[i][j]);//print karakter dengan spasi
                        }else
                        {
                            rotasi[i][j]=transpose[i][j];
                            printf("%d", rotasi[i][j]);//print karakter tanpa spasi
                        }
                    }
                    printf("\n");
                }
            }else if(baris<kolom)
            {
                for(i=kolom-1; i>=0; i--)
                {
                    for(j=baris-1; j>=0; j--)
                    {
                        if(j>=1)
                        {
                            rotasi[i][j]=transpose[i][j];
                            printf("%d ", rotasi[i][j]);//print karakter dengan spasi
                        }else
                        {
                            rotasi[i][j]=transpose[i][j];
                            printf("%d", rotasi[i][j]);//print karakter tanpa spasi
                        }
                    }
                    printf("\n");
                }
            }else if(baris>kolom)
            {
                for(i=kolom-1; i>=0; i--)
                {
                    for(j=baris-1; j>=0; j--)
                    {
                        if(j>=1)
                        {
                            rotasi[i][j]=transpose[i][j];
                            printf("%d ", rotasi[i][j]);//print karakter dengan spasi
                        }else
                        {
                            rotasi[i][j]=transpose[i][j];
                            printf("%d", rotasi[i][j]);//print karakter tanpa spasi
                        }
                    }
                    printf("\n");
                }
            }
         }





    }else if(hasil %2 != 0)//jika hasil kolom yg dijumlahkan ganjil
    {

        if(jumputer == 3)//putaran sebanyak 3 kali ke kiri
        {
            if(baris == kolom)
            {
                
                for(i=0; i<kolom; i++)
                {
                    for(j=baris-1; j>=0; j--)
                {
                    if(j>=1)
                {
                    rotasi[j][i]=transpose[j][i];
                    printf("%d ", rotasi[j][i]);//print karakter dengan spasi
                }else
                {
                    rotasi[j][i]=transpose[j][i];
                    printf("%d", rotasi[j][i]);//print karakter tanpa spasi
                }

                }
                printf("\n");
                }
            }else if(baris <kolom)
            {
                for(i=0; i<baris; i++)
                {
                    for(j=kolom-1; j>=0; j--)
                    {
                    if(j>=1)
                {
                    rotasi[j][i]=transpose[j][i];
                    printf("%d ", rotasi[j][i]);//print karakter dengan spasi
                }else
                {
                    rotasi[j][i]=transpose[j][i];
                    printf("%d", rotasi[j][i]);//print karakter tanpa spasi
                }

                }
                printf("\n");
                }
            }else if(baris>kolom)
            {
                for(i=0; i<baris; i++)
                {
                    for(j=kolom-1; j>=0; j--)
                    {
                    if(j>=1)
                    {
                        rotasi[j][i]=transpose[j][i];
                    printf("%d ", rotasi[j][i]);//print karakter dengan spasi
                    }else
                    {
                        rotasi[j][i]=transpose[j][i];
                    printf("%d", rotasi[j][i]);//print karakter tanpa spasi
                    }

                }
                printf("\n");
                }

            }
        }else if(jumputer==1)//putaran sebanyak 1 kali ke kiri
        {
            if(baris==kolom)
            {
                for(i=baris-1; i>=0; i--)
                {
                    for(j=0; j<=kolom-1; j++)
                    {
                    if(j<kolom-1)
                    {
                        rotasi[j][i]=transpose[j][i];
                    printf("%d ", rotasi[j][i]);//print karakter dengan spasi
                    }else
                    {
                        rotasi[j][i]=transpose[j][i];
                    printf("%d", rotasi[j][i]);//print karakter tanpa spasi
                    }
                    }
                printf("\n");
                }
            }else if(baris<kolom)
            {
                for(i=baris-1; i>=0; i--)
                {
                    for(j=0; j<kolom; j++)
                    {
                        if(j<kolom-1)
                        {
                            rotasi[j][i]=transpose[j][i];
                            printf("%d ", rotasi[j][i]);//print karakter dengan spasi
                        }else
                        {
                            rotasi[j][i]=transpose[j][i];
                            printf("%d", rotasi[j][i]);//print karakter tanpa spasi
                        }
                    }
                    printf("\n");
                }
            }else if(baris>kolom)
            {
                for(i=baris-1; i>=0; i--)
                {
                    for(j=0; j<kolom; j++)
                    {
                       if(j<kolom-1)
                        {
                            rotasi[j][i]=transpose[j][i];
                            printf("%d ", rotasi[j][i]);//print karakter dengan spasi
                        }else
                        {
                            rotasi[j][i]=transpose[j][i];
                            printf("%d", rotasi[j][i]);//print karakter tanpa spasi
                        }
                    }
                    printf("\n");
                }

            }
        }
    }
    int keputusan =0;/*untuk menghitung jika putaran sebanyak 2 atau 0 kali maka akan dicocokan dengan matriks awal,
     jika hasil dari keputusan sama dengan baris dikali kolom maka fix tidak ada perubahan*/

for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            if(jumputer==0)
            {
                if(matriks[i][j]==rotasi[i][j])
                {
                    keputusan+= 1;
                }else if(matriks[i][j]!= rotasi[i][j]){
                    keputusan-=1;
                }
            }else if(jumputer ==2)
            {
                if(matriks[i][j]==rotasi[i][j])
                {
                    keputusan+= 1;
                }else if(matriks[i][j]!= rotasi[i][j])
                {
                    keputusan-=1;
                }
            }
        }
    }




        //nah penjelasan yg diatas dipakai disini kecuali untuk jumlah putar 1 dan 3
        if(keputusan == baris*kolom)
    {
        printf("Putar lagi besok!\n");
    }else if(jumputer==1)//karena sudah fix sama maka langsung saja
    {

            printf("Putar lagi besok!\n");

    }else if(jumputer==3)//karena sudah fix beda langsung saja juga
    {
        printf("Cukup! Aku pusing!\n");
    }else if(keputusan!= baris*kolom){
        printf("Cukup! Aku pusing!\n");
    }








    //printf("\nhasil tambah: %d", hasil);
    //printf("\nkeputusan :%d", keputusan);
}