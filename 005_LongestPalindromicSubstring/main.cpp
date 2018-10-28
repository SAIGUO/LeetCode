#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int MaxLen = 0;
		string SubString;
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = i; j < s.size(); ++j)
			{
				if (isPalindrome(s, i, j))
				{
					if (MaxLen < j - i + 1)
					{
						MaxLen = j - i + 1;
						SubString = s.substr(i, MaxLen);
					}
				}
			}
		}
		return SubString;
	}

	bool isPalindrome(string s, int start, int end)
	{
		while (start <= end)
		{
			if (s[start] != s[end])
				return false;
			else 
			{
				start++;
				end--;
			}
		}
		return true;
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

		string ret = Solution().longestPalindrome(s);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}