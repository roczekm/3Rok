#include <iostream>
#include <ctime>

double PI = 3.14159265359;
double a = -PI / 8;
double b = 3 * PI / 8;

double calculate(double r);


int main() {

	std::srand(std::time(NULL));

	/*for (int i = 0; i < 1000; i++) {

		double r = double(std::rand()) / double(RAND_MAX);
		
		std::cout << calculate(r)<<"\n"<<r<<"\n";


	}*/

	double yl=0.0;
	double xl = 0.0;
	double rl = 0.0;
	for (int i = 0; i < 1000; i++) {

		yl = (std::rand() % (1 - 0) + 0.0);
		rl = std::rand() / RAND_MAX;
		xl = rl * (((3.0*PI) / 8.0) - (-PI / 8.0)) + (-PI / 8.0);
		if (yl <= std::cos(2.0*xl - PI / 4.0)) {
			std::cout << xl << std::endl;
		}
		else {
			i--;;
		}
	}

	

	//system("pause");







}

double calculate(double r)
{
	double x = 0.5* std::asin(2.0 * r - 1.0) + PI / 8.0;

	return x;
}
