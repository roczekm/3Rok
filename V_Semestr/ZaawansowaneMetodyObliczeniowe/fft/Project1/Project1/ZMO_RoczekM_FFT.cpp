#include <complex>
#include <iostream>
#include <vector>
#include<iomanip>


const double PI = 3.14159265359;



using namespace std::complex_literals;

void fft(std::vector<std::complex<double>>& x){
	int n = x.size();

	if (n <= 1) {
		return;
	}


	std::vector<std::complex<double>> Even(n / 2); 
	std::vector<std::complex<double>> Odd(n / 2);
	for (int i = 0; i < n / 2; i++) {

		 
		Even[i] = x[i * 2];
		Odd[i] = x[i * 2 + 1];
	}

	fft(Even);
	fft(Odd);

	

	for (int k = 0; k < (n / 2); k++) {
		x[k] = Even[k] + std::exp(1i * (-2.0 * PI *  double(k)) / double(n)) * Odd[k];
		x[k + n / 2] = Even[k] - std::exp(1i * (-2.0 * PI * double(k)) / double(n)) * Odd[k];
	}
}
void ifft(std::vector<std::complex<double>>& x){
	
	
	for (int i = 0; i < x.size(); i++) {
		
		x[i] = std::conj(x[i]);
	}

	
	fft(x);

	for (int i = 0; i < x.size(); i++) {

		x[i] = std::conj(x[i]);
		x[i] /= x.size();
	}

}





int main()
{
	

	int liczba_punktow = 0;
	std::cin >> liczba_punktow;
	std::vector<std::complex<double>> pkt;

	for (int i = 0; i < liczba_punktow; i++) {

		double tempReal;
		double tempIma;
		std::cin >> tempReal >> tempIma;
		pkt.push_back(std::complex<double>(tempReal, tempIma));
	}

	fft(pkt);


	for (auto const& i : pkt) {

		std::cout << std::fixed << std::setprecision(4) << i << "\n";

	}
	std::cout << "\n\n\n";

	ifft(pkt);


	for (auto const& i : pkt) {

		std::cout << std::fixed << std::setprecision(4) << i << "\n";

	}
	std::cout << "\n\n\n";


	return 0;
}