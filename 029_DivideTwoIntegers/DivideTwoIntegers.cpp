#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
		long long LDividend = abs((long long)dividend), LDivisor = abs((long long)divisor);
		int Flag = (dividend < 0 ^ divisor < 0) ? -1 : 1;
		int Res = 0;
		while (LDividend >= LDivisor)
		{
			long Temp = LDivisor, Multi = 1;
			while (LDividend >= (Temp << 1))
			{
				Temp <<= 1;
				Multi <<= 1;
			}
			Res += Multi;
			LDividend -= Temp;
		}
		return Res*Flag;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int dividend = stringToInteger(line);
		getline(cin, line);
		int divisor = stringToInteger(line);

		int ret = Solution().divide(dividend, divisor);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}