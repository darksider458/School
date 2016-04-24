// uloha-2-1.c -- Tyzden 2 - Uloha 1
// Ronald Demeter, 27.9.2015 20:01:58

#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int top=-1;  
 char *posun(char element, char *pole)
{                      
    pole[++top]=element;
   return pole;
}
 
char pop(char *pole)
{                 
    return(pole[top--]);
}
 
int pr(char element)
{        
    
     if (element == '#')
    {return 0;}
     else if ( element== '(')
    {return 1;}
     else if ( element== '+' || element== '-')
    {return 2; }
     else if (element== '*' || element== '/')
    {return 3;}
    
}

int main()
{	
  	 char infixove[10000],suffixove[10000], *s,ch,element;
    int i=0,k=0;
  s = (char *) malloc(1000);
 while( scanf("%s", infixove)>0)
 {
  for (i=0; i < 10000; i++)
  {
   s[i]=0;
  }
   k=0;
    i=0;
      posun('#', s);// indikuje zaciatok
  while( (ch=infixove[i++]) != '\0')
    {
      if( ch == '(')
      {
        posun(ch, s);
      }
        else
            if(isalnum(ch)) suffixove[k++]=ch; // ci je znak alphanumericky
            else
                if( ch == ')')
                {
                    while( s[top] != '(')
                    {suffixove[k++]=pop(s);}
             		element=pop(s);
                }
                else
                {     
                    while( pr(s[top]) >= pr(ch) )
                    {suffixove[k++]=pop(s);}
                    posun(ch, s);
                }
    }
    while( s[top] != '#') // teraz prechadzam cele pole s a tvorim z neho suffixovy zapis
    { suffixove[k++]=pop(s);}
    suffixove[k]='\0';         
    printf("%s\n",suffixove);
 }
  return 0;
}
