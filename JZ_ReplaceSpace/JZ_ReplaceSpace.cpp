/*
��һ���ַ����еĿո��滻�� "%20".���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

/*
���ַ���β����������ַ���ʹ���ַ����ĳ��ȵ����滻֮��ĳ��ȡ���Ϊһ���ո�Ҫ�滻�������ַ��� % 20����
��˵�������һ���ո�ʱ����Ҫ��β��������������ַ����� P1 ָ���ַ���ԭ����ĩβλ�ã�P2 ָ���ַ������ڵ�ĩβλ�á�
P1 �� P2 �Ӻ���ǰ�������� P1 ������һ���ո�ʱ������Ҫ�� P2 ָ���λ��������� 02 % ��ע��������ģ�����������
�� P1 ָ���ַ���ֵ��
*/

#include <iostream>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0)
			return;
		int End = length;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				End += 2;
			}
		}

		End--;
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				str[End--] = '0';
				str[End--] = '2';
				str[End--] = '%';
			}
			else
				str[End--] = str[i];
		}
	}
};

int main()
{
	char Input[] = "Very Good!";
	int Len = 10;
	Solution().replaceSpace(Input, Len);
	return 0;
}