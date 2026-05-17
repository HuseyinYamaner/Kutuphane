#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kitap.h"

void kitaplariDosyadanYukle(Kitap kitaplar[], int *kitapSayisi)
{
    FILE *fp = fopen("kitaplar.txt", "r");
    if(fp == NULL)
    {
        printf("kitaplar.txt bulunamadi, bos liste ile baslanýyor.\n");
        *kitapSayisi = 0;
        return;
    }

    *kitapSayisi = 0;
    while(fscanf(fp, "%d %s %s %s %s %d %d %d %s %d",
        &kitaplar[*kitapSayisi].id,
        kitaplar[*kitapSayisi].isbn,
        kitaplar[*kitapSayisi].ad,
        kitaplar[*kitapSayisi].yazar,
        kitaplar[*kitapSayisi].yayinevi,
        &kitaplar[*kitapSayisi].yayinYili,
        &kitaplar[*kitapSayisi].sayfaSayisi,
        &kitaplar[*kitapSayisi].stok,
        kitaplar[*kitapSayisi].konum,
        &kitaplar[*kitapSayisi].durum) == 10)
    {
        (*kitapSayisi)++;
    }

    fclose(fp);
    printf("%d kitap yuklendi.\n", *kitapSayisi);
}

void kitaplariDosyayaKaydet(Kitap kitaplar[], int kitapSayisi)
{
    FILE *fp = fopen("kitaplar.txt", "w");
    if(fp == NULL)
    {
        printf("Dosya kaydedilemedi!\n");
        return;
    }

    int i;
    for(i = 0; i < kitapSayisi; i++)
    {
        fprintf(fp, "%d %s %s %s %s %d %d %d %s %d\n",
            kitaplar[i].id,
            kitaplar[i].isbn,
            kitaplar[i].ad,
            kitaplar[i].yazar,
            kitaplar[i].yayinevi,
            kitaplar[i].yayinYili,
            kitaplar[i].sayfaSayisi,
            kitaplar[i].stok,
            kitaplar[i].konum,
            kitaplar[i].durum);
    }

    fclose(fp);
}

void kitapEkle(Kitap kitaplar[], int *kitapSayisi)
{
    Kitap yeni;

    printf("ID: ");           scanf("%d", &yeni.id);
    printf("ISBN: ");         scanf("%s", yeni.isbn);
    printf("Ad: ");           scanf("%s", yeni.ad);
    printf("Yazar: ");        scanf("%s", yeni.yazar);
    printf("Yayinevi: ");     scanf("%s", yeni.yayinevi);
    printf("Yayin Yili: ");   scanf("%d", &yeni.yayinYili);
    printf("Sayfa Sayisi: "); scanf("%d", &yeni.sayfaSayisi);
    printf("Stok: ");         scanf("%d", &yeni.stok);
    printf("Konum: ");        scanf("%s", yeni.konum);
    yeni.durum = 1;

    kitaplar[*kitapSayisi] = yeni;
    (*kitapSayisi)++;

    kitaplariDosyayaKaydet(kitaplar, *kitapSayisi);
    printf("Kitap eklendi.\n");
}

void kitapSil(Kitap kitaplar[], int *kitapSayisi)
{
    int silId, i, bulundu = 0;
    printf("Silinecek kitap ID: ");
    scanf("%d", &silId);

    for(i = 0; i < *kitapSayisi; i++)
    {
        if(kitaplar[i].id == silId)
        {
            bulundu = 1;
            for(; i < *kitapSayisi - 1; i++)
                kitaplar[i] = kitaplar[i+1];
            (*kitapSayisi)--;
            kitaplariDosyayaKaydet(kitaplar, *kitapSayisi);
            printf("Kitap silindi.\n");
            break;
        }
    }

    if(!bulundu) printf("Kitap bulunamadi.\n");
}

void kitapGuncelle(Kitap kitaplar[], int kitapSayisi)
{
    int gunId, i, bulundu = 0;
    printf("Guncellenecek kitap ID: ");
    scanf("%d", &gunId);

    for(i = 0; i < kitapSayisi; i++)
    {
        if(kitaplar[i].id == gunId)
        {
            bulundu = 1;

            printf("\n---- MEVCUT BILGILER ----\n");
            printf("Ad: %s | Yazar: %s | Yayinevi: %s | Sayfa: %d | Durum: %s\n",
                kitaplar[i].ad, kitaplar[i].yazar, kitaplar[i].yayinevi,
                kitaplar[i].sayfaSayisi, kitaplar[i].durum == 1 ? "Mevcut" : "Odunc");
            printf("-------------------------------\n");

            printf("Yeni Ad: ");           scanf("%s", kitaplar[i].ad);
            printf("Yeni Yazar: ");        scanf("%s", kitaplar[i].yazar);
            printf("Yeni Yayinevi: ");     scanf("%s", kitaplar[i].yayinevi);
            printf("Yeni Yayin Yili: ");   scanf("%d", &kitaplar[i].yayinYili);
            printf("Yeni Sayfa Sayisi: "); scanf("%d", &kitaplar[i].sayfaSayisi);
            printf("Yeni Stok: ");         scanf("%d", &kitaplar[i].stok);
            printf("Yeni Konum: ");        scanf("%s", kitaplar[i].konum);

            kitaplariDosyayaKaydet(kitaplar, kitapSayisi);
            printf("Kitap guncellendi.\n");
            break;
        }
    }

    if(!bulundu) printf("Kitap bulunamadi.\n");
}
