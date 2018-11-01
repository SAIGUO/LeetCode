#include <iostream>
#include <string>

using namespace std;

//符号不用单独考虑，除了输入值的范围需要注意，反转后的数字也要满足条件
/*
class Solution {
public:
	int reverse(int x) {
		int Result = 0;
		int Flag = 1;
		if (x == 0 || x < INT_MIN || x > INT_MAX) return 0;
		if (x < 0)
		{
			Flag = -1;
			x = -x;
		}
		while (x % 10 == 0)
			x /= 10;
		while (true)
		{
			if (x / 10 == 0)
			{
				Result = Result * 10 + x;
				break;
			}
			else
			{
				Result = Result * 10 + x % 10;
				x /= 10;
			}
		}
		return Flag * Result;
	}
};*/

class Solution {
public:
	int reverse(int x) {
		int Result = 0;
		while ( x!= 0)
		{
			int Pop = x % 10;
			x /= 10;
			if (Result > INT_MAX / 10 || (Result == INT_MAX / 10 && Pop > 7)) return 0;
			if (Result < INT_MIN / 10 || (Result == INT_MIN / 10 && Pop < -8)) return 0;
			Result = Result * 10 + Pop;
		}
		return Result;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		int ret = Solution().reverse(x);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}