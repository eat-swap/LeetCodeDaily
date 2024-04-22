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

class LC230927 {
public:
	static std::string decodeAtIndex(const std::string& s, int k);
};

class LC231014 {
public:
	static int paintWalls(const std::vector<int>&, const std::vector<int>&);
};

class LC231015 {
public:
	static int numWays(int, int);
};

class LC240421 {
public:
    static bool validPath(int n, const std::vector<std::vector<int>>& edges, int source, int destination) noexcept;
};

class LC240422 {
public:
	static int openLock(const std::vector<std::string>&, std::string);
};


#endif //LEETCODE_CPP_DEFS_H
