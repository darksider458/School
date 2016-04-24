// uloha-2-2.c -- Tyzden 2 - Uloha 2
// Ronald Demeter, 27.9.2015 20:02:50

#include <stdio.h>



typedef struct cislo
{
	int hodnota;
	struct cislo *pravo;

}CISLO;
typedef struct hlbka
{

	CISLO *prve;
	CISLO *posledny;
	struct hlbka *next;
}HLB;



int main()
{
	CISLO *hodnota = NULL, *pravo = NULL, *prve = NULL;
	HLB *psolednyriadok = NULL, *aktriadok = NULL, *prvyriadok = NULL;
	
	int n, aktcislo = 0;
	int i = 0, pocet = 0;
	int init = 0;
	int cislopridane = 0;
	int k = 1;


 	while (scanf("%d", &n)>0){
		init = 0;
		prvyriadok = NULL;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &aktcislo);
			aktriadok = prvyriadok;
			cislopridane = 0;

			while (cislopridane == 0)
			{
				if (aktriadok == NULL)
				{
					aktriadok = (HLB*)malloc(sizeof(HLB));
					aktriadok->prve = NULL;
					aktriadok->posledny = NULL;
					aktriadok->next = NULL;
					pocet++;

					if (init == 0)
					{
						init++;
						prvyriadok = aktriadok;
						psolednyriadok = aktriadok;
					}
					else
					{
						psolednyriadok->next = aktriadok;
						psolednyriadok = aktriadok;
					}
				}
				if (aktriadok->prve == NULL)
				{
					aktriadok->prve = (CISLO*)malloc(sizeof(CISLO));
					aktriadok->prve->hodnota = aktcislo;
					aktriadok->prve->pravo = NULL;
					aktriadok->posledny = aktriadok->prve;
					cislopridane++;
				}
				else{
					if (aktcislo < aktriadok->prve->hodnota)
					{
						CISLO *temp;
						temp = (CISLO*)malloc(sizeof(CISLO));
						temp->pravo = aktriadok->prve;
						aktriadok->prve = temp;
						temp->hodnota = aktcislo;
						cislopridane++;
					}
					else if (aktcislo > aktriadok->posledny->hodnota)
					{
						aktriadok->posledny->pravo = (CISLO*)malloc(sizeof(CISLO));
						aktriadok->posledny = aktriadok->posledny->pravo;
						aktriadok->posledny->pravo = NULL;
						aktriadok->posledny->hodnota = aktcislo;
						cislopridane++;
					}

				}
				if (cislopridane == 0)
				{
					aktriadok = aktriadok->next;
				}

			}
		}

		printf("%d\n", pocet);
		aktriadok = prvyriadok;
		while (aktriadok != NULL)
		{
			CISLO *aktcislop = aktriadok->prve;
			while (aktcislop != NULL)
			{
				printf("%d", aktcislop->hodnota);
				aktcislop = aktcislop->pravo;
			}
			printf("\n");
			aktriadok = aktriadok->next;
		}
		pocet = 0;
		
	}
	return 0;
}


