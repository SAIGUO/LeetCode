#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<int, vector<char>> map;
		for (int i = 0; i < board.size(); i++)
		{
			unordered_set<char> set;
			for (int k = 0; k < board[0].size(); k++)
			{
				if (board[i][k] != '.')
					if (set.find(board[i][k]) == set.end())
						set.insert(board[i][k]);
					else return false;
			}
		}
		for (int i = 0; i < board[0].size(); i++)
		{
			unordered_set<char> set;
			for (int k = 0; k < board.size(); k++)
			{
				if (board[k][i] != '.')
					if (set.find(board[k][i]) == set.end())
						set.insert(board[k][i]);
					else return false;
			}
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int k = 0; k < board[0].size(); k++)
			{
				vector<char> temp = map[3 * (i / 3) + k / 3];
				if (board[i][k] != '.')
				{
					if (search(temp, board[i][k])) return false;
					else {
						temp.push_back(board[i][k]);
						map[3 * (i / 3) + k / 3] = temp;
					}
				}
			}
		}
		return true;
	}

	bool search(vector<char>& vNums, char vBoard)
	{
		for (int i = 0; i < vNums.size(); i++)
		{
			if (vNums[i] == vBoard) return true;
		}
		return false;
	}
};

/*
class Solution {
	bool search(vector<int>& V, int elem) {
		for (int v : V) {
			if (elem == v) return true;
		}
		return false;
	}

public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<int, vector<int>> boxes;

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] != '.') {
					unordered_set<int> ust;
					for (int ii = 0; ii < 9; ii++)
					{
						if (board[ii][j] != '.')
							if (ust.find(board[ii][j]) == ust.end())
								ust.insert(board[ii][j]);
							else return false;
					}
					ust.clear();

					for (int jj = 0; jj < 9; jj++)
					{
						if (board[i][jj] != '.')
							if (ust.find(board[i][jj]) == ust.end())
								ust.insert(board[i][jj]);
							else return false;
					}

					vector<int> v = boxes[3 * (i / 3) + j / 3];
					if (search(v, board[i][j])) return false;
					else {
						v.push_back(board[i][j]);
						boxes[3 * (i / 3) + j / 3] = v;
					}
				}
			}
		}

		return true;
	}
};*/