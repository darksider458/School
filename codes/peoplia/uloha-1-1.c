// uloha-1-1.c -- Tyzden 1 - Uloha 1
// Ronald Demeter, 21.9.2015 14:07:42

#include <stdio.h>

int main()
{	signed long int prve,druhe,temp;

 while(1){
 	if((scanf("%lu %lu" ,&prve,&druhe))<0)
    {break;}
   
   if(prve==0)
   {printf("%lu\n",druhe);}
   
  else if(druhe==0)
   {printf("%lu\n",prve);}
   
   else {while(druhe!=0)
    {
      temp=druhe;
      druhe=prve%druhe;
      prve=temp;
    }
   printf("%lu\n",prve);
        }
 
  
 }
  
  return 0;
}
