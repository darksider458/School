// uloha-3-2.c -- Tyzden 3 - Uloha 2
// Ronald Demeter, 3.10.2015 15:48:25

#include <stdio.h>
#include <stdlib.h>


typedef struct Trienode
{
	struct Trienode  *alphabet[26];

}TrieNode;

void createnode(TrieNode *parent)
{
	int i = 0;
	for (i = 0; i < 26; i++)
	{
		parent->alphabet[i] = NULL;
	}
}



int main()
{
	TrieNode *first = (TrieNode*)malloc(sizeof(TrieNode));
	TrieNode *current = first;
	int line = 10000;
	char word[500];
	int size = 0;
	int max = 0;
  int location = 0;
  
	createnode(current);
  
	while ((line-- > 0) && ((scanf("%s", word)) > 0))
	{
		max =0;
		location=0;
		current = first;
      
      
		while (word[location] != '\0')
		{
			
			if (word[location] < 'A' || word[location] > 'Z' || location>19)
            { line = 0; break;}

			TrieNode *depth = current->alphabet[word[location] - 'A'];
          
			if (depth != NULL)
			{
			max += 1;
			
			}	
			else
			{
              
			current->alphabet[word[location] - 'A'] = (TrieNode*)malloc(sizeof(TrieNode));
			createnode(current->alphabet[word[location] - 'A']);
			depth = current->alphabet[word[location] - 'A'];
              	
			}

			current = depth;
			location += 1;
    
		}
		if (max > size)
		{
			size = max;
          
		}
		

	}


	printf("%d", size);
	return 0;
}
