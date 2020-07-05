#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<char>dic{ 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };

void szyfrowanie(std::string& text, int shift);
void deszyfrowanie(std::string& text, int shift);

int main()
{
	std::ifstream ifs("file.txt");
	std::string text((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	int option;
	int shift;
	std::cout << "0=szyfrowanie,1=deszyfrowanie\n";
	std::cin >> option;
	std::cout << "podaj przesuniecie\n";
	std::cin >> shift;
	

	if (option == 0) {

		szyfrowanie(text, shift);

	}
	else {

		deszyfrowanie(text, shift);

	}


	return 0;
}
//ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
void szyfrowanie(std::string& text, int shift) {
	std::string enText;

	for (int i = 0; i < text.length(); i++) {
		
				if (int(text[i]) >= 48 && int(text[i]) <= 57) {				
					int outChar = 0;
					outChar = int(text[i]) - '0'+26;
					outChar += 36 + shift;
					outChar %= 36;	
					enText += dic[outChar];
				}
				else if (int(text[i]) >= 65 && int(text[i]) <= 90) {
					int outChar = 0;
					outChar = int(text[i]) - 'A';
					outChar += 36 + shift;
					outChar %= 36;
					enText += dic[outChar];
					
				}
				else if (int(text[i]) >= 97 && int(text[i]) <= 122) {
					text[i] = char(int(text[i]) - 32);
					int outChar = 0;
					outChar = int(text[i]) - 'A';
					outChar += 36 + shift;
					outChar %= 36;
					enText += dic[outChar];
				}
				else {
					enText += text[i];
				}
		
	}
		std::ofstream out("output.txt");
		out << enText;
		out.close();


	}
	void deszyfrowanie(std::string & text, int shift) {
		std::string enText;

		for (int i = 0; i < text.length(); i++) {

			if (int(text[i]) >= 48 && int(text[i]) <= 57) {
				int outChar = 0;
				outChar = int(text[i]) - '0' + 26;
				outChar += 36 - shift;
				outChar %= 36;
				enText += dic[outChar];
			}
			else if (int(text[i]) >= 65 && int(text[i]) <= 90) {
				int outChar = 0;
				outChar = int(text[i]) - 'A';
				outChar += 36 - shift;
				outChar %= 36;
				enText += dic[outChar];

			}
			else if (int(text[i]) >= 97 && int(text[i]) <= 122) {
				text[i] = char(int(text[i]) - 32);
				int outChar = 0;
				outChar = int(text[i]) - 'A';
				outChar += 36 - shift;
				outChar %= 36;
				enText += dic[outChar];
			}
			else {
				enText += text[i];
			}

		}
		std::ofstream out("output.txt");
		out << enText;
		out.close();

	}
