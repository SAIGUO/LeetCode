#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> Res;
		generateList(n, n, "", Res);
		return Res;
	}

	void generateList(int vLeft, int vRight, string seq, vector<string>& Res)
	{
		if (vLeft == 0 && vRight == 0)
		{
			Res.push_back(seq);
			return;
		}
		if (vLeft > 0)
			generateList(vLeft - 1, vRight, seq + "(", Res);
		if (vRight > vLeft)
			generateList(vLeft, vRight - 1, seq + ")", Res);
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		vector<string> ret = Solution().generateParenthesis(x);
		std::cout << "[" << std::endl;
		for (int i = 0; i < ret.size(); i++)
		{
			cout << "\"" << ret[i] << "\"" << endl;
		}
		std::cout << "]" << std::endl;
	}
	return 0;
}