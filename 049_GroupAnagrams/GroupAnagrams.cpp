#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> Res;
		unordered_map<string, vector<string>> Map;
		for (int i = 0; i < strs.size(); i++)
		{
			string str = strs[i];
			sort(str.begin(), str.end());
			Map[str].push_back(strs[i]);
		}
		for (auto it : Map)
		{
			//sort(it.second.begin(), it.second.end());
			Res.push_back(it.second);
		}
		return Res;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<string> stringToStringVector(string input) {
	vector<string> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(item);
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<string> Nums = stringToStringVector(line);

		vector<vector<string>> ret = Solution().groupAnagrams(Nums);

		cout << "[";
		for (int i = 0; i < ret.size(); i++)
		{
			cout << "[";
			for (int k = 0; k < ret[i].size(); k++)
			{
				if (k != ret[i].size() - 1)
					cout << ret[i][k] << ",";
				else cout << ret[i][k];
			}
			cout << "]";
			if (i != ret.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}