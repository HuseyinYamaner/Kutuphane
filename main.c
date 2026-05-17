#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oturum.h"
#include "arama.h"
#include "kitap.h"
#include "kullanici.h"
#include "odunc.h"


#define MAX_KITAP 1000

int main()
{
    Kitap kitaplar[MAX_KITAP];
	int kitapSayisi = 0;
	kitaplariDosyadanYukle(kitaplar, &kitapSayisi);

    int secim;
    char aranacak[100];
    int yil;
 	
 	char kullanici_adi[50];
	char sifre[12];
	Kullanici *aktifKullanici = NULL;
	
	printf("===== KUTUPHANE SISTEMI =====\n");
	printf("Kullanici Adi: ");
	scanf("%s", kullanici_adi);
	printf("Sifre: ");
	scanf("%s", sifre);
	
	aktifKullanici = girisYap(kullanici_adi, sifre);
	
	if(aktifKullanici == NULL) {
	    printf("Hatali kullanici adi veya sifre!\n");
	    return 1;
	}
	
	printf("\nHos geldiniz, %s %s!\n", aktifKullanici->ad, aktifKullanici->soyad);
    

    while (1)
	{
	    printf("\n===== KUTUPHANE SISTEMI =====\n");
	    printf("1 - Tum kitaplari listele\n");
	    printf("2 - Kitap adina gore ara\n");
	    printf("3 - Yazara gore ara\n");
	    printf("4 - ISBN numarasina gore ara\n");
	    printf("5 - Yila gore filtrele\n");
	    printf("13 - Odunc al\n");
		printf("14 - Iade et\n");
	
	    if(aktifKullanici->rol >= 1)
	    {
	        printf("6 - Kitap ekle\n");
	        printf("7 - Kitap sil\n");
	        printf("8 - Kitap guncelle\n");
	    }
	
	    if(aktifKullanici->rol >= 2)
	    {
	        printf("9 - Kullanici ekle\n");
	        printf("10 - Kullanici sil\n");
	        printf("11 - Kullanici guncelle\n");
	        printf("12 - Kullanicilari listele\n");
	    }
	
	    printf("0 - Cikis\n");
	
	    printf("\nSeciminizi giriniz: ");
	    scanf("%d", &secim);
	    getchar();
	
	    switch(secim)
	    {
	        case 1:
                printf("\n=== TUM KITAPLAR ===\n");
                kitaplariListele(kitaplar, kitapSayisi);
                break;
                
	        case 2:
                printf("\nAranacak kitap adi: ");
                fgets(aranacak, sizeof(aranacak), stdin);

                aranacak[strcspn(aranacak, "\n")] = '\0';

                kitapAdaGoreAra(kitaplar, kitapSayisi, aranacak);
                break;
	        
	        case 3:
                printf("\nAranacak yazar adi: ");
                fgets(aranacak, sizeof(aranacak), stdin);

                aranacak[strcspn(aranacak, "\n")] = '\0';

                kitapYazaraGoreAra(kitaplar, kitapSayisi, aranacak);
                break;
	        
	        case 4:
                printf("\nAranacak ISBN: ");
                fgets(aranacak, sizeof(aranacak), stdin);

                aranacak[strcspn(aranacak, "\n")] = '\0';

                kitapISBNGoreAra(kitaplar, kitapSayisi, aranacak);
                break;
	        
	        case 5:
                printf("\nYayin yili giriniz: ");
                scanf("%d", &yil);

                kitapYilaGoreFiltrele(kitaplar, kitapSayisi, yil);
                break;
	
	        case 6:
	            if(aktifKullanici->rol >= 1)
	                kitapEkle(kitaplar, &kitapSayisi);
	            else
	                printf("Bu islem icin yetkiniz yok.\n");
	            break;
	
	        case 7:
	            if(aktifKullanici->rol >= 1)
	                kitapSil(kitaplar, &kitapSayisi);
	            else
	                printf("Bu islem icin yetkiniz yok.\n");
	            break;
	
	        case 8:
	            if(aktifKullanici->rol >= 1)
	                kitapGuncelle(kitaplar, kitapSayisi);
	            else
	                printf("Bu islem icin yetkiniz yok.\n");
	            break;
	
	        case 9:
	            if(aktifKullanici->rol >= 2)
	            {
	                Kullanici yeniK;
	                printf("Ad: ");             scanf("%s", yeniK.ad);
	                printf("Soyad: ");          scanf("%s", yeniK.soyad);
	                printf("Kullanici adi: ");  scanf("%s", yeniK.kullanici_adi);
	                printf("Sifre: ");          scanf("%s", yeniK.sifre);
	                printf("Rol (0=uye, 1=gorevli, 2=admin): "); scanf("%d", &yeniK.rol);
	                kullaniciEkle(&yeniK);
	            }
	            else
	                printf("Bu islem icin yetkiniz yok.\n");
	            break;
	
	        case 10:
	            if(aktifKullanici->rol >= 2)
	            {
	                int silId;
	                printf("Silinecek kullanici ID: "); scanf("%d", &silId);
	                kullaniciSil(silId);
	            }
	            else
	                printf("Bu islem icin yetkiniz yok.\n");
	            break;
	
	        case 11:
	            if(aktifKullanici->rol >= 2)
	            {
	                int gunId;
	                printf("Guncellenecek kullanici ID: "); scanf("%d", &gunId);
	                kullaniciGuncelle(gunId);
	            }
	            else
	                printf("Bu islem icin yetkiniz yok.\n");
	            break;
	
	        case 12:
	            if(aktifKullanici->rol >= 2)
	                kullanicilarListele();
	            else
	                printf("Bu islem icin yetkiniz yok.\n");
	            break;
	            
	        case 13:
			    oduncVer(kitaplar, kitapSayisi);
			    break;

			case 14:
			    iadeAl(kitaplar, kitapSayisi);
			    break;   
				
	        case 0:
	            printf("\nProgramdan cikiliyor...\n");
	            free(aktifKullanici);
	            exit(0);
	
	        default:
	            printf("\nGecersiz secim yaptiniz!\n");
	    }
	}
    return 0;
}

