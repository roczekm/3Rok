#include <iostream>
#include <ctime>
double calculate(double D);

double b = 2.7;
double C = 5.0;

int main() {

	/*
	for (int i = 0; i < 1000; i++) {

		double D = double(std::rand()) / double(RAND_MAX);

		std::cout << calculate(D) << "\n";


	}*/
	double fmax = 7.0;
	for (int i = 0; i < 1000; i++) {

		double xl = double(std::rand() / double(RAND_MAX))*(3 - 2) + 2;
		double yl = double(std::rand() / double(RAND_MAX))*(7 - 0) + 0;

		if (yl <= (7 * std::pow((xl - 2),6.0))) {
			std::cout << xl << "\n";
		}

	}


}

double calculate(double D)
{
	double x = 0.0;
	x=std::pow(D, (1 / 7.0))+2;
	return x;
}

