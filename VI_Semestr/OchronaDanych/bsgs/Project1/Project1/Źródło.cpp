#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <chrono>


long long int bsgs(long long int g,long long int p, long long int A);
long long int invmod(long long int a, long long int n);
bool isPrime(long long int n);
long long int powmod(long long int a, long long int  b, long long int  c);


// A=g^a mod p    n=p   a=g  d=A  x=a
//g=1711845894, p=1337379107, A=  882773021: Roczek     Mateusz

int main() {

    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<double> time_span;
    start = std::chrono::high_resolution_clock::now();
    int x = bsgs(1711845894, 1337379107, 882773021);
    end = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << x<<" "<< time_span.count() << " \n";
    //std::cout<<"\n"<<powmod(1711845894, x, 1337379107);


}

long long int bsgs(long long int g, long long int p, long long int A)
{

	long long int m = std::ceil(std::sqrt(p));
   
    long long int tempP=m;
    while(true){
        if (isPrime(tempP) == true){
            
            break;
        }
        tempP++;
    }

	std::vector<std::unordered_map<long long int, long long int>> Lstrona(tempP);
    long long int x = 0;
    


	for (long long int j = 0; j < m ; j++) {
        long long int temp = powmod(g, j, p);
        long long int hash = temp % tempP;
        Lstrona[hash].emplace(temp, j);
	}
    

    long long int v= powmod(invmod(g, p), m, p);
    

    for (long long int i = 0; i < m ; i++) {

        
        long long int temp = (A % p * powmod(v, i, p)) % p;

        long long int tempH = temp % tempP;
        for (auto k : Lstrona[tempH]){
            if (k.first == temp) {
                x = i * m+k.second;
                return x;
            }

        }


    }

	return x;
}


long long int invmod(long long int a, long long int n) {

    long long int r = a;
    long long int r2 = n;
    long long int s1 = 1;
    long long int s2 = 0;


    while (r > 1) {

        long long int q = r / r2;
        long long int temp = r2;
        r2 = r % r2;
        r = temp;
        temp = s2;
        s2 = s1 - q * s2;
        s1 = temp;

        if (r2 == 0) {
            break;
        }
    }


    if (r == 1 && s1 > 0) {
        return s1;
    }
    else if (r == 1 && s1 < 0) {
        return s1 + n;
    }
    return -1;

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

