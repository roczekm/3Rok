#include <iostream>
bool isPrime(long long int n);
long long int powmod(long long int a, long long int  b, long long int  c);



int main() {
    long long int p, g, a, B, k;

    std::cout << "p= ";
    std::cin >> p;
    if (isPrime(p)) {
        std::cout << "g= ";
        std::cin >> g;
        std::cout << "a= ";
        std::cin >> a;
        std::cout << "A= "<< powmod(g,a,p);
        std::cout << "\nB= ";
        std::cin >> B;
        std::cout << "k= " << powmod(B, a, p)<<"\n";
    }

    system("pause");
   
    return 0;
}




bool isPrime(long long int number) {
	bool isPrime = true;

	for (long long int i = 2; i <= long long int(number / 2); i++) {
		if (number % i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime == true) {
		return true;
	}
	else {
		return false;
	}

}

long long int powmod(long long int a, long long int  b, long long int  c) {
    
    long long int temp = 1;

    a = a % c;       

    if (a == 0) return 0; 
    while (b > 0)
    {

        if (b & 1) {
        temp = (temp * a) % c;
    }

        
        b = b >> 1; 
        a = (a * a) % c;
    }
    return temp;

}