#ifndef LEETCODE_CPP_DEFS_H
#define LEETCODE_CPP_DEFS_H

#include <queue>
#include <vector>

class LC230827 {
public:
	static bool canCross(const std::vector<int>&);
};

class LC230828 {
private:
	std::queue<int> q;

public:
	LC230828();
	void push(int x);
	int pop();
	int top();
	bool empty();
};

class LC230829 {
public:
	static int bestClosingTime(const std::string&);
};

#endif //LEETCODE_CPP_DEFS_H
