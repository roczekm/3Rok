#include <random>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> BA(int N);
double CC(const std::vector<std::vector<int>>& vec);
int longestPath(const std::vector<std::vector<int>>& vec, int src);


int main() {

	int n = 0;
	std::cin >> n;
	for (int k = 0; k < n; k++) {
		int N = 0;
		std::cin >> N;

		std::vector<std::vector<int>> vec(N);

		vec = BA(N);

		std::vector<int> pathLength(vec.size());
		for (unsigned int i = 0; i < pathLength.size(); i++) {
			pathLength[i] = longestPath(vec, i);
		}
		std::cout << N;
		std::cout<<" "<<CC(vec);
		std::cout << " " << *std::min_element(pathLength.begin(), pathLength.end());
		std::cout << " " << *std::max_element(pathLength.begin(), pathLength.end());
		std::cout << "\n";

		/*std::cout << "Clustering Coefficient: " << CC(vec);
		std::cout << " Radius: " << *std::min_element(pathLength.begin(), pathLength.end());
		std::cout << " Diameter: " << *std::max_element(pathLength.begin(), pathLength.end());
		
		std::cout << "\n";*/

	}
	
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


double CC(const std::vector<std::vector<int>>& vec)
{
	double cc = 0.0;
	int edges = 0;
	double temp = 0.0;
	for (auto const& i : vec) {
		edges += i.size();
	}
	temp = double(vec.size() * (double(vec.size() - 1.0) / 2.0));
	cc = double(edges / temp);
	return cc;
}


int longestPath(const std::vector<std::vector<int>>& vec, int src) {
	std::vector<int>dist(vec.size(), INT_MAX);
	std::vector<int>parent(vec.size(), -1);
	std::queue<int>qe;
	qe.push(src);
	dist[src] = 0;
	while (!qe.empty()) {
		int u = qe.front(); qe.pop();
		for (auto it = vec[u].begin(); it != vec[u].end(); ++it) {
			int  v = (*it);
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				parent[v] = u;
				qe.push(v);
			}
		}
	}
	return *std::max_element(dist.begin(), dist.end());
}