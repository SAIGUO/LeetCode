#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//µü´ú
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> Subs(1, vector<int>());
		for (int i = 0; i < nums.size(); ++i)
		{
			int n = Subs.size();
			for (int k = 0; k < n; ++k)
			{
				Subs.push_back(Subs[k]);
				Subs.back().push_back(nums[i]);
			}
		}
		return Subs;
	}
};

//4ms, µÝ¹é
/*
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> Sub;
		vector<vector<int>> Subs;
		__subSet(nums, 0, Sub, Subs);
		return Subs;
	}
private:
	void __subSet(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs)
	{
		subs.push_back(sub);
		for (int i = start; i < nums.size(); ++i)
		{
			sub.push_back(nums[i]);
			__subSet(nums, i + 1, sub, subs);
			sub.pop_back();
		}
	}
};*/

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

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> Nums = stringToIntegerVector(line);

		vector<vector<int>> ret = Solution().subsets(Nums);

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
