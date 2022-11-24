/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Alpro2 () dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/


#include <stdio.h>

void operasi(int baris, int kolom, int matriks[baris][kolom], int refleks[baris][kolom], int transpose[kolom][baris], int rotasi[kolom][baris]);

int main(){
    int i,j,k;
    int baris, kolom;
    int jumputer;


    scanf("%d\n %d", &baris, &kolom);

    int matriks[baris][kolom];
    int refleks[baris][kolom];
    int transpose[kolom][baris];
    int rotasi[kolom][baris];

    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }

operasi(baris,  kolom,  matriks,  refleks, transpose, rotasi);




    return 0;
}

void operasi(int baris, int kolom, int matriks[baris][kolom], int refleks[baris][kolom], int transpose[kolom][baris], int rotasi[kolom][baris])
{
    int i,j,jumputer;
    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            if(i==0){
            refleks[baris-1][j]= matriks[i][j];
            }else if(i==baris-1)
            {
                refleks[0][j]= matriks[i][j];
            }else{
                refleks[i][j]=matriks[i][j];
            }

        }
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



    printf("\n");
    int hasil=0;
    //kondisi jika baris > kolom, baris<kolom dan baris == kolom
    for(i=0; i<kolom; i++)
    {
        for(j=baris-1; j<baris; j++)
        {
            hasil += transpose[i][j];
        }
    }

    jumputer = hasil % 4;


    if(hasil % 2 == 0 )
    {

        if(jumputer==0)
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

        }else if(jumputer==2)
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





    }else if(hasil %2 != 0)
    {

        if(jumputer == 3)
        {
            if(baris == kolom)
            {
                // kondisi jika baris == kolom, puter kanan, transpose
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
        }else if(jumputer==1)
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
    int keputusan =0;

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





    if(keputusan == baris*kolom)
    {
        printf("Putar lagi besok!\n");
    }else if(jumputer==1)
    {
        printf("Putar lagi besok!\n");
    }else if(jumputer==3)
    {
        printf("Cukup! Aku pusing!\n");
    }else if(keputusan!= baris*kolom){
        printf("Cukup! Aku pusing!\n");
    }








    //printf("\nhasil tambah: %d", hasil);
    //printf("\nkeputusan :%d", keputusan);
}
