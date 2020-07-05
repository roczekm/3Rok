#include <iostream>
#include <vector>
#include <random>

void random(std::vector<double>& x, int k);
double f(double value);
double df(double value);
void checkXOR(const std::vector<int>& x, const std::vector<double>& weights);

int main() {

	std::vector<int> p1{ -1,-1,1 };
	std::vector<int> p2{ -1,1,1 };
	std::vector<int> p3{ 1,-1,1 };
	std::vector<int> p4{ 1,1,1 };
	//std::vector<int> test{ -1,1,1 };

	std::vector<std::vector<int> > input{ {-1,-1,1},
									   {-1,1,1 },
									   { 1,-1,1 },
									   { 1,1,1 } };




	std::vector<int>t{ 0,1,1,0 };

	double wsp = 0.8;
	double Emax = 0.003;
	double Cmax = 10000;
	int ilosc_obrazow = 4;

	std::vector<double>weights;

	random(weights, 9);

	

	for(int c=0;c<Cmax;c++){
		double E = 0.0;

		for (int i = 0; i < ilosc_obrazow; i++) {

			double neuronY1=0.0;
			double neuronY2=0.0;
			double neuronY3=0.0;

			neuronY1 += input[i][0] * weights[0]+ input[i][1] * weights[1]+ input[i][2] * weights[2];
			neuronY2 += input[i][0] * weights[3] + input[i][1] * weights[4] + input[i][2] * weights[5];

			double temp1 = neuronY1;
			double temp2 = neuronY2;
			neuronY1 = f(neuronY1);
			neuronY2 = f(neuronY2);
			

			neuronY3 += input[i][2] * weights[8] + neuronY1 * weights[6] + neuronY2 * weights[7];
			double temp3 = neuronY3;
			neuronY3 = f(neuronY3);
			////////////obliczaanie sygnalu bledu delta
			double error21 = 0.0;
			double error11 = 0.0;
			double error12 = 0.0;

			error21= (t[i] - neuronY3) * df(temp3);
			error11 = error21 * weights[6] * df(temp1);
			error12 = error21 * weights[7] * df(temp2);
			///update wag

			weights[0] += wsp* error11 * input[i][0];
			weights[1] += wsp * error11 * input[i][1];
			weights[2] += wsp * error11 * input[i][2];

			weights[3] += wsp * error12 * input[i][0];
			weights[4] += wsp * error12 * input[i][1];
			weights[5] += wsp * error12 * input[i][2];

			weights[6] += wsp * error21 * neuronY1;
			weights[7] += wsp * error21 * neuronY2;
			weights[8] += wsp * error21 * input[i][2];
			
			E += 0.5 * std::pow(double(t[i]) - neuronY3, 2.0);

		}

		if (E < Emax) {
			break;
		}
	}

	
	checkXOR(p1, weights);
	checkXOR(p2, weights);
	checkXOR(p3, weights);
	checkXOR(p4, weights);






	system("pause");
	return 0;
}


void random(std::vector<double>& x, int k) {

	std::random_device generator;
	std::uniform_real_distribution<double> dist(-1.0, 1.0);

	for (int i = 0; i < k; i++) {
		x.push_back(dist(generator));
	}


}

double f(double value)
{
	return double(1.0 / (1.0 + double(std::exp(-1.0 * value))));
}
double df(double value)
{
	return double(double(std::exp(-1.0*value)) / std::pow(1.0 + double(std::exp(-1.0 * value)),2.0));
}

void checkXOR(const std::vector<int>& x, const std::vector<double>& weights)
{


	double neuronY1 = 0.0;
	double neuronY2 = 0.0;
	double neuronY3 = 0.0;

	neuronY1 += x[0] * weights[0] + x[1] * weights[1] + x[2] * weights[2];
	neuronY2 += x[0] * weights[3] + x[1] * weights[4] + x[2] * weights[5];

	double temp1 = neuronY1;
	double temp2 = neuronY2;
	neuronY1 = f(neuronY1);
	neuronY2 = f(neuronY2);


	neuronY3 += x[2] * weights[8] + neuronY1 * weights[6] + neuronY2 * weights[7];
	double temp3 = neuronY3;
	neuronY3 = f(neuronY3);
	


	std::cout << neuronY3 << std::endl;


}
