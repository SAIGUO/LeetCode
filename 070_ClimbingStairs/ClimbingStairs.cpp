#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int fast_io = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }();
class Solution {
public:
	int climbStairs(int n) {
		vector<int> Step(n + 1, 1);
		for (int i = 2; i < n + 1; ++i)
		{
			Step[i] = Step[i - 1] + Step[i - 2];
		}
		return Step[n];
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		int ret = Solution().climbStairs(n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}