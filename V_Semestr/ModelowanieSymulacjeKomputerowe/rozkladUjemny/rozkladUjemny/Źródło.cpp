#include <iostream>
#include <ctime>
#include <random>
#include <utility>
#include <vector>
#include <fstream>


double binomialCoeff(double x)
{
	unsigned long long temp = 1;
	for  (int i = 1; i<= x; i++)
	{
		temp *= i;
	}
	return temp;
}


int main() {

	std::random_device generator;
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	
	std::uniform_int_distribution<int> dist1(0, 9);
	
	std::fstream plik;
	plik.open("test1.txt", std::ios::out);
	
	double p = 2.0 / 10.0;
	double porazki = 4.0;
	double pr = 0;

	for (int i = 0; i < 1000; i++) {
		double sukcesy = 0.0;
		int temp = 0;
		while (temp != 4) {
			double rng = dist(generator);
			if (rng <= 0.5) {
				temp++;
			}
			else {
				sukcesy++;
			}
			

		}


		plik<< sukcesy << std::endl;

		
		

	}
	double c = 0.0;
	int tab[14];
	for (int i = 0; i < 14; i++) {
		tab[i] = i;
	}

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j <= i; j++) {
			c = (binomialCoeff(tab[j] + porazki - 1) / (binomialCoeff(porazki - 1)*binomialCoeff((tab[j] + porazki - 1) - (porazki - 1))))*std::pow(p, double(tab[j]))*std::pow((1 - p), porazki);
		}
		std::cout << c<<std::endl;
		c = 0.0;
	}
	
	plik.close();
	system("pause");
	return 0;
}


