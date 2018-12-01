#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<int, string> map =
		{ {0, ""},{1, ""}, { 2,"abc" },{ 3, "def" },{ 4, "ghi" },{ 5, "jkl" },
		{ 6, "mno" },{ 7, "pqrs" },{ 8, "tuv" },{ 9, "wxyz" } };
		vector<vector<string>> Letters(map.size());
		Letters[0] = { map[0] };
		Letters[1] = { map[1] };
		for (int i = 2; i < map.size(); i++)
		{
			for (int k = 0; k < map[i].size(); k++)
			{
				Letters[i].push_back(map[i].substr(k, 1));
			}
		}
		vector<string> Outputs;
		Outputs = getCombinations(Letters, digits);
		return Outputs;
	}

	vector<string> getCombinations(vector<vector<string>>& vLetters, string vDigits) {
		vector<string> Result;
		if (vDigits.size() == 0) return Result;
		if (vDigits.size() == 1) {
			return (vLetters[stoi(vDigits)]);
		}
		string LeftLett = vDigits.substr(0, 1);
		string RightLett = vDigits.substr(1, vDigits.size() - 1);

		vector<string> LeftRes = getCombinations(vLetters, LeftLett);
		vector<string> RightRes = getCombinations(vLetters, RightLett);

		for (int i = 0; i < LeftRes.size(); i++)
		{
			for (int k = 0; k < RightRes.size(); k++)
			{
				Result.push_back(LeftRes[i] + RightRes[k]);
			}
		}
		return Result;
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
		string s = stringToString(line);

		vector<string> ret = Solution().letterCombinations(s);

		vector<string> out = (ret);
		for (int i = 0; i < out.size(); i++)
		{
			cout << out[i] << endl;
		}
	}
	return 0;
}