#include <iostream>
#include <random>
#include <string>
#include <vector>

long long int invmod(long long int a, long long int n);
bool isPrime(long long int n);
long long int powmod(long long int a, long long int  b, long long int  c);
long int potega(long long int base, long long int exponent);




int main() {

   

    
    long long int p, q;

    std::cout << "p = ";
    std::cin >> p;
    std::cout << "q = ";
    std::cin >> q;

    std::default_random_engine generator;
    
    if (isPrime(p) && isPrime(q)) {
        
        long long int n;
        long long int fi;
        long long int e;
        long long int d;
        std::string text;

        n = p * q;
        std::cout<<"n = "<<n<<"\n";
        fi = (p - 1) * (q - 1);
        std::cout << "fi(n) = " << fi << "\n";

        std::uniform_int_distribution<long long int> distribution(2, n);
        e = distribution(generator);
        
        while (invmod(e, fi) == -1) {

            e = distribution(generator);

        }

        d = invmod(e, fi);
        std::cout << "e = " << e << "\n";
        std::cout << "d = " << d << "\n";
        
        std::cout << "tekst=";
        std::cin >> text;
        int blockSize = 3;
        int blocksNumbers= text.size() / blockSize;
        int additionalChars=0;

        if ((text.size() % blockSize)!=0) {

           blocksNumbers = (text.size() / blockSize) + 1;
           additionalChars = text.size() % blockSize;
        }
        
      
        std::vector<long long int> blocks;



        for (int i = 0; i < blocksNumbers; i++) {
             

            if (i != blocksNumbers - 1) {
                blocks.push_back((long long int(text[i * blockSize]) << 16) + (long long int(text[i * blockSize + 1]) << 8) + long long int(text[i * blockSize + 2]));
            }
            else{

                if (additionalChars == 0) {
                    blocks.push_back((long long int(text[i * blockSize]) << 16) + (long long int(text[i * blockSize + 1]) << 8) + long long int(text[i * blockSize + 2]));
                }
                else if (additionalChars == 2) {
                    blocks.push_back((long long int(text[i * blockSize]) << 16) + (long long int(text[i * blockSize + 1]) << 8)) ;
                }
                else if (additionalChars == 1) {
                    blocks.push_back((long long int(text[i * blockSize]) << 16));
                }

            }

        }

        
        std::cout << "bloki= ";

        for (auto const& j : blocks) {
            std::cout << j << " ";
        }

        for (int i = 0; i < blocks.size();i++) {
            blocks[i] =powmod(blocks[i],e,n);
        }

        std::cout << "\nszyfr= ";
        for (auto const& j : blocks) {
            std::cout << j << " ";
        }

        for (int i = 0; i < blocks.size(); i++) {
            blocks[i] = powmod(blocks[i], d, n);
        }

        std::cout << "\nodszyfrowane_bloki= ";
        for (auto const& j : blocks) {
            std::cout << j << " ";
        }

        std::string temp;

        for (auto const& j : blocks) {
            temp += char((j / potega(2, 16)) % potega(2, 8));
            temp += char((j / potega(2, 8)) % potega(2, 8));
            temp += char((j % potega(2, 8)));

        }



        std::cout << "\nodszyfrowany_tekst= " << temp;

    }

    
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

long int potega(long long int base, long long int exponent) {
    long long int result = 1;

    for (long long int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}