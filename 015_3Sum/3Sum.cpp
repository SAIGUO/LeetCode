#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

//Time Limit Exceeded
/*
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int Len = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> Result;
		for (int i = 0; i < Len - 2; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			for (int k = i + 1; k < Len - 1; k++)
			{
				if (k != i + 1 && nums[k] == nums[k - 1]) continue;
				vector<int> Index = findNum(nums, i, k);
				if (Index.size() != 0)
				{
					Result.push_back(Index);
				}
			}
		}
		return Result;
	}

	vector<int> findNum(vector<int>& nums, int First, int Second)
	{
		for (int i = Second + 1; i < nums.size(); i++)
		{
			if (nums[i] == -(nums[First] + nums[Second]))
			{
				return vector<int>{ nums[First], nums[Second], nums[i] };
			}
		}
	}
};*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int Len = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> Result;
		for (int i = 0; i < Len; i++)
		{
			if(i > 0 && nums[i] == nums[i-1]) continue;
			int Left = i + 1, Right = Len - 1;
			while (Left < Right)
			{
				int Sum = nums[i] + nums[Left] + nums[Right];
				if (Sum > 0) Right--;
				else if (Sum < 0) Left++;
				else
				{
					Result.push_back(vector<int> {nums[i], nums[Left], nums[Right]});
					while (Left + 1 < Right && nums[Left] == nums[Left + 1]) Left++;
					while (Right - 1 > Left && nums[Right] == nums[Right - 1]) Right--;
					Left++;
					Right--;
				}
			}
		}
		return Result;
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
		vector<int> Nums = stringToIntegerVector(line);

		vector<vector<int>> ret = Solution().threeSum(Nums);

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
			cout << "]" ;
			if (i != ret.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}
