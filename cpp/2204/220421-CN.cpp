#include <cctype>
#include <string>
#include <sstream>
#include <iostream>

/**
 * 824. Goat Latin
 * You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
 *
 * We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:
 *
 * If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
 * For example, the word "apple" becomes "applema".
 * If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
 * For example, the word "goat" becomes "oatgma".
 * Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
 * For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
 * Return the final sentence representing the conversion from sentence to Goat Latin.
 */

class Solution {
public:
	static std::string toGoatLatin(const std::string& sentence) {
		const std::string vowels = "aeiou";
		std::istringstream sin(sentence);
		std::string ret, word;
		int cnt = 0;
		while (sin >> word) {
			if (std::string::npos == vowels.find(char(std::tolower(word.front())))) {
				char ch = word.front();
				word = word.substr(1);
				word.push_back(ch);
			}
			word += "ma";
			word += std::string(++cnt, 'a');
			if (!ret.empty())
				ret.push_back(' ');
			ret += word;
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::toGoatLatin("I speak Goat Latin") << "\n";
	return 0;
}
