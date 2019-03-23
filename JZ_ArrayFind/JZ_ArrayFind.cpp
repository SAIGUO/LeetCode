/*
给定一个二维数组，其每一行从左到右递增排序，从上到下也是递增排序。给定一个数，判断这个数是否在该二维数组中。
*/

/*
思路：该二维数组中的一个数，它左边的数都比它小，下边的数都比它大。因此，从右上角开始查找，就可以根据 target
和当前元素的大小关系来缩小查找区间，当前元素的查找区间为左下角的所有元素。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool Find(int target, vector<vector<int>> array)
	{
		if (array.empty() || array.size() == 0 || array[0].size() == 0)
			return false;
		int H = array.size();
		int W = array[0].size();
		int R = 0, C = W - 1;
		while (R < H && C >= 0)
		{
			if (target == array[R][C])
				return true;
			if (target < array[R][C])
				C--;
			else R++;
		}
		return false;
	}
};

/*
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())
			return false;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i][array[0].size() - 1] >= target)
			{
				for (int k = array[i].size() - 1; k >= 0; k--)
					if (array[i][k] == target)
						return true;
			}
		}
		return false;
	}
};*/

int main()
{
	int Target = 7;
	vector<vector<int>> Array = { {1, 2, 8, 9},{ 2, 4, 9, 12 }, { 4, 7, 10, 13}, {6, 8, 11, 15}};
	bool Res = Solution().Find(Target, Array);
	cout << Res << endl;
	return 0;
}