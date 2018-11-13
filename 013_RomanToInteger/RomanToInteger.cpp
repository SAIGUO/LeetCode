#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

/*
class Solution {
public:
	int romanToInt(string s) {
		int Len = s.length(), Result = 0, i = 0;
		if (Len <= 0) return 0;
		for (; i < Len - 1;)
		{
			int First = SymbolToValue(s[i]);
			int Second = SymbolToValue(s[i + 1]);
			if (First < Second)
			{
				Result += Second - First;
				i += 2;
			}
			else {
				Result += First;
				i++;
			}
		}
		if (i == Len - 1)
			Result += SymbolToValue(s[i]);
		return Result;
	}

	int SymbolToValue(char vSymbol)
	{
		switch (vSymbol) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}
};*/

class Solution {
public:
	int romanToInt(string s) {
		int Len = s.length();
		if (Len <= 0) return 0;
		int Result = SymbolToValue(s[Len - 1]);
		for (int i = Len - 2; i >= 0; i--)
		{
			if (SymbolToValue(s[i]) >= SymbolToValue(s[i + 1]))
				Result += SymbolToValue(s[i]);
			else
				Result -= SymbolToValue(s[i]);
		}
		return Result;
	}

	int SymbolToValue(char vSymbol)
	{
		switch (vSymbol) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
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

		int ret = Solution().romanToInt(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}