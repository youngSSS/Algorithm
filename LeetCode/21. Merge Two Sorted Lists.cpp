#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode * head = nullptr, * tail;
		while (true) {
			ListNode * node;
			if (l1->val < l2->val) {
				node = l1;
				l1 = l1->next;
			}
			else {
				node = l2;
				l2 = l2->next;
			}

			if (head == nullptr) {
				head = node;
				tail = node;
			}

			tail->next = node;
			tail = node;

			if (l1 == nullptr) {
				tail->next = l2;
				break;
			}
			else if (l2 == nullptr) {
				tail->next = l1;
				break;
			}
		}

		return head;
	}
};


int main() {
	Solution* solution = new Solution();
	ListNode * n1 = new ListNode(), * n2  = new ListNode(), *n3 = new ListNode();
	ListNode * l1 = new ListNode(), *l2 = new ListNode(), *l3 = new ListNode();

	n1->val = 1;
	n1->next = n2;
	n2->val = 2;
	n2->next = n3;
	n3->val = 4;

	l1->val = 1;
	l1->next = l2;
	l2->val = 3;
	l2->next = l3;
	l3->val = 4;

	cout << solution->mergeTwoLists(n1, l1);
	return 0;
}
