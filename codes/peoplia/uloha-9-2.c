// uloha-9-2.c -- Tyzden 9 - Uloha 2
// Ronald Demeter, 19.11.2015 13:52:17

#include <stdio.h>
#include <stdlib.h>

struct Graf
{
	int n;		// pocet vrcholov
	int **a;	// hrany: a[i][j] == 0 akk neexistuje hrana (i,j), inak je a[i][j] sirka hrany z 'i' do 'j'
};

// vytvori prazdny graf s n vrcholmi ... (prazdny = bez hran)
struct Graf *create(int n)
{
	int i, j;
	struct Graf *g = (struct Graf *)malloc(sizeof(struct Graf));

	g->n = n;
	g->a = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		g->a[i] = (int *)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
			g->a[i][j] = 0; // neexistuje hrana (zatial)
	}
	return g;
}

// vrati sirku najsirsej cesty z ‘u’ do ‘v’; -1 ak neexistuje.
int najsirsia_cesta(struct Graf *g, int u, int v)
{
   int maximum, naj_wid, i, *state, *width;
	
  state = (int *)malloc(g->n * sizeof(int));
  width = (int *)malloc(g->n * sizeof(int)); 
  for (i = 0; i < g->n; i++)
  {
    state[i] = 0; 
    width[i] = 0; 
  }
  width[u] = -1; 
  state[u] = state[u] + 1;
  for (i = 0; i < g->n; i++)
    if (g->a[u][i] >= 0) 
  	{
      width[i] = g->a[u][i];  	
    }
  int MIN(int a,int b)
  {
    return (a < b) ? a : b;
  }
  while (state[v] == 0) 
  {
    naj_wid = 0;
    maximum = -1; 
    for (i = 0; i < g->n; i++)
      if (state[i] == 0)
        if (naj_wid < width[i])
        {
          naj_wid = width[i];
          maximum = i;
        }

    if (maximum == -1)
    {
      return -1;
    }
    state[maximum] = 1; 
    for (i = 0; i < g->n; i++)
    {
      if (g->a[maximum][i] > 0)
        if (state[i] == 0)
        {
          if (width[i] < MIN(width[maximum], g->a[maximum][i]))
          {
            width[i] = MIN(width[maximum], g->a[maximum][i]);
          }
         }
    }
  }
  return width[v];
}

int main(void)
{
	int i, n, m, u, v, len;

	scanf("%d %d", &n, &m);
	struct Graf *g = create(n);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &len);
		g->a[u-1][v-1] = len;
		g->a[v-1][u-1] = len;
	}

	scanf("%d %d", &u, &v);

	int vysledok = najsirsia_cesta(g, u-1, v-1);
	if (vysledok < 0)
		printf("Najsirsia cesta z %d do %d neexistuje!\n", u, v);
	else
		printf("Najsirsia cesta z %d do %d je siroka %d.\n", u, v, vysledok);

	return 0;
}
