/*@author Ronald Demeter*/

/*
Keď minule Jakubko nemohol zaspať, zobral si papier a začal si kresliť kopčeky. 

Prvý riadok vstupu obsahuje číslo N (1 ≤ N ≤ 20) vyjadrujúce počet úloh. Každá úloha pozostáva z riadku obsahujúceho dve celé čísla D (2 ≤ D ≤ 5000) a V (1 ≤ V ≤ 200). 

Výstup bude obsahovať N riadkov, pre každú úlohu jeden.
Obsahovať budú počet rôznych kopcov majúcich šírku D metrov a výšku presne V desiatok metrov.
Kopec pozostáva len z troch možných úsekov: stúpanie široké 1 meter a vysoké 10 metrov,
klesanie široké 1 meter a vysoké 10 metrov a rovinka široká 1 meter. Jednotlivé úseky musia na seba nadväzovať, 
výška nesmie presiahnuť V desiatok metrov, na začiatku a na konci musí mať kopec nulovú výšku a nikde inde nesmie
byť výška ≤ 0 (takže kopec napríklad nemôže začínať alebo končiť rovinkou). 

Keďže takých kopcov môže byť veľmi veľa, vypíšte počet kopcov ako zvyšok po delení číslom 100 000 007. 
*/


#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int ULLI;

int main()
{
	int pocet_pripadov;
	int D, V;
	ULLI *pole_bez_vrchola;
	ULLI *pole_s_vrcholom;

	scanf("%d", &pocet_pripadov);
	while (pocet_pripadov>0)
	{
		scanf("%d %d", &D, &V);
		pole_bez_vrchola = (ULLI*)malloc(((D + 2)*V)*sizeof(ULLI));
		pole_s_vrcholom =  (ULLI*)malloc(((D + 2)*V)*sizeof(ULLI));
	}

	return 0;
}
