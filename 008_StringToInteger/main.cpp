#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

//注意边界问题，字符串查找
class Solution {
public:
	int myAtoi(string str) {
		int Len = str.length(), i = 0;
		bool Flag = true;
		double Result = 0;
		if (Len == 0 || str.empty()) return 0;
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);

		if (str[i] == '-')
		{
			Flag = false;
			i++;
		}
		else if (str[i] == '+')
			i++;
		
		for (; i < Len; i++)
		{
			if (str[i] < '0' || str[i] > '9')
				break;
			if (Flag)
				Result = Result * 10 + (str[i] - '0');
			else
				Result = Result * 10 - (str[i] - '0');
		}
		if (Result > INT_MAX)
			Result = INT_MAX;
		if (Result < INT_MIN)
			Result = INT_MIN;
		return (int)Result;
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
		string str = stringToString(line);

		int ret = Solution().myAtoi(str);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}