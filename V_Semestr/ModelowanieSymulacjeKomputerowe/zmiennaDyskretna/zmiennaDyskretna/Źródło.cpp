#include <iostream>
#include <ctime>
#include <random>
#include <utility>
#include <vector>

double sumator(const std::vector < std::pair<int, double>>  &vect,int a);

int main() {



	std::vector<std::pair<int, double> > vec1 = { { 0, 0.01 },{1,0.03} ,{ 2,.05 },{ 3,.07 },{4,.09 },{5,.11},{6,.13 },{7,.15},{8,.17},{9,.19} };

	std::random_device gen1;
	std::random_device generator;
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	std::random_device generator1;
	std::uniform_int_distribution<int> dist1(0, 9);
	std::mt19937 gen(gen1());
	std::discrete_distribution<>rng3({ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 });

	for (int i = 0; i < 1000; i++) {
	
		double rng=dist(generator);
		double rng2 = dist1(generator1);

		/*for (int j = 1; j < 10; j++) {


			if (j + 1 <= 9 && sumator(vec1, j) < rng	&&sumator(vec1, j + 1) > rng) {
				std::cout << j + 1 << std::endl;
			}

		}*/
		
		/*if (vec1[rng2].second >= rng) {
			std::cout << vec1[rng2].first << std::endl;
		}else { i--; }*/
			
		std::cout<<rng3(gen)<<std::endl;
	
	}



	return 0;
}

double sumator(const std::vector < std::pair<int, double>>  &vect,int a)
{
	double suma = 0.0;
	for (int i = 0; i < a;i++) {
		suma += vect[i].second;
	}


	return suma;
}
