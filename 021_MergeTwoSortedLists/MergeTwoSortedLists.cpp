#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//8ms
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *L3 = new ListNode(0);
		ListNode *Head = L3;
		while (l1 || l2)
		{
			if (l1 && l1->val <= (l2 ? l2->val : INT_MAX))
			{
				L3->next = l1;
				l1 = l1->next;
			}
			else
			{
				L3->next = l2;
				l2 = l2->next;
			}
			L3 = L3->next;
		}
		return Head->next;
	}
};

//8ms
/*
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *L3 = new ListNode(0);
		ListNode *Temp = L3;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				L3->next = l1;
				l1 = l1->next;
			}
			else
			{
				L3->next = l2;
				l2 = l2->next;
			}
			L3 = L3->next;
		}
		if (l1 == NULL)
			L3->next = l2;
		else L3->next = l1;
		return Temp->next;
	}
};*/

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

		ListNode* ret = Solution().mergeTwoLists(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}