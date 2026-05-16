#include <stdio.h>
#include <stdlib.h>
#include "arama.h"

#define MAX_KITAP 100

int main()
{
    Kitap kitaplar[MAX_KITAP] = {
        {1, "9789750738609", "Suc ve Ceza", "Dostoyevski", "Can", 1866, 5, "A1"},
        {2, "9786053321986", "1984", "George Orwell", "Can", 1949, 3, "B2"},
        {3, "9789750719387", "Kurk Mantolu Madonna", "Sabahattin Ali", "YKY", 1943, 2, "C3"},
        {4, "9786051850099", "Simyaci", "Paulo Coelho", "Can", 1988, 4, "D4"}
    };

    int kitapSayisi = 4;

    int secim;
    char aranacak[100];
    int yil;

    while (1)
    {
        printf("\n===== KUTUPHANE SISTEMI =====\n");
        printf("1 - Tum kitaplari listele\n");
        printf("2 - Kitap adina gore ara\n");
        printf("3 - Yazara gore ara\n");
        printf("4 - ISBN numarasina gore ara\n");
        printf("5 - Yila gore filtrele\n");
        printf("0 - Cikis\n");

        printf("\nSeciminizi giriniz: ");
        scanf("%d", &secim);

        getchar();

        switch (secim)
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

            case 0:
                printf("\nProgramdan cikiliyor...\n");
                exit(0);

            default:
                printf("\nGecersiz secim yaptiniz!\n");
        }
    }

    return 0;
}

