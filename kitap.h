#ifndef KITAP_H
#define KITAP_H

#include "arama.h"

void kitaplariDosyadanYukle(Kitap kitaplar[], int *kitapSayisi);
void kitaplariDosyayaKaydet(Kitap kitaplar[], int kitapSayisi);
void kitapEkle(Kitap kitaplar[], int *kitapSayisi);
void kitapSil(Kitap kitaplar[], int *kitapSayisi);
void kitapGuncelle(Kitap kitaplar[], int kitapSayisi);

#endif
