#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	int n;			//na ile grafow dzielimy
	int x;			//numer wierzcholka poczatkowego
	int y;			//numer wierzcholka koncowego
	double a;		//poczatek zakresu wagi
	double b		//koniec zakresu wagi
	char* plikwej;
	char* plikwyj;
	int wysokosc,szerokosc;
	int l1;		//licznik do parsowania
	char* bufor=malloc(sizeof( char)* 10);  //string pomocniczy dla flag
	for(l1=1;l1<argc;l1++)
	{
		if(argv[l1][0]=='-')	//zauwazono flage
		{
			strncpy(bufor,&argv[l1][1],5);
		//	if(bufor=="help")			
			if(strcmp(bufor,"help")==0)
			{
			printf("Tutaj będzie pomoc\n");
			return 0;
			}
			
			if(strcmp(bufor,"l.graf")==0)
			{
				if(l1+1<argc && czyint(argv[l1]))
				{
				n=atoi(argv[l1+1]);
				l++;
				continue;
				}
                       		else
                        	{
                       		printf("Wprowadzono nieodpowiedni argument lub wogó le go nie wprowadzono. Należy wywoł ać program z flagą -help\n")
                        	}

			}
			if(strcmp(bufor,"startw")==0)
                        {
                                if(l1+1<argc && czyint(argv[l1]))
                                {
                                x=atoi(argv[l1+1]);
                                continue;
				l++;
                                }
                                else
                                {
                                printf("Wprowadzono nieodpowiedni argument lub wogó  le go nie wprowadzono. Należy wywoł  ać program z flagą -help\n")
                                }

                        }
			if(strcmp(bufor,"koniecw")==0)
                        {
                                if(l1+1<argc && czyint(argv[l1]))
                                {
                                y=atoi(argv[l1+1]);
                                l++;
				continue;
                                }
                                else
                                {
                                printf("Wprowadzono nieodpowiedni argument lub wogó  le go nie wprowadzono. Należy wywoł  ać program z flagą -help\n")
                                }

                        }
			if(strcmp(bufor,"wagap")==0)
                        {
                                if(l1+1<argc && czydouble(argv[l1]))
                                {
                                a=atoi(argv[l1+1]);
                                l++;
				continue;
                                }
                                else
                                {
                                printf("Wprowadzono nieodpowiedni argument lub wogó  le go nie wprowadzono. Należy wywoł  ać program z flagą -help\n")
                                }

                        }
			if(strcmp(bufor,"wagak")==0)
                        {
                                if(l1+1<argc && czydouble(argv[l1]))
                                {
                                b=atoi(argv[l1]);
                                l++;
				continue;
                                }
                                else
                                {
                                printf("Wprowadzono nieodpowiedni argument lub wogó  le go nie wprowadzono. Należy wywoł  ać program z flagą -help\n")
                                }

                        }
			if(strcmp(bufor,"filein")==0)
                        {
                                if(l1+1<argc)
                                {
                                strcpy(plikwej,argv[l1+1]);
                                l++;
				continue;
                                }
                                else
                                {
                                printf("Wprowadzono nieodpowiedni argument lub wogó  le go nie wprowadzono. Należy wywoł  ać program z flagą -help\n")
                                }

                        }
			if(strcmp(bufor,"fileout")==0)
                        {
                                if(l1+1<argc)
                                {
                                strcpy(plikwyj,argv[l1+1]);
                                l++;
				continue;
                                }
                                else
                                {
                                printf("Wprowadzono nieodpowiedni argument lub wogó  le go nie wprowadzono. Należy wywoł  ać program z flagą -help\n")
                                }

                        }
			printf("Wprowadzono nieznaną flagę wejściową, program kończy swoje działanie.\n
			W celu uzyskania informacji o wywołaniu programu należy go wywołać z użyciem flagi -help\n")
			return 0;


		}
	}
//	otworzenie_pliku_i_sprawdzenie_danych(plikwej);		
	czytanie_z_pliku(wysokosc,szerokosc,plikwej,mac_sasiedztwa);
//	podzial_grafu(mac_sasiedztwa);
			

		
	return 0;
}
