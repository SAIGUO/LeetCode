/*
����һ����ά���飬��ÿһ�д����ҵ������򣬴��ϵ���Ҳ�ǵ������򡣸���һ�������ж�������Ƿ��ڸö�ά�����С�
*/

/*
˼·���ö�ά�����е�һ����������ߵ���������С���±ߵ�������������ˣ������Ͻǿ�ʼ���ң��Ϳ��Ը��� target
�͵�ǰԪ�صĴ�С��ϵ����С�������䣬��ǰԪ�صĲ�������Ϊ���½ǵ�����Ԫ�ء�
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