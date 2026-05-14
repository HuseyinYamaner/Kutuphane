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
} Kitap;

/*
    Kitap adına göre arama
    Parametreler:
    - kitaplar : kitap dizisi
    - adet     : dizideki kitap sayısı
    - aranacak : aranacak kitap adı
*/
void kitapAdaGoreAra(Kitap kitaplar[], int adet, const char *aranacak);

/*
    Yazara göre arama
*/
void kitapYazaraGoreAra(Kitap kitaplar[], int adet, const char *aranacak);

/*
    ISBN numarasına göre arama
*/
void kitapISBNGoreAra(Kitap kitaplar[], int adet, const char *aranacak);

/*
    Yayın yılına göre filtreleme
*/
void kitapYilaGoreFiltrele(Kitap kitaplar[], int adet, int yil);

/*
    Tüm kitapları listeleme
*/
void kitaplariListele(Kitap kitaplar[], int adet);

/*
    Kitap bilgisi yazdırma
*/
void kitapBilgisiYazdir(Kitap kitap);

#endif
