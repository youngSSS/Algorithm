#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> map(6, vector<int>(6, 0));

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> s;

void remove_macaron(int x, int y, int color, vector<vector<int>>& visit) {
	s.push_back(make_pair(x, y));
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < 6 && 0 <= ny && ny < 6) {
			if (visit[nx][ny] == 0 && map[nx][ny] == color)
				remove_macaron(nx, ny, color, visit);
		}
	}
}

void drop(int y, int color) {
	int x = 0;
	while (true) {
		if (x + 1 >= 6) {
			map[x][y] = color;
			break;
		}
		if (map[x + 1][y] != 0) {
			map[x][y] = color;
			break;
		}
		x += 1;
	}

	while (true) {
		vector<vector<int>> visit(6, vector<int>(6, 0));
		int flag = 0;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != 0 && visit[i][j] == 0) {
					remove_macaron(i, j, map[i][j], visit);

					if (s.size() >= 3) {
						flag = 1;

						unordered_map<int, int> y_lines;

						while (!s.empty()) {
							int mx = s.back().first;
							int my = s.back().second;
							s.pop_back();

							map[mx][my] = 0;
							visit[mx][my] = 0;

							y_lines[my] += 1;
						}

						for (auto y_line : y_lines) {
							int my = y_line.first;
							int cnt = y_line.second;

							for (int mx = 4; mx >= 0; mx--) {
								if (map[mx][my] != 0 && map[mx + 1][my] == 0) {
									map[mx + cnt][my] = map[mx][my];
									map[mx][my] = 0;
								}
							}
						}

						break;
					}

					s.clear();
				}
			}
			if (flag == 1) break;
		}

		if (flag == 0) break;
	}
}

vector<string> solution(vector<vector<int>> macaron) {
	vector<string> answer;

	for (auto m : macaron) {
		drop(m[0] - 1, m[1]);
	}

	for (int i = 0; i < 6; i++) {
		string ans = "";
		for (int j = 0; j < 6; j++) {
			ans += to_string(map[i][j]);
		}
		answer.push_back(ans);
	}

	return answer;
}

int main() {

	solution({{1,1},{2,1},{1,2},{3,3},{6,4},{3,1},{3,3},{3,3},{3,4},{2,1}});

	return 0;
}
