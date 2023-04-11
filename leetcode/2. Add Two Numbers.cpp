#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {
	}
	ListNode(int x) : val(x), next(nullptr) {
	}
	ListNode(int x, ListNode* next) : val(x), next(next) {
	}
};

class Solution {
 public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* answer = nullptr, * last;
		int n = 0;

		while (!(l1 == nullptr && l2 == nullptr && n == 0)) {
			int v1 = 0, v2 = 0;
			if (l1 != nullptr) {
				v1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				v2 = l2->val;
				l2 = l2->next;
			}

			ListNode* node = new ListNode((v1 + v2 + n) % 10);
			n = (v1 + v2 + n) / 10;

			if (answer == nullptr) answer = node;
			else last->next = node;

			last = node;
		}

		return answer;
	}
};
