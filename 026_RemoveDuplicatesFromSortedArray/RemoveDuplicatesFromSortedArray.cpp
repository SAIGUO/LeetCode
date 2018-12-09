#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1) return nums.size();
		int k = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[k] != nums[i])
			{
				k++;
				nums[k] = nums[i];
			}
		}
		return k + 1;
	}
};

//172ms
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i] == nums[i - 1])
			{
				if (i != nums.size() - 1)
				{
					for (int k = i; k < nums.size() - 1; k++)
					{
						nums[k] = nums[k + 1];
					}
					nums.pop_back();
				}
				else
					nums.pop_back();
			}
		}
		return nums.size();
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

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().removeDuplicates(nums);

		string out = integerVectorToString(nums, ret);
		cout << out << endl;
	}
	return 0;
}