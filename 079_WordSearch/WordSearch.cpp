#include <iostream>
#include <vector>

using namespace std;

int fast_io = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }();

//1200ms,DFS
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size(), col = board[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, false));
		for (int i = 0; i < row; ++i)
		{
			for (int k = 0; k < col; ++k)
			{
				if (search(board, word, 0, i, k, visited))
					return true;
			}
		}
		return false;
	}
	bool search(vector<vector<char>>& board, string word, int index, int row, int col, vector<vector<bool>> visited)
	{
		if (index == word.size())
			return true;
		if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
			return false;
		if (visited[row][col])
			return false;
		if (board[row][col] != word[index])
			return false;
		visited[row][col] = true;
		bool res = search(board, word, index + 1, row + 1, col, visited) || search(board, word, index + 1, row - 1, col, visited) || search(board, word, index + 1, row, col + 1, visited) || search(board, word, index + 1, row, col - 1, visited);
		return res;
	}
};

void main()
{
	vector<vector<char>> board = { {} };
	string word = "";
	bool res = Solution().exist(board, word);
	cout << res << endl;
}