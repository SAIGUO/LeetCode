#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
int fast_io = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }();

//动态规划， 8ms
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int MaxSum = INT_MIN, Temp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			Temp = max(nums[i], Temp + nums[i]);
			MaxSum = max(MaxSum, Temp);
		}
		return MaxSum;
	}
};

//暴力遍历，800ms
/*
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int Sum, Maxsum = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			Sum = nums[i];
			Maxsum = max(Maxsum, Sum);
			for (int k = i + 1; k < nums.size(); k++)
			{
				Sum += nums[k];
				Maxsum = max(Maxsum, Sum);
			}
		}
		return Maxsum;
	}
};
*/

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
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().maxSubArray(nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}