#include <unordered_set>
#include <string>
#include <vector>

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
