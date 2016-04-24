// zadanie3.c -- Zadanie 3 - Popolvar
// Ronald Demeter, 29.11.2015 18:44:33
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define W 5
//#define H 6
#define MAX_HEAP_SIZE 1000
#define RIGHT(x) (2*x+2)
#define LEFT(x) (2*x+1)
#define PARENT(x) ((int)round((double)x/2) - 1)
#define DISTANCE(x) ( x == NULL ? 0xFFFF : x->distance)

typedef struct Vec
{
	int x;
	int y;

}Vector;

typedef struct Popolvar
{
	Vector current_position;

	int dragon_awake_iter;
	int dragon_status;
	int saved_princesses;
}Popo;

typedef struct Tile
{
	Vector pos;

	char visited;
	char type;
	int distance;
	int steps;
	struct Tile *prev;

}TILE;

typedef struct PriorityQueue
{
	int last;
	TILE *heap[MAX_HEAP_SIZE];

}PriorityQueue;


void InitializeArray();

/*MAP MODIFY STRUCTURE FUNCTIONS*/
TILE ** CopyMap(char **MAP, int rows, int cols);
void PrintMap(char num,int w,int h);
int get_distance(char key);
int *get_coordinates(Vector from, Vector to, int transpose,int w,int h);
void VypisCestu(int * cesta);
int *findMin();
/*EOF*/


/*CHARACTER MOVEMENT FUNCTIONS*/
TILE *Move(Vector direction);
void FindKey(Vector from, Vector to, int all,int w,int h,char **mapa);
void Save_the_princess();
/*EOF*/


/*PRIORTY QUEUE FUNCTIONS*/
void Heapify(int i);
void decreaseKey(int position, TILE *tile);
void Insert(TILE *tile);
void Delete();
TILE* GetMin();
/*EOF*/

//MAP REPRESENTATION
/*char *MAP[6] =
{
	"hchph",
	"cchhc",
	"cchpc",
	"chchd",
	"hcchc",
	"nnnnn"
};*/
//core funkcion
int *zachran_princezne(char **mapa, int n, int m, int t, int *dlzka_cesty);
//MAP REPRESENTATION STRUCTURE
TILE ** TILED_MAP;

//VALID MOVES IN 4 DIFFERENT DIRECTIONS 
Vector moves[4] =
{
	{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 },
	{ -1, 0 },
};

//Popolvar (Hero) initialisation
Popo popolvar = { { 0, 0 }, 0, 0, 0 };
//0=Drak, 1=P1.....
Vector pozicie[4];
PriorityQueue priority;
int *Final_paths[10];


void FindKey(Vector from, Vector to, int all,int w,int h,char **mapa)
{
	static int pocet = 0;
	int i = 0;
	Insert(&TILED_MAP[from.x][from.y]);

	while (priority.heap[0] != NULL)
	{
		TILE *current_position = priority.heap[0];
		Delete();

		current_position->visited = 1;

		int pom_X = current_position->pos.x;
		int pom_Y = current_position->pos.y;
		char key = mapa[pom_X][pom_Y];

		if (!all)
		{
			if ((pom_X == to.x) && (pom_Y == to.y)) break;
		}
		else
		{
			if (pocet < all)
			{
				if ((key == 'p' || ((pom_X == 0) && (pom_Y == 0))) && (pocet == 4))
				{
					pocet++;
				}
				else if ((key == 'p') && (pocet < 4))
				{
					pocet++;
				}
			}
			else
			{
				break;
			}
		}

		int old_X = pom_X;
		int old_Y = pom_Y;

		for ( i = 0; i < 4; i++)
		{
			pom_X += moves[i].x;
			pom_Y += moves[i].y;

			if (pom_X >= w || pom_X < 0 || pom_Y >= h || pom_Y < 0)
			{
				pom_X = old_X;
				pom_Y = old_Y;
				continue;
			}

			TILE *looking = &TILED_MAP[pom_X][pom_Y];
			int distance = get_distance(mapa[pom_X][pom_Y]);

			pom_X = old_X;
			pom_Y = old_Y;

			int from_me = current_position->distance + distance;

			if ((distance < 0) || (looking->visited == 1) || (looking->distance < from_me)) continue;

			looking->distance = from_me;
			looking->visited = 1;
			looking->steps = current_position->steps + 1;
			looking->prev = current_position;
			Insert(looking);
		}
	}
	pocet = 0;
}


void PrintMap(char num,int w,int h)
{
	if (TILED_MAP != NULL)
	{
		int i, j;
		i = j = 0;

		for (; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				if (num)
				{
					printf("%d", TILED_MAP[i][j].distance == 255 ? 0 : TILED_MAP[i][j].distance);
				}
				else
					printf("%c", TILED_MAP[i][j].type);

			}

			putchar('\n');
		}
	}
}

TILE ** CopyMap(char **MAP, int rows, int cols)
{
	int i, j;
	i = j = 0;
     static int pom = 0;
	TILE **NEW_MAP = (TILE**)malloc(sizeof(TILE*)*rows);

	for (i = 0; i < rows; i++)
	{
		;
		NEW_MAP[i] = (TILE*)malloc(sizeof(TILE)*cols);

		for (j = 0; j < cols; j++)
		{

			TILE new_tile = { { i, j }, 0, MAP[i][j], 0xFFFF, 0, NULL };

			if (MAP[i][j] == 'p')
			{
				pozicie[pom + 1].x = i;
				pozicie[pom + 1].y = j;
				pom++;
			}
			else if (MAP[i][j] == 'd')
			{
				pozicie[0].x = i;
				pozicie[0].y = j;
			}


			NEW_MAP[i][j] = new_tile;
		}
	}
  pom = 0;
	return NEW_MAP;
}

void Insert(TILE *tile)
{
	priority.last++;
	priority.heap[priority.last - 1] = tile;
	decreaseKey(priority.last - 1, tile);
}


void decreaseKey(int position, TILE *tile)
{
	if (position < 0) return;

	while (position > 0 && (DISTANCE(priority.heap[PARENT(position)]) > DISTANCE(priority.heap[position])))
	{
		TILE *tile = priority.heap[position];
		priority.heap[position] = priority.heap[PARENT(position)];
		priority.heap[PARENT(position)] = tile;
		position = PARENT(position);
	}
}

void Heapify(int i)
{
	int l = LEFT(i);
	int largest;

	if (l < priority.last && DISTANCE(priority.heap[l]) < DISTANCE(priority.heap[i]))
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	int r = RIGHT(i);
	if (r < priority.last && DISTANCE(priority.heap[r]) < DISTANCE(priority.heap[largest]))
	{
		largest = r;
	}

	if (largest != i)
	{
		TILE *tile = priority.heap[i];
		priority.heap[i] = priority.heap[largest];
		priority.heap[largest] = tile;
		Heapify(largest);
	}
}


void Delete()
{
	if (priority.last == 0) return;

	priority.heap[0] = priority.heap[priority.last - 1];
	priority.last--;
	if (priority.last == 0)
	{
		priority.heap[0] = NULL;
		return;
	}
	Heapify(0);
}

int *findMin()
{
	int sums[6];
	int *k = (int*)malloc(sizeof(int) * 3);

	int i = 1;

	//Cez vrchol 1
	sums[0] = Final_paths[1][1] + Final_paths[4][1] + Final_paths[8][1];
	sums[1] = Final_paths[1][1] + Final_paths[6][1] + Final_paths[9][1];
	//Cez vrchol 2
	sums[2] = Final_paths[2][1] + Final_paths[5][1] + Final_paths[6][1];
	sums[3] = Final_paths[2][1] + Final_paths[8][1] + Final_paths[7][1];
	//Cez vrchol 3
	sums[4] = Final_paths[3][1] + Final_paths[7][1] + Final_paths[4][1];
	sums[5] = Final_paths[3][1] + Final_paths[9][1] + Final_paths[5][1];

	int min = sums[0];
	int index = 0;

	for (i = 1; i < 6; i++)
	{
		if (sums[i] < min)
		{
			index = i;
			min = sums[i];
		}
	}

	switch (index)
	{
	case 0:	k[0] = 1; k[1] = 4; k[2] = 8;		break;
	case 1:	k[0] = 1; k[1] = 6; k[2] = 9;		break;
	case 2:	k[0] = 2; k[1] = 5; k[2] = 6;		break;
	case 3:	k[0] = 2; k[1] = 8; k[2] = 7;		break;
	case 4:	k[0] = 3; k[1] = 7; k[2] = 4;		break;
	case 5:	k[0] = 3; k[1] = 9; k[2] = 5;		break;
	}

	return k;
}
TILE *GetMin()
{
	return priority.heap[0];
}

int *get_coordinates(Vector from, Vector to, int transpose,int w,int h )
{
	TILE *start = &TILED_MAP[from.x][from.y];
	TILE *end = &TILED_MAP[to.x][to.y];

	int *coordinates = (Vector*)malloc(sizeof(Vector)*w*h * 2);
	coordinates[0] = transpose ? (start->steps + 1) * 2 + 2 : 0; //DLZKA POLA 
	coordinates[1] = start->distance; //DLZKA CESTY
	int pom = 0;

	while ((start->prev != NULL) && ((end->pos.x != start->pos.x) || (end->pos.y != start->pos.y)))
	{
		if (transpose)
		{
			coordinates[coordinates[0] - 1 - (pom * 2 + 1)] = start->pos.x;
			coordinates[coordinates[0] - 1 - (pom++) * 2] = start->pos.y;
		}
		else
		{
			coordinates[0] += 2;
			coordinates[coordinates[0]] = start->pos.x;
			coordinates[coordinates[0] + 1] = start->pos.y;
		}
		start = start->prev;
	}

	if (!transpose)
	{
		coordinates[0] += 2;
		coordinates[coordinates[0]] = start->pos.x;
		coordinates[coordinates[0] + 1] = start->pos.y;
		coordinates[0] += 2;
	}
	else
	{
		coordinates[2] = start->pos.x;
		coordinates[3] = start->pos.y;
	}

	return coordinates;
}

int get_distance(char k)
{

	if (k == 'h')
	{
		return 2;
	}
	else if (k == 'n')
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


void VypisCestu(int *cesta)
{
  int i =2;
	printf("Cesta je dlha %d\n", cesta[1]);
	for ( i = 2; i < cesta[0] - 1; i += 2)
	{
		printf("Vec(%d,%d)\n", cesta[i], cesta[i + 1]);
	}
}

int *zachran_princezne(char **mapa, int n, int m, int t, int *dlzka_cesty)
{
  	
	int i = 0;
	for ( i = 0; i < 4; i++) { pozicie[i].x = 0; pozicie[i].y = 0; }
 
	TILED_MAP = CopyMap(mapa, n, m);
	priority.last = 0;
	
	for ( i = 0; i < MAX_HEAP_SIZE; i++) priority.heap[i] = NULL;

	TILED_MAP[pozicie[0].x][pozicie[0].y].distance = 0;
	
	Vector drak = pozicie[0];
   
	Vector popolvar = { 0, 0 };
	Vector princess_1 = pozicie[1];
	Vector princess_2 = pozicie[2];
	Vector princess_3 = pozicie[3];

	FindKey(drak, popolvar, 4,n,m,mapa);

	Final_paths[0] = get_coordinates(popolvar, drak, 0,n,m);	//Poplvar -> Drak
	Final_paths[1] = get_coordinates(princess_1, drak, 1,n,m);  //Drak -> Princess1
	Final_paths[2] = get_coordinates(princess_2, drak, 1,n,m);  //Drak -> Princess2
	Final_paths[3] = get_coordinates(princess_3, drak, 1,n,m);	//Drak -> Princess3

	TILED_MAP = CopyMap(mapa, n, m);
	TILED_MAP[princess_1.x][princess_1.y].distance = 0;

	FindKey(princess_1, princess_3, 3,n,m,mapa);

	Final_paths[4] = get_coordinates(princess_2, princess_1, 1,n,m);
	Final_paths[5] = get_coordinates(princess_2, princess_1, 0,n,m);

	Final_paths[6] = get_coordinates(princess_3, princess_1, 1,n,m);
	Final_paths[7] = get_coordinates(princess_3, princess_1, 0, n, m);


	TILED_MAP = CopyMap(mapa, n, m);
	TILED_MAP[princess_2.x][princess_2.y].distance = 0;

	FindKey(princess_2, princess_3, 3,n,m,mapa);

	Final_paths[8] = get_coordinates(princess_3, princess_2, 1, n, m);
	Final_paths[9] = get_coordinates(princess_3, princess_2, 0, n, m);

	int *p = findMin();
	int velkost_spolu = Final_paths[0][0] / 2 - 1 + Final_paths[p[0]][0] / 2 - 2 + Final_paths[p[1]][0] / 2 - 2 + Final_paths[p[2]][0] / 2 - 2;
	int *final_suradnice = (int*)malloc(sizeof(int)*velkost_spolu * 2);
	int pom = 0;
    
    *dlzka_cesty = velkost_spolu;

   for ( i = 2; i < Final_paths[0][0] - 1; i += 2)
	{
		final_suradnice[pom] = Final_paths[0][i];
		final_suradnice[pom + 1] = Final_paths[0][i + 1];
		pom += 2;
	}
	for ( i = 4; i < Final_paths[p[0]][0] - 1; i += 2)
	{
		final_suradnice[pom] = Final_paths[p[0]][i];
		final_suradnice[pom + 1] = Final_paths[p[0]][i + 1];
		pom += 2;
	}
	for ( i = 4; i < Final_paths[p[1]][0] - 1; i += 2)
	{
		final_suradnice[pom] = Final_paths[p[1]][i];
		final_suradnice[pom + 1] = Final_paths[p[1]][i + 1];
		pom += 2;
	}
	for ( i = 4; i < Final_paths[p[2]][0] - 1; i += 2)
	{
		final_suradnice[pom] = Final_paths[p[2]][i];
		final_suradnice[pom + 1] = Final_paths[p[2]][i + 1];
		pom += 2;
	}
	return final_suradnice;
}
            
// Tlacidlo 'Spustit' vyskusa vasu socialnu siet na testovacich scenaroch.
// Vlastna funkcia main() nie je potrebna, a nebude sa spustat.

