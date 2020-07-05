#include<iostream>
#include<random>
#include<vector>


int main() {



	double lam = 3.5;
	double q = std::exp(-lam);

	
	std::random_device generator;
	std::uniform_real_distribution<double> dist(0.0,1.0);

	std::poisson_distribution<int> distribution(5.5);



	for (int i = 0; i < 1000; i++) {
		double X = -1;
		double S = 1;
		while (S > q) {

			double U = dist(generator);
			S *= U;
			X += 1;


		}

		std::cout << X << std::endl;
		//std::cout << distribution(generator) << std::endl;


	}




}