/*������һ�� m �к� n �еķ���һ�������˴����� (0, 0) �ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������������ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ��� k �ĸ��ӡ�*/

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