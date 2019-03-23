/*地上有一个 m 行和 n 列的方格。一个机器人从坐标 (0, 0) 的格子开始移动，每一次只能向左右上下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于 k 的格子。*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<vector<int>> flag(rows, vector<int>(cols, 0));
		int count = move(threshold, rows, cols, 0, 0, flag);
		return count;
	}
	int move(int threshold, int rows, int cols, int row, int col, vector<vector<int>> &flag)
	{
		if (row < 0 || col < 0 || row >= rows || col >= cols || flag[row][col] == 1 || !isArrive(threshold, row, col))
			return 0;

		flag[row][col] = 1;
		int count = move(threshold, rows, cols, row - 1, col, flag) +
			move(threshold, rows, cols, row + 1, col, flag) +
			move(threshold, rows, cols, row, col - 1, flag) +
			move(threshold, rows, cols, row, col + 1, flag) + 1;

		return count;
	}
	bool isArrive(int threshold, int row, int col)
	{
		int sum = 0;
		while (row > 0 || col > 0)
		{
			if (row > 0)
			{
				sum += row % 10;
				row = row / 10;
			}
			if (col > 0) {
				sum += col % 10;
				col = col / 10;
			}
		}
		return sum <= threshold;
	}
};

int main()
{
	int threshold = 10, m = 10, n = 10;
	int res = Solution().movingCount(threshold, m, n);
	cout << res << endl;
	return 0;
}