#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int fast_io = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

//4ms，用sort函数
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k = 0;
		while (k < n)
			nums1[m++] = nums2[k++];
		sort(nums1.begin(), nums1.end());
	}
};

//4ms, 代码缩减后
/*
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, k = n - 1, t = m + n - 1;
		while (k >= 0)
			nums1[t--] = (i >= 0 && nums1[i] > nums2[k]) ? nums1[i--] : nums2[k--];
	}
};*/

//8ms
/*
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, k = n - 1, t = m + n - 1;
		while (k >= 0)
			nums1[t--] = (i >= 0 && nums1[i] > nums1[k]) ? nums1[i--] : nums2[k--];
		while (k >= 0 && i >= 0)
		{
			if (nums1[i] > nums2[k])
				nums1[t--] = nums1[i--];
			else
				nums1[t--] = nums2[k--];
		}
		while (k >= 0)
			nums1[t--] = nums2[k--];
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
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		int m = stringToInteger(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);
		getline(cin, line);
		int n = stringToInteger(line);

		Solution().merge(nums1, m, nums2, n);

		string out = integerVectorToString(nums1);
		cout << out << endl;
	}
	return 0;
}