#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define YUKARI 72
#define ASAGI 80
#define SOL 75
#define SAG 77

#define BOYUT 4
#define SINIR 219
#define ESC 57
#define PR 2

int Matris[BOYUT+1][BOYUT+1]={0};
int puan=0,son=2048;

void baslangic();
void bekle();
void bekleuzun();
void yazdirici(char []);
void vadi();
void Goster();
void her_seyi_yazdir();
void Eylem(int);
void Rastgele_olustur(int);
void Baslangic_Rastgele();
int Geçici_say();
void bitis();
int Asagi();
int Yukari();
int Sol();
int Sag();

void baslangic()
{
    int i;
    char s1[]="\xdb\xdb HOSGELDINIZ \xdb\xdb";
    char s2[]="BASLAMAK ICIN HERHANGI BIR TUSA BASIN";
    char s3[]="TEK OYUNCULU PUZZLE OYUNU";
    
    char s5[]="C'DE 2048'E HOSGELDINIZ";

    char t[]="UGUR POLAT";
    char t1[]="BOLU ABANT IZZET BAYSAL UNIVERSITESI";
    char t2[]="BILGISAYAR MUHENDISLIGI";
    char t3[]="C PROGRAMLAMA";

    bekleuzun();
    bekleuzun();

    printf("\n\n\n\n\n\n\n\t\t\t\t");
    yazdirici(s1);
    bekleuzun();
    bekleuzun();
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
    yazdirici(s2);
    while(!kbhit());

    printf("\n\n\n\n\t");
    yazdirici(s5);
    bekleuzun();
    printf("\n\n\n\n\t\t");
    bekleuzun();
    yazdirici(s3);
    bekleuzun();
    bekleuzun();
    bekleuzun();
    bekleuzun();
    bekleuzun();
    bekleuzun();
    for(i=0;i<20;i++)
    {
        bekleuzun();
    }
    
    system("cls");

    printf("\n\n\t\t\t\t\t");
    yazdirici(t);
    bekleuzun();
    printf("\n\n\n\n\t");
    yazdirici(t1);
    printf("\n\n\t");
    yazdirici(t2);
    printf("\n\n\t");
    yazdirici(t3);
    printf("\n\n\t");
    
    for(i=0;i<50;i++)
    {
        bekleuzun();
    }
    

    printf("\n\n\t\t\t BILGILENDIRME\n\n\n");
    printf(" ->  Ok tuslariyla hareket edebilirsiniz\n\n");
    printf(" ->  Kazanmak icin herhangi bir kutunun 2048 olması gerekir\n\n");
    printf("\t\t\t\t\t\tBASLAMAK ICIN HERHANGI BIR TUSA BASIN\n");
    while(!kbhit());
}

void bekle()
{
    int i;
    for(i=0;i<4500000;i++);
}

void bekleuzun()
{
    int i;
    for(i=0;i<25;i++)
    {
        bekle();
    }
}

void yazdirici(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        printf("%c",s[i]);
        bekle();
        bekle();
        i++;
    }
}

void Eylem(int Ok)
{
    switch(Ok)
    {
        case YUKARI:
            Yukari(); 
            break;
        case ASAGI:
            Asagi();
            break;
        case SOL:
            Sol(); 
            break;
        case SAG:
            Sag(); 
            break;
        default:
            return;
    }

    Rastgele_olustur(puan); 
    puan = Geçici_say(); 
    Goster();
}

void Rastgele_olustur(int oncekiPuan)
{
    int temp1, temp2, ekle, i, j;
    srand(time(NULL));
    temp1 = rand() % BOYUT; 
    srand(time(NULL));
    temp2 = rand() % BOYUT; 

    if ((temp1 + temp2) % 2 == 0)
        ekle = 2;
    else
        ekle = 4; 

    for (i = 0; i < BOYUT; i++)
    {
        for (j = 0; j < BOYUT; j++)
        {
            if (Matris[i][j] == 0)
            {
                Matris[i][j] = ekle; 
                puan += ekle; 
                return; 
            }
        }
    }
}

void Goster()
{
    int i,j;
    system("cls"); 
    her_seyi_yazdir();
    for(i=0;i<BOYUT;i++)
    {
        printf("\t\t\t %c",SINIR); 
        for(j=0;j<BOYUT;j++)
        {
            if(Matris[i][j]==0)
            {
                printf("      "); 
            }
            else
                printf(" %4d ",Matris[i][j]); 
        }
        printf("%c\n\t\t\t %c                        %c\n",SINIR,SINIR,SINIR);
    }
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR);
}

void her_seyi_yazdir()
{
    printf("\n\n\n\t\t\t2-0-4-8\n");
    printf("\t\t\t\t\t\t\t\t PUAN  : %d\n\n\n\n",puan); 
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR,SINIR);
}

void bitis()
{
    printf("\n\n\t\t\t\tPUANINIZ  : %d",puan); 
}

void Baslangic_Rastgele()
{
    Matris[3][1]=8;
    Matris[3][2]=32;
    Matris[3][3]=16;
    Matris[2][2]=8;
    Matris[2][3]=8;
    Matris[1][2]=8;

    Goster(); 
}

int Geçici_say()
{
    int temp = 0;
    int maxBlok = 0;
    int i, j;

    for(i = 0; i < BOYUT; i++)
    {
        for(j = 0; j < BOYUT; j++)
        {
            if (Matris[i][j] == 2048) 
                return 2048; 
            if (Matris[i][j] == 0)
                temp = 1; 
            if (Matris[i][j] > maxBlok) 
                maxBlok = Matris[i][j];
        }
    }
    
    if (temp == 1)
    {
        son = 0; 
        return maxBlok; 
    }
    else
    {
        if (son == 1)
        {
            return 0; 
        }
        son = 1; 
        return maxBlok; 
    }
}

int Asagi()
{
    int i, j; 
    for (j = 0; j < BOYUT; j++)
    {
        i = BOYUT - 2;
        while (1)
        {
            while (Matris[i][j] == 0)
            {
                if (i == -1)
                    break;
                i--;
            }
            if (i == -1)
                break;
            while (i < BOYUT - 1 && (Matris[i + 1][j] == 0 || Matris[i + 1][j] == Matris[i][j]))
            {
                if (Matris[i + 1][j] == Matris[i][j])
                {
                    Matris[i + 1][j] *= 2; 
                    puan += Matris[i + 1][j]; 
                    Matris[i][j] = 0; 
                    break;
                }
                Matris[i + 1][j] = Matris[i][j]; 
                Matris[i][j] = 0; 
                i++;
            }
            i--;
        }
    }
}

int Yukari()
{
    int i, j; 
    for (j = 0; j < BOYUT; j++)
    {
        i = 1;
        while (1)
        {
            while (Matris[i][j] == 0)
            {
                if (i == BOYUT)
                    break;
                i++;
            }
            if (i == BOYUT)
                break;
            while (i > 0 && (Matris[i - 1][j] == 0 || Matris[i - 1][j] == Matris[i][j]))
            {
                if (Matris[i - 1][j] == Matris[i][j])
                {
                    Matris[i - 1][j] *= 2;
                    puan += Matris[i - 1][j]; 
                    Matris[i][j] = 0; 
                    break;
                }
                Matris[i - 1][j] = Matris[i][j]; 
                Matris[i][j] = 0;
                i--;
            }
            i++;
        }
    }
}

int Sol()
{
    int i, j; 
    for (i = 0; i < BOYUT; i++)
    {
        j = 1;
        while (1)
        {
            while (Matris[i][j] == 0)
            {
                if (j == BOYUT)
                    break;
                j++;
            }
            if (j == BOYUT)
                break;
            while (j > 0 && (Matris[i][j - 1] == 0 || Matris[i][j - 1] == Matris[i][j]))
            {
                if (Matris[i][j - 1] == Matris[i][j])
                {
                    Matris[i][j - 1] *= 2; 
                    puan += Matris[i][j - 1]; 
                    Matris[i][j] = 0; 
                    break;
                }
                Matris[i][j - 1] = Matris[i][j]; 
                Matris[i][j] = 0;
                j--;
            }
            j++;
        }
    }
}

int Sag()
{
    int i, j; 
    for (i = 0; i < BOYUT; i++)
    {
        j = BOYUT - 2;
        while (1)
        {
            while (Matris[i][j] == 0)
            {
                if (j == -1)
                    break;
                j--;
            }
            if (j == -1)
                break;
            while (j < BOYUT - 1 && (Matris[i][j + 1] == 0 || Matris[i][j + 1] == Matris[i][j]))
            {
                if (Matris[i][j + 1] == Matris[i][j])
                {
                    Matris[i][j + 1] *= 2; 
                    puan += Matris[i][j + 1];
                    Matris[i][j] = 0; 
                    break;
                }
                Matris[i][j + 1] = Matris[i][j]; 
                Matris[i][j] = 0; 
                j++;
            }
            j--;
        }
    }
}

int main()
{
    int aro; 
    char Ok; 
    char s[] = "BIR DAHAKI SEFERE BOL SANSLAR PUANIN ";
    int temp; 
    baslangic();
    Baslangic_Rastgele();
    Ok = ASAGI; 
    while (Ok != ESC) 
    {
        Ok = getch(); 
        aro = Ok; 
        Eylem(Ok); 
        temp = Geçici_say(); 
        if (temp == 1)
        {
            printf("\n\t\t\tKAZANDIN"); 
            bitis(); 
            break; 
        }
        if (temp == 0 || puan < 0) 
        {
            printf("\n\t\t\tKAYBETTIN\n"); 
            break; 
        }
    }

    system("cls"); 
    printf("\n\n\n\t");
    yazdirici(s); 
    bitis();
    bekleuzun();  
    bekleuzun(); 
    bekleuzun();  
    bekleuzun(); 
}
