#ifndef KITAP_H
#define KITAP_H

typedef struct {

    int id;
    int sayfaSayi;
    int durum; // 1=mevcut, 0=verilmiş

    char isim[100];
    char yazarAd[100];
    char yayinEvi[100];
} Kitap;

void kitapEkle(Kitap *k);
void kitapSil(int id);
void kitapGuncelle(int id);
void kitapListele();

#endif 
