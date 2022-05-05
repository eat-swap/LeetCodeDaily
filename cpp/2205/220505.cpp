#include <queue>
#include <iostream>

/**
 * 225. Implement Stack using Queues
 * Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
 *
 * Implement the MyStack class:
 *
 * void push(int x) Pushes element x to the top of the stack.
 * int pop() Removes the element on the top of the stack and returns it.
 * int top() Returns the element on the top of the stack.
 * boolean empty() Returns true if the stack is empty, false otherwise.
 *
 * Notes:
 *
 * You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
 * Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 */

class MyStack {
private:
	std::queue<int> q;
public:
	MyStack() = default;

	void push(int x) {
		auto s = q.size();
		q.push(x);
		// It sucks.
		// It is ugly, inefficient, slow, and horrible.
		while (s--) {
			q.push(q.front());
			q.pop();
		}
	}

	int pop() {
		int ret = q.front();
		q.pop();
		return ret;
	}

	int top() {
		return q.front();
	}

	bool empty() {
		return q.empty();
	}
};

int main() {
	MyStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	std::cout << s.top() << "\n";
	s.push(4);
	s.push(5);
	while (!s.empty()) {
		std::cout << s.pop() << std::endl;
	}
}
