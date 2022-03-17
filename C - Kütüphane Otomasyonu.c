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

struct uye uye; //global de�i�kenler
struct kitap kitap;

FILE *fp; 
FILE *fo;

void printMessageCenter(const char* message){ //girilecek mesaj�n ortalanmas� i�in kullan�lan fonksiyon
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
    printf("\n\t\t\t############      C Dilinde K�t�phane Y�netim Sistemi          ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage(){//giri� mesaj�n� g�sterir
    headMessage("Proje �devi");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  ------------------\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 K�t�phane                 =");
    printf("\n\t\t\t        =                  Y�netim                  =");
    printf("\n\t\t\t        =                 Sistemine                 =");
    printf("\n\t\t\t        =                Ho�geldiniz                =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  ------------------\n");
    printf("\n\n\n\t\t\t Devam etmek i�in herhangi bir tu�a bas�n�z.....");
    getch();
}

int main(){
	
	setlocale(LC_ALL, "Turkish"); //t�rk�e karakterlerin yaz�lmas� i�in kullan�l�r
	welcomeMessage();             
	int secim,tus,s;
	
	printf("\n\n�ye Sistemi / Kitap Sistemi:\n\n");
	printf("�ye sistemine girmek i�in 0'a, Kitap sistemine girmek i�in ise 1'e bas�n�z.(Sonland�rmak i�in -2'ye bas�n�z.)\n");
	scanf("%d",&s);
	while(s!=-2){
	if(s==0){
	
	do{
		printf("MENU");
		printf("\n\n\n");
		printf("[1]-Yeni �ye Kayd�\n");
		printf("[2]-Kay�tl� �yeleri Listeleme\n");
		printf("[3]-�ye Kayd� Silme\n");
		printf("[4]-�ye Arama\n");
		printf("\n");
		
		printf("Yapmak �stedi�iniz ��lemi Giriniz: ");
		scanf("%d",&secim);
		
		switch(secim) {
			case 1 :kayit_ekle(); break;
			case 2 :kayit_listele(); break;	
			case 3 :kayit_sil(); break;		
			case 4 :kayit_noara(); break;
			default : printf("L�tfen belirtilen i�lem numaralar�ndan birini giriniz.\n\n"); break;
		}
		
			printf("Men�ye d�nmek i�in herhangi bir say� veya harf giriniz.(��kmak i�in -1 giriniz.)\n\n");
			scanf("%d",&tus);
		
	}
	while(tus!=-1);

}
	if(s==1){
	do{
		printf("MENU");
		printf("\n\n\n");
		printf("[1]-Yeni Kitap Kayd�\n");
		printf("[2]-Kay�tl� Kitaplar� Listeleme\n");
		printf("[3]-Kitap Kayd� Silme\n");
		printf("[4]-Kitap Arama\n");
		printf("\n");
		
		printf("Yapmak �stedi�iniz ��lemi Giriniz: ");
		scanf("%d",&secim);
		
		switch(secim) {
			case 1 :kitap_ekle(); break;
			case 2 :kitap_listele(); break;	
			case 3 :kitap_sil(); break;		
			case 4 :kitap_ara(); break;

			default : printf("L�tfen belirtilen i�lem numaralar�ndan birini giriniz.\n\n"); break;
		}
		
			printf("Men�ye d�nmek i�in herhangi bir say� veya harf giriniz.(��kmak i�in -1 giriniz.)\n\n");
			scanf("%d",&tus);
		
	}
	while(tus!=-1);
	
	}
	printf("\n\n�ye ��lemleri / Kitap ��lemleri:\n\n");
	printf("�ye kay�t bilgilerini bakmak i�in 0'a, Kitap kay�t bilgilerine bakmak i�in ise 1'e bas�n�z.(Sonland�rmak i�in -2'ye bas�n�z.)\n");
	scanf("%d",&s);

}
}
int fonk(int a){ //say�n�n ka�  basamakl� oldu�unu d�nd�r
	int c=0;
	while(a!=0){
		a=a/10;
		c++;
	}
	return c;
}

void kayit_ekle(){ //dosyaya �ye kay�t bilgisi ekle
	fo=fopen("dosya.txt","r"); //dosyay� a��p okur
	if((fp = fopen("dosya.txt", "a+")) == NULL) { //dosyay� a��p yazar
      printf("Dosya a�ma hatas�!\n");
    }
    else{
    	char cont[10];
    	fscanf(fo,"%s",cont);
    	if(strcmp(cont,"")==1){
    		fprintf(fp,"�yenin Numaras�          �yenin Ad�               �yenin Soyad�\n");
		}
    		
    	int i,a,b;
    	printf("�ye numaras�n� giriniz:");
   		scanf("%d",&uye.no);
   		printf("Kayd� yap�lmak istenen �yenin ismini giriniz: (En fazla 20 karakter kullan�labilir.)\n");
		scanf("%s",&uye.ad);
		printf("Kayd� yap�lmak istenen �yenin soyad�n� giriniz: (En fazla 20 karakter kullan�labilir.)\n");
		scanf("%s",&uye.soy);
		if(strlen(uye.ad)>=20 || strlen(uye.soy)>=20){
        printf("20 karakter say�s� a��ld�. L�tfen tekrar deneyiniz. \n\n");
        printf("Kayd� yap�lmak istenen �yenin ismini giriniz: (En fazla 20 karakter kullan�labilir.)\n");
		scanf("%s",&uye.ad);
		printf("Kayd� yap�lmak istenen �yenin soyad�n� giriniz: (En fazla 20 karakter kullan�labilir.)\n");
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

		printf("\n\n�ye Kayd� Ba�ar�l�!\n\n");

}

void kayit_listele(){ //dosyay� okuyup �ye bilgilerini terminale yazd�r
	if((fp = fopen("dosya.txt", "r")) == NULL) {
      printf("Dosya a�ma hatas�!\n");
    }
    else{
    	int k,l,i;
    	char a[20];
    	fscanf(fp,"%s",a); //dosyan�n ba��ndaki ilk 6 kelimeyi es ge�
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	fscanf(fp,"%s",a);
    	printf("�yenin Numaras�          �yenin Ad�               �yenin Soyad�\n");
    	
    	fscanf(fp,"%d %s %s",&uye.no,uye.ad,uye.soy); //dosyadan bilgileri okuma
    	while(!feof(fp)){ //dosyan�n sonuna kadar oku
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

void kayit_sil(){ //�ye kayd� silme
	bool kayit=false;
	FILE *newf;
	int no,k,l,i;
	char cont[10];
	fp=fopen("dosya.txt","r");
	newf=fopen("dosya2.txt","a+");
	
	fprintf(newf,"�yenin Numaras�          �yenin Ad�               �yenin Soyad�\n");	
	
	char a[20];
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);
    fscanf(fp,"%s",a);

	printf("Silmek istedi�iniz �ye numaras�n� giriniz:\n");
	scanf("%d",&no);
	while (fscanf(fp,"%d %s %s",&uye.no,uye.ad,uye.soy)!= EOF){ //dosyay� sonuna kadar oku

	if (no==uye.no){ //girilen numarayla �yenin numaras� e�le�irse if e gir
	kayit=true;
	printf ("\n%d %s %s � Silindi!\n",uye.no,uye.ad,uye.soy);
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
		printf("�yenin kayd� bulunmamaktad�r.\n");
	fclose(newf);
	fclose(fp);
	remove("dosya.txt"); //eski dosyay� sil
	rename("dosya2.txt","dosya.txt"); //yeni dosyanin ad�n� eski haline getir
	
}

void kayit_noara(){ //girilen say�n�n �ye listesinde olup olmad���n� kontrol et
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
	printf("Bulmak istedi�iniz �yenin numaras�n� giriniz.\n");
	scanf("%d",&no);
	while (fscanf(fp,"%d %s %s",&uye.no,uye.ad,uye.soy)!= EOF){ //dosyay� sonuna kadar oku
	if(no==uye.no){
		d=true;
		bool e=false;
		printf("�ye kayd� bulunmaktad�r.\n");
		printf("%d %s %s\n",uye.no,uye.ad,uye.soy);
		fo=fopen("kitap.txt","r");
		   	fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
   			fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
    		fscanf(fo,"%s",a);
		printf("Bu �yenin sahip oldu�u kitaplar:\n");
		fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara);
    	while(!feof(fo)){   
		if(uye.no==kitap.numara) { //�yenin sahip oldu�u kitaplar� kontrol et varsa yazd�r                    
			e=true;
    		printf("%s %s %d\n",kitap.ad,kitap.yazar,kitap.numara);
			}	
   		fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara);
    }
    if(e==false)
    	printf("Bu �yenin kay�tl� kitab� bulunmamaktad�r.\n");
	}
}
	if(d==false){
		printf("�ye kayd� bulunmamaktad�r.\n");
	}	
	fclose(fp);

}

void kitap_ekle(){ //dosyaya kitap bilgilerini ekle
	int a,b,i;
	fp=fopen("kitap.txt","r");
	if((fo = fopen("kitap.txt", "a+")) == NULL) {
      printf("Dosya a�ma hatas�!\n");
    }
    
    	else{
    		char cont[10];
    		fscanf(fp,"%s",cont);
    		if(strcmp(cont,"")==1){ //dosya bo� ise if e gir
    			fprintf(fo,"Kitap Ad�                     Kitap Yazar�                  �yenin Numaras�\n");
		}
	
		printf("Kitap ad�n� giriniz: (kitap ad�ndaki bo�luklar� alt tire kullanarak yaz�n�z �rn: fareler_ve_insanlar)\n");
   		scanf("%s",kitap.ad);
   		printf("Kitab�n yazar�n� giriniz: (yazar�n ad�ndaki bo�luklar� alt tire kullanarak yaz�n�z �rn: john_steinbeck) (En fazla 20 karakter kullan�labilir.)\n");
		scanf("%s",kitap.yazar);
		printf("Kitab�n hangi �yenin ald���n� �ye numaras�yla giriniz: \n");
		scanf("%d",&kitap.numara);
		
		if(strlen(uye.ad)>=40 || strlen(uye.soy)>=20){
        printf("Karakter say�s� a��ld�. L�tfen tekrar deneyiniz. \n\n");
        printf("Kitap ad�n� giriniz: (En fazla 40 karakter kullan�labilir.)\n");
		scanf("%s",kitap.ad);
		printf("Kitab�n yazar�n� giriniz: (En fazla 20 karakter kullan�labilir.)\n");
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

void kitap_listele(){  //dosyay� okuyup kitap bilgilerini terminale yazd�r 
	fo=fopen("kitap.txt","r");
		char a[30];
		int k,l,i;
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
    	fscanf(fo,"%s",a);
	    printf("Kitap Ad�                     Kitap Yazar�                  �yenin Numaras�\n");
    	
    	fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara);
    	while(!feof(fo)){ //dosyay� sonuna kadar oku                        
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
    		
    			fprintf(newf,"Kitap Ad�                     Kitap Yazar�                  �yenin Numaras�\n");
		
		char b[30];
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
    	fscanf(fo,"%s",b);
	printf("Silmek istedi�iniz kitab�n ad�n� giriniz:\n");
	scanf("%s",a);
	while (fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara)!= EOF){  // dosyayi sonuna kadar oku

	if (strcmp(a,kitap.ad)==0){ //kitap ad� ile kullan�c�n�n girdi�i kitap ismi e�le�irse if e gir
	kayit=true;
	printf ("%s %s %d � Silindi!",kitap.ad,kitap.yazar,kitap.numara);
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
		printf("Kitap kayd� bulunmamaktad�r.\n");
		
	fclose(newf);
	fclose(fo);
	
	remove("kitap.txt"); //eski dosyay� sil
	rename("kitap2.txt","kitap.txt"); //yeni dosyan�n ad�n� eski haline getir

}
void kitap_ara(){ //girilen kitap ad�n�n kitap listesinde olup olmad���n� kontrol et
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
	printf("Bulmak istedi�iniz kitab�n ad�n� giriniz:\n");
	scanf("%s",b);
	while (fscanf(fo,"%s %s %d",kitap.ad,kitap.yazar,&kitap.numara)!= EOF){  //dosyay� sonuna kadar oku
	if(strcmp(b,kitap.ad)==0){ //kitap ad� ile kullan�c�n�n girdi�i kitap ismi e�le�irse if e gir
		a=true;
		printf("Kitap kayd� bulunmaktad�r.\n");
		printf ("%s %s %d\n",kitap.ad,kitap.yazar,kitap.numara);
	}
}
	if(a==false){
		printf("Kitap kayd� bulunmamaktad�r.\n");
	}	
	fclose(fo);
	
}

