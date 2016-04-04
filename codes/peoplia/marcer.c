#include <stdio.h>
#include <stdlib.h>

int main()
{
  // sem napis svoje riesenie
  int *col_1_poss = malloc(1), *col_1_right = malloc(1), *col_2_poss = malloc(1), *col_2_right = malloc(1), i, j, k, N, D, V;
  
  scanf("%d", &N);
  for(i = 0; i < N; i++)
  {
 	 scanf("%d %d", &D, &V);
  	 free(col_1_poss);
  	 free(col_2_poss);
  	 free(col_1_right);
  	 free(col_2_right);
  	 col_1_poss = malloc(V*sizeof(int));
  	 col_2_poss = malloc(V*sizeof(int));
  	 col_1_right = malloc(V*sizeof(int));
  	 col_2_right = malloc(V*sizeof(int));
     for(j = 0; j < V; j++)
     {
     	col_1_poss[j] = 0;
     	col_2_poss[j] = 0;
     	col_1_right[j] = 0;
     	col_2_right[j] = 0;
     }
    col_2_poss[0] = 1; 	
    if(V == 1)
      col_2_right[0] = 1;
    for(j = 0; j < ((D+1)/2 - 1); j++)
     {
       
       for(k = 0; k < V; k++)
         if(k == (V - 1))
         {
           col_1_poss[k] = (col_2_poss[k] + col_2_poss[k-1]) % 100000007; 
           col_1_right[k] = (col_2_poss[k] + col_2_poss[k-1]) % 100000007; 
         }
         else
           if(k>0)
           {
             col_1_poss[k] = (col_2_poss[k+1] + col_2_poss[k] + col_2_poss[k-1]) % 100000007;
             col_1_right[k] = (col_2_right[k+1] + col_2_right[k] + col_2_right[k-1]) % 100000007; 
           }
           else
           {
             col_1_poss[k] = (col_2_poss[k+1] + col_2_poss[k]) % 100000007;
             col_1_right[k] = (col_2_right[k+1] + col_2_right[k]) % 100000007;
           }
       for(k = 0; k < V; k++)
         if(k == (V - 1))
         {
           col_2_poss[k] = (col_1_poss[k] + col_1_poss[k-1]) % 100000007; 
           col_2_right[k] = (col_1_poss[k] + col_1_poss[k-1]) % 100000007; 
         }
         else
           if(k>0)
           {
             col_2_poss[k] = (col_1_poss[k+1] + col_1_poss[k] + col_1_poss[k-1]) % 100000007;
             col_2_right[k] = (col_1_right[k+1] + col_1_right[k] + col_1_right[k-1]) % 100000007; 
           }
           else
           {
             col_2_poss[k] = (col_1_poss[k+1] + col_1_poss[k]) % 100000007;
             col_2_right[k] = (col_1_right[k+1] + col_1_right[k]) % 100000007;
           }
    }
   if(D%2) printf("%d\n", col_1_right[0]);
     else printf("%d\n",col_2_right[0]);
   }
  return 0;
}
