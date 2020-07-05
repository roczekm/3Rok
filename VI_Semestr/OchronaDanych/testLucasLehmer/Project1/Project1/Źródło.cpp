#include <iostream>

long int potega(long long int base, long long int exponent);
void testLucasLehmer(long long int p);
bool isPrime(long long int n);


int main(){
	
	int j=31;
	for (long long int i = 3; i <= j; i++){
		if (i % 2 != 0 && isPrime(i) == true){
			std::cout << "2^" << i << "-1=" << (potega(2, i) - 1) << " ";
			testLucasLehmer(i);
		}
	}

	return 0;
}


long int potega(long long int base, long long int exponent){
	long long int result = 1;

	for (long long int i = 0; i < exponent; i++){
		result *= base;
	}
	return result;
}

void testLucasLehmer(long long int p){
	long long int s = 4;
	long long int M= (potega(2,p) - 1) ;

	for (long long int i = 0; i < long long int(p - 2); i++){
		s = ((s * s) - 2) % M;
	}
	if (s == 0){
		std::cout << "Pierwsza\n";
	}
	else{
		std::cout << "Zlozona\n";
	}
}

bool isPrime(long long int number){
	bool isPrime = true;

	for (long long int i = 2; i <= long long int(number / 2); i++){
		if (number % i == 0){
			isPrime = false;
			break;
		}
	}
	if (isPrime == true){
		return true;
	}
	else{
		return false;
	}

}