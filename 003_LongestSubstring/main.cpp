#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//����bug
/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		char *p1, *p2, *Cur;
		int MaxSub = 1;
		if (s.length() == 0) return 0;
		for (int i = 0; i < s.length() - 1; i++)
		{
			int Len = 0;
			Cur = p1 = &s[i];
			p2 = p1+1;
			if (*p1 == *p2 || *p2 == '\0')
			{
				Len = 1;
				MaxSub = MaxSub > Len ? MaxSub : Len;
				continue;
			}
			while (*p1 != '\0' && *p2 != '\0')
			{
				Len = 0;
				while (p1 <= p2)
				{
					if (*p1 != *p2) Len++;
					p1++;
				}
				p2++;
				p1 = Cur;
				MaxSub = MaxSub > Len ? MaxSub : Len;
			}
		}
		return MaxSub;
	}
};*/

/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int m[256] = {-1};
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
	}
};*/

/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(256, -1);
		int res = 0, left = -1;
		for (int i = 0; i < s.size(); ++i) {
			left = max(left, m[s[i]]);
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> m;
		int res = 0, left = 0;
		for (int i = 0; i < s.size(); ++i) {
			left = max(left, m[s[i]]);
			m[s[i]] = i + 1;
			res = max(res, i - left + 1);
		}
		return res;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}