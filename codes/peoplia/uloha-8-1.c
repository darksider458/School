// uloha-8-1.c -- Tyzden 8 - Uloha 1
// Ronald Demeter, 10.11.2015 12:35:41

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned int uint;

typedef struct vrcholy
{
	uint distance;
	int searched;

	struct hrana *hrany;
	struct vrcholy *next;
}VRCHOLY;

typedef struct hrana
{
	VRCHOLY *kde;
	struct hrana *next;
}HRANA;

typedef struct qeue
{
	VRCHOLY *first;
	VRCHOLY *posledny;
}QEUE;

VRCHOLY *mesta;
 QEUE qeue;

 void connectcities(VRCHOLY *start, VRCHOLY *end)
{
	VRCHOLY *temp;

	HRANA *hrana = (HRANA *)malloc(sizeof(HRANA));
	hrana->kde = end;
	hrana->next = start->hrany;
	start->hrany = hrana;

	hrana = (HRANA *)malloc(sizeof(HRANA));
	hrana->kde = start;
	hrana->next = end->hrany;
	end->hrany = hrana;

}
 void putinqeue(VRCHOLY *target, uint distance)
 {
	 target->distance += distance;
	 target->searched = 1;

	 if (qeue.first == NULL)
	 {
		 qeue.first = target;
		 qeue.first->next = NULL;
		 qeue.posledny = qeue.first;
	 }
	 else
	 {
		 qeue.posledny->next = target;
		 qeue.posledny = target;
		 qeue.posledny->next = NULL;
	 }
 }

VRCHOLY *removefromqeue()
 {
	 if (qeue.first != NULL)
	 {
		 VRCHOLY *first = qeue.first;
		 qeue.first = qeue.first->next;
		 return first;

	 }
	 else
	 {
		 return NULL;
	 }
 }

 void find()
 {
	 VRCHOLY *got = NULL;
 	 while ((got =removefromqeue())!=NULL)
	 {
		 HRANA  * hrana = got->hrany;
		
			 while (hrana !=NULL)
			 {
				 if (hrana->kde->searched != 1)
				 {
					 putinqeue(hrana->kde, got->distance + 1);

				 }
				 hrana = hrana->next;
			 }
	 }
 }

int main()
{
	int number_of_cities, connected, number_agents;
	int i = 0;
	int start, end;
	int agent;
	scanf("%d %d %d", &number_of_cities, &connected, &number_agents);
	mesta = (VRCHOLY*)malloc(number_of_cities*sizeof(VRCHOLY));
	
	for (i; i < number_of_cities; i++)
	{
		mesta[i].distance = 0;
		mesta[i].searched = -1;
		mesta[i].next = NULL;
		mesta[i].hrany = NULL;
	}
	for (i = 0; i < connected; i++){
		scanf("%d %d", &start, &end);
		connectcities(mesta+start - 1, mesta+end - 1);
	}
	for (i = 0; i < number_agents; i++)
	{
		scanf("%d", &agent);
		putinqeue(mesta+agent-1, 0);
	}

   	find();
	for (i = 0; i < number_of_cities; i++)
	{
		if (mesta[i].searched==1)
		printf("%d %d\n", i + 1, mesta[i].distance);
	}
	return 0;
}
