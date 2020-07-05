#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<utility>
#include<algorithm>
#include <sstream>
#include <set>


void kasiski();

int main()
{
	
	kasiski();
	

	return 0;
}


void kasiski()
{
	std::ifstream ifs("output.txt");
	std::string text((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));


	int para;
	std::cout << "podaj minimalna dlugosc par \n ";
	std::cin >> para;

	std::string enText;
	for (int i = 0; i < text.length(); i++) {

		if ((int(text[i]) >= 48 && int(text[i]) <= 57) || (int(text[i]) >= 65 && int(text[i]) <= 90)) {
			
			enText += text[i];
		}
	}
	

	std::vector<std::pair<int,int>>tablica;
	for (int i = 2; i < 21; i++) {

		tablica.push_back(std::make_pair(i, 0));
	}


	bool temp = true;
	while (para < (enText.length()/2)) {
		std::set<std::string> slownik;
		if (temp == true) {
			temp = false;
			for (int i = 0; i < enText.length(); i++) {
				std::string substr = enText.substr(i, para);
				if (substr.length() < para) {
					break;
				}
				std::vector<int> indeksy;
				if (slownik.find(substr) == slownik.end()) {
					for (std::size_t pos = 0; pos < enText.size(); ++pos)
					{
						if (enText.find(substr, pos) == pos)
						{
							indeksy.push_back(pos);
						}


					}

					if (indeksy.size() > 1) {

						temp = true;

						for (int i = 1; i < indeksy.size(); i++) {

							int dys = indeksy[i] - indeksy[0];
							for (auto& j : tablica) {
								if (dys % j.first == 0) {
									j.second++;
								}

							}

						}
						/*std::cout << substr << " ";
						for (auto const& j : indeksy) {

							std::cout << j << " ";
						}
						std::cout << "\n";*/
					}
				}
				slownik.emplace(substr);
			}
		}
		para++;
	}
	
	for (auto& j : tablica) {
		std::cout << "N=" << j.first << ", " << j.second<<"\n";
		
	}
	
}

