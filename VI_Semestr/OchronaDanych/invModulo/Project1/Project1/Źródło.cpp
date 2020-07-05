#include <iostream>

int invmod(int a, int n);


int main() {


    std::cout <<"(337*x) mod 123=1  x= "<< invmod(122947, 193000) << "\n";
    //std::cout <<"(4321*x) mod 1234=1   x= "<< invmod(4321, 1234)<<"\n";
   // std::cout <<"(432*x) mod 321=1   x= "<< invmod(432, 321);



}

int invmod(int a, int n) {

    int r = a;
    int r2 = n;
    int s1 = 1;
    int s2 = 0;
  

    while (r > 1){ 

        int q = r / r2;
        int temp = r2;
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