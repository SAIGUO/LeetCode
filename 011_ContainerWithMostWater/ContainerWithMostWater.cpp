#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//0(n*n)
/*
class Solution {
public:
	int maxArea(vector<int>& height) {
		int Len = height.size(), MaxContainer = 0;
		if (Len < 2) return 0;
		for (int i = 0; i < Len - 1; i++)
		{
			for (int k = i + 1; k < Len; k++)
			{
				int TempArea = (k - i)*min(height[i], height[k]);
				MaxContainer = max(MaxContainer, TempArea);
			}
		}
		return MaxContainer;
	}
};*/


//0(n)
class Solution {
public:
	int maxArea(vector<int>& height) {
		int Len = height.size(), MaxContainer = 0;
		if (Len < 2) return 0;
		for (int i = 0, j = Len-1; i < j; )
		{
			MaxContainer = max(MaxContainer, min(height[j], height[i])*(j - i));
			height[i] < height[j] ? i++ : j--;
		}
		return MaxContainer;
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

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> height = stringToIntegerVector(line);

		int ret = Solution().maxArea(height);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}