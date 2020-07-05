#include <iostream>
#include <ctime>
#include <random>
#include <utility>
#include <vector>
#include <fstream>


double binomialCoeff(double n, double k)
{
	// Base Cases  
	if (k == 0 || k == n)
		return 1;

	// Recur  
	return binomialCoeff(n - 1, k - 1) +
		binomialCoeff(n - 1, k);
}


int main() {

	std::random_device generator;
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	std::uniform_int_distribution<int> dist1(0, 9);

	std::fstream plik;
	plik.open("test1.txt", std::ios::out);

	double p = 2.0 / 10.0;
	double porazki = 1.0;
	double pr = 0;

	for (int i = 0; i < 1000; i++) {
		double sukcesy = 0.0;
		int temp = 0;
		while (temp != porazki) {
			double rng = dist(generator);
			if (rng <= 0.5) {
				temp++;
			}
			else {
				sukcesy++;
			}


		}


		plik << sukcesy << std::endl;


		

	}
	for (int i = 0; i < 15; i++) {
		if (i != 0) {
			std::cout << i << " " << std::pow(p, i)*(1 - p) << std::endl;
		}
	}
	plik.close();
	system("pause");
	return 0;
}


