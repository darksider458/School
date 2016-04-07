/*Jakubko si kúpil zošiť s omaľovávankami. Na každej strane zošitu je jeden útvar na vyfarbenie, spolu teda
postupne N (za sebou idúcich) útvarov. Pre jednoduchosť sa rozhodol, že každý útvar nafarbí celý len jednou farbou 
-- červenou, zelenou alebo modrou. Chcel by tiež, aby za sebou idúce útvary boli nafarbené odlišnými farbami. 
Pre každý útvar a možnú farbu vie určiť ako veľmi (čím menšia hodnota, tým peknejšie) sa mu páči vyfarbenie útvaru
konkrétnou farbou. 

Pomôžte Jakubkovi určiť akými farbami nafarbiť útvary tak, aby sa mu celá omaľovávanka 
páčila čo možno najviac (súčet ohodnotení pre všetky útvary by mal byť najmenší možný). 

Vstup: Štandardný vstup obsahuje zápisy viacerých omaľovávaniek. Každý zápis 
obsahuje najskôr počet útvarov N (<= 25) a potom N trojíc čísel -- ako veľmi (menšie čísla sú krajšie) 
sa Jakubkovi páči i-ty útvar vyfarbený červenou, zelenou alebo modrou. 

Výstup: Pre každé zadanie omaľovávanky na vstupe vypíšte na
štandardný výstup jeden riadok obsahujúci jedno číslo -- najmenšiu možnú 
celkovú hodnotu vyfarbenia útvarov tak, aby za sebou idúce útvary mali odlišnú farbu. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int vyslednepole[3];
	int temppole[3] = {0,0,0};
	int novepole[3];
	int n = 0;
	int i = 0; 
	while(scanf("%d",&n)>0)
	{
		
		scanf("%d %d %d", &vyslednepole[0], &vyslednepole[1], &vyslednepole[2]);
		for (int j = 1; j < n; j++)
		{
			scanf("%d %d %d", &novepole[0], &novepole[1], &novepole[2]);
			
			for (i = 0; i < 3; i++)
			{
				if (i == 0)
				{
					if (novepole[i] + vyslednepole[i + 1] >= novepole[i] + vyslednepole[i + 2])
					{
						temppole[i] = novepole[i] + vyslednepole[i + 2];
					}
					else
					{
						temppole[i]=novepole[i] + vyslednepole[i + 1];
					}
				}
				if (i == 1)
				{
					if (novepole[i] + vyslednepole[i - 1] >= novepole[i] + vyslednepole[i + 1])
					{
						temppole[i] = novepole[i] + vyslednepole[i + 1];
					}
					else
					{
						temppole[i] = novepole[i] + vyslednepole[i - 1];
					}
				}
				if (i == 2)
				{
					if (novepole[i] + vyslednepole[i - 1] >= novepole[i] + vyslednepole[i - 2])
					{
						temppole[i] = novepole[i] + vyslednepole[i - 2];
					}
					else
					{
						temppole[i] = novepole[i] + vyslednepole[i - 1];
					}
				}

			}
				
				
			for (int  g = 0; g < 3; g++)
			{
				vyslednepole[g] = temppole[g];
			}
		}
		int min = vyslednepole[0];
		for (int l = 0; l < 3; l++)
		{
			if (min > vyslednepole[l])
			{
				min = vyslednepole[l];
			}

		}
		printf("%d\n", min);
		min = 0;
	}

	return 0;
}
