#include <string>

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

class Solution {
public:
	static std::string simplifyPath(const std::string&);
};

std::string Solution::simplifyPath(const std::string& path) {
	char buf[3072]{};
	int n = path.size(), ps = 0, pt = 1, prev = 0;
	const char* ptr = path.c_str();
	for (; pt <= n; ++pt) {
		if (ptr[pt] && ptr[pt] != '/')
			continue;
		if (int diff = pt - prev; diff == 3 && ptr[pt - 1] == '.' && ptr[pt - 2] == '.') {
			while (ps > 0 && buf[--ps] != '/');
		} else if (diff > 2 || (diff == 2 && ptr[prev + 1] != '.')) {
			buf[ps++] = '/';
			for (int i = prev + 1; i < pt; buf[ps++] = ptr[i++]);
		}
		prev = pt;
	}
	return ps ? std::string(buf, buf + ps) : "/";
}

int main() {
	auto r = Solution::simplifyPath("/a//b////c/d//././/..");
	return 0;
}
