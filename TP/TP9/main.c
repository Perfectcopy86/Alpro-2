/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP9 Alpro2 (PEMATER) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    char pita[101];       // varibael pita
    char temp1;           // tampungan untuk getchar
    char temp2;           // tampungan untuk huruf setelah kunci
    char temp3;           // tampungan untuk huruf sebelum kunci
    int tempidx;          // tampungan menandai indeks
    int n = 0;            // variabel untuk menandai apakah teks palsu atau asli
    char kunci;           // variabel huruf kunci
    scanf(" %c", &kunci); // masukan kunci

    scanf(" %100[^\n]s", &pita); // masukan pita

    if (kunci >= 65 && kunci <= 90) // jika huruf kapital diubah ke huruf kecil
    {
        kunci += 32;
    }

    START(pita);
    while (EOP() == 0)
    {

        ADV(pita);       // menjalankan fungsi adv
        temp1 = GETCC(); // menjalankan fungsi getcc

        if (kunci == temp1) // jika menemui karakter kunci
        {
            // proses pengambilan karakter setelah kunci(indeks+1)
            tempidx = tanda();
            tempidx++;
            temp2 = pita[tempidx];
            while ((temp2 == ' ') && (EOP() == 0))
            {
                tempidx++;
                temp2 = pita[tempidx];
            }

            // proses pengambilan karakter sebelum kunci(indeks-1)
            tempidx = tanda();
            tempidx--;
            temp3 = pita[tempidx];
            while ((temp3 == ' ') && (EOP() == 0))
            {
                tempidx--;
                temp3 = pita[tempidx];
            }

            // mengubah huruf kapital menjadi kecil
            if (temp2 >= 65 && temp2 <= 90)
            {
                temp2 += 32;
            }
            if (temp3 >= 65 && temp3 <= 90)
            {
                temp3 += 32;
            }

            if (temp2 == temp3) // jika huruf sebelum kunci dan sesudah kunci sama maka n++
            {
                n++;
            }
        }
    }
    // keluaran
    if (n > 0)
    {
        printf("Teks palsu.\n");
    }
    else if (n == 0)
    {
        printf("Teks asli.\n");
    }

    return 0;
}
