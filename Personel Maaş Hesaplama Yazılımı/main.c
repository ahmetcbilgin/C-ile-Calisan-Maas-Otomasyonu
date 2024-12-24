#include <stdio.h>
#include <stdlib.h>

int main()
{
int calisan_sayac=0,ITAANUACS=0,BYOCSUFOS=0;
float onbes_sayac=0,yirmi_sayac=0,yirmiyedi_sayac=0,otuzbes_sayac=0;
float evli_sayac=0,bekar_sayac=0,calisanes_sayac=0,engelli_sayac=0,SBYCO=0;
float EAYO,CAYO1,CAYO2,CTAYO,ATBU[50],GVK[50],EOran,EDerece,ANU[50],GVMTM,ABU,BYOCS[50],YABOS;
double TCKN[50];
char  Ad[50][50],MD,ECCD,EDurum,icvm;

//Bilgi Girisi
do{
calisan_sayac++;
printf("%40d. Calisan Icin Bilgi Girisi\n\n",calisan_sayac);
printf("Lutfen TC kimlik numarasini giriniz: ");
scanf("%lf",&TCKN[calisan_sayac-1]);
printf("\n");

getchar();
printf("Lutfen adini ve soyadini giriniz: ");
scanf(" %[^\n]s",Ad[calisan_sayac-1]);

printf("\n");

do{
printf("Aylik brut asgari ucret 1777.50 TL'dir.\n");
printf("Lutfen Aylik Brut Ucretini(TL) giriniz: ");
scanf("%f",&ABU);
printf("\n");
}while(ABU<1777.50);
printf("\n");

getchar();

printf("Lutfen medeni durumunu giriniz.\nEvliyse e/E bekarsa b/B harfini giriniz: ");
scanf("%c",&MD);
printf("\n");

if(MD == 'e' || MD == 'E'){
{
    getchar();
    evli_sayac++;
    printf("Esi calisiyor mu?\nCalisiyorsa e/E calismiyorsa h/H harfini tuslayiniz: ");
    scanf("%c",&ECCD);
    printf("\n");
}
        if(ECCD == 'e' || ECCD == 'E'){
        EAYO = 0;
        calisanes_sayac++;}
        else if(ECCD == 'h' || ECCD == 'H')
        EAYO = 220;
}
else if(MD == 'b' || MD == 'B'){
    EAYO = 0;
    bekar_sayac++;}

printf("Bakmakla yukumlu oldugu cocuk sayisi: ");
scanf("%f",&BYOCS[calisan_sayac-1]);

if(BYOCS[calisan_sayac-1]>3)
    BYOCSUFOS++;


if(BYOCS[calisan_sayac-1]>0){
    SBYCO++;
    do{
    printf("Yasi 6'dan buyuk olanlarin sayisi: ");
    scanf("%f",&YABOS);
    }while(YABOS>BYOCS[calisan_sayac-1]);
    CAYO1 = YABOS*45;
    CAYO2 = (BYOCS[calisan_sayac-1]-YABOS)*25;
    CTAYO = CAYO1 + CAYO2;}
else if( BYOCS[calisan_sayac-1] == 0)
    CTAYO = 0;


printf("\n");

getchar();
printf("Herhangi bir engeli var midir?\nEvet icin e/E hayir icin h/H harfini giriniz: ");
scanf("%c",&EDurum);
printf("\n");

if(EDurum == 'e' || EDurum == 'E')
{
    engelli_sayac++;
    printf("Engellilik orani nedir: ");
    scanf("%f",&EOran);

    printf("\n");
}

else if(EDurum == 'h' || EDurum == 'H')
{
     EDerece=0;
     EOran=0;
     GVMTM =0;
}

    printf("\n");

//Maas Detaylari


ATBU[calisan_sayac-1] = ABU + EAYO + CTAYO;

printf("\n");

if (EOran>=40 && EOran<60){
    EDerece = 3;
    GVMTM = 210;
}
else if (EOran>=60 && EOran<80){
    EDerece = 2;
    GVMTM = 470;
}
else if (EOran>=80){
    EDerece = 1;
    GVMTM = 900;
}
else{
    EDerece = 0;
    GVMTM = 0;
}

printf("\n\n");

//Gelir Vergi Kesintisi Hesaplama

if (ATBU[calisan_sayac-1]<2000){
    GVK[calisan_sayac-1] = ((ATBU[calisan_sayac-1]-GVMTM)*15/100);
    onbes_sayac++;}
else if (ATBU[calisan_sayac-1]>=2000 && ATBU[calisan_sayac-1]<5000){
    GVK[calisan_sayac-1] = ((ATBU[calisan_sayac-1]-GVMTM)*20/100);
    yirmi_sayac++;}
else if (ATBU[calisan_sayac-1]>=5000 && ATBU[calisan_sayac-1]<10000){
    GVK[calisan_sayac-1] = ((ATBU[calisan_sayac-1]-GVMTM)*27/100);
    yirmiyedi_sayac++;}
else if (ATBU[calisan_sayac-1]>=10000){
    GVK[calisan_sayac-1] = ((ATBU[calisan_sayac-1]-GVMTM)*35/100);
    otuzbes_sayac++;}
else
    GVK[calisan_sayac-1] = 0;


//Aylik net ucret
ANU[calisan_sayac-1] = ATBU[calisan_sayac-1]-GVK[calisan_sayac-1];

if(ANU[calisan_sayac-1]<2000)
    ITAANUACS++;

//Ekrana Bilgi Yazdirma
printf("------------------%d. CALISANIN BILGILERI-------------------\n\n",calisan_sayac);

printf("TC Kimlik Numarasi               : %.0f\n",TCKN[calisan_sayac-1]);
printf("Adi ve Soyadi                    : %s\n",Ad[calisan_sayac-1]);
printf("Aylik brut ucret                 : %.2f\n",ABU);
printf("Es icin aile yardim odenegi      : %.2f\n",EAYO);
printf("Cocuk icin aile yardim odenegi   : %.2f\n",CTAYO);
printf("Aylik toplam brut ucret          : %.2f\n",ATBU[calisan_sayac-1]);
printf("Gelir vergi kesintisi            : %.2f\n",GVK[calisan_sayac-1]);
if(EDerece!=0)
   printf("Engel derecesi                   : %.2f\n",EDerece);
printf("Aylik net ucret                  : %.2f\n",ANU[calisan_sayac-1]);


//Para sayilarini hesaplama
int ikiyuz=0,yuz=0,elli=0,yirmi=0,on=0,bes=0,bir=0;
int ellikrs=0,yirmibeskrs=0,onkrs=0,beskrs=0;
float birkrs=0;
float kalan=0,sonuc,result;

printf("\n");

//Banknot
ikiyuz = (ANU[calisan_sayac-1])/200;
kalan  = ANU[calisan_sayac-1] - (ikiyuz*200);

yuz = kalan/100;
kalan -= yuz*100;

elli = kalan/50;
kalan -= elli*50;

yirmi = kalan/20;
kalan -= yirmi*20;

on = kalan/10;
kalan -= on*10;

bes = kalan/5;
kalan -= bes*5;

//Madeni para

bir = kalan/1;
kalan -= bir*1;

ellikrs = kalan/(0.50);
kalan -= ellikrs*(0.50);

yirmibeskrs = kalan/(0.25);
kalan -= yirmibeskrs*(0.25);

onkrs = kalan/(0.10);
kalan -= onkrs*(0.10);

beskrs = kalan/(0.05);
kalan -= beskrs*(0.05);

//kuruslarin dogru hesabi
kalan = kalan*100;
result = round(kalan);
kalan = kalan/100;

birkrs = kalan/(0.01);

if(birkrs == 5)
{
    birkrs = 0;
    beskrs++;
}

//Para sayilarini ekrana yazdirma
printf("-------------------BANKNOT VE MADENI PARA SAYILARI----------------------\n");

printf("200TL :%d\n100TL :%d\n50TL :%d\n20TL :%d\n10TL :%d\n5TL :%d\n\n",ikiyuz,yuz,elli,yirmi,on,bes);

printf("1TL :%d\n50 kurus :%d\n25 kurus :%d\n10 kurus :%d\n5 kurus :%d\n1 kurus :%.0f\n\n",bir,ellikrs,yirmibeskrs,onkrs,beskrs,birkrs);


//Baska calisan olup olmadigini sorma
getchar();
printf("Is yerinizde baska calisan var mi?\nEvet icin e/E hayir icin h/H harfini giriniz : ");

do{
scanf("%c",&icvm);
} while(icvm == '\n');
printf("\n");
} while(icvm == 'e' || icvm == 'E' );


int i=0,j=1,t,p,TCS;
float ATNU,TGVK,TATBU=0,ATNUO,TATBUO=0;
float yuzde1=0,yuzde2=0,yuzde3=0,yuzde4=0,yuzde5=0,yuzde6=0,yuzde7=0;
float EYATBU,EYANU,GVK1,GVK2,ANU1,ATBU1;
double TCKN1,TCKN2;

//ISTATISTIKLER
printf("\n*************************ISTATISTIKLER****************************");

//aylik toplam net ucret
printf("\n");
for(i=0;i<calisan_sayac;i++){
    ATNU += ANU[i];
}

printf("\n");
printf("1) Tum calisanlara bir ayda odenen aylik toplam net ucret = %.2f ",ATNU);

//toplam gelir vergi kesintisi
printf("\n");
for(i=0;i<calisan_sayac;i++){
    TGVK += GVK[i];
}
printf("\n");
printf("1) Devlete aktarilan aylik toplam gelir vergisi tutari = %.2f ",TGVK);

//toplam aylik toplam brut ucret
printf("\n");
for(i=0;i<calisan_sayac;i++){
    TATBU += ATBU[i];
}

printf("\n");
//printf("TATBU = %.2f ",TATBU);

//ortalamalar
ATNUO = ATNU/calisan_sayac;
TATBUO = TATBU/calisan_sayac;

printf("\n\n");
printf("2) Aylik toplam brut ucret ortalama = %.2f  VE Aylik toplam net ucret ortalama = %.2f ",TATBUO,ATNUO);

//2000 TL’nin altinda aylik net ucret alan calisanlarin sayisi
printf("\n\n");
printf("3) Iki bin Tl'nin altinda aylik net ucret alan calisan sayisi = %d",ITAANUACS);

//gvo icin calisan sayi ve yuzdeleri

yuzde1 = onbes_sayac/calisan_sayac*100;
yuzde2 = yirmi_sayac/calisan_sayac*100;
yuzde3 = yirmiyedi_sayac/calisan_sayac*100;
yuzde4 = otuzbes_sayac/calisan_sayac*100;


printf("\n\n");
printf("4) Her gelir vergisi orani icin ayri ayri calisan sayi ve yuzdeleri : \n\n");
printf("   sayilar                  yuzdeler\n");
printf(" GVO-15 = %.0f %20.2f\n ",onbes_sayac,yuzde1);
printf("GVO-20 = %.0f %20.2f\n ",yirmi_sayac,yuzde2);
printf("GVO-27 = %.0f %20.2f\n ",yirmiyedi_sayac,yuzde3);
printf("GVO-35 = %.0f %20.2f\n ",otuzbes_sayac,yuzde4);


//ATBUEYC
printf("\n\n");
EYATBU = ATBU[0];


   for (i = 0; i < calisan_sayac; i++) {
      if (ATBU[i] >= EYATBU) {
         EYATBU = ATBU[i];
         TCKN1 = TCKN[i];
         GVK1 = GVK[i];
         ANU1 = ANU[i];
         t = i;

      }
   }
    printf("\n5)Aylik toplam brut ucreti en yuksek calisanin bilgileri : \n");
    printf("TC Kimlik Numarasi               : %.0f\n",TCKN1);
    printf("Adi ve Soyadi                    : %s\n",Ad[t]);
    printf("Aylik toplam brut ucret          : %.2f\n",EYATBU);
    printf("Gelir vergi kesintisi            : %.2f\n",GVK1);
    printf("Aylik net ucret                  : %.2f\n",ANU1);

//ANUEYC
printf("\n\n");
EYANU = ANU[0];


   for (i = 0; i < calisan_sayac; i++) {
      if (ANU[i] >= EYANU) {
         EYANU = ANU[i];
         TCKN2 = TCKN[i];
         GVK2 = GVK[i];
         ATBU1 = ATBU[i];
         p = i;

      }
   }
    printf("\n6)Aylik net ucreti en yuksek calisanin bilgileri : \n");
    printf("TC Kimlik Numarasi               : %.0f\n",TCKN2);
    printf("Adi ve Soyadi                    : %s\n",Ad[p]);
    printf("Aylik toplam brut ucret          : %.2f\n",ATBU1);
    printf("Gelir vergi kesintisi            : %.2f\n",GVK2);
    printf("Aylik net ucret                  : %.2f\n",EYANU);

//evli bekar sayisi ve orani

yuzde5 = evli_sayac/calisan_sayac*100;
yuzde6 = bekar_sayac/calisan_sayac*100;
yuzde7 = calisanes_sayac/evli_sayac*100;

printf("\n\n");
printf("7) Tum calisanlar icindeki evli ve bekar olanlarin yuzdeleri : \n\n");
printf("   sayilar                  yuzdeler\n");
printf(" Evliler = %.0f  %20.2f\n ",evli_sayac,yuzde5);
printf("Bekarlar = %.0f %20.2f\n ",bekar_sayac,yuzde6);
printf("\n8) Es calisma yuzde =  %10.2f\n ",yuzde7);

//Bakmakla yukumlu olunan cocuk sayisi ortalama

printf("\n\n");
for(i=0;i<calisan_sayac;i++){
   TCS += BYOCS[i];
}

printf("9) Calisanlarin bakmakla yukumlu oldugu cocuk sayisinin ortalamasi = %.2f ",TCS/SBYCO);

//Bakmakla yukumlu olunan cocuk sayisi 3ten fazla olanlarin sayisi
printf("\n\n");
printf("10) Bakmakla yukumlu olunan cocuk sayisi 3ten fazla olanlarin sayisi = %d",BYOCSUFOS);

//engelli sayisi ve orani;
printf("\n\n");
printf("11) Engelli calisanlarin sayisi = %.0f ve tum calisanlar icindeki yuzdesi = %.2f",engelli_sayac,(engelli_sayac/calisan_sayac*100));
printf("\n\n");




    return 0;
}
