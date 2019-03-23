/*
将一个字符串中的空格替换成 "%20".例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

/*
在字符串尾部填充任意字符，使得字符串的长度等于替换之后的长度。因为一个空格要替换成三个字符（ % 20），
因此当遍历到一个空格时，需要在尾部填充两个任意字符。令 P1 指向字符串原来的末尾位置，P2 指向字符串现在的末尾位置。
P1 和 P2 从后向前遍历，当 P1 遍历到一个空格时，就需要令 P2 指向的位置依次填充 02 % （注意是逆序的），否则就填充
上 P1 指向字符的值。
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