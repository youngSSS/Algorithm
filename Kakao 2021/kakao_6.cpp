#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct line {
	int y1, y2;
	int d;
};

int dsum[1005];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	int m = board.size(), n = board[0].size();
	map<int, vector<line>> y_lines;

	for (int i = 0; i < skill.size(); i++) {
		if (skill[i][0] == 1) skill[i][5] *= -1;

		line line1, line2;

		line1.y1 = skill[i][2];
		line1.y2 = skill[i][4];
		line1.d = skill[i][5];
		y_lines[skill[i][1]].push_back(line1);

		line2.y1 = skill[i][2];
		line2.y2 = skill[i][4];
		line2.d = -skill[i][5];
		y_lines[skill[i][3] + 1].push_back(line2);
	}

	for (int i = 0; i < m; i++) {
		int l[1005] = { 0 };

		for (int j = 0; j < y_lines[i].size(); j++) {
			l[y_lines[i][j].y1] += y_lines[i][j].d;
			l[y_lines[i][j].y2 + 1] -= y_lines[i][j].d;
		}

		int s = 0;
		for (int j = 0; j < n; j++) {
			s += l[j];
			dsum[j] += s;
			if (board[i][j] + dsum[j] > 0) answer += 1;
		}
	}

	return answer;
}

int main() {
	cout << solution(
		{
			{ 5, 5, 5, 5, 5 },
			{ 5, 5, 5, 5, 5 },
			{ 5, 5, 5, 5, 5 },
			{ 5, 5, 5, 5, 5 }
		},
		{
			{ 1, 0, 0, 3, 4, 4 },
			{ 1, 2, 0, 2, 3, 2 },
			{ 2, 1, 0, 3, 1, 2 },
			{ 1, 0, 1, 3, 3, 1 }
		});
	return 0;
}
