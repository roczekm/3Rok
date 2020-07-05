#include <iostream>
#include <ctime>
#include <cmath>



double mi = 2.0;
double sigma = 5.0;
double calculateR(double D);
double calcutateTheta(double D);
double calculateDyst(double D);

double b = 1.0;
double C = 0.0;


int main() {

	/*
	for (int i = 0; i < 1000; i++) {

	double D1 = double(std::rand()) / double(RAND_MAX);
	double D2 = double(std::rand()) / double(RAND_MAX);
	
	double R = calculateR(D1);
	double theta = calcutateTheta(D2);
	double Z1 = R * std::cos(theta);
	double x = sigma*Z1 + mi;
	std::cout << x << "\n";


	}*/
	
	/*for (int i = 0; i < 1000; i++) {
		double mi2 = 0.5;
		double sigma2 = 1.0 / std::pow(12.0, (1.0 / 2.0));
		double sumaX = 0.0;
		double y2;
		for (int j = 0; j < 10; j++) {
			sumaX+= double(std::rand()) / double(RAND_MAX);
		}
		double y=((1.0/10.0)*sumaX-mi2)/(sigma2/ std::pow(10.0, (1.0 / 2.0)));
		std::cout << y << "\n";

		

	}*/
	double xmax = (3 * (std::log(10.0) / b)) + C;
	for (int i = 0; i < 1000; i++) {

			double xl = double(std::rand() / double(RAND_MAX))*(xmax - C) + C;
			double yl= double(std::rand() / double(RAND_MAX))*b;
			
			if (yl <= ((1.0 / std::pow((2.0*3.14159265359), 0.5)) * exp(-(std::pow(xl,2.0)/2.0)))){

				double temp = double(std::rand() / double(RAND_MAX));
				if (temp > 0.5) {
					std::cout << xl << "\n";
				}
				else {
					std::cout << -xl << "\n";
				}

			}
			else {
				i--;
			}
		
		

	}



	//system("pause");
}

double calculateR(double D)
{
	double R = 0.0;
	R = std::pow((-2.0*std::log(D)), (1.0 / 2.0));
	return R;
}

double calcutateTheta(double D)
{
	double theta = 0.0;
	theta = 2.0*3.14159265359*D;
	return theta;
}

double calculateDyst(double D)
{
	double x = 0.0;

	x = (-1.0*(std::log(1.0 - D) / b) + C);
	return x;

}
