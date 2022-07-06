#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <unordered_map>

/**
 * 736. Parse Lisp Expression
 * You are given a string expression representing a Lisp-like expression to return the integer value of.
 * The syntax for these expressions is given as follows.
 * An expression is either an integer, let expression, add expression, mult expression, or an assigned variable. Expressions always evaluate to a single integer.
 * (An integer could be positive or negative.)
 * A let expression takes the form "(let v1 e1 v2 e2 ... vn en expr)", where let is always the string "let", then there are one or more pairs of alternating variables and expressions, meaning that the first variable v1 is assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, and so on sequentially; and then the value of this let expression is the value of the expression expr.
 * An add expression takes the form "(add e1 e2)" where add is always the string "add", there are always two expressions e1, e2 and the result is the addition of the evaluation of e1 and the evaluation of e2.
 * A mult expression takes the form "(mult e1 e2)" where mult is always the string "mult", there are always two expressions e1, e2 and the result is the multiplication of the evaluation of e1 and the evaluation of e2.
 * For this question, we will use a smaller subset of variable names. A variable starts with a lowercase letter, then zero or more lowercase letters or digits. Additionally, for your convenience, the names "add", "let", and "mult" are protected and will never be used as variable names.
 * Finally, there is the concept of scope. When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially. It is guaranteed that every expression is legal. Please see the examples for more details on the scope.
 */

class Solution {
private:
	static std::vector<std::string> spiltPreservingStructure(const std::string& str, char ch = ' ') {
		std::vector<std::string> ret;
		int n = str.length(), prevPos = 0;
		const char* s = str.c_str();

		auto tryPush = [&](int x, int y) {
			auto nx = std::string(s + x, s + y);
			if (!nx.empty())
				ret.push_back(std::move(nx));
		};

		for (int i = 0; i < n; ++i) {
			if (s[i] == ch) {
				tryPush(prevPos, i);
				prevPos = 1 + i;
			}
			if (s[i] != '(')
				continue;

			// s[i] == '('
			for (int stack = 1, dummy = ++i; stack; ++i) {
				if (s[i] == '(')
					++stack;
				else if (s[i] == ')')
					--stack;
			}
			--i;
		}
		tryPush(prevPos, n);
		return ret;
	}

	std::vector<std::unordered_map<std::string, int>> m;

public:
	int evaluate(std::string expression) {
		if (expression.empty())
			return 0;
		if (std::isdigit(expression[0]) || expression[0] == '-')
			return std::stoi(expression);
		if (std::isalpha(expression[0])) {
			for (auto it = m.rbegin(); it != m.rend(); ++it)
				if (it->count(expression))
					return it->at(expression);
			return -1;
		}

		// strip ()
		expression = expression.substr(1);
		expression.pop_back();
		m.emplace_back();
		auto r = spiltPreservingStructure(expression);
		const int n = r.size();
		int ret = -1;
		switch (r[0][0]) {
			case 'l':
				for (int i = 2; i < n; i += 2) {
					m.back()[r[i - 1]] = evaluate(r[i]);
				}
				ret = evaluate(r.back());
				break;
			case 'm':
				ret = evaluate(r[1]) * evaluate(r[2]);
				break;
			case 'a':
				ret = evaluate(r[1]) + evaluate(r[2]);
		}
		m.pop_back();
		return ret;
	}
};


int main() {
	Solution s;
	std::cout << s.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))");
	return 0;
}
