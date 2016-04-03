/*@author Ronald Demeter*/

/*
Keď minule Jakubko nemohol zaspať, zobral si papier a začal si kresliť kopčeky. 

Prvý riadok vstupu obsahuje číslo N (1 ? N ? 20) vyjadrujúce počet úloh. Každá úloha pozostáva z riadku obsahujúceho dve celé čísla D (2 ? D ? 5000) a V (1 ? V ? 200). 

Výstup bude obsahovať N riadkov, pre každú úlohu jeden.
Obsahovať budú počet rôznych kopcov majúcich šírku D metrov a výšku presne V desiatok metrov.
Kopec pozostáva len z troch možných úsekov: stúpanie široké 1 meter a vysoké 10 metrov,
klesanie široké 1 meter a vysoké 10 metrov a rovinka široká 1 meter. Jednotlivé úseky musia na seba nadväzovať, 
výška nesmie presiahnuť V desiatok metrov, na začiatku a na konci musí mať kopec nulovú výšku a nikde inde nesmie
byť výška ? 0 (takže kopec napríklad nemôže začínať alebo končiť rovinkou). 

Keďže takých kopcov môže byť veľmi veľa, vypíšte počet kopcov ako zvyšok po delení číslom 100 000 007. 
*/

// uloha-6-1.c -- Tyzden 6 - Uloha 1
// Ronald Demeter, 31.3.2016 09:04:24

#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int ULLI;
typedef struct array
{
	ULLI numberof_mountains_withoutmax;
	ULLI numberof_mountains_withmax;

}ARRAY;
typedef ARRAY* ARRAY_ptr;

int main()
{
	int pocet_pripadov;
	int D, V;
	ARRAY_ptr **mountain;
	int i = 0, j = 0, k = 0, g = 0;
	scanf("%d", &pocet_pripadov);
	while (pocet_pripadov > 0)
	{
		scanf("%d %d", &D, &V);
		mountain = (ARRAY***)malloc((V + 1)*sizeof(ARRAY**));
		for (i = 0; i < (V + 1); i++)
		{
			mountain[i] = (ARRAY**)malloc((D + 1)*sizeof(ARRAY*));
		}
		i = 0;
		for (j = 0; j < V + 1; j++)
		{
			for (k = 0; k < D + 1; k++)
			{
				mountain[j][k] = (ARRAY*)malloc(sizeof(ARRAY));

				if ((j == k))
				{
					mountain[j][k]->numberof_mountains_withoutmax = 1;
					mountain[j][k]->numberof_mountains_withmax = 0;
				}

				else
				{
					mountain[j][k]->numberof_mountains_withmax = 0;
					mountain[j][k]->numberof_mountains_withoutmax = 0;
				}
				if (j == k && j == V)
				{
					mountain[j][k]->numberof_mountains_withoutmax = 0;
					mountain[j][k]->numberof_mountains_withmax = 1;
				}

			}
		}

		j = k = 0;
		for (g = 0; g < D + 1; g++)
		{

			for (j = 1; j < V + 1; )
			{
				for (k = g + 1; k < D + 1;)
				{
					if (j == (V))
					{
						mountain[j][k]->numberof_mountains_withoutmax = 0;
						mountain[j][k]->numberof_mountains_withmax = (mountain[j][k - 1]->numberof_mountains_withmax + mountain[j - 1][k - 1]->numberof_mountains_withmax + mountain[j - 1][k - 1]->numberof_mountains_withoutmax) % 100000007;
					}
					else if (j>0 && j<V)
					{
						mountain[j][k]->numberof_mountains_withoutmax = (mountain[j][k - 1]->numberof_mountains_withoutmax + mountain[j + 1][k - 1]->numberof_mountains_withoutmax + mountain[j - 1][k - 1]->numberof_mountains_withoutmax) % 100000007;
						mountain[j][k]->numberof_mountains_withmax = (mountain[j][k - 1]->numberof_mountains_withmax + mountain[j - 1][k - 1]->numberof_mountains_withmax + mountain[j + 1][k - 1]->numberof_mountains_withmax) % 100000007;
					}
					else if (j == 0)
					{
						mountain[j][k]->numberof_mountains_withoutmax = (mountain[j][k - 1]->numberof_mountains_withoutmax + mountain[j + 1][k - 1]->numberof_mountains_withoutmax) % 100000007;
						mountain[j][k]->numberof_mountains_withmax = (mountain[j][k - 1]->numberof_mountains_withmax + mountain[j + 1][k - 1]->numberof_mountains_withmax) % 100000007;

					}
					j++;
					k++;
				}
				j++;

			}
		}


		printf("%d", mountain[1][D - 1]->numberof_mountains_withmax);

		printf("\n");

		pocet_pripadov--;

	}

	return 0;
}
