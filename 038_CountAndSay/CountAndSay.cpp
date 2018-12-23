#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

//ตÝน้
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";
		return readString(countAndSay(n - 1));
	}

	string readString(string vStr)
	{
		if (vStr.size() == 1)
			return "11";
		string Res = "";
		int Count = 1;
		char Digit = vStr[0];
		for (int i = 1; i < vStr.size(); i++)
		{
			if (vStr[i] == Digit)
				Count++;
			else
			{
				Res += to_string(Count);
				Res += Digit;
				Digit = vStr[i];
				Count = 1;
			}
		}
		Res += to_string(Count);
		Res += Digit;

		return Res;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		string ret = Solution().countAndSay(n);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}