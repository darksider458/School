


#ifndef _GENERATION_H_
#define _GENERATION_H_


#include<vector>
#include<math.h>
#include"Monk.h"
#include"Map.h"
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Generation
{
protected:
	vector<Monk> population;
	int generation;
	int population_size;

public:
	Generation();
	~Generation();
	void fillGeneration(int size, int generation,Map map);
	vector<Monk> gethumanity();
	vector<Monk> selection1(); //tournament
	vector<Monk> selection2(double T); // truncation
	vector<Monk> crossover(vector<Monk> matingpool, double mutation_chance);
	int hrabanie(Map map, Monk gardener);
};

#endif
