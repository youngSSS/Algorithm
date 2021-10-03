#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <cstdio>

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
	ListNode* reverseKGroup(ListNode* head, int k) {
		vector<ListNode*> node(k);
		ListNode* answer, * start = nullptr, * end;
		int idx = 0;

		while (head != nullptr) {
			node[idx] = head;
			idx += 1;

			if (idx == k) {
				end = head->next;
				for (int i = 0; i < k; i++) {
					if (i == 0) node[i]->next = end;
					else node[i]->next = node[i - 1];
				}
				if (start == nullptr) answer = node.back();
				else start->next = node.back();
				start = node[0];
				idx = 0;

				head = end;
			}
			else head = head->next;
		}

		return answer;
	}
};