#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kitap.h"

//yeni bir kitabı dosyaya ekleme

void kitapEkle(Kitap *k){

    FILE *fp =fopen("kitaplar.txt", "a");

    if (fp == NULL){

        printf(" Dosya acilamadi! \n");
        return;

    }

    // Verileri dosyaya boşluklara ayırıp yazma

    fprintf(fp, "%d %s %s %s %d %d \n", k->id, k->isim, k->yazarAd, k->yayinEvi, k->sayfaSayi, k->durum);

    fclose(fp);

    printf("Kitap başarıyla eklendi.\n");
}

//Tüm kitapları ekrana listeleme

void kitapListele(){

    FILE *fp = fopen("kitaplar.txt", "r");

    if(fp == NULL){

        printf("Henuz hic kitap eklenmemis veya dosya bulunamadi. \n");
        return;

    }

    Kitap k;

    printf("\n%-5s %-20s %-20s %-15s %-10s %-10s \n", "ID", "Kitap Adi", "Yazar", "Yayinevi", "Sayfa", "Durum");
    printf("*************************************************************************************\n");

    //satırları tek tek okuma

    while (fscanf(fp, "%d %s %s %s %d %d", &k.id, &k.isim, &k.yazarAd, &k.yayinEvi, &k.sayfaSayi, &k.durum) == 6){

        char *durum_str = (k.durum == 1 ) ? "Mevcut" : "Odunc" ;
        printf("%-5d %-20s %-20s %-15s %-10d %-10s\n", k.id, k.isim, k.yazarAd, k.yayinEvi, k.sayfaSayi, durum_str);

    }

    fclose(fp);
}
//Belirtilen ID'ye sahip kitabı dosuadan silme

void kitapSil(int id){

    FILE *fp = fopen("kitaplar.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL){

        printf("Dosya acilamadi.\n");
        return; 

    }

    Kitap k;
    int bulundu = 0;
    
    while(fcanf(fp, "%d %s %s %s %d %d", &k.id, &k.isim, &k.yazarAd, &k.yayinEvi, &k.sayfaSayi, &k.durum) == 6){

        if(k.id != id){

            fprintf(temp, "%d %s %s %s %d %d\n", k.id, k.isim, k.yazarAd, k.yayinEvi, k.sayfaSayi, k.durum );
        }else{
            bulundu=1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("kitaplar.txt");
    rename("temp.txt", "kitaplar.txt");

    if(bulundu) printf("ID: %d olan kitap silindi.\n", id);
    else printf("Kitap bulunamadi.\n");

}

//KitapSile benzer şekilde ID eşleştiğinde işlem yapar
void kitapGuncelle(int id){

    FILE *fp = fopen("kitaplar.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL){

        printf(" Dosyalar acilamadi.\n");
        return;

    }

    Kitap k;
    int bulundu =0;

    //Dosyayı satır satır okuma

    while (fscanf(fp, "%d %s %s %s %d %d", &k.id, &k.yazarAd, &k.yayinEvi, &k.sayfaSayi, &k.durum) == 6){

        if(k.id ==id){

            bulundu=1;
            
            printf("\n---- MEVCUT BİLGİLER ----\n");
            printf("Kitap Adi: %s ||| Yazar Adi: %s ||| Yayinevi: %s ||| Sayfa Sayisi: %d ||| Durum: %s\n", k.isim, k.yazarAd, k.yayinEvi, k.sayfaSayi, (k.durum == 1 ? "Mevcut" : "Odunc Verilmis"));
            printf("-------------------------------\n");

            printf("---- YENİ BİLGİLERİ GİRİN ----\n");
            printf("Yeni Kitap Adi: "); scanf("%s", k.isim);
            printf("Yeni Yazar Adi: "); scanf("%s", k.yazarAd);
            printf("Yeni Yayinevi: "); scanf("%s", k.yayinEvi);
            printf("Yeni Sayfa Sayisi: "); scanf("%d", &k.sayfaSayi);
            printf("Yeni Durum (1: Mevcut, 0: Odunc): "); scanf("%d", &k.durum);

            //Güncellenmiş veriyi temp dosyasına yazma

            fprintf(temp, "%d %s %s %s %d %d\n", k.id, k.isim, k.yazarAd, k.yayinEvi, k.sayfaSayi, k.durum);
            
        }else{
        
        //Değişmeyen verileri olduğu gibi temp dosyasına yazma

        fprintf(temp, "%d %s %s %s %d %d\n",k.id, k.isim, k.yazarAd, k.yayinEvi, k.sayfaSayi, k.durum);

        }

    }

    fclose(fp);
    fclose(temp);

    //eski doyayı silip yeni dosyaya adını verme
    remove("kitaplar.txt");
    rename("temp.txt","kitaplar.txt");

    if(bulundu){

        printf("\nID: %d olan kitap basariyla guncellendi.\n",id);

    }else{

        printf("\nID: %d olan kitap bulunamadi.\n",id);
    }
}



