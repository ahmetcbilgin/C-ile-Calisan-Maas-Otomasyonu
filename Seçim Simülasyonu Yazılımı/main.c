#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int MK[4];
int largest=0,s;
float Y[4];
int MV[4][4];
int kopya[4][4];
char harfler[4]={'A','B','C','D'};



void sehir(int OY[][4], int s)
{
    int a,b;
    printf("             Oy Sayisi         Oy Yuzdesi          MV Sayisi\n");
    printf("            ----------         ----------         -----------\n");
       for(a=0,b='A';a<4,b<'E';a++,b++){

            printf("%c partisi %10d %20.2f %15d\n",harfler[a],kopya[s][a],Y[a],MV[s][a]);
			}
}


void diziyi_sirala(int OY[][4], int s)
{

	harfler[0]='A';
	harfler[1]='B';
	harfler[2]='C';
	harfler[3]='D';
    int a,b,at; char at2;
for(a=0;a<4;a++){
        for(b=0;b<4;b++){
            if( OY[s][a]> OY [s][b] ){
                at=OY[s][a];
                OY[s][a] = OY[s][b];
                OY[s][b] = at;
				at2=harfler[a];
                harfler[a] = harfler[b];
                harfler[b] = at2;}
        }
    }
}

    void dizi_sira(int kopya[][4], int s)
{

    int a,b,at;
for(a=0;a<4;a++){
        for(b=0;b<4;b++){
            if( kopya[s][a]> kopya [s][b] ){
                at=kopya[s][a];
                kopya[s][a] = kopya[s][b];
                kopya[s][b] = at;}
        }
    }

}

int oylari_topla(int OY[][4], int s)
{
int toplam=0,i;
for(i=0;i<4;i++)
    {
        toplam += OY[s][i];
    }
return toplam;
}


void yuzde(int OY[][4], int s)
{

Y[0] = (float)OY[s][0]/oylari_topla(OY,s)*100;
Y[1] = (float)OY[s][1]/oylari_topla(OY,s)*100;
Y[2] = (float)OY[s][2]/oylari_topla(OY,s)*100;
Y[3] = (float)OY[s][3]/oylari_topla(OY,s)*100;


}

int buyuk_eleman(int OY[][4], int s)
{
    int i;
    largest = OY[s][0];

   for (i = 0; i <4; i++) {
      if (OY[s][i] > largest) {
         largest = OY[s][i];
      }
   }

   return largest;

}

void MV_atama(int OY[][4], int a)
{
    int i;
    for(i=0;i<MK[a];i++)
    {
    buyuk_eleman(OY,a);
    //printf(" %d ",buyuk_eleman(OY,a));

    if (largest == OY[a][0])
    {
        MV[a][0]++;
        OY[a][0] = OY[a][0]/2;
    }
     else if (largest == OY[a][1])
    {
        MV[a][1]++;
        OY[a][1] = (OY[a][1])/2;
    }
    else if (largest == OY[a][2])
    {
        MV[a][2]++;
        OY[a][2] = (OY[a][2])/2;
    }
    else if (largest == OY[a][3])
    {
        MV[a][3]++;
        OY[a][3] = (OY[a][3])/2;
    }

    }


}

void bilgi_islem(int OY[][4], int s)
{

printf("Il Plaka Kodu : %d\n",s+1);
printf("Milletvekili Kontenjani : %d\n",MK[s]);
printf("Gecerli Oy Sayisi : %d\n",oylari_topla(OY,s));
}



int main()
{
    int OY[4][4];
    int i,j,l;
    char k;
    int AT=0,BT=0,CT=0,DT=0,TT=0;
    int MVA=0,MVB=0,MVC=0,MVD=0,MVT=0;
    float MVAY1,MVAY2,MVAY3,MVAY4;


    float TGY1,TGY2,TGY3,TGY4;
    for(i=0;i<4;i++)
    {
        printf("%d. ilin milletvekili kontenjan sayisini giriniz: ",i+1);
        scanf("%d",&MK[i]);
    }



    printf("\n");
     for (j=0;j<4;j++)
     {
        for (k='A',l=0;k<'E',l<4;k++,l++){
            printf("%d. ildeki %c partisinin aldigi oy sayisini giriniz: ",j+1,k);
            scanf("%d",&OY[j][l]);}
            printf("\n");
     }


     //oy toplam

     for(i=0;i<4;i++)
        AT += OY[i][0];

     for(i=0;i<4;i++)
        BT += OY[i][1];

     for(i=0;i<4;i++)
        CT += OY[i][2];

     for(i=0;i<4;i++)
        DT += OY[i][3];

        TT = AT+BT+CT+DT;
     //oyyuzde

     TGY1 = (float)AT/TT*100;
     TGY2 = (float)BT/TT*100;
     TGY3 = (float)CT/TT*100;
     TGY4 = (float)DT/TT*100;



     //dizi kopyalama
     for(i=0;i<4;i++)
     {
         for(j=0;j<4;j++)
         {
             kopya[i][j] = OY[i][j];
         }
     }


     for(i=0;i<4;i++)
     {
printf("\n");
bilgi_islem(OY,i);
printf("\n");

diziyi_sirala(OY,i);
printf("\n");

dizi_sira(kopya,i);

yuzde(OY,i);

printf("\n");
MV_atama(OY,i);

if(harfler[0]=='A')
    MVA += MV[i][0];
else if(harfler[1]=='A')
    MVA += MV[i][1];
else if(harfler[2]=='A')
    MVA += MV[i][2];
else if(harfler[3]=='A')
    MVA += MV[i][3];

if(harfler[0]=='B')
    MVB += MV[i][0];
else if(harfler[1]=='B')
    MVB += MV[i][1];
else if(harfler[2]=='B')
    MVB += MV[i][2];
else if(harfler[3]=='B')
    MVB += MV[i][3];


if(harfler[0]=='C')
    MVC += MV[i][0];
else if(harfler[1]=='C')
    MVC += MV[i][1];
else if(harfler[2]=='C')
    MVC += MV[i][2];
else if(harfler[3]=='C')
    MVC += MV[i][3];


if(harfler[0]=='D')
    MVD += MV[i][0];
else if(harfler[1]=='D')
    MVD += MV[i][1];
else if(harfler[2]=='D')
    MVD += MV[i][2];
else if(harfler[3]=='D')
    MVD += MV[i][3];


printf("\n");
sehir(OY,i);

printf("Devam etmek icin bir tusa basiniz...\n\n");
getch();
     }
for(i=0;i<4;i++)
{
    MVT += MK[i];
}

//MV yuzde
     MVAY1 = (float)MVA/MVT*100;
     MVAY2 = (float)MVB/MVT*100;
     MVAY3 = (float)MVC/MVT*100;
     MVAY4 = (float)MVD/MVT*100;

printf("\n");

//Turkiye Geneli
printf("Turkiye Geneli\n");
printf("Milletvekili Kontenjani : %d\n",MVT);
printf("Gecerli Oy Sayisi : %d\n",TT);

 printf("             Oy Sayisi         Oy Yuzdesi          MV Sayisi          MV Yuzdesi\n");
 printf("            ----------         ----------         -----------         -----------\n");

printf("A partisi %10d %20.2f %15d %20.2f\n",AT,TGY1,MVA,MVAY1);
printf("B partisi %10d %20.2f %15d %20.2f\n",BT,TGY2,MVB,MVAY2);
printf("C partisi %10d %20.2f %15d %20.2f\n",CT,TGY3,MVC,MVAY3);
printf("D partisi %10d %20.2f %15d %20.2f\n",DT,TGY4,MVD,MVAY4);















}
