#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
//210229024 Muhammet Yaşar
char vowel[8]= {'a','e','i',(char)141,'u',(char)129,'o',(char)148};//ünlü
char low_vowel[8]= {'a',(char)141,'u','o','A','I','U','O'}; //kalın ünlü
char high_vowel[8]= {'E',(char)152,(char)153,'e','i',(char)148,(char)129}; //ince ünlü
char nonvowel[21]= {'z','y','v','t',(char)159,'s','r','p','n','r','m','l','k','h','j',(char)167,'g','d',(char)135,'c','b'};//ünsüz
char strong_l[8]= {'f','s','t','k',(char)135,(char)159,'h','p'};
char numbers[10]={'0','1','2','3','4','5','6','7','8','9'};
char punct[7]={'.',',',';',':','?','!',' '};

void connexion(char str[],char vowel[],char nonvowel[])//ULAMA
{
    int toplam,i,j,z,ulama=0;
    int k,x;
    for(i=0; i<strlen(str); i++)
    {
        if(str[i]==' ')//BOŞLUK KONTROLÜ
        {
            for(j=0; j<21; j++)
            {
                if(str[i-1]==nonvowel[j])//ÜNSÜZ KONTROLÜ
                {
                    for(z=0; z<8; z++)
                    {
                        if(str[i+1]==vowel[z])//ÜNLÜ KONTROLÜ
                        {
                            ulama++;
                            k=i+1;
                            x=i-1;
                            for(k=i+1; k; k++)//ULAMADAKİ ÜNLÜ HARFİN OLDUĞU KELİMENİN SONUNA GİDİYOR.
                            {
                                if(str[k]==' ')
                                {
                                    break;
                                }
                            }
                            for(x=i-1; x; x--)//ULAMADAKİ ÜNSÜZ HARFİN OLDUĞU KELİMENİN SONUNA GİDİYOR.
                            {
                                if(str[x]==' ')
                                {
                                    break;
                                }
                            }

                            for(x; x<k; x++)
                            {
                                printf("%c",str[x]);//YAZDIRMA
                            }

                            printf("\n");//KELİMELER DEN SONRA 1 SATIR AŞŞA İNME
                        }
                    }

                }
            }
        }
    }
    printf("%d ulama found\n",ulama);
}
void harmony(char cumle[])//Büyük Ünlü Uyumu
{
    int i,j,k,x;
    int ince=0,kalin=0;
    int lowharmony=0,highharmony=0;
    for(i=0; i<strlen(cumle); i++)
    {
        if(cumle[i]=='a'||cumle[i]==(char)141||cumle[i]=='u'||cumle[i]=='o')
        {
            kalin++;//kalın ünlüleri bulma
        }
        else if(cumle[i]=='e'||cumle[i]=='i'||cumle[i]==(char)148||cumle[i]==(char)129)
        {
            ince++;//ince ünlüleri bulma
        }
        else if(cumle[i]==' '|| cumle[i]=='.' )//kelime bitti konrole geçiyor.
        {
            if(kalin!=0&&ince==0)
            {
                lowharmony++;//kelimede ince harf yoksa kalın ünlü uyumu sağlanıyor.
                k=i;
                for(x=i;x;x--)
                {
                    if(cumle[x-1]==' '||cumle[x-1]=='.'||cumle[x-1]==','||cumle[x-1]=='?')
                    {
                        break;
                    }
                }
                for(x;x<k;x++)
                {
                    printf("%c",cumle[x]);

                }
                printf("\n");

            }
            else if(kalin==0&&ince!=0)
            {
                highharmony++;//kalın harf yoksa ince ünlü uyumu
                 k=i;
                for(x=i;x;x--)
                {
                    if(cumle[x-1]==' '||cumle[x-1]=='.'||cumle[x-1]==','||cumle[x-1]=='?')
                    {
                        break;
                    }
                }
                for(x;x<k;x++)
                {
                    printf("%c",cumle[x]);
                }

            printf("\n");
            }
            ince=0;
            kalin=0;
        }
    }
    printf("%d harmony found.",lowharmony+highharmony);
}
void connective(char str[])//bağlaç
{
   int i;
   int sum=0;
   for(i=0;i<strlen(str);i++)
   {
       if(str[i]=='d')
       {
           if(str[i+1]=='e'||str[i+1]=='a')
           {
               if(str[i+2]==' ')
               {
                 sum++;
               }

           }
       }
       else if(str[i]=='v')
       {
           if(str[i+1]=='e')
           {
             if(str[i+2]==' ')
             {
                 sum++;
             }
           }
       }
        else if(str[i]=='k')
       {
           if(str[i+1]=='i')
           {
             if(str[i+2]==' ')
             {
                 sum++;
             }
           }
       }
   }
   printf("%d connective word found.",sum);
}
void plural(char str[])//çoğul
{
    int toplam,i,x,k,cogul=0;
    toplam=strlen(str);
    for(i=0; i<toplam; i++)
    {
        if(str[i]=='l'  )
        {
            if(str[i+1]=='e' ||str[i+1]=='a')
            {
                if(str[i+2]=='r')
                {
                    cogul++;

                    for(k=i; k; k++)
                    {
                        if(str[k]==' ')
                        {
                            break;
                        }
                    }
                    for(x=i; x; x--)
                    {
                        if(str[x]==' ')
                        {
                            break;
                        }
                    }

                    for(x; x<k; x++)
                    {
                        printf("%c",str[x]);
                    }

                    printf("\n");
                }
            }
        }
    }
    printf("%d plural words found.",cogul);
}
void sentence(char str[])//cümle sayıı
{
    int toplam,i,cumle=0;
    toplam=strlen(str);
    for(i=0; i<toplam; i++)
    {
        if(str[i]=='.')
        {
            cumle++;
        }
    }
    printf("%d sentences found.",cumle);
}
void letter(char str[])//harf sayısı
{
    int sum=strlen(str);
    int toplam=sum;
    int i,j,z;
    for(i=0; i<sum; i++)
    {
        for(z=0;z<7;z++)
        {
            if(str[i]==punct[z])
            {
                toplam--;
            }
        }
        for(j=0;j<10;j++)
        {
            if(str[i]==numbers[j])
            {
               toplam--;
            }
        }

    }
    printf("%d letters found.",toplam);
}
void word_count(char str[])//kelime sayısı
{
    int word=0,i;
    int sum=strlen(str);
    for(i=0; i<sum; i++)
    {
        if(str[i]==' ')
        {
            word++;
        }

    }
    printf("%d words found.",word+1);
}
void strong(char str[],char bold[])
{
    int sum=strlen(str),j,i,strong;
    for(i=0; i<sum; i++)
    {
        for(j=0; j<8; j++)
        {
            if(str[i]==bold[j])
            {
                if(str[i+1]=='ç'||str[i+1]=='t'||str[i+1]=='k')
                {
                    strong++;
                }
            }
        }
    }
    printf("%d strong found.",strong);
}
int main()
{
    setlocale(LC_ALL, "Turkish.turkey_1254");
    char s1[10000];
    int answer;
    char ans2;
    printf("Please enter a text that you want to check.\n");//metin girişi
    gets(s1);
    printf("Please choose what yo want to get checked:\n");//menü
    printf("1.Connexion\n");//ulama
    printf("2.Harmony\n");//büyük-kücük ünlü uyumu
    printf("3.Connective Words\n"); //benzeşme
    printf("4.Plural Words\n");// Çoðul kelimeler.
    printf("5.Number of Sentences\n");//cümle sayısı
    printf("6.number of letters\n");//Harf Sayisi
    printf("7.number of words\n");//Kelime Sayisi
    printf("8.number of strong words\n");//Benzeşme


    scanf("%d",&answer);
    while(answer)
    {
        if(answer==1)
        {
            connexion(s1,vowel,nonvowel);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }
        else if(answer==2)
        {
            harmony(s1);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }
        else if(answer==3)
        {
            connective(s1);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }
        else if(answer==4)
        {
            plural(s1);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }
        else if(answer==5)
        {
            sentence(s1);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }
        else if(answer==6)
        {
            letter(s1);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }
        else if(answer==7)
        {
            word_count(s1);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }
         else if(answer==8)
        {
            strong(s1,strong_l);
            printf("\nDo you want to check another rule?\n");
            scanf("%s",&ans2);
            if(ans2=='Y' || ans2=='y')
            {
                printf("Please choose what yo want to get checked:\n");
                scanf("%d",&answer);
            }
            else
            {
                printf("Thanks for using our program");
            }
        }

    }

    return 0;
}
