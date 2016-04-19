#include "Map.h"



Map::Map()
{
	
	this->width = 12;
	this->height=10;
	this->stonecount = 6;
	this->map = { { '0','0','0','0', '0','0', '0','0', '0','0', '0','0' },
				  { '0','0','0','0', '0','k', '0','0', '0','0', '0','0' },
				  { '0','k','0','0', '0','0', '0','0', '0','0', '0','0' },
				  { '0','0','0','0', 'k','0', '0','0', '0','0', '0','0' },
				  { '0','0','k','0', '0','0', '0','0', '0','0', '0','0' },
				  { '0','0','0','0', '0','0', '0','0', '0','0', '0','0' },
				  { '0','0','0','0', '0','0', '0','0', 'k','k', '0','0' },
				  { '0','0','0','0', '0','0', '0','0', '0','0', '0','0' },
				  { '0','0','0','0', '0','0', '0','0', '0','0', '0','0' },
				  { '0','0','0','0', '0','0', '0','0', '0','0', '0','0' }
	};
}


Map::~Map()
{
}

void Map::printmap()
{
	for (int i = 0; i < 10; i++)
	{
		for  (int k = 0; k < 12;  k++)
		{
			cout << "[" << map[i][k] << "]";
		}
		cout << endl;
	}
}
Map::Map(int width, int height, int number_of_sotnes)
{
	this->width = width;
	this->height = height;
	this->stonecount = number_of_sotnes;
}
void Map::loadmap()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int k = 0; k < this->width; k++)
		{
			this->map[i][k] = '0';
		}
	}
	int stones_placed = 0;
	cout << "map widht:" << this->width << "map height:" << this->height;
	int y, x;
	while (stones_placed != this->stonecount)
	{
		cout << "enter Y and X coordinates of the stone " << endl << "Y=row and X=column" << endl;
		cin >> y, x;
		this->map[y][x] = 'k';
		
	}
	this->printmap();
}

vector< vector<char> > Map::getmap()
{
	return this->map;
}

vector<int> Map::getstarts()
{
	return this->starting_points;
}

void Map::generatestartingpoints()
{
	this->starting_points.resize(2 * this->width + 2 * this->height);
	for (int i = 0; i < (2 * this->width + 2 * this->height); i++)
	{
		this->starting_points[i] = i;
	}
	
}

int Map::getwidth()
{
	return this->width;
}

int Map::getheight()
{
	return this->height;
}
int Map::getstonecount()
{
	return this->stonecount;
}
void Map::calculatestones()
{
	this->stonecount=0;
	for (int i = 0; i < this->height; i++)
	{
		for (int k = 0; k < this->width; k++)
		{
			if (this->map[i][k] == 'k')
			{
				this->stonecount++;
			}
		}

	}
}
void Map::setmap(vector< vector<char> > map)
{
	this->map=map;
}