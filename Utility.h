#ifndef UTILITY_H
#define UTILITY_H
#include <ctype.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <limits.h>
#define NIESKONCZONOSC 100000000
struct ListaPoziom
{
    int wierz;
    double waga;
    struct ListaPoziom* next;
};

struct Lista
{
    struct ListaPoziom* teges; //wskaznik na pierwszy ten teges listy
};
struct Graf
{
    int l_wierz;
    struct Lista* t;        //tablica na graf
    int wiersze;
    int te_drugie;
};

struct wezel_o_min_wadze
{
    int  wierz;
    double waga_prz;
};

struct kolejka_minimalna                //szukajac wszelkich mozliwych informacji o dijkstrze stwierdzilismy ze Hindus z filmiku na Youtube calkiem madrze prawi wiec wybralismy tak¹ drzewiast¹ kolejke
{
    int l_wezlow;  //w koljece ile jest wezlow teraz
    int maks_l_wez;     //pojemnosc maksymalna kolejki - maks il. wezlow
    int* r;            // struktury pomocnicze do pomniejszanka
    struct wezel_o_min_wadze** t;
};

struct ListaPoziom* dodaj_wezel(int wierzcholek, double waga);

struct Graf* Rozpoczecie_wszystkiego(int l_w);

void dodaj_krawedz(struct Graf* graf, int wierz_pocz, int wierz_konc, double waga);

struct wezel_o_min_wadze* nowy_wezel_min(int w, double waga);

struct kolejka_minimalna* utworz_kolejke_min(int poj);

void zamianka(struct wezel_o_min_wadze** x, struct wezel_o_min_wadze** y);

void tegesownik(struct kolejka_minimalna* kol_min, int w);

int sprawdzenie_czy_cos_jest(struct kolejka_minimalna* kol_min);

struct wezel_o_min_wadze* znajdz_min(struct kolejka_minimalna* kol_min);

void pomniejszanko(struct kolejka_minimalna* kol_min, int wierz, double waga);

int czy_wierz_w_min_kolejce(struct kolejka_minimalna* kol_min, int w);

void wypisz_tablice_odl(double odleglosci[], int n);

void dijkstra(struct Graf* graf, int w_pocz);


//void otworzenie_pliku_i_sprawdzenie_danych(char * plikwej, graf_str ** graf);	
#endif
