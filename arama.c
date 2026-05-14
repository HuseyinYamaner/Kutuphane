#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "arama.h"
void kitapAdaGoreAra(Kitap kitaplar[], int adet, const char *aranacak)
{
    int i;
    int bulundu = 0;

    for (i = 0; i < adet; i++)
    {
        if (stringIceriyor(kitaplar[i].ad, aranacak))
        {
            kitapBilgisiYazdir(kitaplar[i]);
            bulundu = 1;
        }
    }

    if (!bulundu)
    {
        printf("\nAranan isimde kitap bulunamadi.\n");
    }
}

void kitapYazaraGoreAra(Kitap kitaplar[], int adet, const char *aranacak)
{
    int i;
    int bulundu = 0;

    for (i = 0; i < adet; i++)
    {
        if (stringIceriyor(kitaplar[i].yazar, aranacak))
        {
            kitapBilgisiYazdir(kitaplar[i]);
            bulundu = 1;
        }
    }

    if (!bulundu)
    {
        printf("\nAranan yazara ait kitap bulunamadi.\n");
    }
}

void kitapISBNGoreAra(Kitap kitaplar[], int adet, const char *aranacak)
{
    int i;
    int bulundu = 0;

    for (i = 0; i < adet; i++)
    {
        if (stringKarsilastir(kitaplar[i].isbn, aranacak))
        {
            kitapBilgisiYazdir(kitaplar[i]);
            bulundu = 1;
        }
    }

    if (!bulundu)
    {
        printf("\nBu ISBN numarasina ait kitap bulunamadi.\n");
    }
}

void kitapYilaGoreFiltrele(Kitap kitaplar[], int adet, int yil)
{
    int i;
    int bulundu = 0;

    for (i = 0; i < adet; i++)
    {
        if (kitaplar[i].yayinYili == yil)
        {
            kitapBilgisiYazdir(kitaplar[i]);
            bulundu = 1;
        }
    }

    if (!bulundu)
    {
        printf("\nBu yila ait kitap bulunamadi.\n");
    }
}
