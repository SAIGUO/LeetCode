/*
����һ��������������������Ʊ�ʾ�� 1 �ĸ�����
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

//λ����
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
	int B = stoi(N);//�������ַ�����ʾ��intתΪint
	int res = Solution().NumberOf1(B);
	string a = to_string(res);//��int����������Ϊstring���
	cout << res << endl;
	return 0;
}