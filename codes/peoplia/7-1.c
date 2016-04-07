/*Jakubko sa práve naučil pravidlá futbalu, zapol si televízor a sledoval zápasy. 
Pozorovaním vie zistiť, aká je pravdepodobnosť, že tím strelí gól. Keďže už pozná aj prvočísla, 
zaujíma ho preto, aká je pravdepodobnosť, že niektorý z tímov strelí v zápase prvočíselný počet gólov. 

Pre jednoduchosť uvažujme, že futbalový zápas trvá presne 90 minút, pričom si ho 
rozdelíme do 5 minútových blokov, počas ktorých vieme pravdepodobnosť, že niektorý z tímov strelí gól.
Predpokladáme, že v jednom intervale strelí každý tím najviac jeden gól. 

Štandardný vstup môže obsahovať zápisy viacerých úloh. Každý zápis obsahuje dve
celé čísla A a B, obe sú od 0 do 100, vyjadrujúce pravdepodobnosť že prvý resp. druhý tím 
strelí počas 5 minútového intervalu gól. Počas celého zápasu je pravdepodobnosť pre tím rovnaká. 
Pre každé zadanie úlohy na vstupe vypíšte na štandardný výstup jeden riadok obsahujúci jedno číslo s
presnosťou na 9 desatinných miest -- pravdepodobnosť, že niektorý z tímov dosiahne na konci zápasu
prvočíselný počet gólov
*/

#include<stdint.h>
#include<stdio.h>
#include<math.h>

typedef long long int LLI;

LLI binomialnumber(int n, int k);



int main() 
{
	int firstteam, secondteam;
	int P1, P2;
	int primes[7] = { 2,3,5,7,11,13,17 };
	int notprimes[12] = { 0,1,4,6,8,9,10,12,14,15,16,18 };
	double firstteam_result = 0;
	double firsteamnot = 0;
	double seconnot = 0;
	double secondteam_result = 0;
	while (scanf("%d %d", &P1, &P2) == 2)
	{
		double chance1 = P1 / (double)100;
		double chance2 = P2 / (double)100;
		for (int i = 0; i < 7; i++)
		{
			firstteam_result += binomialnumber(18, primes[i])*pow(chance1, primes[i])*pow((1 - chance1), 18 - primes[i]);
			secondteam_result += binomialnumber(18, primes[i])*pow(chance1, primes[i])*pow((1 - chance1), 18 - primes[i]);
		}
		printf("kombined:%.9lf\n",1-((1-firstteam_result)*(1-secondteam_result)));
		firstteam_result = 0 ;
		secondteam_result = 0 ;
	}

	return 0;
}

LLI binomialnumber(int n, int k)
{
	
	LLI result = 1;
	for (int i = 1; i <= k; i++)
	{
		result *= n - (k - i);
		result /= i;
	}
	return result;
}
