#include "pomocnicze.h"

double generator_double(double min, double max)
{
srand(time(NULL));
double losowa=((double) rand()) / RAND_MAX;
double zasieg=(max-min)*losowa;
double liczba = min+zasieg;
return liczba;
}

int czyint(char numer[])
{
int v=0;
if(numer[0]=='-')
	v++;
for(;numer[v]!=0;v++)
{
if(!isdigit(numer[v]))
	return 0;
}
return 1;
}

int czydouble(char numer[])
{
	int v=0;
	int l=0;
if(numer[0]=='-')
	v++;
for(;numer[v]!=0;v++)
{
if(!isdigit(numer[v]))
	if((/*numer[v] == ',' ||*/ numer[v] == '.') && l == 0)
	{
		l++;
		continue;
	}
	else
	return 0;
}
return 1;
}


