/*����һ�� double ���͵ĸ����� base �� int ���͵����� exponent���� base �� exponent �η���*/

#include <iostream>

using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base;
		int isnagetive = false;
		if (exponent < 0)
		{
			exponent = -exponent;
			isnagetive = true;
		}
		double Res = Power(base*base, exponent / 2);
		if (exponent % 2 != 0)
			Res = Res*base;
		return isnagetive ? 1 / Res : Res;
	}
};

int main()
{
	int E = 5;
	double B = 2.1;
	double Res = Solution().Power(B, E);
	cout << Res << endl;
}