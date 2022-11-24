#include "header.h"

int indeks; // varibael indeks
char cc; 

void START(char pita[])
{
    indeks = 0;
    cc = pita[indeks];
}

void INC(char pita[])
{
    indeks++;
    cc = pita[indeks];
}

int EOP()
{
    if (cc == '$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ADV(char pita[])
{
    indeks++;
    cc = pita[indeks];
    while ((cc == ' ') && (EOP() == 0))
    {
        indeks++;
        cc = pita[indeks];
    }
}

char GETCC()
{
    return cc;
}