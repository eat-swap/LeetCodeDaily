#include <queue>

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

LC230828::LC230828() = default;

void LC230828::push(int x) {
	int n = q.size();
	q.push(x);
	while (n--) {
		q.push(q.front());
		q.pop();
	}
}

int LC230828::pop() {
	int ret = q.front();
	q.pop();
	return ret;
}

int LC230828::top() {
	return q.front();
}

bool LC230828::empty() {
	return q.empty();
}


