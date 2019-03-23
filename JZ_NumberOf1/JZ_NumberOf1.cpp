/*
输入一个整数，输出该数二进制表示中 1 的个数。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		unsigned int bit = 1;
		while (bit)
		{
			if (n&bit)
				count++;
			bit <<= 1;
		}
		return count;
	}
};

//位计算
/*
class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		while (n != 0)
		{
			count++;
			n &= n - 1;
		}
		return count;
	}
};*/

int main()
{
	string N = "10";
	int B = stoi(N);//将输入字符串表示的int转为int
	int res = Solution().NumberOf1(B);
	string a = to_string(res);//将int类型数据作为string输出
	cout << res << endl;
	return 0;
}