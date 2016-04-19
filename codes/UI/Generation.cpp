#include "Generation.h"



Generation::Generation()
{
}


Generation::~Generation()
{
}

void Generation::fillGeneration(int size, int generation, Map map)
{
	this->population_size = size;
	this->generation = generation;
	this->population.resize(size);
	for (int i = 0; i < size; i++)
	{
		this->population[i] = Monk(map, generation);
	}
}

vector<Monk> Generation::gethumanity()
{
	return this->population;
}

vector<Monk> Generation::selection1() //tournament
{
	vector<Monk> matingpool;
	int current_pool_filling = 0;
	matingpool.reserve(this->population_size / 2);
	Monk first_contenstance = Monk();
	Monk second_contenstance = Monk();
	int first;
	int second;
	while (current_pool_filling != this->population_size/2)
	{
		first = ((rand() % this->population_size));
		second = ((rand() % this->population_size));
		while (first == second)
		{
			second = ((rand() % this->population_size));
		}
		first_contenstance = this->population[first];
		second_contenstance = this->population[second];
		if (first_contenstance.getfitness() >= second_contenstance.getfitness())
		{
			matingpool.push_back(first_contenstance);
			current_pool_filling++;
		}
		else
		{
			matingpool.push_back(second_contenstance);
			current_pool_filling++;
		}
	}
	return matingpool;

}

vector<Monk> Generation::selection2(double T)
{
	vector<Monk> matingpool;
	vector<Monk> full = this->population;
	double numbers = (double)this->population_size / T;
	std::sort(full.begin(), full.end());
	matingpool.reserve((int)numbers);
	
	for (int i = 0; i < (int)numbers; i++)
	{
		matingpool.push_back(this->population[i]);
	}
	return matingpool;
}

int Generation::hrabanie(Map map, Monk gardener)
{
	Map povodna = map;
	vector< vector<char> > garden=map.getmap();
	vector<Monk::Movement> free;
	Monk monk = gardener;
	Monk::Movement current_direction;
	bool set = false;
	bool game_over = false;;
	vector<int> starts = monk.getstarts();
	free.reserve(2);
	for (int i = 0; i < starts.size(); i++)
	{

		monk.setdirection(starts[i]);
		current_direction = monk.getdirection();
		if (current_direction == Monk::DOWN)
			{
				monk.setY(0);
				monk.setX(starts[i]);
			}
		else if (current_direction == Monk::LEFT)
			{
				monk.setY(starts[i] % povodna.getheight());
				monk.setX(0);
			}
		else if (current_direction == Monk::UP)
			{
				monk.setY(povodna.getheight()-1);
				monk.setX(starts[i] % povodna.getwidth());
			}
		else if (current_direction == Monk::RIGHT)
			{
				monk.setY(starts[i] % povodna.getheight());
				monk.setX(povodna.getwidth() - 1);
			}


			while (monk.isinside())
				{

					while (current_direction == Monk::DOWN )
					{
						if (!monk.isinside())
						{
							break;
						}

						if (garden[monk.getY()][monk.getX()] !='0')
						{
							monk.setY(monk.getY() - 1);
							free = monk.lookaround();
							if (free.empty())
							{
								game_over = true;
								return -1;
							}
							else
							{
								for each (Monk::Movement var in free)
								{
									if (var == monk.getprefrered())
									{
										set = true;
										monk.setdirection(var);
										current_direction = monk.getdirection();
										if (monk.getprefrered() == Monk::RIGHT)
										{
											monk.setX(monk.getX() - 1);
										}
										else if (monk.getprefrered() == Monk::LEFT)
										{
											monk.setX(monk.getX() + 1);
										}

									}
								}

								if (!set)
								{
									monk.setdirection(free[0]);
									current_direction = monk.getdirection();
									if (monk.getdirection() == Monk::RIGHT)
									{
										monk.setX(monk.getX() - 1);
									}
									else if (monk.getdirection() == Monk::LEFT)
									{
										monk.setX(monk.getX() + 1);
									}
									break;
								}
								else
								{
									break;
								}
							}
						}
						else
						{
							garden[monk.getY()][monk.getX()] = (i+1) + '0';
							monk.setY(monk.getY() + 1);
						}
					}//while down end


					while (current_direction == Monk::UP)
					{
						if (!monk.isinside())
						{
							break;
						}

						if (garden[monk.getY()][monk.getX()] != '0')
						{
							monk.setY(monk.getY() + 1);
							free = monk.lookaround();
							if (free.empty())
							{
								game_over = true;
								return -1;
							}
							else
							{
								for each (Monk::Movement var in free)
								{
									if (var == monk.getprefrered())
									{
										set = true;
										monk.setdirection(var);
										current_direction = monk.getdirection();
										if (monk.getprefrered() == Monk::RIGHT)
										{
											monk.setX(monk.getX() - 1);
										}
										else if (monk.getprefrered() == Monk::LEFT)
										{
											monk.setX(monk.getX() + 1);
										}
									}
								}

								if (!set)
								{
									monk.setdirection(free[0]);
									current_direction = monk.getdirection();
									if (monk.getdirection() == Monk::RIGHT)
									{
										monk.setX(monk.getX() - 1);
									}
									else if (monk.getdirection() == Monk::LEFT)
									{
										monk.setX(monk.getX() + 1);
									}
									break;
								}
								else
								{
									break;
								}
							}
						}
						else
						{
							garden[monk.getY()][monk.getX()] = (i + 1) + '0';
							monk.setY(monk.getY() - 1);
						}
					}// while up end


					while (current_direction == Monk::LEFT)
					{
						if (!monk.isinside())
						{
							break;
						}

						if (garden[monk.getY()][monk.getX()] != '0')
						{
							monk.setX(monk.getX() -1);
							free = monk.lookaround();
							if (free.empty())
							{
								game_over = true;
								return -1;
							}
							else
							{
								for each (Monk::Movement var in free)
								{
									if (var == monk.getprefrered())
									{
										set = true;
										monk.setdirection(var);
										current_direction = monk.getdirection();
										if (monk.getprefrered() == Monk::RIGHT)
										{
											monk.setY(monk.getY() + 1);
										}
										else if (monk.getprefrered() == Monk::LEFT)
										{
											monk.setY(monk.getY() - 1);
										}
									}
								}

								if (!set)
								{
									monk.setdirection(free[0]);
									current_direction = monk.getdirection();
									if (monk.getdirection() == Monk::RIGHT)
									{
										monk.setY(monk.getY() + 1);
									}
									else if (monk.getdirection() == Monk::LEFT)
									{
										monk.setY(monk.getY() - 1);
									}
									break;
								}
								else
								{
									break;
								}
							}
						}
						else
						{
							garden[monk.getY()][monk.getX()] = (i + 1) + '0';
							monk.setX(monk.getX() + 1);
						}
					}// while left end
					while (current_direction == Monk::RIGHT)
					{
						if (!monk.isinside())
						{
							break;
						}

						if (garden[monk.getY()][monk.getX()] != '0')
						{
							monk.setX(monk.getX() + 1);
							free = monk.lookaround();
							if (free.empty())
							{
								game_over = true;
								return -1;
							}
							else
							{
								for each (Monk::Movement var in free)
								{
									if (var == monk.getprefrered())
									{
										set = true;
										monk.setdirection(var);
										current_direction = monk.getdirection();
										if (monk.getprefrered() == Monk::RIGHT)
										{
											monk.setY(monk.getY() + 1);
										}
										else if (monk.getprefrered() == Monk::LEFT)
										{
											monk.setY(monk.getY() - 1);
										}
									}
								}

								if (!set)
								{
									monk.setdirection(free[0]);
									current_direction = monk.getdirection();
									if (monk.getdirection() == Monk::RIGHT)
									{
										monk.setY(monk.getY() + 1);
									}
									else if (monk.getdirection() == Monk::LEFT)
									{
										monk.setY(monk.getY() - 1);
									}
									break;
								}
								else
								{
									break;
								}
							}
						}
						else
						{
							garden[monk.getY()][monk.getX()] = (i + 1) + '0';
							monk.setX(monk.getX() - 1);
						}
					}// while right end
			}// while end
			/*monk.setmap(garden);
			std::cout << endl;
			monk.getmap().printmap();*/

	}//for end
	monk.setmap(garden);
	std::cout << endl;
	monk.getmap().printmap();
}
