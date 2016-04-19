#include<iostream>
#include"Generation.h"
#include<math.h>
#include<ctime>
using namespace std;


int main()
{
	double mutation_chance;
	srand(time(NULL));
	int mode;
	int selection;
	int population_size;
	
	double mutation;
	cout << "select mode "<<endl<<"1:default "<<endl<<"2:custom " <<endl<<"3 :exit"<< endl;
	cin >> mode;
	cout << "you choose [" << mode << "] " << endl;
	if (mode == 1)
	{
		population_size = 40;
		cout << "select selection " << "1:tournament " << "2:truncation " << endl;
		cin >> selection;
		cout << "selection [" << selection << "] " << endl;

		Map map = Map();
		Monk tester = Monk(map, 0);
		tester.generategenes();
		tester.printgenes();
		cout << "your map" << endl;
		map.printmap();
		map.generatestartingpoints();
		Generation humanity = Generation();
		humanity.fillGeneration(population_size, 1, map);
		vector<Monk> first = humanity.gethumanity();
		for (int i = 0; i < population_size; i++)
		{
			humanity.hrabanie(map, first[i]);
			cout << endl;
		}
	//	humanity.hrabanie(map, first[0]);
		cout << endl;
	
		cin >> mode;
		
			
	}
	else if (mode == 2)
	{
		cout << "select selection " << "1:tournament " << "2:truncation " << endl;
		cin >> selection;
		cout << "selection [" << selection << "] " << endl;

		cout << "world";
	}
	if (mode == 3)
	{
		return 0;
	}
	

}