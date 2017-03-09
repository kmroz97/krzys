#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct produkt {
    const char * nazwa;
    const char * typ;
    double cena;
    char * data;
    const char * producent;
    int ilosc;
    struct produkt * nastepny;
};
struct produkt * generuj (const char * name, const char * type, double price, char * day, const char * maker, int number) {
    struct produkt *poczatek = (struct produkt *)malloc(sizeof(struct produkt));
    poczatek->nastepny = NULL;
    poczatek->nazwa = name;
    poczatek->typ = type;
    poczatek->cena = price;
    poczatek->producent = maker;
    poczatek->ilosc = number;
    return poczatek;
};
struct produkt * dodaj (struct produkt *zmienna, const char * name, const char * type, double price, char * day, const char * maker, int number) {
    struct produkt * nowy = (struct produkt *)malloc(sizeof(struct produkt));
    while(zmienna->nastepny!=NULL)
    {
        zmienna= zmienna->nastepny;
    }
    zmienna->nastepny = nowy;
    nowy->nastepny = NULL;
    nowy->nazwa = name;
    nowy->typ = type;
    nowy->cena = price;
    nowy->producent = maker;
    nowy->ilosc = number;
    return nowy;
};
int main()
{
    struct produkt * pierwszy = generuj("chipsy", "spozywczy", 4.22, "2017-09-09", "Lays", 20);
    printf("%s %s %lf %s %s %d\n", pierwszy->nazwa, pierwszy->typ, pierwszy->cena, pierwszy->data, pierwszy->producent, pierwszy->ilosc);

}

