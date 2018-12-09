#include <iostream>
#include <string>
#include <assert.h>

using namespace std; 

//4ms
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0) return 0;
		for (int i = 0; ; i++)
		{
			for (int k = 0; ; k++)
			{
				if (i + k == haystack.size()) return -1;
				if (haystack[i + k] != needle[k]) break;
				if (k == needle.length() - 1) return i;
			}
		}
		return -1;
	}
};

//576ms
/*
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0) return 0;
		int Loc = -1;
		for (int i = 0; i < haystack.length(); i++)
		{
			if (needle[0] == haystack[i])
			{
				Loc = i;
				for (int k = 1; k < needle.length(); k++)
				{
					if (i + k >= haystack.length() || haystack[i + k] != needle[k])
					{
						Loc = -1; break;
					}
				}
			}
			if (Loc != -1) return Loc;
		}
		return Loc;
	}
};
*/

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
		string haystack = stringToString(line);
		getline(cin, line);
		string needle = stringToString(line);

		int ret = Solution().strStr(haystack, needle);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}