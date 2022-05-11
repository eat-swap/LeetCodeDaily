#include <functional>
#include <cstdio>
#include <string>
#include <cstring>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

// Generic Tree
class CodecGeneric {
private:
	static inline int digits(int x) {
		if (!x)
			return 1;
		int r = 0;
		for (; x; x /= 10)
			++r;
		return r;
	}

	static TreeNode* deHelp(const char* ptr, int len) {
		if (!len)
			return nullptr;

		int val = 0;
		std::sscanf(ptr, "%d", &val);

		auto d = digits(val);
		auto* ret = new TreeNode(val);
		if (d == len)
			return ret;

		int L = 0;
		ptr += d + 1; // value|
		std::sscanf(ptr, "%d", &L);
		ptr += digits(L) + 1; // len,
		ret->left = deHelp(ptr, L);

		int R = 0;
		ptr += L + 1;
		std::sscanf(ptr, "%d", &R);
		ptr += digits(R) + 1;
		ret->right = deHelp(ptr, R);

		return ret;
	}

public:
	// Encodes a tree to a single string.
	static std::string serialize(TreeNode* root) {
		if (!root)
			return {};

		// value|len,leftTree|len,rightTree
		std::string ret = std::to_string(root->val);
		if (!root->left && !root->right)
			return ret;

		std::string	l = serialize(root->left),
					r = serialize(root->right);

		ret.reserve(ret.length() + l.length() + r.length() + 16);
		ret.append("|");
		ret.append(std::to_string(l.length()));
		ret.append(",");
		ret.append(l);
		ret.append("|");
		ret.append(std::to_string(r.length()));
		ret.append(",");
		ret.append(r);
		return ret;
	}

	// Decodes your encoded data to tree.
	static TreeNode* deserialize(const std::string& data) {
		if (data.empty())
			return nullptr;

		auto* ptr = data.c_str();
		return deHelp(ptr, data.length());
	}
};

class Base64 {
private:
	inline static const char TABLE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	inline static const int REV_TABLE[256] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0, 0, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0,
		0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
	};

public:
	static std::string encode(const uint8_t* data, int len) {
		std::string ret;
		ret.reserve(int(len * 1.34) + 1);

		int full = len / 3, trailing = len % 3;
		for (int i = 0; i < full; ++i) {
			int x = data[3 * i];
			x = (x << 8) | data[3 * i + 1];
			x = (x << 8) | data[3 * i + 2];
			ret.push_back(TABLE[(x >> 18) & 63]);
			ret.push_back(TABLE[(x >> 12) & 63]);
			ret.push_back(TABLE[(x >> 6) & 63]);
			ret.push_back(TABLE[x & 63]);
		}

		if (trailing) {
			int x = int(data[len - 1]) << 8;
			x = (trailing & 2) ? (x | (int(data[len - 2]) << 16)) : (x << 8);
			ret.push_back(TABLE[(x >> 18) & 63]);
			ret.push_back(TABLE[(x >> 12) & 63]);
			ret.push_back((trailing & 2) ? TABLE[(x >> 6) & 63] : '=');
			ret.push_back('=');
		}

		return ret;
	}

	static std::vector<uint8_t> decode(const char* data, int len) {
		std::vector<uint8_t> ret;
		ret.reserve(len / 1.3);

		for (int i = 0; i < len - 4; i += 4) {
			int x = (REV_TABLE[data[i]] << 18) | (REV_TABLE[data[1 + i]] << 12) | (REV_TABLE[data[2 + i]] << 6) | REV_TABLE[data[3 + i]];
			ret.push_back((x >> 16) & 0xFF);
			ret.push_back((x >> 8) & 0xFF);
			ret.push_back(x & 0xFF);
		}

		int t = (data[len - 1] == '=') + (data[len - 2] == '=');
		int x = (REV_TABLE[data[len - 4]] << 18) | (REV_TABLE[data[len - 3]] << 12) | (t > 1 ? 0 : (REV_TABLE[data[len - 2]] << 6)) | (t ? 0 : REV_TABLE[data[len - 1]]);
		ret.push_back((x >> 16) & 0xFF);
		if (t <= 1)
			ret.push_back((x >> 8) & 0xFF);
		if (!t)
			ret.push_back(x & 0xFF);

		return ret;
	}
};

/**
 * 449. Serialize and Deserialize BST
 * Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 * Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.
 * The encoded string should be as compact as possible.
 */

class Codec {
private:
	static void sHelp(TreeNode* r, std::vector<uint16_t>& s) {
		s.push_back(r->val);
		if (r->left)
			sHelp(r->left, s);
		if (r->right)
			sHelp(r->right, s);
	}

	static TreeNode* dHelp(const uint16_t* x, int len) {
		auto* ret = new TreeNode(*x);
		if (len == 1)
			return ret;

		auto* nx = x + 1;
		while (*nx < *x && nx - x < len)
			++nx;
		if (nx - x - 1)
			ret->left = dHelp(x + 1, nx - x - 1);
		if (nx - x < len)
			ret->right = dHelp(nx, len - (nx - x));
		return ret;
	}
public:
	// Encodes a tree to a single string.
	static std::string serialize(TreeNode* root) {
		if (!root)
			return {};

		std::vector<uint16_t> s;
		sHelp(root, s);

		return Base64::encode(reinterpret_cast<const uint8_t*>(s.data()), sizeof(uint16_t) * s.size());
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(const std::string& data) {
		if (data.empty())
			return nullptr;
		auto x = Base64::decode(data.c_str(), data.length());
		return dHelp(reinterpret_cast<const uint16_t*>(x.data()), x.size() / sizeof(uint16_t));
	}
};


int main() {

	Codec x;
	auto ss = x.serialize(new TreeNode(2, new TreeNode(1), new TreeNode(3)));
	auto rr = x.deserialize(ss);
	return 0;
}
