#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		if (pNode->right != NULL)
		{
			TreeLinkNode* pRight = pNode->right;
			while (pRight->left != NULL)
				pRight = pRight->left;
			return pRight;
		}
		else
		{
			while (pNode->next != NULL)
			{
				TreeLinkNode* pParent = pNode->next;
				if (pParent->left == pNode)
					return pParent;
				pNode = pNode->next;
			}
		}
		return NULL;
	}
};

int main()
{
	return 0;
}