#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void greedyColoring(int V,const std::vector<std::vector<int>>& vec);
void welshPowell(int V, const std::vector<std::vector<int>>& vec);
bool backtracking(const std::vector<std::vector<int>>& vec,int index,int numbersOfColors,std::vector<int>&colors);
bool isSafe(const std::vector<std::vector<int>>&vec,int index, int color,const std::vector<int>&colors);

std::vector<std::vector<int>> BA(int N);


int main()
{
  
   

        std::vector<std::vector<int>> vec1(10);
        std::vector<std::vector<int>> vec2(100);
        std::vector<std::vector<int>> vec3(1000);
        std::vector<std::vector<int>> vec4(2000);


 

        std::vector<int>colors(10, -1);
        std::vector<int>colors2(100, -1);
        std::vector<int>colors3(1000, -1);
        std::vector<int>colors4(2000, -1);

       

       /* int N;
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            int n;
            std::cin >> n;
            for (int j = 0; j < n; j++) {
                int temp;
                std::cin >> temp;
                vec1[i].push_back(temp);
            }
        }
  
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            int n;
            std::cin >> n;
            for (int j = 0; j < n; j++) {
                int temp;
                std::cin >> temp;
                vec2[i].push_back(temp);
            }
        }
     
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            int n;
            std::cin >> n;
            for (int j = 0; j <n; j++) {
                int temp;
                std::cin >> temp;
                vec3[i].push_back(temp);
            }
        }
    
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            int n;
            std::cin >> n;
            for (int j = 0; j < n; j++) {
                int temp;
                std::cin >> temp;
                vec4[i].push_back(temp);
            }
        }*/
      
        vec1 = BA(10);
        vec2 = BA(100);
        vec3 = BA(1000);
        vec4 = BA(2000);

  
        std::cout << "\n\n\n";
        std::chrono::high_resolution_clock::time_point start, end;
        std::chrono::duration<double> time_span ;
      
        

        start = std::chrono::high_resolution_clock::now();
        greedyColoring(10, vec1);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        greedyColoring(100, vec2);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        greedyColoring(1000, vec3);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        greedyColoring(2000, vec4);
        end = std::chrono::high_resolution_clock::now();
         time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n\n";

        start = std::chrono::high_resolution_clock::now();
        welshPowell(10, vec1);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        welshPowell(100, vec2);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        welshPowell(1000, vec3);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        welshPowell(2000, vec4);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n\n";


        start = std::chrono::high_resolution_clock::now();
        backtracking(vec1, 0, 10, colors);
        std::cout << *std::max_element(colors.begin(), colors.end());
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        backtracking(vec2, 0, 100, colors2);
        std::cout << *std::max_element(colors2.begin(), colors2.end());
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        backtracking(vec3, 0, 1000, colors3);
        std::cout << *std::max_element(colors3.begin(), colors3.end());
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

        start = std::chrono::high_resolution_clock::now();
        backtracking(vec4, 0, 2000, colors4);
        std::cout << *std::max_element(colors4.begin(), colors4.end());
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << " " << time_span.count() << " \n";

       

     

      



}


void greedyColoring(int V, const std::vector<std::vector<int>>& vec)
{
    std::vector<int> result(V,-1);
    result[0] = 0;
    
  
 
    for (int i = 1; i < V; i++) {
        std::vector<bool> available(V, true);

        for (auto it = vec[i].begin(); it != vec[i].end(); ++it) {
            if (result[*it] != -1) {
                available[result[*it]] = false;
            }
        }
        int color;
        for (color = 0; color < V; color++) {
            if (available[color] == true) {
                break;
            }
        }
        result[i] = color; 

    }
    std::cout << *std::max_element(result.begin(), result.end());

}

void welshPowell(int V, const std::vector<std::vector<int>>& vec)
{

  
    std::vector<int> result(V, -1);
    result[0] = 0;

  


    std::vector<std::pair<int, int>>degrees;
    for (int i = 0; i < V; i++) {
        degrees.push_back(std::make_pair(i, vec[i].size()));
    }
    std::sort(degrees.begin(), degrees.end(), [](const  std::pair<int, int>& a, const  std::pair<int, int>& b) { return a.second > b.second; });


    result[degrees[0].first] = 0;

 
    for (int i = 1; i < V; i++) {
        std::vector<bool> available(V, true);
        int temp = degrees[i].first;
        for (auto it = vec[temp].begin(); it != vec[temp].end(); ++it) {
            if (result[*it] != -1) {
                available[result[*it]] = false;
            }
        }
       
        int color;
        for (color = 0; color < V; color++) {
            if (available[color] == true) {
                break;
            }
        }

        result[temp] = color; 

       
      
    }
    

    std::cout << *std::max_element(result.begin(), result.end());
 


}

bool backtracking(const std::vector<std::vector<int>>& vec, int index, int numbersOfColors, std::vector<int>&colors)
{
    if (index == vec.size()) {
        return true;
    }


    for (int i = 0; i < numbersOfColors; i++) {
        if (isSafe(vec, index, i, colors)) {
            colors[index] = i;

           
            if (backtracking(vec, index + 1, numbersOfColors, colors)) {
                return true;
            }

           
            colors[index] = -1;
        }

    }
    return false;
}

bool isSafe(const std::vector<std::vector<int>>& vec, int index, int color, const std::vector<int>& colors)
{
    for (auto it = vec[index].begin(); it != vec[index].end(); ++it) {
        if (colors[*it] == color) {
            return false;
        }
    }
    return true;
}


std::vector<std::vector<int>> BA(int N) {

    std::random_device dev;
    std::uniform_real_distribution<double> distribution(0., 1.);
    std::vector<std::vector<int>> vec(2);

    vec[0].push_back(1);
    vec[1].push_back(0);

    while (vec.size() < N) {
        double kc = 0.0;
        double prob = 0.0;
        bool added = false;
        for (int i = 0; i < vec.size(); i++) {
            kc += vec[i].size();
        }

        kc = (0.5 * kc);
        vec.resize(vec.size() + 1);

        for (int i = 0; i < vec.size() - 1; i++) {

            prob = (vec[i].size() / kc);
            double rng = distribution(dev);

            if (rng <= prob) {

                vec[vec.size() - 1].push_back(i);
                vec[i].push_back(vec.size() - 1);
                added = true;
            }
        }
        if (added == false) {
            vec[vec.size() - 1].push_back(0);
            vec[0].push_back(vec.size() - 1);
        }
    }
    return vec;
}


