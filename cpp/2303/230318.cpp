#include <string>
#include <vector>
#include <algorithm>

/**
 * 1472. Design Browser History
 *
 * You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.
 *
 * Implement the BrowserHistory class:
 *
 * BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
 * void visit(string url) Visits url from the current page. It clears up all the forward history.
 * string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
 * string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
 */

class BrowserHistory {
private:
	int pos = 0, cap = 0;
	std::vector<std::string> s;

public:
    explicit BrowserHistory(const std::string& homepage) {
		s.push_back(homepage);
    }

    void visit(const std::string& url) {
		if ((cap = ++pos) == s.size())
			s.push_back(url);
		else
			s[pos] = url;
    }

    std::string back(int steps) {
		return s[pos = std::max(0, pos - steps)];
    }

    std::string forward(int steps) {
		return s[pos = std::min(cap, pos + steps)];
    }
};

