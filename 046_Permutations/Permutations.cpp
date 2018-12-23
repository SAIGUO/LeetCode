#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//dfs
class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > result;

		permuteRecursive(num, 0, result);
		return result;
	}

	// permute num[begin..end]
	// invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result) {
		if (begin >= num.size()) {
			// one permutation instance
			result.push_back(num);
			return;
		}

		for (int i = begin; i < num.size(); i++) {
			swap(num[begin], num[i]);
			permuteRecursive(num, begin + 1, result);
			// reset
			swap(num[begin], num[i]);
		}
	}
};

//使用STL中next_permutation函数，12ms
/*
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> Res;
		sort(nums.begin(), nums.end());
		do {
			Res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return Res;
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
		vector<int> height = stringToIntegerVector(line);

		vector<vector<int>> ret = Solution().permute(height);

		std::cout << "[";
		for (int i = 0; i < ret.size(); i++)
		{
			std::cout << "[";
			for (int k = 0; k < ret[i].size() - 1; k++)
			{
				std::cout << ret[i][k] << ",";
			}
			std::cout << ret[i][ret[i].size() - 1] << "]";
		}
		std::cout << "]" << std::endl;
	}
	return 0;
}