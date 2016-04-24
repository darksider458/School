// uloha-6-2.c -- Tyzden 6 - Uloha 2
// Ronald Demeter, 4.11.2015 16:33:40

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;
char **hash_table;

uint hash_string(char *string)
{
	
	uint pom = 0;
    int i;
      for(i=0;i<strlen(string);i++)
    {
      pom = string[i] + 31 * i;
	}

	return pom;
}


uint hash_position(char *string,uint size)
{
	uint pos = hash_string(string) % size;
	uint i = 1;
	while (hash_table[pos]!=NULL && (strcmp(hash_table[pos], string)!=0))
	{
		pos = (pos + i++) % size;
	}

	return pos;
}



// spracuje cisla OP: vrati pocet najdenych duplikatov.
int vyhadzovac(char *a[], int n)
{
	uint size = n * 2 ;
	uint i = 0;
	
	uint copies = 0;
	hash_table = (char**)malloc(sizeof(char*)*size);

	for (i=0;i < size;i++)
	{
		hash_table[i] = NULL;
	}

	for (i = 0;i < n;i++)
	{
		uint pozition = hash_position(a[i], size);
		if (hash_table[pozition] == NULL)
		{
			hash_table[pozition] = a[i];
		}
		else copies++;
	}

	return copies;
}

// ukazkovy test
int main(void)
{
  char *a[] = {"AA123456", "BA987689", "AA123123", "AA312312", "BB345345", "AA123123"};
  printf("Pocet duplikatov: %d\n", vyhadzovac(a, 6));
  return 0;
}
