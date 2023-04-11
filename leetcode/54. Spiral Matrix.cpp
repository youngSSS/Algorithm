#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> answer;
		int x = 0, y = 0;
		int m = matrix.size(), n = matrix[0].size();
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		vector<vector<int>> visit(m, vector<int>(n, 0));

		visit[0][0] = 1;
		answer.push_back(matrix[0][0]);

		int dir = 0;
		int fail_cnt = 0;
		while (fail_cnt < 4) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (0 <= nx && nx < m && 0 <= ny && ny < n && visit[nx][ny] == 0) {
				x = nx;
				y = ny;
				visit[x][y] = 1;
				answer.push_back(matrix[x][y]);
				fail_cnt = 0;

			}
			else {
				dir = (dir + 1) % 4;
				fail_cnt += 1;
			}
		}

		return answer;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<vector<int>> nums = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};

	solution->spiralOrder(nums);

	return 0;
}