#include <iostream>
#include <vector>

using namespace std;

int fast_io = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }();

//用matrix[0][0] = 0表示第一行为0，用IsCol = true表示第一列为0
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int H = matrix.size(), W = matrix[0].size();
		bool IsCol = false;
		for (int i = 0; i < H; ++i)
		{
			if (matrix[i][0] == 0) IsCol = true;
			for (int k = 1; k < W; ++k)
			{
				if (matrix[i][k] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][k] = 0;
				}
			}
		}
		for (int i = 1; i < H; ++i)
		{
			for (int k = 1; k < W; ++k)
			{
				if (matrix[i][0] == 0 || matrix[0][k] == 0)
					matrix[i][k] = 0;
			}
		}
		if (matrix[0][0] == 0)
		{
			for (int i = 0; i < W; ++i)
				matrix[0][i] = 0;
		}
		if (IsCol == true)
		{
			for (int i = 0; i < H; ++i)
				matrix[i][0] = 0;
		}
	}
};

//会有已经被赋值为0的行或列再次被赋值
/*
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int H = matrix.size(), W = matrix[0].size();
		vector<vector<int>> Zero(H, vector<int>(W, 1));
		for (int i = 0; i < H; ++i)
		{
			for (int k = 0; k < W; ++k)
			{
				if (matrix[i][k] == 0)
				{
					Zero[i][k] = 0;
				}
			}
		}
		for (int i = 0; i < H; ++i)
		{
			for (int k = 0; k < W; ++k)
			{
				if (Zero[i][k] == 0)
				{
					matrix[i] = vector<int>(W, 0);
					for (int m = 0; m < H; ++m)
						matrix[m][k] = 0;
				}
			}
		}
	}
};*/

void main()
{
	vector<vector<int>> Input = { { 1,1,1,}, {1,0,1},{1,1,1} };
	Solution().setZeroes(Input);
	std::cout << "[";
	for (int i = 0; i < Input.size(); ++i)
	{
		std::cout << "[";
		for (int k = 0; k < Input[0].size() - 1; ++k)
		{
			std::cout << Input[i][k] << ",";
		}
		std::cout << Input[i][Input[0].size() - 1] << "]";
	}
	std::cout << "]" << std::endl;
}