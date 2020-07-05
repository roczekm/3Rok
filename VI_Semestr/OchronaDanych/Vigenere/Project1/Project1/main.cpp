#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<utility>
#include<algorithm>


std::vector<char>dic{ 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };

void szyfrowanie(std::string& text);
void deszyfrowanie(std::string& text);
int hasloshift(std::string&haslo,int j);


int main()
{
	std::ifstream ifs("last.txt");
	std::string text((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

    std::ifstream ifs1("output.txt");
	std::string text2((std::istreambuf_iterator<char>(ifs1)),
		(std::istreambuf_iterator<char>()));

	int option;


	std::cout << "0=szyfrowanie,1=deszyfrowanie\n";
	std::cin >> option;


	if (option == 0) {

		szyfrowanie(text);

	}
	else if(option==1) {

		deszyfrowanie(text2);

	}


	return 0;
}
//ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
void szyfrowanie(std::string& text) {
	std::string haslo;
	std::cout << "podaj haslo\n";
	std::cin >> haslo;

	std::string enText;
    int shift;
    int j=0;
	for (int i = 0; i < text.length(); i++) {

                shift=hasloshift(haslo,j);

				if (int(text[i]) >= 48 && int(text[i]) <= 57) {

					int outChar = 0;
					outChar = int(text[i]) - '0'+26;
					outChar += 36 + shift;
					outChar %= 36;
					enText += dic[outChar];
					j++;
				}
				else if (int(text[i]) >= 65 && int(text[i]) <= 90) {
					int outChar = 0;
					outChar = int(text[i]) - 'A';
					outChar += 36 + shift;
					outChar %= 36;
					enText += dic[outChar];
					j++;

				}
				else if (int(text[i]) >= 97 && int(text[i]) <= 122) {
					text[i] = char(int(text[i]) - 32);
					int outChar = 0;
					outChar = int(text[i]) - 'A';
					outChar += 36 + shift;
					outChar %= 36;
					enText += dic[outChar];
					j++;
				}
				else {
					enText += text[i];
				}
				if(j>=haslo.length()){
                    j=0;
				}

	}
		std::ofstream out("output.txt");
		out << enText;
		out.close();


	}
	void deszyfrowanie(std::string & text) {
		std::string haslo;
		std::cout << "podaj haslo\n";
		std::cin >> haslo;

		std::string enText;
		int shift=0;
        int j=0;
		for (int i = 0; i < text.length(); i++) {
             shift=hasloshift(haslo,j);
			if (int(text[i]) >= 48 && int(text[i]) <= 57) {
				int outChar = 0;
				outChar = int(text[i]) - '0' + 26;
				outChar += 36 - shift;
				outChar %= 36;
				enText += dic[outChar];
				j++;
			}
			else if (int(text[i]) >= 65 && int(text[i]) <= 90) {
				int outChar = 0;
				outChar = int(text[i]) - 'A';
				outChar += 36 - shift;
				outChar %= 36;
				enText += dic[outChar];
				j++;

			}
			else if (int(text[i]) >= 97 && int(text[i]) <= 122) {
				text[i] = char(int(text[i]) - 32);
				int outChar = 0;
				outChar = int(text[i]) - 'A';
				outChar += 36 - shift;
				outChar %= 36;
				enText += dic[outChar];
				j++;
			}
			else {
				enText += text[i];
			}
			if(j>=haslo.length()){
                    j=0;
				}

		}
		std::ofstream out("output1.txt");
		out << enText;
		out.close();

	}
int hasloshift(std::string&haslo,int j){


        if (int(haslo[j]) >= 48 && int(haslo[j]) <= 57) {

                return (int(haslo[j]) - '0'+26);

				}
				else if (int(haslo[j]) >= 65 && int(haslo[j]) <= 90) {

					return (int(haslo[j]) - 'A');


				}
				else if (int(haslo[j]) >= 97 && int(haslo[j]) <= 122) {
					haslo[j] = char(int(haslo[j]) - 32);

					return (int(haslo[j]) - 'A');

				}



}
