#include <iostream>
#include <ctime>
double calculateDyst(double D);

double b = 2.7;
double C = 5.0;

int main() {

	double xmax = (3 * (std::log(10.0) / b)) + C;
	for (int i = 0; i < 1000; i++) {

		double D = double(std::rand()) / double(RAND_MAX);

		std::cout << calculateDyst(D) << "\n";//<< D << "\n";


	}

	
	////std::cout << xmax<<"\n";
	//for (int i = 0; i < 1000; i++) {

	//	double xl = double(std::rand() / double(RAND_MAX))*(xmax - C) + C;
	//	double yl= double(std::rand() / double(RAND_MAX))*(b - 0.0) + 0.0;
	//	
	//	if (yl <= b * exp(-(b*(xl - C)))) {

	//		std::cout << xl << "\n";// << yl << "\n";

	//	}
	//	else {
	//		i--;
	//	}

	//}
	//system("pause");


}

double calculateDyst(double D)
{
	double x=0.0;

	x = (-1.0*(std::log(1.0 - D) / b) + C);
	return x;

}

