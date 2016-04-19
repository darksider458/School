

#ifndef _MAP_H_
#define _MAP_H_

//=============
//includes
//=============
#include <vector>
#include <iostream>


class Monk;
using namespace std;


class Map
{
protected:
	
	vector< vector<char> > map;
	int width;
	int height;
	int stonecount;
	vector<int>starting_points;
	

public:
	Map();
	Map(int width, int height, int number_of_stones);
	~Map();
	vector< vector<char> > getmap();
	void printmap();
	void generatestartingpoints();
	int getwidth();
	int getheight();
	int getstonecount();
	void calculatestones();
	vector<int> getstarts();
	void loadmap();
	void setmap(vector< vector<char> > map);
	//
};

#endif // !_MAP_H_