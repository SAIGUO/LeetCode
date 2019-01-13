#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//DP
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> Mat(m, vector<int>(n, 1));
		for (int i = 1; i < m; ++i)
		{
			for (int k = 1; k < n; ++k)
			{
				Mat[i][k] = Mat[i - 1][k] + Mat[i][k - 1];
			}
		}
		return Mat[m - 1][n - 1];
	}
};

//用Res*=这种形式会出现中间有除不尽的数，影响最后结果
/*
class Solution {
public:
	int uniquePaths(int m, int n) {
		double Res = 1;
		for (int i = 1; i < m; ++i)
		{
			Res = Res * (n - 1 + i) / i;
		}
		return (int)Res;
	}
};*/

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int m = stringToInteger(line);
		getline(cin, line);
		int n = stringToInteger(line);

		int ret = Solution().uniquePaths(m, n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}