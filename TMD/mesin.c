/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Evaluasi Tugas Masa Depan Alpro2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"
void start(char pita[]) // start pita
{
    idx = 0;
    panjangkata = 0;

    while (pita[idx] == ' ')
    {
        idx++;
    }

    while ((pita[idx] != ' ') && (eop(pita) == 0))
    {
        cc[panjangkata] = pita[idx];
        idx++;
        panjangkata++;
    }
    cc[panjangkata] = '\0';
}

void inc(char pita[]) // maju satu kata pada pita
{
    panjangkata = 0;

    while (pita[idx] == ' ')
    {
        idx++;
    }

    while ((pita[idx] != ' ') && (eop(pita) == 0))
    {
        cc[panjangkata] = pita[idx];
        idx++;
        panjangkata++;
    }
    cc[panjangkata] = '\0';
}

int getlen() // ambil panjang kata
{
    return panjangkata;
}

char *getcw() // ambil kata
{
    return cc;
}

int eop(char pita[]) // pengecekan apakah inputan selesai
{
    if (pita[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// fungsi untuk mengecek inputan dari user
int choose(char pita[])
{
    int pilih = 0;

    start(pita);

    if (strcmp(getcw(), "ENTRI") == 0)
    {
        pilih = 1; // jika kata pertama merupakan ENTRI
    }
    else if (strcmp(getcw(), "HAPUS") == 0)
    {
        pilih = 2; // jika kata pertama merupakan HAPUS
    }
    else if (strcmp(getcw(), "UBAH") == 0)
    {
        pilih = 3; // jika kata pertama merupakan UBAH
    }
    else if (strcmp(getcw(), "TAMPIL") == 0)
    {
        pilih = 4; // jika kata pertama merupakan TAMPIL
    }
    else if (strcmp(getcw(), "SELESAI") == 0)
    {
        pilih = 5;
    }
    else
    {
        pilih = 0;
        printf("Perintah gagal\n");
        printf("Silakan input ulang\n");
    }
    return pilih;
}

void entri(char pita[], f1 data[]) // prosedur untuk memasukkan data dari pita
{
    int n = 0; // variabel penyimpan banyaknya data
    int i;
    int ganda = 0; // variabel pengecek kode

    int drv = 0; // variabel penanda data yang dimasukkan adalah data untuk driver
    int tim = 0; // variabel penanda data yang dimasukkan adalah data untuk team

    // tampungan untung dipanggil dikeluaran
    char kodemasuk[50];
    char drivermasuk[50];
    char negaramasuk[50];
    char teammasuk[50];
    char mesinmasuk[50];

    inc(pita);
    // jika data yang ingin diakses adalah Driver
    if (strcmp(getcw(), "Driver") == 0)
    {
        drv = 1;
    }
    // jika data yang ingin diakses adalah Team
    else if (strcmp(getcw(), "Team") == 0)
    {
        tim = 1;
    }
    // untuk dua query selanjutnya, misal entri hapus, entri ubah dll
    else if (strcmp(getcw(), "UBAH") == 0)
    {
        ubah(pita, data);
    }
    else if (strcmp(getcw(), "HAPUS") == 0)
    {
        hapus(pita, data);
    }
    else if (strcmp(getcw(), "TAMPIL") == 0)
    {
        printf("Pilih Salah Satu Query\n");
    }
    else if (strcmp(getcw(), "ENTRI") == 0)
    {
        printf("Query Error\n");
    }
    else
    {
        printf("Query salah, perbaiki query!\n");
    }

    if (drv == 1)
    {
        // membuka file dengan mode read
        FILE *fdriver;
        fdriver = fopen("driver.dat", "r");

        // membaca file dan memindahkan data yang ada di file driver.dat ke kode program
        fscanf(fdriver, "%s %s %s", &data[n].kode, &data[n].driver, &data[n].negara);

        // memindahkan semua data dari file driver.dat ke kode program sampai menemukan EOP
        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(fdriver, "%s %s %s", &data[n].kode, &data[n].driver, &data[n].negara);
        }
        // menutup file
        fclose(fdriver);

        int cek = 0; // variabel pengecek bagian kata yang dimasukkan

        while (eop(pita) == 0)
        {
            // jika bukan kata ENTRI dan kata Driver
            if ((strcmp(getcw(), "ENTRI") != 0) && (strcmp(getcw(), "Driver") != 0))
            {
                // jika variabel cek masih bernilai 0, maka kata yang dimasukkan adalah kode
                // masukkan kode ke dalam bungkusan
                if (cek == 0 && strcmp(getcw(), "####") != 0)
                {
                    strcpy(data[n].kode, getcw());
                    strcpy(kodemasuk, getcw());
                }
                // jika variabel cek bernilai 1, maka kata yang dimasukkan adalah nama
                // masukkan nama ke dalam bungkusan
                else if (cek == 1 && strcmp(getcw(), "####") != 0)
                {
                    strcpy(data[n].driver, getcw());
                    strcpy(drivermasuk, getcw());
                }
                cek++;
            }
            inc(pita);
        }
        // jika kata terakhir langsung dimasukan saja
        strcpy(data[n].negara, getcw());
        strcpy(negaramasuk, getcw());
        n++;

        // jika cekEntri bukan 2, berarti data yang dimasukkan melebihi jumlah kolom
        // data tersebut harus dihapus
        if (cek == 2)
        {
            for (i = 0; i < n - 1; i++)
            {
                if (strcmp(data[i].kode, data[n - 1].kode) == 0)
                {
                    ganda = 1;
                }
            }
            if (ganda == 0)
            {
                printf("Query yang dijalankan adalah\n");
                printf("ENTRI Driver %s %s %s\n\n", kodemasuk, drivermasuk, negaramasuk);
                printf("Data Berhasil Masuk\n");
                printf("%s %s %s\n", kodemasuk, drivermasuk, negaramasuk);
            }
            else if (ganda == 1)
            {
                printf("Data Sudah ada\n");
                strcpy(data[n - 1].kode, "Delete");
            }
        }
        else
        {
            printf("Data tidak masuk!\n");
            strcpy(data[n - 1].kode, "Delete");
        }

        // membuka file dengan mode write
        fdriver = fopen("driver.dat", "w");
        for (i = 0; i < n; i++)
        {
            // jika kode barang bukan "Delete" (data yang dihapus)
            if (strcmp(data[i].kode, "Delete") != 0)
            {
                fprintf(fdriver, "%s %s %s\n", data[i].kode, data[i].driver, data[i].negara);
            }
        }
        // menyimpan EOF
        fprintf(fdriver, "%s %s %s\n", "####", "####", "####");
        // menutup file
        fclose(fdriver);
    }
    else if (tim == 1)
    {
        // membuka file dengan mode read
        FILE *ftim;
        ftim = fopen("tim.dat", "r");

        // membaca file dan memindahkan data yang ada di file team.dat ke kode program
        fscanf(ftim, "%s %s %s", &data[n].kode, &data[n].team, &data[n].mesin);

        // memindahkan semua data dari file team.dat ke kode program sampai menemukan EOP
        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(ftim, "%s %s %s", &data[n].kode, &data[n].team, &data[n].mesin);
        }

        // menutup file
        fclose(ftim);

        int cek = 0; // variabel pengecek bagian kata yang dimasukkan

        while (eop(pita) == 0)
        {
            if ((strcmp(getcw(), "ENTRI") != 0) && (strcmp(getcw(), "Team") != 0))
            {
                if (cek == 0 && strcmp(getcw(), "####") != 0)
                {
                    strcpy(data[n].kode, getcw());
                    strcpy(kodemasuk, getcw());
                }
                else if (cek == 1 && strcmp(getcw(), "####") != 0)
                {
                    strcpy(data[n].team, getcw());
                    strcpy(teammasuk, getcw());
                }
                cek++;
            }
            inc(pita);
        }
        strcpy(data[n].mesin, getcw());
        strcpy(mesinmasuk, getcw());
        n++;

        // jika cekEntri bukan 2, berarti data yang dimasukkan melebihi jumlah kolom
        // data tersebut harus dihapus
        if (cek == 2)
        {
            for (i = 0; i < n - 1; i++)
            {
                if (strcmp(data[i].kode, data[n - 1].kode) == 0)
                {
                    ganda = 1;
                }
            }
            if (ganda == 0)
            {
                printf("Query yang dijalankan adalah\n");
                printf("ENTRI Team %s %s %s\n\n", kodemasuk, teammasuk, mesinmasuk);
                printf("Data Berhasil Masuk\n");
                printf("%s %s %s\n", kodemasuk, teammasuk, mesinmasuk);
            }
            else if (ganda == 1)
            {
                printf("Data Sudah ada\n");
                strcpy(data[n - 1].kode, "Delete");
            }
        }
        else
        {
            printf("Data tidak masuk!\n");
            strcpy(data[n - 1].kode, "Delete");
        }

        // membuka file dengan mode write
        ftim = fopen("tim.dat", "w");
        for (i = 0; i < n; i++)
        {
            // jika kode barang bukan "Delete" (data yang dihapus)
            if (strcmp(data[i].kode, "Delete") != 0)
            {
                fprintf(ftim, "%s %s %s\n", data[i].kode, data[i].team, data[i].mesin);
            }
        }
        // menyimpan EOF
        fprintf(ftim, "%s %s %s\n", "####", "####", "####");
        // menutup file
        fclose(ftim);
    }
}

void ubah(char pita[], f1 data[])
{
    int n = 0; // variabel penyimpan banyaknya data
    int i;

    int drv = 0; // variabel penanda data yang dimasukkan adalah data untuk driver
    int tim = 0; // variabel penanda data yang dimasukkan adalah data untuk team

    // tampungan
    char kodeedit[50];
    char dataedit[50];
    char dataedit2[50];

    inc(pita);

    if (strcmp(getcw(), "Driver") == 0)
    {
        drv = 1;
    }
    else if (strcmp(getcw(), "Team") == 0)
    {
        tim = 1;
    }
    else if (strcmp(getcw(), "HAPUS") == 0)
    {
        hapus(pita, data);
    }
    else if (strcmp(getcw(), "TAMPIL") == 0)
    {
        printf("Pilih Salah Satu Query\n");
    }
    else if (strcmp(getcw(), "ENTRI") == 0)
    {
        entri(pita, data);
    }
    else if (strcmp(getcw(), "UBAH") == 0)
    {
        printf("Query Error\n");
    }
    else
    {
        printf("Query salah, perbaiki query!\n");
    }

    if (drv == 1)
    {
        // membuka file dengan mode read
        FILE *fdriver;
        fdriver = fopen("driver.dat", "r");

        // membaca fule dan memindahkan data yang ada di file driver.dat ke kode program
        fscanf(fdriver, "%s %s %s", data[n].kode, data[n].driver, data[n].negara);

        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(fdriver, "%s %s %s", data[n].kode, data[n].driver, data[n].negara);
        }
        // menutup file
        fclose(fdriver);

        int cekubah = 0; // variabel pengecek bagian kata yang dimasukkan

        // pengecekan jika kata pada pita merupakan data yang ingin diubah
        while (eop(pita) == 0)
        {
            if (strcmp(getcw(), "UBAH") != 0 && strcmp(getcw(), "Driver"))
            {
                if (cekubah == 0)
                {
                    strcpy(kodeedit, getcw());
                }
                else if (cekubah == 1)
                {
                    strcpy(dataedit, getcw());
                }
                cekubah++;
            }
            inc(pita);
        }
        strcpy(dataedit2, getcw());

        if (cekubah > 2)
        {
            printf("Query yang dimasukkan salah\n");
            strcpy(kodeedit, "Delete");
        }

        int terubah = 0;                     // variabel penanda terjadinya perubahan data jika data yang ingin diubah adalah nama barang
        if (strcmp(dataedit, "driver") == 0) // perulangan untuk mengubah driver
        {
            for (i = 0; i < n; i++)
            {
                if (strcmp(data[i].kode, kodeedit) == 0)
                {
                    strcpy(data[i].driver, dataedit2);
                    terubah = 1;
                }
            }
        }
        else if (strcmp(dataedit, "negara") == 0) // perulangan untuk mengubah negara
        {
            for (i = 0; i < n; i++)
            {
                if (strcmp(data[i].kode, kodeedit) == 0)
                {
                    strcpy(data[i].negara, dataedit2);
                    terubah = 1;
                }
            }
        }
        // jika ada data yang berhasil diubah
        if (terubah == 1)
        {
            printf("Data Berhasil Diedit\n");
        }
        else if (terubah == 0) // jika tidak ada data yang sesuai untuk diubah
        {
            printf("Data tidak berhasil diedit\n");
        }

        // membuka file dengan mode write
        fdriver = fopen("driver.dat", "w");

        for (i = 0; i < n; i++)
        {
            if (strcmp(data[i].kode, "Delete") != 0)
            {
                fprintf(fdriver, "%s %s %s\n", data[i].kode, data[i].driver, data[i].negara);
            }
        }
        // menyimpan EOF
        fprintf(fdriver, "%s %s %s\n", "####", "####", "####");
        // menutup file
        fclose(fdriver);
    }

    else if (tim == 1)
    {
        // membuka file dengan mode read
        FILE *ftim;
        ftim = fopen("tim.dat", "r");

        fscanf(ftim, "%s %s %s", data[n].kode, data[n].team, data[n].mesin);

        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(ftim, "%s %s %s", data[n].kode, data[n].team, data[n].mesin);
        }

        // menutup file
        fclose(ftim);

        int cekubah = 0; // variabel pengecek bagian kata yang dimasukkan

        // pengecekan jika kata pada pita merupakan data yang ingin diubah
        while (eop(pita) == 0)
        {
            if (strcmp(getcw(), "UBAH") != 0 && strcmp(getcw(), "Team"))
            {
                if (cekubah == 0)
                {
                    strcpy(kodeedit, getcw());
                }
                else if (cekubah == 1)
                {
                    strcpy(dataedit, getcw());
                }
                cekubah++;
            }
            inc(pita);
        }
        strcpy(dataedit2, getcw());

        if (cekubah > 2)
        {
            printf("Query yang dimasukkan salah\n");
            strcpy(kodeedit, "Delete");
        }

        int terubah = 0; // variabel penanda terjadinya perubahan data jika data yang ingin diubah adalah team
        if (strcmp(dataedit, "team") == 0)
        {
            for (i = 0; i < n; i++)
            {
                if (strcmp(data[i].kode, kodeedit) == 0)
                {
                    strcpy(data[i].team, dataedit2);
                    terubah = 1;
                }
            }
        }
        // variabel penanda terjadinya perubahan data jika data yang ingin diubah adalah mesin
        else if (strcmp(dataedit, "mesin") == 0)
        {
            for (i = 0; i < n; i++)
            {
                if (strcmp(data[i].kode, kodeedit) == 0)
                {
                    strcpy(data[i].mesin, dataedit2);
                    terubah = 1;
                }
            }
        }
        // jika ada data yang berhasil diubah
        if (terubah == 1)
        {
            printf("Data Berhasil Diedit\n");
        }
        // jika tidak ada data yang sesuai untuk diubah
        else if (terubah == 0)
        {
            printf("Data tidak berhasil diedit\n");
        }

        // membuka file dengan mode write
        ftim = fopen("driver.dat", "w");

        for (i = 0; i < n; i++)
        {
            if (strcmp(data[i].kode, "Delete") != 0)
            {
                fprintf(ftim, "%s %s %s\n", data[i].kode, data[i].team, data[i].mesin);
            }
        }
        // menyimpan EOF
        fprintf(ftim, "%s %s %s\n", "####", "####", "####");
        // menutup file
        fclose(ftim);
    }
}

void hapus(char pita[], f1 data[])
{
    int n = 0; // variabel penyimpan banyaknya data
    int i;

    // tampungan
    char kodehapus[50];
    char namahapus[50];
    char negarahapus[50];
    char teamhapus[50];
    char mesinhapus[50];

    int drv = 0; // variabel penanda data yang dimasukkan adalah data driver
    int tim = 0; // variabel penanda data yang dimasukkan adalah data team

    inc(pita);

    if (strcmp(getcw(), "Driver") == 0)
    {
        drv = 1;
    }
    else if (strcmp(getcw(), "Team") == 0)
    {
        tim = 1;
    }
    else if (strcmp(getcw(), "TAMPIL") == 0)
    {
        printf("Pilih Salah Satu Query\n");
    }
    else if (strcmp(getcw(), "ENTRI") == 0)
    {
        entri(pita, data);
    }
    else if (strcmp(getcw(), "UBAH") == 0)
    {
        ubah(pita, data);
    }

    if (drv == 1)
    {
        // membuka file dengan mode read
        FILE *fdriver;
        fdriver = fopen("driver.dat", "r");

        fscanf(fdriver, "%s %s %s", &data[n].kode, &data[n].driver, &data[n].negara);

        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(fdriver, "%s %s %s", &data[n].kode, &data[n].driver, &data[n].negara);
        }

        fclose(fdriver);

        int cekhapus = 0; // variabel pengecek bagian kata yang dimasukkan

        while (eop(pita) == 0)
        {
            if (strcmp(getcw(), "HAPUS") != 0 && strcmp(getcw(), "Driver") != 0)
            {
                cekhapus++;
            }
            inc(pita);
            strcpy(kodehapus, getcw());
            inc(pita);
            strcpy(namahapus, getcw());
            inc(pita);
        }

        strcpy(negarahapus, getcw());

        // jika cekHapus melebihi 1, berarti data yang dimasukkan salah
        // kodeHapus harus dihapus
        if (cekhapus > 1)
        {
            printf("Query yang dimasukkan salah\n");
            strcpy(kodehapus, "Delete");
        }

        int terhapus; // variabel pengecek data yang dihapus
        for (i = 0; i < n; i++)
        {
            if (strcmp(data[i].kode, kodehapus) == 0)
            {
                if (strcmp(data[i].driver, namahapus) == 0)
                {
                    if (strcmp(data[i].negara, negarahapus) == 0)
                    {
                        strcpy(data[i].kode, "Delete");
                        terhapus = 1;
                    }
                }
            }
        }

        // jika ada data yang terhapus
        if (terhapus == 1)
        {
            printf("Query yang dijalankan adalah\n");
            printf("HAPUS Driver %s %s %s\n\n", kodehapus, namahapus, negarahapus);
            printf("Data berhasil terhapus\n");
            printf("%s %s %s\n", kodehapus, namahapus, negarahapus);
        }
        else
        {
            printf("Tidak ada data yang terhapus\n");
        }

        // membuka file dengan mode write
        fdriver = fopen("driver.dat", "w");

        for (i = 0; i < n; i++)
        {
            if (strcmp(data[i].kode, "Delete") != 0)
            {
                fprintf(fdriver, "%s %s %s\n", data[i].kode, data[i].driver, data[i].negara);
            }
        }
        // menyimpan EOF
        fprintf(fdriver, "%s %s %s\n", "####", "####", "####");
        // menutup file
        fclose(fdriver);
    }
    else if (tim == 1)
    {
        // membuka file dengan mode read
        FILE *ftim;
        ftim = fopen("tim.dat", "r");

        fscanf(ftim, "%s %s %s", &data[n].kode, &data[n].team, &data[n].mesin);

        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(ftim, "%s %s %s", &data[n].kode, &data[n].team, &data[n].mesin);
        }
        // menutup file
        fclose(ftim);

        int cekhapus = 0; // variabel pengecek bagian kata yang dimasukkan

        // pengecekan jika pada pita merupakan data yang ingin dihapus
        while (eop(pita) == 0)
        {
            if (strcmp(getcw(), "HAPUS") != 0 && strcmp(getcw(), "Team") != 0)
            {
                cekhapus++;
            }
            inc(pita);
            strcpy(kodehapus, getcw());
            inc(pita);
            strcpy(teamhapus, getcw());
            inc(pita);
        }

        strcpy(mesinhapus, getcw());

        if (cekhapus > 1)
        {
            printf("Query yang dimasukkan salah\n");
            strcpy(kodehapus, "Delete");
        }

        int terhapus; // variabel pengecek data barang yang dihapus
        for (i = 0; i < n; i++)
        {
            if (strcmp(data[i].kode, kodehapus) == 0)
            {
                if (strcmp(data[i].team, teamhapus) == 0)
                {
                    if (strcmp(data[i].mesin, mesinhapus) == 0)
                    {
                        strcpy(data[i].kode, "Delete");
                        terhapus = 1;
                    }
                }
            }
        }

        // jika ada data yang terhapus
        if (terhapus == 1)
        {
            printf("Query yang dijalankan adalah\n");
            printf("HAPUS Team %s %s %s\n\n", kodehapus, teamhapus, mesinhapus);
            printf("Data berhasil terhapus\n");
            printf("%s %s %s\n", kodehapus, teamhapus, mesinhapus);
        }
        else
        {
            printf("Tidak ada data yang terhapus\n");
        }

        // membuka file dengan mode write
        ftim = fopen("tim.dat", "w");

        for (i = 0; i < n; i++)
        {
            if (strcmp(data[i].kode, "Delete") != 0)
            {
                fprintf(ftim, "%s %s %s\n", data[i].kode, data[i].team, data[i].mesin);
            }
        }

        // menyimpan EOF
        fprintf(ftim, "%s %s %s\n", "####", "####", "####");

        // menutup file
        fclose(ftim);
    }
}

void tampil(char pita[], f1 data[])
{
    int n = 0; // variabel penyimpan banyaknya data
    int i, j;
    int drv = 0;
    int tim = 0;

    inc(pita);

    if (strcmp(getcw(), "Driver") == 0)
    {
        drv = 1;
    }
    else if (strcmp(getcw(), "Team") == 0)
    {
        tim = 1;
    }
    else
    {
        printf("Query salah, perbaiki query!\n");
    }

    if (drv == 1)
    {
        FILE *fdriver;
        fdriver = fopen("driver.dat", "r");
        fscanf(fdriver, "%s %s %s", &data[n].kode, &data[n].driver, &data[n].negara);

        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(fdriver, "%s %s %s", &data[n].kode, &data[n].driver, &data[n].negara);
        }

        fclose(fdriver);

        int kodeterpanjang = 0;
        int namaterpanjang = 0;
        int kodelen = 0;

        for (i = 0; i < n; i++)
        {
            if (kodeterpanjang < strlen(data[i].kode))
            {
                kodeterpanjang = strlen(data[i].kode);
            }
        }

        for (i = 0; i < n; i++)
        {
            if (namaterpanjang < strlen(data[i].driver))
            {
                namaterpanjang = strlen(data[i].driver);
            }
        }

        printf("Data Driver\n\n");

        printf("Kode");
        for (j = 0; j < 2 + (kodeterpanjang - strlen("Kode")); j++)
        {
            printf(" ");
        }
        printf("Driver");
        for (j = 0; j < 2 + (namaterpanjang - strlen("Driver")); j++)
        {
            printf(" ");
        }
        printf("Negara\n");
        printf("+--------------------------------+\n");

        for (i = 0; i < n; i++)
        {
            printf("%s", data[i].kode);
            for (j = 0; j < 2 + (kodeterpanjang - strlen(data[i].kode)); j++)
            {
                printf(" ");
            }
            printf("%s", data[i].driver);
            for (j = 0; j < 2 + (namaterpanjang - strlen(data[i].driver)); j++)
            {
                printf(" ");
            }
            printf("%s\n", data[i].negara);
        }
        printf("+--------------------------------+\n");
    }
    else if (tim == 1)
    {
        FILE *ftim;
        ftim = fopen("tim.dat", "r");
        fscanf(ftim, "%s %s %s", &data[n].kode, &data[n].team, &data[n].mesin);

        while (strcmp(data[n].kode, "####") != 0)
        {
            n++;
            fscanf(ftim, "%s %s %s", &data[n].kode, &data[n].team, &data[n].mesin);
        }

        fclose(ftim);

        int kodeterpanjang = 0;
        int namaterpanjang = 0;

        for (i = 0; i < n; i++)
        {
            if (kodeterpanjang < strlen(data[i].kode))
            {
                kodeterpanjang = strlen(data[i].kode);
            }
        }

        for (i = 0; i < n; i++)
        {
            if (namaterpanjang < strlen(data[i].team))
            {
                namaterpanjang = strlen(data[i].team);
            }
        }

        printf("Data Team\n\n");
        printf("Kode");
        for (j = 0; j < 2 + (kodeterpanjang - strlen("Kode")); j++)
        {
            printf(" ");
        }
        printf("Team");
        for (j = 0; j < 2 + (namaterpanjang - strlen("Team")); j++)
        {
            printf(" ");
        }

        printf("Mesin\n");
        printf("+--------------------------------+\n");

        for (i = 0; i < n; i++)
        {
            printf("%s", data[i].kode);
            for (j = 0; j < 2 + (kodeterpanjang - strlen(data[i].kode)); j++)
            {
                printf(" ");
            }
            printf("%s", data[i].team);
            for (j = 0; j < 2 + (namaterpanjang - strlen(data[i].team)); j++)
            {
                printf(" ");
            }
            printf("%s\n", data[i].mesin);
        }
        printf("+--------------------------------+\n");
    }
}