/*
在一个长度为 n 的数组里的所有数字都在 0 到 n - 1 的范围内。数组中某些数字是重复的，
但不知道有几个数字是重复的，也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		unordered_map<int, int> map;
		if (numbers == NULL || length <= 0)
			return false;
		for (int i = 0; i < length; i++)
		{
			if (map.find(numbers[i]) != map.end())
			{
				*duplication = numbers[i];
				return true;
			}
			else
				map[numbers[i]] = 1;
		}
		return false;
	}
};

int main()
{
	int Num[] = { 1,2,3,2,5 };
	int Len = 5;
	int* pDup = new int[1];
	bool Res = Solution().duplicate(Num, Len, pDup);
	cout << Res << "， " << *pDup << endl;
	delete[] pDup;
	pDup = NULL;
	return 0;
}