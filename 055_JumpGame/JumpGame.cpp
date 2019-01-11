#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int fast_io = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }();

//4ms
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int Len = nums.size(), Pos = 0;
		for (int i = 0; i < Len; i++)
		{
			if (Pos < i) return false;
			Pos = max(Pos, i + nums[i]);
		}
		return true;
	}
};

//4ms
/*
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int Len = nums.size();
		if (Len <= 1) return true;
		for (int i = 0; i < Len;)
		{
			if (nums[i] == 0 && i < Len - 1) return false;
			if (nums[i] + i >= Len - 1) return true;
			for (int k = 1; k <= nums[i]; ++k)
			{
				if (nums[i + k] + k > nums[i] || k == nums[i])
				{
					i = i + k; break;
				}
			}
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		bool ret = Solution().canJump(nums);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}