#include <iostream>
#include <vector>

int main(){
	std::vector<std::pair<int, bool>> temp;
	std::vector<int> primeNumbers;
	int N = 15000000;
	for (int i = 2; i <= N; i++){
		temp.push_back(std::make_pair(i, false));
	}
	
	for (int i = 0; i < sqrt(N); i++){
		if (temp[i].second == false){
			temp[i].second = true;
			primeNumbers.push_back(temp[i].first);
			for (int j = i + i; j < temp.size(); j++){
				if (temp[j].first % temp[i].first == 0){
					temp[j].second = true;
				}
			}
		}
	}
	
	for (int i = 0; i < temp.size(); i++){
		if (temp[i].second == false){
			temp[i].second = true;
			primeNumbers.push_back(temp[i].first);
		}
	}
	
	int counter=0;
	for (int i = 0; i < primeNumbers.size(); i++){
		if (primeNumbers[i] >= 14000000){
			counter++;
		}
	}
	std::cout << counter;
}