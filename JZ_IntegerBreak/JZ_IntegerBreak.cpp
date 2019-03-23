/*把一根绳子剪成多段，并且使得每段的长度乘积最大。*/

/*尽可能多剪长度为 3 的绳子，并且不允许有长度为 1 的绳子出现。如果出现了，就从已经切好长度为 3 的绳子中
拿出一段与长度为 1 的绳子重新组合，把它们切成两段长度为 2 的绳子。

证明：当 n >= 5 时，3(n - 3) - n = 2n - 9 > 0，且 2(n - 2) - n = n - 4 > 0。因此在 n >= 5 的情况下，
将绳子剪成一段为 2 或者 3，得到的乘积会更大。又因为 3(n - 3) - 2(n - 2) = n - 5 >= 0，所以剪成一段长度
为 3 比长度为 2 得到的乘积更大。*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//数学方法
class Solution {
public:
	int integerBreak(int n) {
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		int timesof3 = n / 3;
		if (n - timesof3 * 3 == 1)
			timesof3--;
		int timesof2 = (n - timesof3 * 3) / 2;
		return pow(3, timesof3)*pow(2, timesof2);
	}
};

//动态规划
/*
class Solution {
public:
	int integerBreak(int n) {
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= n; i++)
		{
			for (int k = 1; k <= i / 2; k++)
				dp[i] = max(dp[i], dp[k] * dp[i - k]);
		}
		return dp[n];
	}
};*/

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		int ret = Solution().integerBreak(n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}