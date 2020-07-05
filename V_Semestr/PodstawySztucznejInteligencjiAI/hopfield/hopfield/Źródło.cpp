#include<vector>
#include<iostream>
#include<Windows.h>

double delta(int i, int j);
const void Display(const std::vector<std::vector<int>>& x,int k);
int main() {


	std::vector<std::vector<int> > input{
		{// A
			1, 1, 1, 1, 1,
			1, -1, -1, -1, 1,
			1, -1, -1, -1, 1,
			1, 1, 1, 1, 1,
			1, -1, -1, -1, 1,
			1, -1, -1, -1, 1,
		1, -1, -1, -1, 1
	},
	{ // C
		1,1,1,1,1,
		1,-1,-1,-1,-1,
		1,-1,-1,-1,-1,
		1,-1,-1,-1,-1,
		1,-1,-1,-1,-1,
		1,-1,-1,-1,-1,
		1,1,1,1,1,
	},
	{ // I
		-1,-1,1,-1,-1,
		-1,-1,1,-1,-1,
		-1,-1,1,-1,-1,
		-1,-1,1,-1,-1,
		-1,-1,1,-1,-1,
		-1,-1,1,-1,-1,
		-1,-1,1,-1,-1,
	},
	{ // X
		-1,-1,-1,-1,-1,
		1,-1,-1,-1,1,
		-1,1,-1,1,-1,
		-1,-1,1,-1,-1,
		-1,1,-1,1,-1,
		1,-1,-1,-1,1,
		-1,-1,-1,-1,-1
	}
	};



	std::vector<std::vector<int> > test{
		{// A
			1, 1, 1, 1, 1,
			-1, -1, -1, -1, 1,
			1, -1, -1, -1, 1,
			-1, -1, -1, -1,-1,
			1, -1, -1, -1, 1,
			-1, -1, -1, -1, 1,
			1, -1, -1, -1, 1
		},
		{ // C
			1,1,1,1,1,
			1,-1,-1,-1,-1,
			1,-1,-1,-1,-1,
			1,-1,-1,-1,-1,
			1,-1,-1,-1,-1,
			1,-1,-1,-1,-1,
			1,-1,-1,-1,-1,
		},
		{ // I
			-1,-1,1,-1,-1,
			-1,-1,1,-1,-1,
			-1,-1,-1,-1,-1,
			-1,-1,1,-1,-1,
			-1,-1,1,-1,-1,
			-1,-1,-1,-1,-1,
			-1,-1,1,-1,-1,
		},
		{ // X
			1,-1,-1,-1,-1,
			1,1,-1,-1,1,
			-1,1,1,1,-1,
			-1,-1,1,-1,-1,
			-1,1,-1,1,-1,
			1,-1,-1,-1,1,
			-1,-1,-1,-1,-1
		}
	};

	std::vector<std::vector<double> > weights(35, std::vector<double>(35));
	double suma = 0.0;
	for (int i = 0; i < 35; i++) {

		for (int j = 0; j < 35; j++) {
			suma = 0.0;
			for (int m = 0; m < 4; m++) {
				suma += input[m][i] * input[m][j];
			}

			weights[i][j] = double(1.0 - delta(i, j)) * suma;
			
		}
	}

	
	bool testy = true;
	suma = 0.0;

	

	for(int k=0;k<4;k++){
		while (testy) {
			std::vector<int> y(35, 0);
			std::vector<double> net(35, 0);

			Display(test,k);
			for (int i = 0; i < 35; i++) {
				for (int j = 0; j < 35; j++) {
					net[i] += test[k][j] * weights[i][j];
				}
			}
			for (int t = 0; t < 35; t++) {

				if (net[t] > 0) {
					y[t] = 1;
				}else if (net[t] == 0) {
					y[t] = test[k][t];
				}else {
					y[t] = -1;
				}

			}

			testy = false;
			for (int i = 0; i < 35; i++) {

				if (y[i] != test[k][i]) {
					testy = true;

				}

			}

			if (testy){
				for (int i = 0; i < 35; i++){
					test[k][i] = y[i];
				}
			}

		}
		testy = true;
	
	}
	system("pause");

}

double delta(int i, int j) {

	if (i == j) {
		return 1;
	}
	else {
		return 0;
	}
}


const void Display(const std::vector<std::vector<int>>& x, int k)
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "\n";
	for (int i = 0; i < 35; i++) {
		
		if (i % 5 == 0){
			std::cout << std::endl;
			}

			if (x[k][i] == 1)
			{
				SetConsoleTextAttribute(hndl, 12);
				std::cout << "X";
			}
			else if (x[k][i] == -1)
			{
				SetConsoleTextAttribute(hndl, 14);
				std::cout << "O";
			}
		
	
	}
	std::cout << "\n";
	
}