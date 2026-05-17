#ifndef KULLANICI_H
#define KULLANICI_H

typedef struct{
	int id;
	char ad[50];
	char soyad[50];
	char kullanici_adi[50];
	char sifre[12];
	int rol;//2,1,0(admin,görevli,uye)
} Kullanici;

void kullaniciEkle(Kullanici *k);
void kullaniciSil(int id);
void kullaniciGuncelle(int id);
void kullanicilarListele();

#endif
