#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

//超出时间限制
/*
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
};*/

//动态规划
/*
class Solution {
public:
	string longestPalindrome(string s) {
		int Start = 0, MaxLen = 0;
		int Len = s.length();
		bool P[1000][1000] = {false};

		for (int i = 0; i < Len; i++)
		{
			P[i][i] = true;
			Start = i;
			MaxLen = 1;
		}

		for (int i = 0; i < Len - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				P[i][i + 1] = true;
				Start = i;
				MaxLen = 2;
			}
		}

		for (int StrLen = 3; StrLen <= Len; StrLen++)
		{
			for (int First = 0; First <= Len - StrLen; First++)
			{
				int Second = First + StrLen - 1;
				if (P[First + 1][Second - 1] && s[First] == s[Second])
				{
					P[First][Second] = true;
					MaxLen = StrLen;
					Start = First;
				}
			}
		}
		if (MaxLen > 0)
			return s.substr(Start, MaxLen);
		return s;
	}
};*/

//中心扩展算法
class Solution {
public:
	string longestPalindrome(string s) {
		int First = 0, Second = 0;
		int Len = s.size();

		if (s.size() < 1) return s;
		for (int i = 0; i < Len; i++)
		{
			int StrLen1 = subStringLen(s, i, i);
			int StrLen2 = subStringLen(s, i, i + 1);
			int StrLen = max(StrLen1, StrLen2);
			if (StrLen > Second - First)
			{
				First = i - (StrLen - 1) / 2;
				Second = i + StrLen / 2;
			}
		}
		return s.substr(First, Second - First + 1);
	}

	int subStringLen(string s, int vLeft, int vRight)
	{
		while (vLeft >= 0 && vRight <= s.size() && s[vLeft] == s[vRight])
		{
			vLeft--;
			vRight++;
		}
		return vRight - vLeft - 1;
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