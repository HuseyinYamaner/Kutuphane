#include <stdio.h>
#include "odunc.h"

void oduncVer(Kitap kitaplar[], int kitapSayisi)
{
    int id, i, bulundu = 0;
    printf("Odunc alinacak kitap ID: ");
    scanf("%d", &id);

    for(i = 0; i < kitapSayisi; i++)
    {
        if(kitaplar[i].id == id)
        {
            bulundu = 1;
            if(kitaplar[i].stok <= 0)
            {
                printf("Bu kitap stokta yok.\n");
            }
            else
            {
                kitaplar[i].stok--;
                if(kitaplar[i].stok == 0)
                    kitaplar[i].durum = 0;
                kitaplariDosyayaKaydet(kitaplar, kitapSayisi);
                printf("Kitap odunc verildi. Kalan stok: %d\n", kitaplar[i].stok);
            }
            break;
        }
    }

    if(!bulundu) printf("Kitap bulunamadi.\n");
}

void iadeAl(Kitap kitaplar[], int kitapSayisi)
{
    int id, i, bulundu = 0;
    printf("Iade edilecek kitap ID: ");
    scanf("%d", &id);

    for(i = 0; i < kitapSayisi; i++)
    {
        if(kitaplar[i].id == id)
        {
            bulundu = 1;
            kitaplar[i].stok++;
            kitaplar[i].durum = 1;
            kitaplariDosyayaKaydet(kitaplar, kitapSayisi);
            printf("Kitap iade alindi. Guncel stok: %d\n", kitaplar[i].stok);
            break;
        }
    }

    if(!bulundu) printf("Kitap bulunamadi.\n");
}
