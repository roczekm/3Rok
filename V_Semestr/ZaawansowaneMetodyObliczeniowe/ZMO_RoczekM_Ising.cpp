#include <iostream>
#include <random>
#include <map>
#include <vector>


int suma(int** tab);
int magnetyzacja(int** tab);
double calcAverageEd(const std::map<int, int>& temp_map);
double calcAverageN(const std::map<int, int>& temp_map);
double calcAverageEdxN(const std::map<int, int>& temp_map);
double calcAverageEdxEd(const std::map<int, int>& temp_map);


int col = 100;
int row = 100;


int main() {


	//int demon = 0;
	int x, y;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist100(0, 99);
	std::vector<int> demon{500,1000,2000,2500,5000, 10000,15000,20000 };


	//while (std::cin >> demon) {
	for(int m=0;m< demon.size();m++){
		std::cout << "poczatkowa energia demona: " << demon[m] << "\n";
		int** tab = new int* [row];


		for (int i = 0; i < row; i++) {

			tab[i] = new int[col];

		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				tab[i][j] = 1;

			}
		}

		int E = 0;
		int mag = 0;
		double sMag = 0.0;
		std::map<int, int> histogram;

		for (int k = 0; k < 50000; k++) {

			E = suma(tab);
			x = dist100(rng);
			y = dist100(rng);
			tab[x][y] *= -1;
			int E1;
			E1 = suma(tab);

			if (E1 >= E) {

				if (demon[m] >= E1 - E) {
					demon[m] -= E1 - E;
				}
				else {
					tab[x][y] *= -1;
					E1 = suma(tab);

				}

			}

			else if (E1 < E) {

				demon[m] += E - E1;
			}

			E = E1;

			if (k > 48000 && k < 49001) {


				if (!histogram.count(demon[m])) {

					histogram.insert({ demon[m], 1 });

				}
				else {

					histogram[demon[m]]++;

				}

				mag = magnetyzacja(tab);
				sMag += double(mag);

			}


		}



		sMag /= 1000.0;



		double licznik = calcAverageEdxN(histogram) - (calcAverageEd(histogram) * calcAverageN(histogram));
		double mianownik = calcAverageEdxEd(histogram) - pow(calcAverageEd(histogram), 2.0);
		double beta = licznik / mianownik;
		double temperatura = -1.0 / beta;


		
		std::cout <<"srednia magnetyzacja: " <<sMag << " temperatura: " << temperatura << "\n"<<"Histogram: \n";

		for (auto&& item : histogram)
			std::cout << item.first << ": " << item.second << '\n';


		for (int i = 0; i < row; ++i) {
			delete[] tab[i];
		}
		delete[] tab;
	}

	

	//system("pause");

}

int suma(int** tab)
{
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			if (i == row - 1 && j == col - 1) {

				sum += tab[i][j] * tab[0][col - 1];
				sum += tab[i][j] * tab[row - 1][0];

			}


			else if (j == col - 1) {

				sum += tab[i][0] * tab[i][j];
				sum += tab[i][j] * tab[i + 1][j];

			}
			else if (i == row - 1) {
				sum += tab[i][j] * tab[i][j + 1];
				sum += tab[i][j] * tab[0][j];
			}

			else {
				sum += tab[i][j] * tab[i][j + 1];
				sum += tab[i][j] * tab[i + 1][j];
			}


		}
	}

	sum *= -1;
	return sum;

}

int magnetyzacja(int** tab)
{
	int mag = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mag += tab[i][j];
		}
	}
	return mag;

}

double calcAverageEd(const std::map<int, int>& temp_map)
{
	double averageEd = 0.0;
	for (auto& temp : temp_map) {

		averageEd += temp.first;

	}


	return (averageEd / temp_map.size());
}

double calcAverageN(const std::map<int, int>& temp_map)
{
	double averageN = 0.0;
	for (auto& temp : temp_map) {

		averageN += log(temp.second);

	}


	return (averageN / temp_map.size());
}

double calcAverageEdxN(const std::map<int, int>& temp_map)
{
	double averageEdxN = 0.0;
	for (auto& temp : temp_map) {

		averageEdxN += temp.first * log(temp.second);

	}


	return (averageEdxN / temp_map.size());
}

double calcAverageEdxEd(const std::map<int, int>& temp_map)
{
	double averageEdxEd = 0.0;
	for (auto& temp : temp_map) {

		averageEdxEd += pow(temp.first, 2);

	}


	return (averageEdxEd / temp_map.size());
}


