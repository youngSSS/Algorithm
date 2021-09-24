#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* node = head;
		unordered_map<int, ListNode*> map;

		int idx = 0;
		while (node != nullptr) {
			map[idx] = node;
			idx += 1;
			node = node->next;
		}

		int targetIdx = idx - n;
		if (map[targetIdx] == head) return head->next;
		else {
			map[targetIdx - 1]->next = map[targetIdx + 1];
			return head;
		}
	}
};

int main() {
	Solution* solution = new Solution();
	ListNode* head, * prev = new ListNode();
	for (int i = 1; i < 6; i++) {
		ListNode* n = new ListNode();
		n->val = i;
		if (i != 1) prev->next = n;
		if (i == 1) head = n;
		prev = n;
	}

	solution->removeNthFromEnd(head, 2);
	return 0;
}
