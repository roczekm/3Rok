#include<random>
#include<iostream>
#include <chrono>
#include<fstream>

int etap1();
int etap2();
int etap3();
int etap4();
int etap5();
int etap6();

std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());

int main() {

	std::fstream fileout("file.out", std::ios_base::out);
	
	for (int i = 0; i < 2000; i++) {
		int time = 0;
		time += etap1();
		time += etap2();
		time += etap4();
		time += etap5();
		time += etap6();
		fileout << time << std::endl;
	}
	fileout.close();
	return 0;
		



}

int etap1()
{
	std::bernoulli_distribution probability(0.5);
	
	if (!probability(generator)){
		std::discrete_distribution<int> distribution{ 0.0,0.1,0.1,0.1,0.2,0.2,0.1,0.1,0.1 };
		return distribution(generator);
	}
	return 0;
}

int etap2()
{
	std::bernoulli_distribution probability(0.5);

	if (!probability(generator)) {
		
		return etap3();
	}
	return 0;
}

int etap3()
{
	std::normal_distribution<double> distribution(1.0, 0.5);
	if (distribution(generator) > 1.0) {
		std::uniform_int_distribution<int> distribution1(20, 35);
		return distribution1(generator);
	}
	else {
		std::uniform_int_distribution<int> distribution1(10, 17);
		return distribution1(generator);
	}

}

int etap4()
{
	std::discrete_distribution<int> distribution{ 0.1,0.3,0.6 };
	int number = distribution(generator);
	if (number == 0) {
		std::uniform_int_distribution<int> distribution1(8, 11);
		return distribution1(generator);
	}
	else if (number == 1) {
		std::uniform_int_distribution<int> distribution1(4, 7);
		return distribution1(generator);
	}
	else {
		std::uniform_int_distribution<int> distribution1(1, 3);
		return distribution1(generator);
	}

}

int etap5()
{
	std::bernoulli_distribution probability(0.6);

	if (!probability(generator)) {
		std::uniform_int_distribution<int> distribution(15, 25);
		return distribution(generator);

	}
	else {
		std::uniform_int_distribution<int> distribution(7, 10);
		return distribution(generator);
	}
}

int etap6()
{
	std::discrete_distribution<int> distribution{ 0.6,0.3,0.1 };
	int number = distribution(generator);
	if (number == 0) {
		return 0;
	}
	else if (number == 1) {
		std::uniform_int_distribution<int> distribution1(1, 3);
		return distribution1(generator);
	}
	else {
		std::uniform_int_distribution<int> distribution1(5, 15);
		return distribution1(generator);
	}
}
