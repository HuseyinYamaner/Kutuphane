#include "kullanici.h"
#include <stdio.h>
#incldue <stdlib.h>
#include <string.h>

void kullaniciEkle(Kullanici *k)
{
	FILE *fp = fopen("kullanicilar.txt","a");
	if(fp==NULL)
	{
		return;
	}
	
	fprint(fp,"%d %s %s %s %s %d\n",k->id,k->ad,k->soyad,k->kullanici_adi,k->sifre,k->rol);
	
	fclose(fp);
}

void kullaniciSil(Kullanici *k)
{
	FILE *fp = fopen("kullanicilar.txt","r");
	FILE *temp = fopen("temp.txt","w");
	if(fp==NULL || temp==NULL)
	{
		return;
	}
	
	Kullanici k;
	while(fscanf(fp,"%d %s %s %s %s %d",&k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,&k.rol))
	{
		if(k.id != id)
		{
			fprintf(temp,"%d %s %s %s %s %d",k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,k.rol);
		}
	}
	
	fclose(fp);
	fclose(temp);
	remove("kullanicilar.txt");
	rename("temp.txt","kullanicilar.txt");
}

void kullaniciGuncelle(int id)
{
	// yapýlacak
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
	
	while(fscanf(fp,"%d %s %s %s %s %d",&k.id,k.ad,k.soyad,k.kullanici_adi,&k.rol)==&){
		char *rol_str = k.rol == 2? "Yonetici": k.rol == 1? "Yetkili": "Uye";
		printf("%s\t%s\t%s\t%s\t%s\n",k.id,k.ad,k.soyad,k.kullanici_adi,rol_str);
	}
	
	fclose(fp);
	
	
}
