/*��һ�����Ӽ��ɶ�Σ�����ʹ��ÿ�εĳ��ȳ˻����*/

/*�����ܶ������Ϊ 3 �����ӣ����Ҳ������г���Ϊ 1 �����ӳ��֡���������ˣ��ʹ��Ѿ��кó���Ϊ 3 ��������
�ó�һ���볤��Ϊ 1 ������������ϣ��������г����γ���Ϊ 2 �����ӡ�

֤������ n >= 5 ʱ��3(n - 3) - n = 2n - 9 > 0���� 2(n - 2) - n = n - 4 > 0������� n >= 5 ������£�
�����Ӽ���һ��Ϊ 2 ���� 3���õ��ĳ˻����������Ϊ 3(n - 3) - 2(n - 2) = n - 5 >= 0�����Լ���һ�γ���
Ϊ 3 �ȳ���Ϊ 2 �õ��ĳ˻�����*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//��ѧ����
class Solution {
public:
	int integerBreak(int n) {
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		int timesof3 = n / 3;
		if (n - timesof3 * 3 == 1)
			timesof3--;
		int timesof2 = (n - timesof3 * 3) / 2;
		return pow(3, timesof3)*pow(2, timesof2);
	}
};

//��̬�滮
/*
class Solution {
public:
	int integerBreak(int n) {
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= n; i++)
		{
			for (int k = 1; k <= i / 2; k++)
				dp[i] = max(dp[i], dp[k] * dp[i - k]);
		}
		return dp[n];
	}
};*/

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		int ret = Solution().integerBreak(n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}