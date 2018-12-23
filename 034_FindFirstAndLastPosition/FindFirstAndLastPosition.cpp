#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto Range = equal_range(begin(nums), end(nums), target);
		if (Range.first == Range.second)
			return vector<int> {-1, -1};
		size_t Left = distance(begin(nums), Range.first);
		size_t Right = distance(begin(nums), Range.second) - 1;
		return {(int)Left, (int)Right};
	}
};

//12ms, ¶þ·Ö²éÕÒ
/*
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int end = nums.size(), start = 0, mid, left, right;
		while (start < end)
		{
			mid = (start + end) / 2;
			if (nums[mid] >= target)
				end = mid;
			else start = mid + 1;
		}
		left = start;
		start = 0;
		end = nums.size();
		while (start < end)
		{
			mid = (start + end) / 2;
			if (nums[mid] > target)
				end = mid;
			else start = mid + 1;
		}
		right = start;
		return left == right ? vector<int> {-1, -1} : vector<int>{ left, right - 1 };
	}
};*/

//STL, 12ms
/*
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int Len = nums.size(), Start = -1, End = -1;
		if (Len == 0) return vector<int>{-1, -1};
		if (target < nums[0] || target > nums[Len - 1])
			return vector<int>{-1, -1};
		vector<int>::iterator it;
		it = find(nums.begin(), nums.end(), target);
		if (it == nums.end()) return vector<int>{-1, -1};
		Start = it - nums.begin();
		End = Start;
		for (int i = Start+1; i < Len; i++)
		{
			if (nums[i] == target) End++;
			else return vector<int>{Start, End};
		}
		return vector<int>{Start, End};
	}
};*/
//8ms
/*
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int Len = nums.size(), Start = -1, End = -1;
		if (Len == 0) return vector<int>{-1, -1};
		if (target < nums[0] || target > nums[Len - 1])
			return vector<int>{-1, -1};
		for (int i = 0; i < Len; i++)
		{
			if (nums[i] == target && Start == -1)
			{
				Start = i;
				End = i;
				continue;
			}
			if (Start != -1 && nums[i] != target)   break;
			if (nums[i] == target) End++;
		}
		return vector<int>{Start, End};
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

int stringToInteger(string input) {
	return stoi(input);
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
		getline(cin, line);
		int target = stringToInteger(line);

		vector<int> ret = Solution().searchRange(nums, target);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}