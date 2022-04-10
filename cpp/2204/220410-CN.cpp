#include <unordered_set>
#include <string>
#include <vector>

/**
 * 804. Unique Morse Code Words
 * International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:
 *
 * 'a' maps to ".-",
 * 'b' maps to "-...",
 * 'c' maps to "-.-.", and so on.
 * For convenience, the full table for the 26 letters of the English alphabet is given below:
 *
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
 *
 * For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
 * Return the number of different transformations among all words we have.
 */

class Solution {
private:
	inline static const std::string MORSE[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
	static int uniqueMorseRepresentations(const std::vector<std::string>& words) {
		std::unordered_set<std::string> s;
		for (const auto& str : words) {
			std::string t;
			for (char ch : str)
				t += MORSE[ch - 'a'];
			s.insert(t);
		}
		return s.size();
	}
};

int main() {
	return 0;
}
