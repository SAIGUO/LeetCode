/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建二叉树并返回。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return __construct(pre, vin, 0, pre.size(), 0, vin.size());
	}

private:
	TreeNode* __construct(vector<int> &pre, vector<int> &vin, int vPreStart, int vPerEnd, int vInStart, int vInEnd)
	{
		if (vPreStart >= vPerEnd || vInStart >= vInEnd)
			return NULL;
		TreeNode* pRoot = new TreeNode(pre[vPreStart]);
		int Pos;
		for (Pos = vInStart; Pos < vInEnd; Pos++)
		{
			if (vin[Pos] == pre[vPreStart])
				break;
		}
		pRoot->left = __construct(pre, vin, vPreStart + 1, vPreStart + Pos - vInStart + 1, vInStart, Pos);
		pRoot->right = __construct(pre, vin, vPreStart + Pos - vInStart + 1, vPerEnd, Pos + 1, vInEnd);
		return pRoot;
	}
};

int main()
{
	vector<int> vPre = { 3,9,20,15,7 };
	vector<int> vIn = { 9, 3, 15, 20, 7 };
	TreeNode* Tree = Solution().reConstructBinaryTree(vPre, vIn);
	return 0;
}