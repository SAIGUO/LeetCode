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

//two pass, 8ms
/*
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int Len = 0;
		ListNode* pList = head;
		while (pList != NULL)
		{
			Len++;
			pList = pList->next;
		}
		pList = head;
		while (n + 1 < Len)
		{
			pList = pList->next;
			Len--;
		}
		if (Len == 1 && n == 1) return NULL;
		if (Len == n) return head->next;
		pList->next = pList->next->next;
		return head;
	}
};*/

//one pass, 4ms
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *slow = head, *fast = head;
		for (int i = 0; i < n; i++)
		{
			fast = fast->next;
		}
		if (fast == NULL)
			return head->next;
		while (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
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

int stringToInteger(string input) {
	return stoi(input);
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
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		int n = stringToInteger(line);

		ListNode* ret = Solution().removeNthFromEnd(head, n);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}