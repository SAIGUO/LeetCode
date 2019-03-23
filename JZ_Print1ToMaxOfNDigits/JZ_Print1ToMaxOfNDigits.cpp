/*输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数即 999。*/

#include <iostream>

using namespace std;

//排列
class Solution
{
public:
	void print1ToMax(int vNum)
	{
		if (vNum <= 0) return;
		char* Res = new char[vNum + 1];
		Res[vNum] = '\0';
		printRecursively(Res, 0);
	}

	void printRecursively(char* voRes, int vNum)
	{
		if (vNum == strlen(voRes))
		{
			printRes(voRes);
			return;
		}
		for (int i = 0; i <= 9; i++)
		{
			voRes[vNum] = i + '0';	
			printRecursively(voRes, vNum + 1);
		}
	}

	void printRes(char* vRes)
	{
		bool start = false;
		for (int i = 0; i < strlen(vRes); i++)
		{
			if (!start && vRes[i] != '0')
			{
				start = true;
			}
			if (start)
				cout << vRes[i];
		}
		cout << endl;
	}
};

//递增计算
/*
class Solution
{
public:
	void print1ToMax(int vNum)
	{
		if (vNum <= 0) return;
		char* Res = new char[vNum + 1];
		memset(Res, '0', vNum);
		Res[vNum] = '\0';
		while (!increase(Res, vNum))
		{
			printRes(Res);
		}
		delete[] Res;
	}
	bool increase(char* voRes, int vNum)
	{
		bool Overflow = false;
 		int Flag = 0;
		for (int i = vNum - 1; i >= 0; i--)
		{
			int Sum = voRes[i] - '0' + Flag;
			if (i == vNum - 1)
				Sum++;
			if (Sum >= 10)
			{
				if (i == 0)
					Overflow = true;
				else {
					Sum -= 10;
					Flag = 1;
					voRes[i] = '0' + Sum;
				}
			}
			else {
				voRes[i] = '0' + Sum;
				break;
			}
		}
		return Overflow;
	}

	void printRes(char* vRes)
	{
		bool start = false;
		for (int i = 0; i < strlen(vRes); i++)
		{
			if (!start && vRes[i] != '0')
			{
				start = true;
			}
			if (start)
				cout << vRes[i];
		}
		cout << endl;
	}
};*/

int main()
{
	int N = 3;
	Solution().print1ToMax(N);
	return 0;
}