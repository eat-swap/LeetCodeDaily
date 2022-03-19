#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

class FreqStack {
private:
	std::unordered_map<int, std::stack<int>> s;
	std::unordered_map<int, int> val2Freq;
	int maxFreq = 0;
public:
	FreqStack() = default;

	void push(int val) {
		int newFreq = ++val2Freq[val];
		maxFreq = std::max(maxFreq, newFreq);
		s[newFreq].push(val);
	}

	int pop() {
		int ret = s[maxFreq].top();
		s[maxFreq].pop();
		if (s[maxFreq].empty()) {
			--maxFreq;
		}
		--val2Freq[ret];
		return ret;
	}
};

class FreqStackOld {
private:
	std::list<int> stack;
	std::map<int, std::unordered_set<int>> freq2Val;
	std::unordered_map<int, int> val2Freq;
public:
	FreqStackOld() = default;

	void push(int val) {
		int newFreq = ++val2Freq[val];
		stack.push_front(val);
		if (newFreq > 1) {
			if (freq2Val[newFreq - 1].size() <= 1)
				freq2Val.erase(newFreq - 1);
			else
				freq2Val[newFreq - 1].erase(val);
		}
		freq2Val[newFreq].insert(val);
	}

	int pop() {
		// Get most frequent element
		std::unordered_set<int>& s = freq2Val.rbegin()->second;
		std::list<int>::iterator toErase;
		if (s.size() == 1) {
			toErase = std::find(stack.begin(), stack.end(), *s.begin());
			freq2Val.erase(std::prev(freq2Val.end()));
		} else {
			toErase = stack.begin();
			for (auto it = stack.begin(); it != stack.end(); ++it) {
				bool OK = false;
				for (int i: s) {
					if (*it == i) {
						// Found that, will erase;
						toErase = it;
						OK = true;
						break;
					}
				}
				if (OK) break;
			}
			freq2Val.rbegin()->second.erase(*toErase);
		}
		int newFreq = --val2Freq[*toErase], ret = *toErase;
		freq2Val[newFreq].insert(*toErase);
		stack.erase(toErase);
		return ret;
	}
};

int main() {
	FreqStack freqStack;
	freqStack.push(5); // The stack is [5]
	freqStack.push(7); // The stack is [5,7]
	freqStack.push(5); // The stack is [5,7,5]
	freqStack.push(7); // The stack is [5,7,5,7]
	freqStack.push(4); // The stack is [5,7,5,7,4]
	freqStack.push(5); // The stack is [5,7,5,7,4,5]
	std::cout << std::endl << freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
	std::cout << std::endl << freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
	std::cout << std::endl << freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
	std::cout << std::endl << freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
	return 0;
}
