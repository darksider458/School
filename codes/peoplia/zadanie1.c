// zadanie1.c -- Zadanie 1 - Spravca pamati
// Ronald Demeter, 27.9.2015 20:00:11

#include <stdio.h>

typedef struct hlav
{
	unsigned int  pravo;
	unsigned int  celkova_free_size;
}HLAV;


void *poitr = NULL;

void memory_init(void *ptr, unsigned int  size)
{
	poitr = ptr;
	HLAV head;
	head.pravo = size - sizeof(HLAV) - sizeof(unsigned int);
	head.celkova_free_size = size - (sizeof(unsigned int) + 4);
	*((unsigned int *)ptr) = size - (sizeof(unsigned int) + sizeof(HLAV));
	*((HLAV *)((unsigned int *)ptr + 1)) = head;

}



void *memory_alloc(unsigned int  size)
{
	HLAV *start = (HLAV*)((unsigned int *)poitr + 1);
	unsigned int  velkost_celeho_pola = *((unsigned int *)poitr);
	unsigned int  size_to_the_right;
	HLAV *aktual_pozition = start;
	size_to_the_right = aktual_pozition->pravo;


	if ((size & 1) == 1)
	{
		size++;
	}

	while ((aktual_pozition->pravo <= size) || (aktual_pozition->pravo & 1))
	{

			if (((char*)(aktual_pozition + aktual_pozition->pravo+sizeof(HLAV)) >= ((char*)poitr + velkost_celeho_pola)) )
		{

			return 0;
		}

		if ((aktual_pozition->pravo & 1))
		{
			aktual_pozition = (HLAV*)((char*)(HLAV*)(aktual_pozition + 1) + aktual_pozition->pravo - 1);
		}
		else { aktual_pozition = (HLAV*)((char*)(HLAV*)(aktual_pozition + 1) + aktual_pozition->pravo); }

		size_to_the_right = aktual_pozition->pravo;




	}
	if ((char*)aktual_pozition + aktual_pozition->pravo == ((char*)poitr + (velkost_celeho_pola + 4)))
	{
		HLAV *new_head;

		aktual_pozition->pravo = size + 1;
		new_head = (HLAV*)((char*)aktual_pozition + (size + sizeof(HLAV)));
		new_head->celkova_free_size = size_to_the_right - ((size)+sizeof(HLAV));
		new_head->pravo = size_to_the_right - ((size)+sizeof(HLAV));

		return aktual_pozition + 1;

	}
	else
	{
		aktual_pozition->pravo = aktual_pozition->pravo + 1;
		return aktual_pozition + 1;
	}


}

int memory_free(void *valid_ptr)
{
	((HLAV*)valid_ptr - 1)->pravo -= 1;


	return 0;
}

int memory_check(void *ptr)
{
	HLAV *lokacia;

	if (ptr == NULL){ return 0; }
	else{ lokacia = (HLAV*)ptr - 1; }

	if ((lokacia->pravo & 1) && lokacia != NULL)
	{
		return 1;
	}
	else {
		return 0;
	}
}




// Tlacidlo 'Spustit' vyskusa vasho spravcu pamati na testovacich scenaroch.
// Vlastna funkcia main() nie je potrebna, a nebude sa spustat.

