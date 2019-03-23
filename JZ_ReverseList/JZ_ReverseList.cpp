/*从尾到头反过来打印出每个结点的值。*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//栈
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> Res;
		stack<int> Sta;
		while (head != NULL)
		{
			Sta.push(head->val);
			head = head->next;
		}
		while (!Sta.empty())
		{
			Res.push_back(Sta.top());
			Sta.pop();
		}
		return Res;
	}
};

//递归
/*
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> Res;

		__reverse(head, Res);

		return Res;
	}

private:
	void __reverse(ListNode* head, vector<int>& voRes)
	{
		if (head != NULL)
		{
			if (head->next != NULL)
				__reverse(head->next, voRes);
			voRes.push_back(head->val);
		}
	}
};
*/

//头插法
/*
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> Res;
		while (head != NULL)
		{
			Res.insert(Res.begin(), head->val);
			head = head->next;
		}
		return Res;
	}
};
*/

int main()
{
	ListNode* pList = new ListNode(1);
	ListNode* pHead = pList;
	pList->next = new ListNode(2);
	pList = pList->next;
	pList->next = new ListNode(3);
	pList = pList->next;
	vector<int> Res = Solution().printListFromTailToHead(pHead);
	return 0;
}