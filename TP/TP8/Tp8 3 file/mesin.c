/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP8 Alpro2 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int read(int k, char string[101], code data2[3][51])
{
    int n = 0;
    FILE *fdata;
    // membuka file status read
    fdata = fopen(string, "r");
    fscanf(fdata, "%s %s", data2[k][n].str1, data2[k][n].str2);
    // tahap membaca file
    while (strcmp(data2[k][n].str1, "####") != 0)
    {
        n++;
        fscanf(fdata, "%s %s", data2[k][n].str1, data2[k][n].str2);
    }
    fclose(fdata);

    return n;
}

void search(int z, code data2[][51], int m, char neangan2[50])
{
    int i = 0;
    int k = 0;
    int found = 0;
    // kode untuk melakukan search metode binary
    while ((i <= m) && (found == 0))
    {
        k = (int)((i + m) / 2);
        if (strcmp(data2[z][k].str1, neangan2) == 0)
        {
            printf("%s\n", data2[z][k].str2);
            found = 1;
        }
        else
        {
            if (strcmp(data2[z][k].str1, neangan2) > 0)
            {
                m = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }
    }
}

void list(film data[51], code data2[3][51])
{
    int i, j, n = 0;
    FILE *ffilm;
    // membuka file status read
    ffilm = fopen("ListFilm.dat", "r");
    fscanf(ffilm, "%s %s %s %s", data[n].judul, data[n].sutradara, data[n].genre, data[n].bioskop);
    // tahap membaca file
    while (strcmp(data[n].judul, "####") != 0)
    {
        n++;
        fscanf(ffilm, "%s %s %s %s", data[n].judul, data[n].sutradara, data[n].genre, data[n].bioskop);
    }
    fclose(ffilm);

    // membaca file
    int m = read(0, "Sutradara.dat", data2);
    int k = read(1, "Genre.dat", data2);
    int p = read(2, "Bioskop.dat", data2);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (strcmp(data2[0][j].str1, data[i].sutradara) == 0)
            {
                strcpy(data[i].sutradara, data2[0][j].str2);
            }
        }
        for (j = 0; j < k; j++)
        {
            if (strcmp(data2[1][j].str1, data[i].genre) == 0)
            {
                strcpy(data[i].genre, data2[1][j].str2);
            }
        }
        for (j = 0; j < p; j++)
        {
            if (strcmp(data2[2][j].str1, data[i].bioskop) == 0)
            {
                strcpy(data[i].bioskop, data2[2][j].str2);
            }
        }
        printf("%s %s %s %s\n", data[i].judul, data[i].sutradara, data[i].genre, data[i].bioskop);
    }

    ffilm = fopen("ListFilmfinal.dat", "w");
    for (i = 0; i < n; i++)
    {
        fprintf(ffilm, "%s %s %s %s\n", data[i].judul, data[i].sutradara, data[i].genre, data[i].bioskop);
    }
    fprintf(ffilm, "#### #### ####\n");
    fclose(ffilm);
}

void menumencari(film data[51], code data2[3][51])
{
    int i, j, n = 0;
    FILE *ffilm;
    // membuka file status read
    ffilm = fopen("ListFilm.dat", "r");
    fscanf(ffilm, "%s %s %s %s", data[n].judul, data[n].sutradara, data[n].genre, data[n].bioskop);
    // tahap membaca file
    while (strcmp(data[n].judul, "####") != 0)
    {
        n++;
        fscanf(ffilm, "%s %s %s %s", data[n].judul, data[n].sutradara, data[n].genre, data[n].bioskop);
    }
    fclose(ffilm);

    // membaca file
    int m = read(0, "Sutradara.dat", data2);
    int k = read(1, "Genre.dat", data2);
    int p = read(2, "Bioskop.dat", data2);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (strcmp(data2[0][j].str1, data[i].sutradara) == 0)
            {
                strcpy(data[i].sutradara, data2[0][j].str2);
            }
        }
        for (j = 0; j < k; j++)
        {
            if (strcmp(data2[1][j].str1, data[i].genre) == 0)
            {
                strcpy(data[i].genre, data2[1][j].str2);
            }
        }
        for (j = 0; j < p; j++)
        {
            if (strcmp(data2[2][j].str1, data[i].bioskop) == 0)
            {
                strcpy(data[i].bioskop, data2[2][j].str2);
            }
        }
    }
    char cari[50];  // variabel untuk search sesuai kategori
    char cari2[50]; // variabel untuk search sesuai kode
    scanf("%s", &cari);
    printf("Masukkan id nya!\n");
    scanf("%s", &cari2);
    if (strcmp(cari, "sutradara") == 0)
    {

        search(0, data2, m, cari2);
    }
    else if (strcmp(cari, "genre") == 0)
    {

        search(1, data2, k, cari2);
    }
    else if (strcmp(cari, "bioskop") == 0)
    {

        search(2, data2, p, cari2);
    }
}
