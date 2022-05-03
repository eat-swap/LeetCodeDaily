#include <string>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

/**
 * 591. Tag Validator
 * Given a string representing a code snippet, implement a tag validator to parse the code and return whether it is valid.
 * A code snippet is valid if all the following rules hold:
 *
 * The code must be wrapped in a valid closed tag. Otherwise, the code is invalid.
 * A closed tag (not necessarily valid) has exactly the following format : <TAG_NAME>TAG_CONTENT</TAG_NAME>. Among them, <TAG_NAME> is the start tag, and </TAG_NAME> is the end tag. The TAG_NAME in start and end tags should be the same. A closed tag is valid if and only if the TAG_NAME and TAG_CONTENT are valid.
 * A valid TAG_NAME only contain upper-case letters, and has length in range [1,9]. Otherwise, the TAG_NAME is invalid.
 * A valid TAG_CONTENT may contain other valid closed tags, cdata and any characters (see note1) EXCEPT unmatched <, unmatched start and end tag, and unmatched or closed tags with invalid TAG_NAME. Otherwise, the TAG_CONTENT is invalid.
 * A start tag is unmatched if no end tag exists with the same TAG_NAME, and vice versa. However, you also need to consider the issue of unbalanced when tags are nested.
 * A < is unmatched if you cannot find a subsequent >. And when you find a < or </, all the subsequent characters until the next > should be parsed as TAG_NAME (not necessarily valid).
 * The cdata has the following format : <![CDATA[CDATA_CONTENT]]>. The range of CDATA_CONTENT is defined as the characters between <![CDATA[ and the first subsequent ]]>.
 * CDATA_CONTENT may contain any characters. The function of cdata is to forbid the validator to parse CDATA_CONTENT, so even it has some characters that can be parsed as tag (no matter valid or invalid), you should treat it as regular characters.
 */

class Solution {
public:
	static bool isValid(const std::string& code) {
		std::stack<std::string> t;
		const int n = code.length();
		for (int i = 0; i < n; ++i) {
			if (i && t.empty())
				return false;
			if (code[i] != '<') {
				continue;
			} else if (code.substr(i + 1, 8) == "![CDATA[") {
				auto next = code.find("]]>", i + 9);
				if (next == std::string::npos)
					return false;
				i = next + 2;
				continue; // Then +1, next i at char after >
			}
			auto next = code.find('>', i + 1);
			if (code[i + 1] == '/') { // closing tag
				auto ct = code.substr(i + 2, next - (i + 2));
				if (t.empty() || t.top() != ct)
					return false;
				t.pop();
			} else { // new tag
				if (next - (i + 1) > 9 || next <= i + 1)
					return false;
				auto ct = code.substr(i + 1, next - (i + 1));
				if (!std::all_of(ct.begin(), ct.end(), [](char ch){ return std::isupper(ch); }))
					return false;
				t.push(ct);
			}
			i = next;
		}
		return t.empty();
	}
};

int main() {
	const std::vector<std::string> ss {
		"<DIV>This is the first line <![CDATA[<div>]]></DIV>",
		"<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>",
		"<A>  <B> </A>   </B>",
		"<DIV>  div tag is not closed  <DIV>",
		"<DIV>  unmatched <  </DIV>",
		"<DIV> closed tags with invalid tag name  <b>123</b> </DIV>",
		"<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>",
		"<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>"
	};

	for (const auto& str : ss)
		std::cout << (Solution::isValid(str) ? "true" : "false") << "\n";
}
