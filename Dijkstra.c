#include "Utility.h"
//#include "Dijkstra.h"

void dijkstra(struct Graf* graf, int w_pocz)        //ta funkcja calkowicie niespodziewanie *werble* no robi caly algorytm dijskstry, wywoluje poprzednio
{                                                   //zrobione funkcje i operuje wszystkim i rozwiazuje wszystkie nasze slodkie problemy

 
    int l_w = graf->l_wierz;        //ile wierzchlkow w grafiksie
    double odleglosci[l_w];
    struct kolejka_minimalna* kol_min = utworz_kolejke_min(l_w);
    int j;     

    for (j = 0; j < l_w; j++)         //rozpoczynam kopco kolejke 
    {
        odleglosci[j] = NIESKONCZONOSC;
        kol_min->t[j] = nowy_wezel_min(j,odleglosci[j]);
        kol_min->r[j] = j;
    }

    kol_min->t[w_pocz] = nowy_wezel_min(w_pocz, odleglosci[w_pocz]);        //ustalam odleglosc o wezla poczatkowego na 0 
    kol_min->r[w_pocz] = w_pocz;                                            
    odleglosci[w_pocz] = 0;
    pomniejszanko(kol_min, w_pocz, odleglosci[w_pocz]);                     //przechodze pomiejszankiem po kolejko drzewie

    kol_min->l_wezlow = l_w;        

    while (!sprawdzenie_czy_cos_jest(kol_min))
    {

        struct wezel_o_min_wadze* wezel_min = znajdz_min(kol_min);      //wybieram wieczholek o minimalnej odleglosci
        int nr_w = wezel_min->wierz;

        struct ListaPoziom* o = graf->t[nr_w].teges;        //przechodze po sasiednich wierzcholkach do tego, bo jak o bedzie NULLEM to znaczy ze lista sie konczy
        while (o != NULL)
        {
            int v = o->wierz;

            if (czy_wierz_w_min_kolejce(kol_min, v) && odleglosci[nr_w] != NIESKONCZONOSC && o->waga + odleglosci[nr_w] < odleglosci[v]) //warunek jak znajdujemy lepsza odlegosc niz mamy wczesniej
            {
                odleglosci[v] = odleglosci[nr_w] + o->waga;
                pomniejszanko(kol_min, v, odleglosci[v]);
            }
            o = o->next;        //przechodze do nastepnej pozycji 
        }
    }

    wypisz_tablice_odl(odleglosci, l_w);        //operacja wypisania taktycznego wszystkiego, co trzeba tam wypisac
}
