#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <math.h>




void random(std::vector<double>& x, int k);
double f1(double value);
double f3(double value);

void N1B0();
void N1B1();
void N3B0();
void N3B1();


int main() {

	N1B0();
	N1B1();
	N3B0();
	N3B1();

	system("pause");
	return 0;



}

void random(std::vector<double>& x, int k) {

	std::random_device generator;
	std::uniform_real_distribution<double> dist(-5.0, 5.0);

	for (int i = 0; i < k; i++) {
		x.push_back(dist(generator));
	}


}


double f1(double value)
{
	if (value >= 1) {
		return 1.0;
	}
	else {
		return 0.0;
	}
}


double f3(double value)
{
	return double(1.0 / (1.0 + double(std::exp(-1.0 * value))));
}

void N1B0()
{

	std::vector<double>weights;
	double y = 0;
	random(weights, 2);
	std::cout << "neuron o 2 sygnalach wejsciowych bias=0 \n";
	std::cout << " Progowa RED => o , BLUE => x \n\n\n";
	
	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			//random(weights, 2);
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			//suma += signal[0] * weights[0] + signal[1] * weights[1];
			suma += i * weights[0] + j * weights[1];

			y = f1(suma);
			if (y == 1) {

				std::cout << 'o';
			}
			else {

				std::cout << 'x';
			}

		}
		std::cout << "\n";
	}

	std::cout << " liniowa GRANATOWY => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			//random(weights, 2);
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			//suma += signal[0] * weights[0] + signal[1] * weights[1];
			suma += i * weights[0] + j * weights[1];

			if (suma <-5.0) {

				std::cout << '+';
			}else if(suma>=-5.0 && suma <=0.0) {

				std::cout << 'x';
			}
			else if (suma >= 0.0 && suma <= 5.0) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}

	std::cout << " sigmoidalna YELLOW => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			//random(weights, 2);
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			//suma += signal[0] * weights[0] + signal[1] * weights[1];
			suma += i * weights[0] + j * weights[1];

			double y = f3(suma);
			if (y <=0.25) {

				std::cout << '+';
			}
			else if (y > 0.25 && y <= .5) {

				std::cout << 'x';
			}
			else if (y > 0.5 && y <= 0.75) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}


}

void N1B1()
{
	std::vector<double>weights;
	double y = 0;
	random(weights, 3);
	std::cout << "neuron o 2 sygnalach wejsciowych bias=1 \n";
	std::cout << " Progowa RED => o , BLUE => x \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			//random(weights, 3);
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			//suma += signal[0] * weights[0] + signal[1] * weights[1]+weights[2];
			suma += i * weights[0] + j * weights[1]+weights[2];

			y = f1(suma);
			if (y == 1) {

				std::cout << 'o';
			}
			else {

				std::cout << 'x';
			}

		}
		std::cout << "\n";
	}

	std::cout << " liniowa GRANATOWY => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			//random(weights, 3);
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			//suma += signal[0] * weights[0] + signal[1] * weights[1]+weights[2];
			suma += i * weights[0] + j * weights[1] + weights[2];

			if (suma < -5.0) {

				std::cout << '+';
			}
			else if (suma >= -5.0 && suma <= 0.0) {

				std::cout << 'x';
			}
			else if (suma >= 0.0 && suma <= 5.0) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}

	std::cout << " sigmoidalna YELLOW => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			//random(weights, 3);
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			//suma += signal[0] * weights[0] + signal[1] * weights[1]+weights[2];
			suma += i * weights[0] + j * weights[1] + weights[2];

			double y = f3(suma);
			if (y <= 0.25) {

				std::cout << '+';
			}
			else if (y > 0.25 && y <= .5) {

				std::cout << 'x';
			}
			else if (y > 0.5 && y <= 0.75) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}




}

void N3B0()
{

	std::vector<double>weights;
	double y = 0;
	random(weights, 6);
	std::cout << "neuron o 3 sygnalach wejsciowych bias=0 \n";
	std::cout << " Progowa RED => o , BLUE => x \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			double suma2 = 0.0;
			double suma3 = 0.0;
			suma = i * weights[0] + j * weights[1];
			suma2 = i * weights[2] + j * weights[3];
			suma3 = suma * weights[4] + suma2 * weights[5];

			y = f1(suma3);
			if (y == 1) {

				std::cout << 'o';
			}
			else {

				std::cout << 'x';
			}

		}
		std::cout << "\n";
	}

	std::cout << " liniowa GRANATOWY => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			
			//std::vector<double>signal;
			//random(signal, 2);
			
			double suma = 0.0;
			double suma2 = 0.0;
			double suma3 = 0.0;
			suma = i * weights[0] + j * weights[1];
			suma2 = i * weights[2] + j * weights[3];
			suma3 = suma * weights[4] + suma2 * weights[5];

			if (suma3 < -5.0) {

				std::cout << '+';
			}
			else if (suma3 >= -5.0 && suma3 <= 0.0) {

				std::cout << 'x';
			}
			else if (suma3 >= 0.0 && suma3 <= 5.0) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}

	std::cout << " sigmoidalna YELLOW => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {
			
			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			double suma2 = 0.0;
			double suma3 = 0.0;
			suma = i * weights[0] + j * weights[1];
			suma2 = i * weights[2] + j * weights[3];
			suma3 = suma * weights[4] + suma2 * weights[5];

			double y = f3(suma3);
			if (y <= 0.25) {

				std::cout << '+';
			}
			else if (y > 0.25 && y <= .5) {

				std::cout << 'x';
			}
			else if (y > 0.5 && y <= 0.75) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}


}

void N3B1()
{

	std::vector<double>weights;
	double y = 0;
	random(weights, 9);
	std::cout << "neuron o 3 sygnalach wejsciowych bias=1 \n";
	std::cout << " Progowa RED => o , BLUE => x \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {

			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			double suma2 = 0.0;
			double suma3 = 0.0;
			suma = i * weights[0] + j * weights[1]+weights[6];
			suma2 = i * weights[2] + j * weights[3]+weights[7];
			suma3 = suma * weights[4] + suma2 * weights[5]+weights[8];

			y = f1(suma3);
			if (y == 1) {

				std::cout << 'o';
			}
			else {

				std::cout << 'x';
			}

		}
		std::cout << "\n";
	}

	std::cout << " liniowa GRANATOWY => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {

			//std::vector<double>signal;
			//random(signal, 2);

			double suma = 0.0;
			double suma2 = 0.0;
			double suma3 = 0.0;
			suma = i * weights[0] + j * weights[1] + weights[6];
			suma2 = i * weights[2] + j * weights[3] + weights[7];
			suma3 = suma * weights[4] + suma2 * weights[5] + weights[8];

			if (suma3 < -5.0) {

				std::cout << '+';
			}
			else if (suma3 >= -5.0 && suma3 <= 0.0) {

				std::cout << 'x';
			}
			else if (suma3 >= 0.0 && suma3 <= 5.0) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}

	std::cout << " sigmoidalna YELLOW => + BLUE => x GREEN => * RED => o  \n\n\n";

	for (int i = -50; i < 50; i++) {
		for (int j = -50; j < 50; j++) {

			//std::vector<double>signal;
			//random(signal, 2);
			double suma = 0.0;
			double suma2 = 0.0;
			double suma3 = 0.0;
			suma = i * weights[0] + j * weights[1] + weights[6];
			suma2 = i * weights[2] + j * weights[3] + weights[7];
			suma3 = suma * weights[4] + suma2 * weights[5] + weights[8];

			double y = f3(suma3);
			if (y <= 0.25) {

				std::cout << '+';
			}
			else if (y > 0.25 && y <= .5) {

				std::cout << 'x';
			}
			else if (y > 0.5 && y <= 0.75) {
				std::cout << '*';
			}
			else {
				std::cout << 'o';
			}

		}
		std::cout << "\n";
	}




}

