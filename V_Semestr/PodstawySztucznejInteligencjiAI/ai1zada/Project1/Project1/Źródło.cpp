#include <iostream>
#include <vector>
#include <random>


int main() {

	int n, col, row;
	double wspU = 0.54;
	double Emax = 0.063;
	int Cmax = 2000;


	std::cin >> n >> col >> row;
	int iloscWejsc = (col * row) + 1;
	std::vector<std::vector<int> > pic(n,std::vector<int>(col*row));
	std::vector<int> mT(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (col*row); j++) {
			std::cin>> pic[i][j];
		}
		std::cin >> mT[i];
	}
	
	
	std::random_device generator;
	std::uniform_real_distribution<double> dist(-1.0, 1.0);
	
	std::vector<double> wagi;
	wagi.push_back(0.);
	for (int i = 0; i < iloscWejsc-1; i++) {
		wagi.push_back(dist(generator));
	}
	
	double E;
	int k;
	for (k = 0; k < Cmax; k++) {

		E = 0.0;
		
		for (int i = 0; i < n; i++) {
			double y = 1.0 * wagi[0];
			for (int j = 0; j < (col * row); j++) {
				y += pic[i][j] * wagi[j + 1];

			}
			y = (1.0 / (1.0 + std::exp(-1.0 * y)));
			//wagi update w1 += n * (d-y) * x1
			std::cout << y<<std::endl;

			wagi[0] = wagi[0] + wspU * double(mT[i] - y) * (1.0 - y) * 1.0 * y;
			for (int j = 1; j < iloscWejsc; j++) {
				wagi[j] = wagi[j] + wspU *double(mT[i] - y)* (1.0 - y) * pic[i][j-1] * y;
				//wagi[j] = wagi[j] + wspU * double(mT[i] - y) * pic[i][j - 1];
			}
			//wagi[0] += wspU * double(mT[i] - y);

			E += 0.5 * std::pow(double(mT[i]) - y, 2.0);
		}
		if (E < Emax){
			break;
		}

	}
	
	double ytemp = 0.0;
	ytemp = 1.0 * wagi[0];
	for (int j = 0; j < (col * row); j++) {
		ytemp += pic[1][j] * wagi[j + 1];

	}
	ytemp = (1.0 / (1.0 + std::exp(-1.0 * ytemp)));

	std::cout << ytemp<<std::endl;
	std::cout << k << std::endl;
	std::cout << E;
	
	system("pause");










}