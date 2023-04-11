#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <cstdio>

// INCOMPLETE
class Solution {
private:
	static int calc_dist(const std::string&, const std::string&);

	static void get_next(std::mt19937&, std::vector<int>&, int = 1);

	static const inline int ITER_COUNT = 2200000;
public:
	static std::string shortestSuperstring(const std::vector<std::string>&);
};

std::string Solution::shortestSuperstring(const std::vector<std::string>& w) {
	const int n = w.size();
	int dist[12][12]{}, MAX_DIST = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			dist[i][j] = calc_dist(w[i], w[j]);
			dist[j][i] = calc_dist(w[j], w[i]);
			MAX_DIST = std::max(MAX_DIST, std::max(dist[i][j], dist[j][i]));
		}
	}
	auto energy = [&](const std::vector<int>& v) {
		int ret = 0;
		for (int i = 1; i < v.size(); ++i)
			ret += dist[v[i - 1]][v[i]];
		return -ret;
	};
	auto print_state = [](const char* prompt, const std::vector<int>& v) {
		std::printf("%s: ", prompt);
		for (int i : v)
			std::printf("%2d ", i);
		std::printf("\n");
	};
	auto seed = std::time(nullptr);
	std::cout << "Seed = " << seed << "\n";
	std::mt19937 r(seed);
	std::vector<int> state(n), next_state;
	std::iota(state.begin(), state.end(), 0);
	int current_energy = energy(state);
	for (int i = 0; i < ITER_COUNT; ++i) {
		// std::printf("ITERATION # %d\n", i);
		// Temperature is defined as (ITER_COUNT - i);
		next_state = state;
		get_next(r, next_state);
		// print_state("Current state", state);
		// print_state("Next state", next_state);
		int next_energy = energy(next_state);
		if (next_energy <= current_energy) {
			// std::printf("Next E = %d < %d (Current E), accepting new state.\n", next_energy, current_energy);
			state = next_state;
			current_energy = next_energy;
		} else if (double x = (double(r()) / r.max()), dte = double(current_energy - next_energy) / (double(ITER_COUNT - i) / ITER_COUNT * MAX_DIST), dt = std::exp(dte); x < dt) {
			// std::printf("Next state worse (%d >= %d), rand = %.5f and exp(dE / T) = %.5f, accept anyway.\n", next_energy, current_energy, x, dt);
			state = next_state;
			current_energy = next_energy;
		} else {
			// std::printf("Next state worse (%d >= %d), rand = %.5f and exp(dE / T) = %.5f, rejected.\n", next_energy, current_energy, x, dt);
		}
		// std::printf("------------------------------------------------\n");
	}
	print_state("Final state", state);
	std::printf("ENERGY = %d\n", energy(state));
	std::string ret = w[state[0]];
	for (int i = 1; i < n; ++i)
		ret += w[state[i]].substr(dist[state[i - 1]][state[i]]);
	return ret;
}

int Solution::calc_dist(const std::string& s, const std::string& t) {
	const int m = s.size(), n = t.size();
	int k = std::min(m, n), r = 0;
	for (int i = 1; i <= k; ++i) {
		int p = m - i, q = 0, ok = 1;
		for (; p < m; ++p, ++q) {
			if (s[p] != t[q]) {
				ok = 0;
				break;
			}
		}
		r = ok ? i : r;
	}
	return r;
}

void Solution::get_next(std::mt19937& r, std::vector<int>& v, int c) {
	int i, j;
	while (c--) {
		i = double(r()) / r.max() * v.size();
		j = double(r()) / r.max() * v.size();
		std::swap(v[i], v[j]);
	}
}

int main() {
	auto r = Solution::shortestSuperstring({"cgjufdqhfw","bsrchpiau","hfwbsrchpi","sezsorql","srchpiaues","rqlmc"});
	Solution::shortestSuperstring({"wmiy","yarn","rnnwc","arnnw","wcj"});
	Solution::shortestSuperstring({"jap","zebr","ebrxx","apz"});
	std::printf("%s\n", r.c_str());
	return 0;
}
