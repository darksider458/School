// uloha-6-1.c -- Tyzden 6 - Uloha 1
// Ronald Demeter, 3.11.2015 07:13:44
#include<stdio.h>
#include<stdlib.h>

typedef unsigned int uint;
uint *hashtableT;

uint hash(uint key, uint size)
{
	uint pozicia;
	pozicia = key % size;
	while ((hashtableT[pozicia]!=NULL) && (hashtableT[pozicia]!=key))
	{
			pozicia = (pozicia + 1) % size;
	}
	return pozicia;
}


int is_subset(int s[], int n, int t[], int m)
{	int i=0;
	
	hashtableT = (uint*)malloc((2*m)*sizeof(uint));
	for ( i = 0; i < 2 * m; i++)
	{
		hashtableT[i] = NULL;
	}

	for (i = 0; i < m; i++)
	{
		hashtableT[hash(t[i], 2 * m)] = t[i];
	}

	for (i = 0; i < n; i++)
	{
		uint result = hashtableT[hash(s[i], 2 * m)];
		if (result == NULL)return 0;
		
	}
	return 1;
}


// ukazkovy test
int main(void)
{
  int a[] = {10, 20, 30};
  int b[] = {30, 10};
	if (is_subset(b, 2, a, 3))
    printf("B je podmnozina A (spravne)\n");
   else
    printf("B nie je podmnozina A (nespravne)\n");
  return 0;
}
