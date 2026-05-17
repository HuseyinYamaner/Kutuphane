#include "kullanici.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kullaniciEkle(Kullanici *k)
{
    FILE *fp = fopen("kullanicilar.txt", "r");
    
    int sonId = 0;
    Kullanici temp;
    if(fp != NULL)
    {
        while(fscanf(fp, "%d %s %s %s %s %d",
               &temp.id, temp.ad, temp.soyad,
               temp.kullanici_adi, temp.sifre, &temp.rol) == 6)
        {
            if(temp.id > sonId) sonId = temp.id;
        }
        fclose(fp);
    }
    k->id = sonId + 1;

    fp = fopen("kullanicilar.txt", "a");
    if(fp == NULL) return;
    
    fseek(fp, -1, SEEK_END);
	int sonKarakter = fgetc(fp);
	if(sonKarakter != '\n' && sonKarakter != EOF)
    fprintf(fp, "\n");

    fprintf(fp, "%d %s %s %s %s %d\n",
            k->id, k->ad, k->soyad,
            k->kullanici_adi, k->sifre, k->rol);

    fclose(fp);
}

void kullaniciSil(int id)
{
	FILE *fp = fopen("kullanicilar.txt","r");
	FILE *temp = fopen("temp.txt","w");
	if(fp==NULL || temp==NULL)
	{
		return;
	}
	
	Kullanici k;
	while(fscanf(fp,"%d %s %s %s %s %d\n",&k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,&k.rol)==6	)
	{
		if(k.id != id)
		{
			fprintf(temp,"%d %s %s %s %s %d\n",k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,k.rol);
		}
	}
	
	fclose(fp);
	fclose(temp);
	remove("kullanicilar.txt");
	rename("temp.txt","kullanicilar.txt");
}

void kullaniciGuncelle(int id)
{
	FILE *fp = fopen("kullanicilar.txt","r");
	FILE *temp = fopen("temp.txt","w");
	
	if(fp==NULL || temp == NULL)
	{
		return;
	}
	
	Kullanici k;
	
	while(fscanf(fp,"%d %s %s %s %s %d",&k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,&k.rol)==6)
	{
		if(k.id==id)
		{
			printf("Yeni ad: ");
			scanf("%s",k.ad);
			printf("Yeni Soyad: ");
			scanf("%s",k.soyad);
			printf("Yeni kullanici adi: ");
			scanf("%s",k.kullanici_adi);
			printf("Yeni sifre: ");
			scanf("%s",k.sifre);
			printf("Yeni rol(0=uye,1=gorevli,2=admin): ");
			scanf("%d",&k.rol);
		}
		fprintf(temp,"%d %s %s %s %s %d\n",k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,k.rol);
	}
	fclose(fp);
	fclose(temp);
	remove("kullanicilar.txt");
	rename("temp.txt","kullanicilar.txt");
}

void kullanicilarListele()
{
	FILE *fp = fopen("kullanicilar.txt","r");
	if(fp==NULL)
	{
		printf("Listelenecek veri yok");
		return;
	}
	
	Kullanici k;
	printf("%s\t%s\t%s\t%s\t%s\n\n","ID","Ad","Soyad","Kullanici_Adi","Rol");
	
	while(fscanf(fp,"%d %s %s %s %s %d",&k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,&k.rol)==6){
		char *rol_str = k.rol == 2? "Yonetici": k.rol == 1? "Yetkili": "Uye";
		printf("%d\t%s\t%s\t%s\t%s\n",k.id,k.ad,k.soyad,k.kullanici_adi,rol_str);
	}
	
	fclose(fp);
	
	
}
