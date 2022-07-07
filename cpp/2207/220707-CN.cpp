#include <string>
#include <vector>
#include <bitset>
#include <iostream>

/**
 * 648. Replace Words
 * In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
 * Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
 * Return the sentence after the replacement.
 */

class Solution {
private:
	static const int MAX_NODES = 100008;

	int nodes[MAX_NODES][26]{};
	std::bitset<MAX_NODES> terminate;
	int cnt = 1;

	static constexpr inline int id(char c) { return c - 'a'; }

	void insert(const std::string& s) {
		int u = 0;
		for (char ch : s) {
			int c = id(ch);
			if (!nodes[u][c])
				nodes[u][c] = cnt++;
			u = nodes[u][c];
		}
		terminate.set(u);
	}

public:
	std::string replaceWords(const std::vector<std::string>& dictionary, const std::string& sentence) {
		for (const auto& i : dictionary)
			this->insert(i);
		std::string ret;
		const char* str = sentence.c_str();
		const int n = sentence.length();
		for (int pos = 0; pos < n; ) {
			int np = pos;
			bool set = false;
			for (int u = 0; str[np] && str[np] != ' '; ++np) {
				if (!(u = nodes[u][id(str[np])])) {
					// No Match, use whole string
					while (np < n && str[np] != ' ')
						++np;
					ret.append(str + pos, str + np);
					ret.append(1, ' ');
					set = true;
					break;
				}
				if (terminate.test(u)) {
					// OK for prefix
					ret.append(str + pos, str + np + 1);
					ret.append(1, ' ');
					while (np < n && str[np] != ' ')
						++np;
					set = true;
					break;
				}
			}
			if (!set) {
				ret.append(str + pos, str + np);
				ret.append(1, ' ');
			}
			pos = np + 1;
		}
		ret.pop_back();
		return ret;
	}
};

int main() {
	auto* s = new Solution();
	auto r = s->replaceWords({"e","k","c","harqp","h","gsafc","vn","lqp","soy","mr","x","iitgm","sb","oo","spj","gwmly","iu","z","f","ha","vds","v","vpx","fir","t","xo","apifm","tlznm","kkv","nxyud","j","qp","omn","zoxp","mutu","i","nxth","dwuer","sadl","pv","w","mding","mubem","xsmwc","vl","farov","twfmq","ljhmr","q","bbzs","kd","kwc","a","buq","sm","yi","nypa","xwz","si","amqx","iy","eb","qvgt","twy","rf","dc","utt","mxjfu","hm","trz","lzh","lref","qbx","fmemr","gil","go","qggh","uud","trnhf","gels","dfdq","qzkx","qxw"}, "ikkbp miszkays wqjferqoxjwvbieyk gvcfldkiavww vhokchxz dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dco kddxmckhvqifbuzkhstp wc ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy ifvifheoxqlbosfww mengfdydekwttkhbzenk wjhmmyltmeufqvcpcxg hthcuovils ldipovluo aiprogn nusquzpmnogtjkklfhta klxvvlvyh nxzgnrveghc mpppfhzjkbucv cqcft uwmahhqradjtf iaaasabqqzmbcig zcpvpyypsmodtoiif qjuiqtfhzcpnmtk yzfragcextvx ivnvgkaqs iplazv jurtsyh gzixfeugj rnukjgtjpim hscyhgoru aledyrmzwhsz xbahcwfwm hzd ygelddphxnbh rvjxtlqfnlmwdoezh zawfkko iwhkcddxgpqtdrjrcv bbfj mhs nenrqfkbf spfpazr wrkjiwyf cw dtd cqibzmuuhukwylrnld dtaxhddidfwqs bgnnoxgyynol hg dijhrrpnwjlju muzzrrsypzgwvblf zbugltrnyzbg hktdviastoireyiqf qvufxgcixvhrjqtna ipfzhuvgo daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh qzsaobsghgm ichlpsjlsrwzhbyfhm ksenb bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala qmxixtooxtbrzyorn gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn frotscysdyclrc ckcttaceuuxzcghw pxbd oklwhcppuziixpvihihp");
	std::cout << r;
	return 0;
}
