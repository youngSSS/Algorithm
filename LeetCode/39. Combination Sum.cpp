class Solution {
 public:
	vector<vector<int>> answer;
	unordered_map<int, int> map;

	vector<vector<int>> combinationSum(vector<int> candidates, int target) {
		vector<int> list;
		for (int cond : candidates) map[cond] = 1;
		dfs(list, 0, target, 1);
		return answer;
	}

	void dfs(vector<int>& list, int value, int target, int idx) {
		if (value == target) {
			answer.push_back(list);
			return;
		}

		for (int i = idx; i <= target - value; i++) {
			list.push_back(i);
			if (map[i] == 1) dfs(list, value + i, target, i);
			list.pop_back();
		}
	}
};