#ifndef ARAMA_H
#define ARAMA_H

#define MAX_KITAP 1000
#define MAX_STR 100

typedef struct {
    int id;
    char isbn[20];
    char ad[MAX_STR];
    char yazar[MAX_STR];
    char yayinevi[MAX_STR];
    int yayinYili;
    int stok;
    char konum[MAX_STR];
    int durum;
    int sayfaSayisi;
} Kitap;

/*
    Kitap adÄ±na gÃ¶re arama
    Parametreler:
    - kitaplar : kitap dizisi
    - adet     : dizideki kitap sayÄ±sÄ±
    - aranacak : aranacak kitap adÄ±
*/
void kitapAdaGoreAra(Kitap kitaplar[], int adet, const char *aranacak);

/*
    Yazara gÃ¶re arama
*/
void kitapYazaraGoreAra(Kitap kitaplar[], int adet, const char *aranacak);

/*
    ISBN numarasÄ±na gÃ¶re arama
*/
void kitapISBNGoreAra(Kitap kitaplar[], int adet, const char *aranacak);

/*
    YayÄ±n yÄ±lÄ±na gÃ¶re filtreleme
*/
void kitapYilaGoreFiltrele(Kitap kitaplar[], int adet, int yil);

/*
    TÃ¼m kitaplarÄ± listeleme
*/
void kitaplariListele(Kitap kitaplar[], int adet);

/*
    Kitap bilgisi yazdÄ±rma
*/
void kitapBilgisiYazdir(Kitap kitap);

// Büyük/küçük harf duyarsýz alt string arama
int stringIceriyor(const char *kaynak, const char *aranan);

// Büyük/küçük harf duyarsýz tam eþleþme karþýlaþtýrma
int stringKarsilastir(const char *s1, const char *s2);
#endif
