#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//牛顿迭代法开方，用long避免Ans*Ans溢出
class Solution {
public:
	int mySqrt(int x) {
		long Ans = x;
		while (Ans*Ans > x)
		{
			Ans = (Ans + x / Ans) / 2;
		}
		return Ans;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		int ret = Solution().mySqrt(x);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}