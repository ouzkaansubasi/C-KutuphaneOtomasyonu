#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<locale.h>

void printMessageCenter();
void headMessage();
void welcomeMessage();
void kayit_ekle();
void kayit_listele();
void kayit_sil();
void kayit_noara();
void kayit_adara();
void kitap_ekle();
void kitap_listele();
void kitap_sil();
void kitap_ara();

struct uye{
	int no;
	char ad[20];
	char soy[20];
};

struct kitap{
	int numara;
	char ad[40];
	char yazar[20];
};

struct uye uye; //global deðiþkenler
struct kitap kitap;

FILE *fp; 
FILE *fo;

void printMessageCenter(const char* message){ //girilecek mesajýn ortalanmasý için kullanýlan fonksiyon
    int len=0;
    int pos=0;
    len=(78-strlen(message))/2;
    printf("\t\t\t");
    for(pos=0;pos<len;pos++){
        printf(" ");
    }

    printf("%s",message);
}

void headMessage(const char *message){
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      C Dilinde Kütüphane Yönetim Sistemi          ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage(){//giriþ mesajýný gösterir
    headMessage("Proje Ödevi");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  ------------------\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 Kütüphane                 =");
    printf("\n\t\t\t        =                  Yönetim                  =");
    printf("\n\t\t\t        =                 Sistemine                 =");
    printf("\n\t\t\t        =                Hoþgeldiniz                =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  ------------------\n");
    printf("\n\n\n\t\t\t Devam etmek için herhangi bir tuþa basýnýz.....");
    getch();
}

int main(){
	
	setlocale(LC_ALL, "Turkish"); //türkçe karakterlerin yazýlmasý için kullanýlýr
	welcomeMessage();             
	int secim,tus,s;
	
	printf("\n\nÜye Sistemi / Kitap Sistemi:\n\n");
	printf("Üye sistemine girmek için 0'a, Kitap sistemine girmek için ise 1'e basýnýz.(Sonlandýrmak için -2'ye basýnýz.)\n");
	scanf("%d",&s);
	while(s!=-2){
	if(s==0){
	
	do{
		printf("MENU");
		printf("\n\n\n");
		printf("[1]-Yeni Üye Kaydý\n");
		printf("[2]-Kayýtlý Üyeleri Listeleme\n");
		printf("[3]-Üye Kaydý Silme\n");
		printf("[4]-Üye Arama\n");
		printf("\n");
		
		printf("Yapmak Ýstediðiniz Ýþlemi Giriniz: ");
		scanf("%d",&secim);
		
		switch(secim) {
			case 1 :kayit_ekle(); break;
			case 2 :kayit_listele(); break;	
			case 3 :kayit_sil(); break;		
			case 4 :kayit_noara(); break;
			default : printf("Lütfen belirtilen iþlem numaralarýndan birini giriniz.\n\n"); break;
		}
		
			printf("Menüye dönmek için herhangi bir sayý veya harf giriniz.(Çýkmak için -1 giriniz.)\n\n");
			scanf("%d",&tus);
		
	}
	while(tus!=-1);

}
	if(s==1){
	do{
		printf("MENU");
		printf("\n\n\n");
		printf("[1]-Yeni Kitap Kaydý\n");
		printf("[2]-Kayýtlý Kitaplarý Listeleme\n");
		printf("[3]-Kitap Kaydý Silme\n");
		printf("[4]-Kitap Arama\n");
		printf("\n");
		
		printf("Yapmak Ýstediðiniz Ýþlemi Giriniz: ");
		scanf("%d",&secim);
		
		switch(secim) {
			case 1 :kitap_ekle(); break;
			case 2 :kitap_listele(); break;	
			case 3 :kitap_sil(); break;		
			case 4 :kitap_ara(); break;

			default : printf("Lütfen belirtilen iþlem numaralarýndan birini giriniz.\n\n"); break;
		}
		
			printf("Menüye dönmek için herhangi bir sayý veya harf giriniz.(Çýkmak için -1 giriniz.)\n\n");
			scanf("%d",&tus);
		
	}
	while(tus!=-1);
	
	}
	printf("\n\nÜye Ýþlemleri / Kitap Ýþlemleri:\n\n");
	printf("Üye kayýt bilgilerini bakmak için 0'a, Kitap kayýt bilgilerine bakmak için ise 1'e basýnýz.(Sonlandýrmak için -2'ye basýnýz.)\n");
	scanf("%d",&s);

}
}
int fonk(int a){ //sayýnýn kaç  basamaklý olduðunu döndür
	int c=0;
	while(a!=0){
		a=a/10;
		c++;
	}
	return c;
}

void kayit_ekle(){ //dosyaya üye kayýt bilgisi ekle
	fo=fopen("dosya.txt","r"); //dosyayý açýp okur
	if((fp = fopen("dosya.txt", "a+")) == NULL) { //dosyayý açýp yazar
      printf("Dosya açma hatasý!\n");
    }
    else{
    	char cont[10];
    	fscanf(fo,"%s",cont);
    	if(strcmp(cont,"")==1){
    		fprintf(fp,"Üyenin Numarasý          Üyenin Adý               Üyenin Soyadý\n");
		}
    		
    	int i,a,b;
    	printf("Üye numarasýný giriniz:");
   		scanf("%d",&uye.no);
   		printf("Kaydý yapýlmak istenen üyenin ismini giriniz: (En fazla 20 karakter kullanýlabilir.)\n");
		scanf("%s",&uye.ad);
		printf("Kaydý yapýlmak istenen üyenin soyadýný giriniz: (En fazla 20 karakter kullanýlabilir.)\n");
		scanf("%s",&uye.soy);
		if(strlen(uye.ad)>=20 || strlen(uye.soy)>=20){
        printf("20 karakter sayýsý aþýldý. Lütfen tekrar deneyiniz. \n\n");
        printf("Kaydý yapýlmak istenen üyenin ismini giriniz: (En fazla 20 karakter kullanýlabilir.)\n");
		scanf("%s",&uye.ad);
		printf("Kaydý yapýlmak istenen üyenin soyadýný giriniz: (En fazla 20 karakter kullanýlabilir.)\n");
		scanf("%s",&uye.soy);
    }
    
    	b=strlen(uye.ad);
    	a=fonk(uye.no);
		fprintf(fp,"%d",uye.no);
		for(i=0;i<25-a;i++)
			fprintf(fp," ");
		fprintf(fp,"%s",uye.ad);
		for(i=0;i<25-b;i++)
			fprintf(fp," ");
		fprintf(fp,"%s\n",uye.soy);
		fclose(fp);
		fclose(fo);
	}

		printf("\n\nÜye Kaydý Baþarýlý!\n\n");

}

void kayit_listele(){ //dosyayý okuyup üye bilgilerini terminale yazdýr
	if((fp = fopen("dosya.txt", "r")) == NULL) {
      printf("Dosya açma hatasý!\n");
    }
    else{
    	int k,l,i;
    	char a[20];
    	fscanf(fp,"%s",a); //dosyanýn baþýndaki ilk 6 kelimeyi es geç
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	printf("Üyenin Numarasý          Üyenin Adý               Üyenin Soyadý\n");
    	
    	fscanf(fp,"%d %s %s",&uye.no,uye.ad,uye.soy); //dosyadan bilgileri okuma
    	while(!feof(fp)){ //dosyanýn sonuna kadar oku
    	k=strlen(uye.ad);
    	l=fonk(uye.no);
		printf("%d",uye.no);
		for(i=0;i<25-l;i++)
			printf(" ");
		printf("%s",uye.ad);
		for(i=0;i<25-k;i++)
			printf(" ");
		printf("%s\n",uye.soy);
    	
   		fscanf(fp,"%d %s %s",&uye.no,uye.ad,uye.soy);
   		
    }
	fclose(fp);  
}
}

void kayit_sil(){ //üye kaydý silme
	bool kayit=false;
	FILE *newf;
	int no,k,l,i;
	char cont[10];
	fp=fopen("dosya.txt","r");
	newf=fopen("dosya2.txt","a+");
	
	fprintf(newf,"Üyenin Numarasý          Üyenin Adý               Üyenin Soyadý\n");	
	
	char a[20];
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);

	printf("Silmek istediðiniz üye numarasýný giriniz:\n");
	scanf("%d",&no);
	while (fscanf(fp,"%d %s %s",&uye.no,uye.ad,uye.soy)!= EOF){ //dosyayý sonuna kadar oku

	if (no==uye.no){ //girilen numarayla üyenin numarasý eþleþirse if e gir
	kayit=true;
	printf ("\n%d %s %s – Silindi!\n",uye.no,uye.ad,uye.soy);
}
	else{
		k=strlen(uye.ad);
    	l=fonk(uye.no);
		fprintf(newf,"%d",uye.no);
		for(i=0;i<25-l;i++)
			fprintf(newf," ");
		fprintf(newf,"%s",uye.ad);
		for(i=0;i<25-k;i++)
			fprintf(newf," ");
		fprintf(newf,"%s\n",uye.soy);

}

}
	if(kayit==false)
		printf("Üyenin kaydý bulunmamaktadýr.\n");
	fclose(newf);
	fclose(fp);
	remove("dosya.txt"); //eski dosyayý sil
	rename("dosya2.txt","dosya.txt"); //yeni dosyanin adýný eski haline getir
	
}

void kayit_noara(){ //girilen sayýnýn üye listesinde olup olmadýðýný kontrol et
	bool d=false;
	fp=fopen("dosya.txt","r");
	char a[20];
   	fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
	int no;
	printf("Bulmak istediðiniz üyenin numarasýný giriniz.\n");
	scanf("%d",&no);
	while (fscanf(fp,"%d %s %s",&uye.no,uye.ad,uye.soy)!= EOF){ //dosyayý sonuna kadar oku
	if(no==uye.no){
		d=true;
		bool e=false;
		printf("Üye kaydý bulunmaktadýr.\n");
		printf("%d %s %s\n",uye.no,uye.ad,uye.soy);
		fo=fopen("kitap.txt","r");
		   	fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
   			fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
		printf("Bu üyenin sahip olduðu kitaplar:\n");
		fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara);
    	while(!feof(fo)){   
		if(uye.no==kitap.numara) { //üyenin sahip olduðu kitaplarý kontrol et varsa yazdýr                    
			e=true;
    		printf("%s %s %d\n",kitap.ad,kitap.yazar,kitap.numara);
			}	
   		fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara);
    }
    if(e==false)
    	printf("Bu üyenin kayýtlý kitabý bulunmamaktadýr.\n");
	}
}
	if(d==false){
		printf("Üye kaydý bulunmamaktadýr.\n");
	}	
	fclose(fp);

}

void kitap_ekle(){ //dosyaya kitap bilgilerini ekle
	int a,b,i;
	fp=fopen("kitap.txt","r");
	if((fo = fopen("kitap.txt", "a+")) == NULL) {
      printf("Dosya açma hatasý!\n");
    }
    
    	else{
    		char cont[10];
    		fscanf(fp,"%s",cont);
    		if(strcmp(cont,"")==1){ //dosya boþ ise if e gir
    			fprintf(fo,"Kitap Adý                     Kitap Yazarý                  Üyenin Numarasý\n");
		}
	
		printf("Kitap adýný giriniz: (kitap adýndaki boþluklarý alt tire kullanarak yazýnýz örn: fareler_ve_insanlar)\n");
   		scanf("%s",kitap.ad);
   		printf("Kitabýn yazarýný giriniz: (yazarýn adýndaki boþluklarý alt tire kullanarak yazýnýz örn: john_steinbeck) (En fazla 20 karakter kullanýlabilir.)\n");
		scanf("%s",kitap.yazar);
		printf("Kitabýn hangi üyenin aldýðýný üye numarasýyla giriniz: \n");
		scanf("%d",&kitap.numara);
		
		if(strlen(uye.ad)>=40 || strlen(uye.soy)>=20){
        printf("Karakter sayýsý aþýldý. Lütfen tekrar deneyiniz. \n\n");
        printf("Kitap adýný giriniz: (En fazla 40 karakter kullanýlabilir.)\n");
		scanf("%s",kitap.ad);
		printf("Kitabýn yazarýný giriniz: (En fazla 20 karakter kullanýlabilir.)\n");
		scanf("%s",kitap.yazar);
    }
   		a=strlen(kitap.ad);
    	b=strlen(kitap.yazar);
		fprintf(fo,"%s",kitap.ad);
		for(i=0;i<30-a;i++)
			fprintf(fo," ");
		fprintf(fo,"%s",kitap.yazar);
		for(i=0;i<30-b;i++)
			fprintf(fo," ");
		fprintf(fo,"%d\n",kitap.numara);
		fclose(fo);
		fclose(fp);
	
}
}

void kitap_listele(){  //dosyayý okuyup kitap bilgilerini terminale yazdýr 
	fo=fopen("kitap.txt","r");
		char a[30];
		int k,l,i;
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
	    printf("Kitap Adý                     Kitap Yazarý                  Üyenin Numarasý\n");
    	
    	fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara);
    	while(!feof(fo)){ //dosyayý sonuna kadar oku                        
    	k=strlen(kitap.ad);
    	l=strlen(kitap.yazar);
		printf("%s",kitap.ad);
		for(i=0;i<30-k;i++)
			printf(" ");
		printf("%s",kitap.yazar);
		for(i=0;i<30-l;i++)
			printf(" ");
		printf("%d\n",kitap.numara);
    	
   		fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara);
   		
    }
	fclose(fo);  
}

void kitap_sil(){ //dosyadan kitap bilgisi sil
	bool kayit=false;
	FILE *newf;
	char a[40];
	fo=fopen("kitap.txt","r");
	newf=fopen("kitap2.txt","w+");
	char cont[10];
    		
    			fprintf(newf,"Kitap Adý                     Kitap Yazarý                  Üyenin Numarasý\n");
		
		char b[30];
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
	printf("Silmek istediðiniz kitabýn adýný giriniz:\n");
	scanf("%s",a);
	while (fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara)!= EOF){  // dosyayi sonuna kadar oku

	if (strcmp(a,kitap.ad)==0){ //kitap adý ile kullanýcýnýn girdiði kitap ismi eþleþirse if e gir
	kayit=true;
	printf ("%s %s %d – Silindi!",kitap.ad,kitap.yazar,kitap.numara);
}
	else{
		int k,i,l;
		k=strlen(kitap.ad);
    	l=strlen(kitap.yazar);
		fprintf(newf,"%s",kitap.ad);
		for(i=0;i<30-k;i++)
			fprintf(newf," ");
		fprintf(newf,"%s",kitap.yazar);
		for(i=0;i<30-l;i++)
			fprintf(newf," ");
		fprintf(newf,"%d\n",kitap.numara);
		
	}


}
	if(kayit==false)
		printf("Kitap kaydý bulunmamaktadýr.\n");
		
	fclose(newf);
	fclose(fo);
	
	remove("kitap.txt"); //eski dosyayý sil
	rename("kitap2.txt","kitap.txt"); //yeni dosyanýn adýný eski haline getir

}
void kitap_ara(){ //girilen kitap adýnýn kitap listesinde olup olmadýðýný kontrol et
	bool a=false;
		fo=fopen("kitap.txt","r");
		char c[40];
    	fscanf(fo,"%s",c);
    	fscanf(fo,"%s",c);
    	fscanf(fo,"%s",c);
    	fscanf(fo,"%s",c);
    	fscanf(fo,"%s",c);
    	fscanf(fo,"%s",c);
	char b[40];
	printf("Bulmak istediðiniz kitabýn adýný giriniz:\n");
	scanf("%s",b);
	while (fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara)!= EOF){  //dosyayý sonuna kadar oku
	if(strcmp(b,kitap.ad)==0){ //kitap adý ile kullanýcýnýn girdiði kitap ismi eþleþirse if e gir
		a=true;
		printf("Kitap kaydý bulunmaktadýr.\n");
		printf ("%s %s %d\n",kitap.ad,kitap.yazar,kitap.numara);
	}
}
	if(a==false){
		printf("Kitap kaydý bulunmamaktadýr.\n");
	}	
	fclose(fo);
	
}

