#include <stdio.h>
#include <stdlib.h>
#include "Pomocnicze.h"
int main(int argc, char **argv)
{
	int n;			//na ile grafow dzielimy
	int x;			//numer wierzcholka poczatkowego
	int y;			//numer wierzcholka koncowego
	double a;		//poczatek zakresu wagi
    double b;		//koniec zakresu wagi
    int flagan = 0, flagaa = 0, flagab = 0, flagax = 0, flagay = 0, flagafs = 0, flagafw = 0;
	char * plikwej= malloc(sizeof(char) * 10);
	char * plikwyj= malloc(sizeof(char) * 10);
	int wysokosc,szerokosc;
    int flagapliku = 0;
	int l1;		//licznik do parsowania
	char* bufor=malloc(sizeof( char)* 10);  //string pomocniczy dla flag
	for(l1=1;l1<argc;l1++)
    {
       
		if(argv[l1][0]=='-')	//zauwazono flage
        {
			strncpy(bufor,&argv[l1][1],10);
		
			if(strcmp(bufor,"help")==0)	{
			    printf("Program generuje niskierowany ważony graf o wyznaczonj liczbie wierszy i kolumn, po czym sparwdza czy on jest spójny i zuka najkrótszą drogę między wybranymi parami węzłów.\n");
                printf(".//a.out [-filein file] [//-l.graf n] [//-fileout file] [//-startw x][//-koniecw y] [//-wagap a] [//-wagak b] [// -help]\n");
                printf("Argumenty \n");
                printf("\t-filein file  - informuje, że w pliku file jest zawarty graf\n");
                printf("\t-l.graf n	- program podzieli graf na n grafó. Domyślnie n=1\n");
                printf("\t-fileout file - plik wyjściowy o nazwie file\t");
                printf("\t-startw x	- podaje numer wierzchołka początkowego dla szukania najkrótszej ścieżki. Domyślnie x - pierwszy wierzchołek grafu\n");
                printf("\t-koniecw y	- podaje numer wierzchołka końcowego dla szukania najkrótszej ścieżki. Domyślnie y - ostatni wierzchołek grafu\n");
                printf("\t-wagap a	- podaje minimumalne znaczenie do generowania wag. Domyślnie a=1\t");
                printf("\t-wagak b	- podaje maksymalne znaczenie do generowania wag. Domyślnie b=100\n");
                printf("\t-help		- wypisje dla użytkownika opis programu oraz agrumentów wywołania\n");
			return 0;
			}

			if(strcmp(bufor,"l_graf")==0)
            {
                flagan = 1;

				if(l1+1<argc && czyint(argv[l1+1]))
                {
                
				n=atoi(argv[l1+1]);

				l1++;
				continue;
				}
                       		else
                        	{
                              n = 1;
                              continue;
                            }

			}
			if(strcmp(bufor,"startw")==0)
            {
                flagax = 1;

                                if(l1+1<argc && czyint(argv[l1+1]))
                                {
                                x=atoi(argv[l1+1]);
                                l1++;
                                continue;
                                }
                                else
                                {
                                    x = 0;
                                    continue;
                                }

                        }
			if(strcmp(bufor,"koniecw")==0)
            {
                flagay = 1;

                                if(l1+1<argc && czyint(argv[l1+1]))
                                {
                                y=atoi(argv[l1+1]);
                                l1++;
				                continue;
                                }
                                else
                                {
                                    y = (wysokosc * szerokosc) - 1;
                                    continue;
                                }

                        }
			if(strcmp(bufor,"wagap")==0)
            {
                flagaa = 1;

                                if(l1+1<argc && czydouble(argv[l1+1]))
                                {
                                    printf("%f\n", atof(argv[l1 + 1]));
                                a=atof(argv[l1+1]);
                                l1++;
			                	continue;
                                }
                                else
                                {
                                    a = 1;
                                    continue;
                                }

                        }
			if(strcmp(bufor,"wagak")==0)
            {
                flagab = 1;

                                if(l1+1<argc && czydouble(argv[l1+1]))
                                {
                                b=atof(argv[l1+1]);
                                l1++;
				                continue;
                                }
                                else
                                {
                                    b = 100;
                                    continue;
                                }

                        }
			if(strcmp(bufor,"filein")==0)
            {
                flagafs = 1;

                                if(l1+1<argc && argv[l1+1][0]!='-')
                                {
                                strcpy(plikwej,argv[l1+1]);
                                l1++;
				                continue;
                                }
                                else
                                {
                                    plikwej = "losowanko";
                                    wysokosc = 100;
                                    szerokosc = 100;
                                    flagapliku = 1;
                                    continue;
                                }

                        }
			if(strcmp(bufor,"fileout")==0)
            {
                flagafw = 1;
                                if(l1+1<argc && argv[l1 + 1][0] != '-')
                                {

                                strcpy(plikwyj,argv[l1+1]);
                                l1++;
				                continue;
                                }
                                else
                                {
                                    plikwyj = "stdout";
                                    continue;
                                }

                        }
            printf("Wprowadzono nieznana flage wejsciowa, program konczy swoje dzialanie.\n W celu uzyskania informacji o wywolaniu programu nalezy go wywolac z uzyciem flagi -help\n");
			


		}
	}
    if (flagaa == 0)
    {
        a = 1;
    }
    if (flagab == 0)
    {
        b = 100;
    }
    if (flagax == 0)
    {
        x = 0;
    }
    if (flagay == 0)
    {
        y = (wysokosc*szerokosc)-1;
    }
    if (flagafs == 0)
    {
        plikwej = "losowanko";
    }
    if (flagafw == 0)
    {
         plikwyj="stdout";
    }
    if (flagan == 0)
    {
        n = 1;
    }

    printf("n=%d\n", n);
       printf("x = % d\n",x);
       printf("y = % d\n",y);
        printf("a = % f\n", a);
        printf("b = % f\n",b);
        printf("filein = % s\n", plikwej);
        printf("fileout = % s", plikwyj);
//	otworzenie_pliku_i_sprawdzenie_danych(plikwej);		
//	czytanie_z_pliku(wysokosc,szerokosc,plikwej,lis_sasiedztwa);
//	podzial_grafu(lis_sasiedztwa);
//   BFS()
			

		
	return 0;
}
