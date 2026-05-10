#include "oturum.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Kullanici *girisYap(char *kullanici_adi, char *sifre)
{
	FILE *fp = fopen("kullanicilar.txt","r");
	if(*fp==NULL)
	{
		return NULL;
	}


	Kullanici k;
	
	while(fscanf(fp,"%d %s %s %s %s %d",&k.id,k.ad,k.soyad,k.kullanici_adi,k.sifre,&k.rol)==6)
	{
		if(strcmp(k.kullanici_adi,kullanici_adi)&&strcmp(k.sifre,sifre))
		{
			Kullanici *bulunan = malloc(sizeof(Kullanici));
			if(bulunan == NULL)
			{
				fclose(fp);
				return NULL;
			}
			*bulunan = k;
			fclose(fp);
			return bulunan;
		}	
	}

	fclose(fp);
	return NULL;

}
