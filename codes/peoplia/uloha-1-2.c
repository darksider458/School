// uloha-1-2.c -- Tyzden 1 - Uloha 2
// Ronald Demeter, 21.9.2015 14:09:48

#include <stdio.h>

int main()
{	int cislo,i,j;
 	int pole[1299721];
	 int primepole[1299721];
 	
 	 for (i=0;i<1299721;i++){
        pole[i]=i+2;
    }
 	
 	for (i=0;i<1299721;i++){
        if (pole[i]!=-1){
            for (j=2*pole[i]-2;j<1299721;j+=pole[i])
                pole[j]=-1;
        }
    }
  
 	j = 0;
    for (i=0;((i<1299721)&&(j<primepole));i++)
        if (pole[i]!=-1)
            primepole[j++] = pole[i];
      
      while(!(scanf("%d",&cislo)<0))
    {
      printf("%d\n",primepole[cislo-1]);
    
    }
  
  return 0;
}
