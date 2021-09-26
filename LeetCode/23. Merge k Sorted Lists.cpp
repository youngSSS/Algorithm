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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int> nums;
		for (auto list : lists) {
			while (list != nullptr) {
				nums.push_back(list->val);
				list = list->next;
			}
		}
		sort(nums.begin(), nums.end());
		ListNode * head = nullptr, * tail;
		for (int num : nums) {
			ListNode * node = new ListNode();
			node->val = num;
			if (head == nullptr) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
				tail = node;
			}
		}
		return head;
	}
};

int main() {
	Solution* solution = new Solution();
	solution->mergeKLists();
	return 0;
}
