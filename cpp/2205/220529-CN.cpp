#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * 468. Validate IP Address
 * Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
 *
 * A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.
 *
 * A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
 *
 * 1 <= x[i].length <= 4
 * x[i] is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
 * Leading zeros are allowed in xi.
 * For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
 */

class Solution {
private:
	inline static std::string IPv4 = "IPv4";
	inline static std::string IPv6 = "IPv6";
	inline static std::string Neither = "Neither";

	static std::vector<std::string> spilt(const std::string& str, char delimiter) {
		std::vector<std::string> ret;
		std::size_t pos = 0, nextPos = 0;
		while (pos < str.length() && (nextPos = str.find(delimiter, pos)) != std::string::npos) {
			ret.push_back(str.substr(pos, nextPos - pos));
			pos = nextPos + 1;
		}
		if (pos < str.length())
			ret.push_back(str.substr(pos));
		else if (pos == str.length())
			ret.emplace_back();
		return ret;
	}

public:
	static std::string validIPAddress(const std::string& queryIP) {
		if (queryIP.find('.') != std::string::npos) { // IPv4
			auto sp = spilt(queryIP, '.');
			if (sp.size() != 4)
				return Neither;
			for (const std::string& i : sp) {
				if (i.empty() || (i.front() == '0' && i.length() > 1) || std::any_of(i.begin(), i.end(), [](char c) { return !isdigit(c); }))
					return Neither; // Leading 0 + empty
				try {
					if (std::stoi(i) > 255)
						return Neither;
				} catch (...) {
					return Neither;
				}
			}
			return IPv4;
		} else if (queryIP.find(':') != std::string::npos) { // IPv6
			auto sp = spilt(queryIP, ':');
			if (sp.size() != 8)
				return Neither; // Yes. This is non-standard.
			for (const std::string& i : sp) {
				if (i.empty() || i.length() > 4)
					return Neither;
				for (char c : i)
					if (!isdigit(c) && std::toupper(c) > 'F')
						return Neither;
			}
			return IPv6;
		} else return Neither;
	}
};

int main() {
	/*
	auto x = Solution::spilt("172.16.254.1", '.');
	for (const auto& i : x)
		std::cout << i << "\n";
	 */
	std::cout << (Solution::validIPAddress("20EE:FGb8:85a3:0:0:8A2E:0370:7334"));
	return 0;
}
