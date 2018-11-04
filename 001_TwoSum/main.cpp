/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
	unordered_map<int, int> map;
	vector<int> Result;
	for (int i = 0; i < nums.size(); i++) {
		int complement = target - nums[i];
		auto it = map.find(complement);
		if (it != map.end()) {
			Result.push_back(it->second);
			Result.push_back(i);
			return Result;
		}
		//map.insert(unordered_map<int, int>::value_type(nums[i], i));
		map.insert(map.end(), make_pair(nums[i], i));
	}
}

int main(int argc, char* argv[])
{
	vector<int> Nums = { 2, 7, 11, 15 };
	int Target = 9;
	vector<int> Result = twoSum(Nums, Target);
	cout << "[";
	for (int i = 0; i < Result.size(); i++)
	{
		if(i != Result.size() - 1)
			cout << Result[i] << ",";
		else cout << Result[i];
	}
	cout << "]" << endl;
	return 0;
}