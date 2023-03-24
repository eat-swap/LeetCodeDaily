#include <vector>
#include <string>
#include <iostream>

class KMP {
private:
	std::string str;
	std::vector<int> m;
	int pos = 0;

public:
	explicit KMP(std::string s) : str(std::move(s)), m(str.length()) {
		for (int i = 1; i < str.length(); ++i) {
			int j = m[i - 1];
			for (; j > 0 && str[j] != str[i]; j = m[j - 1]);
			m[i] = j + (str[i] == str[j]);
		}
	}

	const std::string& get_string() const {
		return str;
	}

	bool advance(char ch) {
		if (ch == str[pos]) {
			++pos;
		} else {
			for (; pos > 0 && str[pos] != ch; pos = m[pos - 1]);
			pos += str[pos] == ch;
		}
		if (pos == str.length()) {
			pos = m[pos - 1];
			return true;
		}
		return false;
	}
};

/**
 * 1032. Stream of Characters
 *
 * Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.
 *
 * For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.
 *
 * Implement the StreamChecker class:
 *
 * StreamChecker(String[] words) Initializes the object with the strings array words.
 * boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.
 */

class StreamChecker {
private:
	std::vector<KMP> sms;

public:
	explicit StreamChecker(const std::vector<std::string>& words) {
		sms.reserve(words.size());
		for (const std::string& i : words)
			sms.emplace_back(i);
	}

	bool query(char c) {
		bool ret = false;
		for (KMP& sm : sms)
			ret |= sm.advance(c);
		return ret;
	}
};

int main() {
	StreamChecker sc({"acacac"});
	for (int i = 0; i < 4; ++i) {
		std::cout << sc.query('a') << sc.query('c');
	}
	return 0;
}
