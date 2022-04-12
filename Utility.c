#include "Utility.h"



struct ListaPoziom* dodaj_wezel( int wierzcholek, double waga)      //ta funkcja calkowicie niespodziewanie *werble* dodaje krawedzi do listy
{
    struct ListaPoziom* wezel = malloc(sizeof(struct ListaPoziom));     //alokowanko
    wezel->wierz = wierzcholek;     //przypisanie wartosci wszelakich i przedluzenie listy tak o 
    wezel->waga = waga;
    wezel->next = NULL;
    return wezel;       //zwracanko wskaznika na wezel
}
struct Graf * Rozpoczecie_wszystkiego(int l_w) //ta funkcja calkowicie niespodziewanie *werble* alokuje graf i ogolnie wszystko w nim wpisuje
{
    struct Graf * graf = malloc(sizeof(struct Graf));
    graf->l_wierz = l_w;

    
    graf->t = malloc(l_w * sizeof(struct Lista));       //tablica do listy o rozmiarze ilosci wierzcholkow

    int i;
    for ( i = 0; i < l_w; ++i)      //inicjacja tablicy co daje wskazniki tegesom na puste miejsce
        graf->t[i].teges = NULL;

    return graf;        //zwracam wskaznik na graf
}
void dodaj_krawedz(struct Graf* graf, int wierz_pocz, int wierz_konc, double waga)     // ta funkcja calkowicie niespodziewanie* werble* dodaje krawedzie do grafu
{

    struct ListaPoziom * wezel = dodaj_wezel(wierz_konc, waga);     //te trzy linijki dodaj¹ wezel do listy na poczatku 
    wezel->next = graf->t[wierz_pocz].teges;
    graf->t[wierz_pocz].teges = wezel;

    // Since graph is undirected,
    // add an edge from dest to src also
    wezel = dodaj_wezel(wierz_pocz, waga);      //te linijki powinny zrobic to samo co tamte ale odwrotnie, bo mamy graf nieskierowany wiec wagi sie powtarzaja, a przynajmniej powinny z zamyslu
    wezel->next = graf->t[wierz_konc].teges;
    graf->t[wierz_konc].teges = wezel;
}


struct wezel_o_min_wadze * nowy_wezel_min(int w, double waga)       //funkcja do alokacji i wpisania wartosci do struktury mini wezla
{
    struct wezel_o_min_wadze * wezel_mini = malloc(sizeof(struct wezel_o_min_wadze));
    wezel_mini->wierz = w;
    wezel_mini->waga_prz = waga;
    return wezel_mini;
}




struct kolejka_minimalna* utworz_kolejke_min(int poj)       //funckja rozpoczyna cala taka jakby strukture tej koleji panstwowej i alokuje miejsce odpowiednie potrzebne
{
    struct kolejka_minimalna* kolejka_min = malloc(sizeof(struct kolejka_minimalna));
    kolejka_min->r = malloc(poj * sizeof(int));
    kolejka_min->l_wezlow = 0;
    kolejka_min->maks_l_wez = poj;
    kolejka_min->t = malloc(poj * sizeof(struct wezel_o_min_wadze*));
    return kolejka_min;
}

void zamianka(struct wezel_o_min_wadze** x,  struct wezel_o_min_wadze** y)      //ta funkcja calkowicie niespodziewanie *werble* dokonuje taktycznej zamianki polozenia dwoch wezlow w kolejce za pomoc¹ wskaznikowej magii
{
    struct wezel_o_min_wadze* t = *x;
    *x = *y;
    *y = t;
}

void tegesownik(struct kolejka_minimalna* kol_min,  int w)      //no mysle ze kazdy wie do czego sluzy tegesownik - operacje z kolejka i te sprawy
{
    int mini,l,p;
    mini = w;
    l = 2 * w + 1;
    p = 2 * w + 2;

    if (l < kol_min->l_wezlow && kol_min->t[l]->waga_prz < kol_min->t[mini]->waga_prz)
        mini = l;

    if (p < kol_min->l_wezlow && kol_min->t[p]->waga_prz < kol_min->t[mini]->waga_prz)
        mini = p;

    if (mini != w)          //znaleziono lepszy mini wiec nalezy zamianke zrobic
    {
        struct wezel_o_min_wadze* mini_w = kol_min->t[mini];            //deklaracja wskaznikow co trzeba je zamienic
        struct wezel_o_min_wadze* wezel_w = kol_min->t[w];

        kol_min->r[mini_w->wierz] = w;              //zamiania miejscowek w kolejce z mini wezlem
        kol_min->r[wezel_w->wierz] = mini;              

        zamianka(&kol_min->t[mini], &kol_min->t[w]);        //podmianka wezlow za pomoca zamianki 

        tegesownik(kol_min, mini);
    }
}

int sprawdzenie_czy_cos_jest(struct kolejka_minimalna* kol_min)     //ta funkcja calkowicie niespodziewanie *werble* sprawdza czy kolejka jest pusta
{
    return kol_min->l_wezlow == 0;
}

// Standard function to extract
// minimum node from heap
struct wezel_o_min_wadze* znajdz_min(struct kolejka_minimalna* kol_min)     //funkcja ta znajduje z kolejki wierzcholek minimalny i zwraca wskaznik na niego
{
    if (sprawdzenie_czy_cos_jest(kol_min))
        return NULL;


    struct wezel_o_min_wadze* k = kol_min->t[0];    //przechowujemy korzonka    

    struct wezel_o_min_wadze* ostatni = kol_min->t[kol_min->l_wezlow - 1];      //dokonujemy taktycznej podmianki korzonka z ostatnim weirzcholkiem
    kol_min->t[0] = ostatni;

    kol_min->r[k->wierz] = kol_min->l_wezlow - 1;       //po podmiance trzeba ten ostatni wierzcholek zrobic cacy
    kol_min->r[ostatni->wierz] = 0;


    kol_min->l_wezlow--;        //po usunieciu zmieniamy rozmiar kolejki
    tegesownik(kol_min, 0);

    return k;
}

// Function to decreasy dist value
// of a given vertex v. This function
// uses pos[] of min heap to get the
// current index of node in min heap
void pomniejszanko(struct kolejka_minimalna* kol_min,int wierz, double waga)        //wlasciwie chyba mozna nazwac to sercem algorytmu nawet bym sie pokusil - ona operuje na wszelakich odleglosciach
{                                                                                   //znajduje wezly najlepsze i wogole przechodzi sobie po grafie

    int i = kol_min->r[wierz];          //i - znacznik wierz z tabeli indeksowej


    kol_min->t[i]->waga_prz = waga;         //dajemy wezlowi now¹ odleglosc

    while (i && kol_min->t[i]->waga_prz < kol_min->t[(i - 1) / 2]->waga_prz)        //przechodzimy po tej kolejce drzewiastej az nie dokonamy calkowitego skopcowania
    {
        kol_min->r[kol_min->t[i]->wierz] = (i - 1) / 2;     //zamianka wierzcholka z rodzicem
        kol_min->r[kol_min->t[(i - 1) / 2]->wierz] = i;
        zamianka(&kol_min->t[i],&kol_min->t[(i - 1) / 2]);

        i = (i - 1) / 2;        //przechodze do rodzica w kolejko drzewie
    }
}

int czy_wierz_w_min_kolejce(struct kolejka_minimalna* kol_min, int w)       //sprawdzalka czy wierczholek jest w kopcu
{
    if (kol_min->r[w] < kol_min->l_wezlow)
        return 1;
    return 0;
}


void wypisz_tablice_odl(double odleglosci[], int n)     //ta funkcja calkowicie niespodziewanie *werble* wypisuje wszystkie odleglosci do kazdego wierzcholka
{                                                       //wlasciwie to chyba nie jest potrzebna za bardzo bo mamy tylko do jednego wierzcholka odleglosci
    printf("Vertex   Distance from Source\n");          //ale jest to przydatna funkcja do robienia testow dzialania, ktorych nie przeprowadzilismy
    int i;
    for (i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, odleglosci[i]);
}

// The main function that calculates
// distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void dijkstra(struct Graf* graf, int w_pocz)        //ta funkcja calkowicie niespodziewanie *werble* no robi caly algorytm dijskstry, wywoluje poprzednio
{                                                   //zrobione funkcje i operuje wszystkim i rozwiazuje wszystkie nasze slodkie problemy

 
    int l_w = graf->l_wierz;        //ile wierzchlkow w grafiksie
    double odleglosci[l_w];
    struct kolejka_minimalna* kol_min = utworz_kolejke_min(l_w);
    int j;     

    for (j = 0; j < l_w; j++         //rozpoczynam kopco kolejke 
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

//void otworzenie_pliku_i_sprawdzenie_danych(char * plikwej, graf_str ** graf);	

