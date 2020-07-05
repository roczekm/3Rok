#include <iostream>
#include <vector>
#include <fstream>
#include<utility>
#include<algorithm>



int main()
{

    std::ifstream ifs("output.txt");
	std::string text((std::istreambuf_iterator<char>(ifs)),
    (std::istreambuf_iterator<char>()));

 	std::vector<std::pair<char,double>>histogram;

	for(int i=0;i<26;i++){

        histogram.push_back( std::make_pair(char(65+i),0.0));
	}
	for(int i=0;i<10;i++){
        histogram.push_back( std::make_pair(char(48+i),0.0));
	}
	for (int i=0;i<text.size();i++) {
        //std::cout<<i.first<<i.second<<"\n";
    if (int(text[i]) >= 97 && int(text[i]) <= 122) {
            text[i] = char(int(text[i]) - 32);
        }
        for (auto & j : histogram) {
            if(text[i]==j.first){
                j.second++;
            }
	}
}
double numbersOfChar=0;
double suma=0;
 for (auto const& j : histogram) {
        std::cout<<j.first<<" "<<j.second<<"\n";
        numbersOfChar+=j.second;
}
 for (auto const& j : histogram) {
        std::cout<<j.first<<" "<<j.second/numbersOfChar*100<<"\n";
}

std::sort(histogram.begin(), histogram.end(), [](const std::pair<char,double> &left, const std::pair<char,double> &right) {
    return left.second > right.second;
});
 for (auto const& j : histogram) {
        std::cout<<j.first<<" "<<j.second/numbersOfChar*100<<"\n";
}
}
