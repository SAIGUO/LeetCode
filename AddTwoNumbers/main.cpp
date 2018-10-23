/*
You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output : 7 -> 0 -> 8
	Explanation : 342 + 465 = 807.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//gss
/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* pHead1 = l1;
		ListNode* pHead2 = l2;
		ListNode* pResult = new ListNode(0);
		ListNode* pResultHead = pResult;
		
		while (pHead1->next != NULL && pHead2->next != NULL)
		{
			pResult->val = pHead1->val + pHead2->val;
			pResult->next = new ListNode(0);
			pResult = pResult->next;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		pResult->val = pHead1->val + pHead2->val;
		pResult->next = pHead1->next == NULL ? pHead2->next : pHead1->next;
		pResult = pResultHead;
		while (pResult->next != NULL)
		{
			if (pResult->val > 9)
			{
				pResult->val %= 10;
				pResult->next->val += 1;
				pResult = pResult->next;
			}
			else pResult = pResult->next;
		}
		if (pResult->val > 9)
		{
			pResult->val %= 10;
			pResult->next = new ListNode(1);
		}
		
		return pResultHead;
	}
};*/

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* pHead1 = l1, *pHead2 = l2;
		ListNode* pResult = new ListNode(0);
		ListNode* pResultHead = pResult;

		int Carry = 0;
		while (pHead1 != NULL || pHead2 != NULL)
		{
			int V1 = pHead1 != NULL ? pHead1->val : 0;
			int V2 = pHead2 != NULL ? pHead2->val : 0;
			pResult->next = new ListNode((V1 + V2 + Carry) % 10);
			pResult = pResult->next;
			if (pHead1 != NULL) pHead1 = pHead1->next;
			if (pHead2 != NULL) pHead2 = pHead2->next;
			Carry = (V1 + V2 + Carry) / 10;
		}
		if (Carry == 1)
			pResult->next = new ListNode(1);

		return pResultHead->next;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}


int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* l1 = stringToListNode(line);
		getline(cin, line);
		ListNode* l2 = stringToListNode(line);

		ListNode* ret = Solution().addTwoNumbers(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
} 