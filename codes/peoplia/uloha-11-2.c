// uloha-11-2.c -- Tyzden 11 - Uloha 2
//Ronald Demeter, 28.11.2015 21:17:47
#include <stdio.h>
#pragma GCC optimize("O3")

void quick_sort(int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}
 

void utried(int *a, int n){

quick_sort(a,n);	
	
}
int main(void)
{
  int i, *x, n;

  scanf("%d", &n);
  x = (int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);

  utried(x, n);
  
  printf("%d", x[0]);
  for (i = 1; i < n; i++)
  {
    printf(" %d", x[i]);
    if (x[i-1] > x[i])
    {
      printf(" -- CHYBA\n");
      return 0;
    }
  }
  printf("\n");

  printf("OK\n");
  return 0;
}
