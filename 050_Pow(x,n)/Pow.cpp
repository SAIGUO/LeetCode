#include <iostream>
#include <string>

using namespace std;

//12ms
class Solution {
public:
	double myPow(double x, int n) {
		double Res = 1;
		if (n < 0)
		{
			x = 1 / x;
			n = -n;
		}
		double Dig[32];
		Dig[0] = x;
		for (int i = 1; i < 32; ++i)
		{
			Dig[i] = Dig[i - 1] * Dig[i - 1];
		}
		unsigned int m = n;
		for (int i = 0; i < 32; ++i)
		{
			if (m & 0x1 << i)
				Res *= Dig[i];
		}
		return Res;
	}
};

//Time Limit Exceeded
/*
class Solution {
public:
	double myPow(double x, int n) {
		int N = sqrt(abs(n));
		double Res = 1;
		if (n < 0) x = 1 / x;
		while (N > 0)
		{
			Res *= x;
			N--;
		}
		return Res;
	}
};*/

int stringToInteger(string input) {
	return stoi(input);
}

double stringToDouble(string input)
{
	return stod(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		double x = stringToDouble(line);
		getline(cin, line);
		int n = stringToInteger(line);

		double ret = Solution().myPow(x, n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}