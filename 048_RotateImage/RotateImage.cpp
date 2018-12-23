#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int N = matrix.size();
		for (int i = 0; i < N / 2; i++)
		{
			int Temp;
			for (int k = i + 1; k < N - i; k++)
			{
				Temp = matrix[i][k];
				matrix[i][k] = matrix[N - 1 - k][i];
				matrix[N - 1 - k][i] = matrix[N - 1 - i][N - 1 - k];
				matrix[N - 1 - i][N - 1 - k] = matrix[k][N - 1 - i];
				matrix[k][N - 1 - i] = Temp;
			}
		}
	}
};