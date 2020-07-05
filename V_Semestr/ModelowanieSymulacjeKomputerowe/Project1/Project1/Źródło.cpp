/*
rozklad prawdopodobiensta,test chi kwadrat, moment centralny poczytac

test pokerowy, 
LCG
xi+1=(a*xi+c)mod m

a,c,m ->naturlna
xi->naturalna
xi=0,1,...m-1

yi=xi/(m-1)  <0,1>
zi-xi/m  <0,1)


rozklad prawdobodobienstwa
calki

*/

#include<iostream>
#include <fstream>
int lcg(int a, int c,int  m, int xi);
double lcg2(int xi,int m);
int suma(int k,unsigned int tablica[200][5]);




int main()
{

	int a, c, m, xi,n;
	double yi = 0.0;
	double yiS = 0.0;
	double yiS2 = 0.0;
	double yiS3 = 0.0;
	double d = 0.1;
	double X2 = 0.0;



	int tab[10];

	for (int i = 0; i < 10; i++) {
		tab[i] = 0;
	}

	/*a = 4;
	c = 5;
	m = 9;
	xi = 5;
	n = 100;*/


	a = 17;
	c = 2;
	m =100011;
	xi = 1;
	n = 100;
	//std::cin >> a>> c>> m>> xi>>n;

	for (int i = 0; i < n;i++) {
		xi = lcg(a, c, m, xi);
		yi = lcg2(xi, m);
		std::cout << yi<<" ";
		yiS += yi;
		yiS2 += yi * yi;
		yiS3 += yi * yi*yi;

		tab[int(yi/d)] += 1;
	}
	
	
	yiS = yiS / n;
	yiS2 = yiS2 / n;
	yiS3 = yiS3 / n;

	std::cout << "\n" << yiS <<" "<< yiS2<<" " << yiS3;

	/*for (int i = 0; i < n; i++) {
		yi = double(xi) / double((m - 1));
		std::cout << yi << " ";
	}*/
	std::cout << "\n"<<"\n";

	for (int i = 0; i < 10; i++) {

	std::cout << tab[i]<<" ";


	}
	for (int i = 0; i < 10; i++) {

		X2 += (std::pow(double(tab[i] - double(n) / double(10)), 2))/double(n/10);
	}
	
	std::cout<<"\n "<< X2;

	////////////////////////////////zajecia2//////////////////////////////////
	std::cout << "\n " << "\n " << "\n "<<"2zajecia" << "\n " << "\n ";

	double nt = 50;
	double tabZaj2[1000];
	std::fstream plik;
	plik.open("test1.txt", std::ios::out);
	int counter = 0;

	for (int i = 0; i < 1000; i++) {
		xi = lcg(a, c, m, xi);
		yi = (double)xi / ((double)m - 1.0);
		tabZaj2[i] = yi;
		plik << tabZaj2[i]<<" ";
		counter++;
		if (counter == 2) {
			plik << std::endl;
			counter = 0;
		}

	}

	double tab22[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			tab22[i][j] = 0.0;

		}
	}

	

	for (int i = 0; i < 100; i += 2) {

		tab22[int (tabZaj2[i] / (double)1 / double(100))][int(tabZaj2[i + 1] / ((double)1 / (double)100))]++;
		

		

	}
	plik.close();
	double text_x2_2 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			text_x2_2 += (std::pow(double(tab22[i][j] - double(50)), 2) / double(50))/50;
		}
	}
	std::cout << text_x2_2;

	//////////////////////////////////////////////////////////TEST POKEROWYY/////////////////////////////////////////////////////////////////////
	std::cout << "\n " << "\n " << "\n " << "TEST POKEROWY" << "\n " << "\n ";

	const unsigned int N = 1000;
	const unsigned int liczba_graczy = N / 5;
	const unsigned K = 7;


	unsigned int karty_graczy[liczba_graczy][5];

	for (int i = 0; i < liczba_graczy; i++) {
		for (int j = 0; j < 5; j++) {

			karty_graczy[i][j] = 0;

		}
	}


	for (int i = 0; i < liczba_graczy; i++) {
		for (int j = 0; j < 5; j++) {

			xi = lcg(a, c, m, xi);
			yi = lcg2(xi, m);
			karty_graczy[i][j] = int(yi* K);


		}
	}

	for (int i = 0; i < liczba_graczy; i++) {
		std::cout << i << "gracz " ;
		for (int j = 0; j < 5; j++) {

			std::cout << " " << karty_graczy[i][j];
			


		}
		std::cout << std::endl;
	}

	int Nukl[7] = {0,0,0,0,0,0,0};

	
	/*
	
abcde=0
aabcd=2
aaabc=6
aabbc=4
aaabb=8
aaaab=12
aaaaa=20
	
	*/
	int sumak = 0;

	double P[liczba_graczy] = {};
	for (int i = 0; i < liczba_graczy; i++) {

		sumak = suma(i, karty_graczy);
		if (sumak == 0) { 
			
			P[i] = ((K - 1)*(K - 2)*(K - 3)*(K - 4)) / (K * K*K*K);
			Nukl[0]++; }
		
		else if (sumak == 2) { 

			P[i] = (10 * (K - 1)*(K - 2)*(K - 3)) / (K * K*K*K);
			Nukl[1]++;
		}
		else if (sumak == 6) { 

			P[i] = (10 * (K - 1)*(K - 2)) / (K * K*K*K);
			
			Nukl[2]++; }
		else if (sumak == 4) { 
			P[i] = (10 * (K - 1)) / (K * K*K*K);
			Nukl[3]++; }
		else if (sumak == 8) { 
			P[i] = (15 * (K - 1)*(K - 2)) / (K * K*K*K);
			
			Nukl[4]++; }
		else if (sumak == 12) {

			P[i] = (5 * (K - 1)) / (K * K*K*K);
			Nukl[5]++;
		}
		else if (sumak == 20) {

			
			P[i] = 1/ (K * K*K*K);
			Nukl[6]++;
		};



	}
	for (int i = 0; i < 7; i++) {
		std::cout << Nukl[i]<<" ";
	}
	std::cout << "\n";
	for (int i = 0; i < 7; i++) {

		std::cout << double(Nukl[i]) / double(liczba_graczy) <<" " << double(Nukl[i])/double(N)/double(5)<< std::endl;


	}


	system("PAUSE");


	return 0;
}

int lcg(int a, int c, int m, int xi)
{
	
	//for (int i = 0; i < n; i++) {
		xi = (a * xi + c) % m;
		//std::cout << xi << " ";
	//}

	return xi;
}

double lcg2(int xi,int m)
{
	double yi = 0;
	//for (int i = 0; i < n; i++) {
		yi = double(xi) / double((m - 1));
		//std::cout << yi << " ";
	//}
		return yi;
}

int suma(int k, unsigned int tablica[200][5])
{
	int lspr[5] = { 0 };


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i != j) {
				if (tablica[k][i] == tablica[k][j]) {
					lspr[i]++;
				}
			}
		}
	}


	return lspr[0] + lspr[1] + lspr[2] + lspr[3] + lspr[4];
}
