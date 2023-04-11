#include <vector>
#include <string>
#include <iostream>

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
	ListNode* sortList(ListNode* head) {
		if (head == nullptr) return nullptr;

		vector<pair<int, ListNode*>> list;

		ListNode* temp = head;
		while (temp != nullptr) {
			list.push_back(make_pair(temp->val, temp));
			temp = temp->next;
		}

		sort(list.begin(), list.end());
		for (int i = 0; i < list.size() - 1; i++)
			list[i].second->next = list[i + 1].second;
		list.back().second->next = nullptr;

		return list[0].second;
	}
};

int main() {
	auto* node4 = new ListNode(3);
	auto* node3 = new ListNode(1, node4);
	auto* node2 = new ListNode(2, node3);
	auto* node1 = new ListNode(4, node2);

	auto* solution = new Solution();
	cout << solution->sortList(node1)->val;

	return 0;
}