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

int stringIceriyor(const char *kaynak, const char *aranan)
{
    char k[MAX_STR], a[MAX_STR];
    int i;
    for (i = 0; kaynak[i]; i++) k[i] = tolower((unsigned char)kaynak[i]);
    k[i] = '\0';
    for (i = 0; aranan[i]; i++) a[i] = tolower((unsigned char)aranan[i]);
    a[i] = '\0';
    return strstr(k, a) != NULL;
}

int stringKarsilastir(const char *s1, const char *s2)
{
    char a[MAX_STR], b[MAX_STR];
    int i;
    for (i = 0; s1[i]; i++) a[i] = tolower((unsigned char)s1[i]);
    a[i] = '\0';
    for (i = 0; s2[i]; i++) b[i] = tolower((unsigned char)s2[i]);
    b[i] = '\0';
    return strcmp(a, b) == 0;
}

void kitapBilgisiYazdir(Kitap kitap)
{
    printf("----------------------------------\n");
    printf("ID       : %d\n", kitap.id);
    printf("ISBN     : %s\n", kitap.isbn);
    printf("Ad       : %s\n", kitap.ad);
    printf("Yazar    : %s\n", kitap.yazar);
    printf("Yayinevi : %s\n", kitap.yayinevi);
    printf("Yil      : %d\n", kitap.yayinYili);
    printf("Stok     : %d\n", kitap.stok);
    printf("Konum    : %s\n", kitap.konum);
    printf("Sayfa    : %d\n", kitap.sayfaSayisi);
}

void kitaplariListele(Kitap kitaplar[], int adet)
{
    int i;
    if (adet == 0) {
        printf("Listede hic kitap yok.\n");
        return;
    }
    printf("%-5s %-15s %-25s %-15s %-6s %-5s %-6s\n",
           "ID", "ISBN", "Ad", "Yazar", "Yil", "Stok", "Konum");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < adet; i++) {
        printf("%-5d %-15s %-25s %-15s %-6d %-5d %-6s\n",
               kitaplar[i].id, kitaplar[i].isbn, kitaplar[i].ad,
               kitaplar[i].yazar, kitaplar[i].yayinYili,
               kitaplar[i].stok, kitaplar[i].konum);
    }
}
