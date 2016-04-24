// uloha-5-1.c -- Tyzden 5 - Uloha 1
// Ronald Demeter, 17.10.2015 14:21:09
#include <stdio.h>

int i,front,rear,number;
long list[6000];

void check(long data)
{
	int i, j;

	for (i = 0; i <= rear; i++)
	{
		if (data == list[i])
		{
			rear--;
			return;
		}
		else
		{
			if (data <= list[i])
			{
				for (j = rear + 1; j > i; j--)
				{
					list[j] = list[j - 1];
				}
				list[i] = data;
				return;
			}
		}
	}
	list[i] = data;
}


void init()
{
	front = rear = -1;
}

void insertbypriority(long data)
{
	if (rear >= 5001)
	{
		return;
	}
	if ((front == -1) && (rear == -1))
	{
		front++;
		rear++;
		list[rear] = data;
		return;
	}
	else
		check(data);
	rear++;
}

int main()
{
  init;
  insertbypriority(1);
  for(i = 1;i<4000;i++){
    insertbypriority(list[i]*3);
    insertbypriority(list[i]*5);
    insertbypriority(list[i]*7);
  }
  while(scanf("%i", &number) >0)
  {
  printf("%li\n",list[number]);
  }

  return 0;
}
