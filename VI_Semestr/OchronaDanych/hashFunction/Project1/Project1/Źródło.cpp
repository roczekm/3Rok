#include <iostream>
#include<string>
#include <random>
#include<vector>

unsigned int DJB(const std::string& s);
unsigned int adler32(const std::string& s);
std::string randomString(int n);
void checkCollision(int D,int N,int o);




int main() {

	

	checkCollision(8, 100000, 0);
	checkCollision(100, 100000, 0);
	checkCollision(8, 100000, 1);
	checkCollision(100, 100000, 1);

}




unsigned int DJB(const std::string& s) {
	unsigned int hash = 5381;

	for (auto const& i : s) {
		hash = hash*32 + hash + int(i);
		
	}
	return hash;


}
unsigned int adler32(const std::string& s) {

	unsigned int A = 1;
	unsigned int B = 0;
	unsigned int P = 65521;
	for (auto const& i : s) {
		A = (A + int(i)) % P;
		B = (B + A) % P;
	}
	return B * 65536 + A;
}

std::string randomString(int n) {


	std::string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<> distribution(0, str.size() - 1);

	std::string randomString;

	for (int i = 0; i < n; i++){
		randomString += str[distribution(generator)];
	}

	return randomString;
}

void checkCollision(int D,int N,int o)
{

	
	bool hasCollision = false;
	int collisions = 0;
	std::string firstText;
	std::string secondText;
	unsigned int hashCollision=0;

	
	std::vector<std::string>vec;
	for (int i = 0; i < N; i++) {
		vec.push_back(randomString(D));
	}
	std::vector<unsigned int> sums;
	if (o == 0) {
		for (auto const& i : vec) {
			sums.push_back(adler32(i));
		}
		std::cout << "ADLER 32, D=" << D << ", N=" << N<<"\n";

	} else {
		for (auto const& i : vec) {
			sums.push_back(DJB(i));
		}
		std::cout << "DJB, D=" << D << ", N=" << N << "\n";
	}
	
	for (int i = 0; i < sums.size();i++) {
		for (int j = i + 1; j < sums.size(); j++) {
			if (sums[i] == sums[j]) {
				collisions++;
				
				if (hasCollision == false) {
					firstText = vec[i];
					secondText = vec[j];
					hashCollision = sums[i];
					hasCollision = true;
				}


			}
			
		}

	}
	std::cout << collisions << " kolizji\n"<<firstText<<" "<<secondText<<" "<<hashCollision<<"\n\n";
	
	
}
