#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>

/**
 * 831. Masking Personal Information
 *
 * You are given a personal information string s, representing either an email address or a phone number. Return the masked personal information using the below rules.
 *
 * Email address:
 *
 * An email address is:
 *
 * A name consisting of uppercase and lowercase English letters, followed by
 * The '@' symbol, followed by
 * The domain consisting of uppercase and lowercase English letters with a dot '.' somewhere in the middle (not the first or last character).
 * To mask an email:
 *
 * The uppercase letters in the name and domain must be converted to lowercase letters.
 * The middle letters of the name (i.e., all but the first and last letters) must be replaced by 5 asterisks "*****".
 * Phone number:
 *
 * A phone number is formatted as follows:
 *
 * The phone number contains 10-13 digits.
 * The last 10 digits make up the local number.
 * The remaining 0-3 digits, in the beginning, make up the country code.
 * Separation characters from the set {'+', '-', '(', ')', ' '} separate the above digits in some way.
 * To mask a phone number:
 *
 * Remove all separation characters.
 * The masked phone number should have the form:
 * "***-***-XXXX" if the country code has 0 digits.
 * "+*-***-***-XXXX" if the country code has 1 digit.
 * "+**-***-***-XXXX" if the country code has 2 digits.
 * "+***-***-***-XXXX" if the country code has 3 digits.
 * "XXXX" is the last 4 digits of the local number.
 */

class Solution {
private:
	static auto mail(const std::string& s) {
		auto pos = s.find('@');
		std::string ret;
		ret += std::tolower(s[0]);
		ret += "*****";
		ret += std::tolower(s[pos - 1]);
		ret += '@';
		for (int i = pos + 1; i < s.length(); ++i)
			ret += std::tolower(s[i]);
		return ret;
	}

	static auto phone(const std::string& s) {
		auto cnt = std::count_if(s.begin(), s.end(), [&](auto&& x) { return std::isdigit(x); });
		std::string t;
		std::copy_if(s.begin(), s.end(), std::back_inserter(t), [](auto&& x) { return std::isdigit(x); });
		return (!(cnt - 10) ? std::string() : "+" + std::string(cnt - 10, '*') + '-') + "***-***-" + t.substr(t.length() - 4, 4);
	}

public:
	static auto maskPII(const std::string& s) {
		return ((s.find('@') != -1) ? mail : phone)(s);
	}
};
