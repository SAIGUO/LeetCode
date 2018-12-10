#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int Back = nums.size() - 1, Front = 0;
		while (Front <= Back)
		{
			int Mid = Front + (Back - Front) / 2;
			if (nums[Mid] == target) return Mid;
			if (Front == Back) break;
			if (nums[Mid] > nums[Front])
			{
				if (target < nums[Mid] && target >= nums[Front])
					Back = Mid - 1;
				else Front = Mid + 1;
			}
			else
			{
				if (target >= nums[Mid + 1] && target <= nums[Back])
					Front = Mid + 1;
				else
					Back = Mid - 1;
			}
		}
		return -1;
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

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);

		int ret = Solution().search(nums, target);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}