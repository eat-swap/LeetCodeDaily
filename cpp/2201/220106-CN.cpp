#include <string>
#include <stack>
#include <cstring>
#include <iostream>

/**
 * 71. Simplify Path
 * Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
 *
 * In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
 *
 * The canonical path should have the following format:
 *
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
 * Return the simplified canonical path.
 */

// Using pointer, in-place
class Solution {
public:
	static std::string simplifyPath(const std::string& path) {
		char* p = new char[path.length()+1];
		std::strcpy(p, path.c_str());
		char* r = new char[path.length()+1]{'/'};
		for (char* current = std::strtok(p, "/"), *ptr = r; current; current = std::strtok(nullptr, "/")) {
			if (!*current || !std::strcmp(".", current))
				continue;
			if (!std::strcmp("..", current)) {
				if (ptr > r)
					*ptr-- = 0;
				while (ptr > r && *ptr != '/')
					*ptr-- = 0;
				if (ptr > r && *ptr == '/')
					*ptr = 0;
			}
			else {
				*(ptr++) = '/';
				while (*ptr++ = *current++);
				--ptr;
			}
		}
		delete[] p;
		std::string ret(r);
		delete[] r;
		return ret;
	}
};

// Using stack
class SolutionStack {
public:
	static std::string simplifyPath(const std::string& path) {
		int len = path.length();
		const char* pathStr = path.c_str();
		int names[3010]{};
		int nNames = 0;
		for (int pos = 0; pos < len; ) {
			for (; pathStr[pos] == '/' && pos < len; ++pos);
			names[nNames++] = pos;
			for (; pathStr[pos] != '/' && pos < len; ++pos);
			names[nNames++] = pos;
		}
		std::stack<std::string> s;
		for (int pos = 0; pos < nNames; pos += 2) {
			if (names[pos + 1] - names[pos] == 0)
				break;
			std::string str(pathStr + names[pos], names[pos + 1] - names[pos]);
			if (str == ".") continue;
			if (str == "..") {
				if (!s.empty())
					s.pop();
			} else {
				s.push("/" + str);
			}
		}
		std::string ret;
		while (!s.empty()) {
			ret = s.top().append(ret);
			s.pop();
		}
		return ret.empty() ? "/" : ret;
	}
};

int main() {
	std::cout << Solution::simplifyPath("/a//b////c/d//././/..") << std::endl;
	return 0;
}