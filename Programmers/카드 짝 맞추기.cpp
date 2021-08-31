#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> cards[7];
vector< vector<int> > map;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int get_cost(pair<int, int> start, pair<int, int> end) {
    int visit[4][4] = {0};
    queue<pair<int, int>> q;
    int cost = 0;

    if (start.first == end.first && start.second == end.second) return 0;

    q.push(start);
    visit[start.first][start.second] = 1;
    while (!q.empty()) {
        int size = q.size();
        cost += 1;

        for (int s = size; s > 0; s--) {
            pair<int, int> now = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = now.first;
                int ny = now.second;

                if (0 <= i && i < 4) {
                    nx += dx[i];
                    ny += dy[i];
                }
                else if (4 <= i && i < 8) {
                    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
                        while (true) {
                            if (0 <= nx + dx[i % 4] && nx + dx[i % 4] < 4 && 0 <= ny + dy[i % 4] && ny + dy[i % 4] < 4) {
                                nx += dx[i % 4];
                                ny += dy[i % 4];

                                if (map[nx][ny] == 1) break;
                            }
                            else break;
                        }
                    }
                }

                if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && visit[nx][ny] == 0) {
                    visit[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }

                if (nx == end.first && ny == end.second) return cost;
            }
        }
    }

    return cost;
}

int get_min_cost(pair<int, int> now, int next_idx, vector<int> targets, int cost) {
    pair<int, int> next1 = cards[targets[next_idx]][0];
    pair<int, int> next2 = cards[targets[next_idx]][1];

    int now_next1_cost = get_cost(now, next1);
    map[next1.first][next1.second] = 0;
    int next1_next2_cost = get_cost(next1, next2);
    map[next2.first][next2.second] = 0;

    int cost1 = now_next1_cost + next1_next2_cost + 2;

    if (next_idx < targets.size() - 1) cost1 = get_min_cost(next2, next_idx + 1, targets, cost + cost1);
    else cost1 += cost;

    map[next1.first][next1.second] = 1;
    map[next2.first][next2.second] = 1;

    int now_next2_cost = get_cost(now, next2);
    map[next2.first][next2.second] = 0;
    int next2_next1_cost = get_cost(next2, next1);
    map[next1.first][next1.second] = 0;

    int cost2 = now_next2_cost + next2_next1_cost + 2;

    if (next_idx < targets.size() - 1) cost2 = get_min_cost(next1, next_idx + 1, targets, cost + cost2);
    else cost2 += cost;

    map[next1.first][next1.second] = 1;
    map[next2.first][next2.second] = 1;

    return cost1 < cost2 ? cost1 : cost2;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9;
    vector<int> target_cards;
    vector< vector<int> > permutations;
    map = board;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) cards[board[i][j]].push_back(make_pair(i, j));
        }
    }

    for (int i = 1; i < 7; i++){
        if (!cards[i].empty()) target_cards.push_back(i);
    }

    permutations.push_back(target_cards);
    while (next_permutation(target_cards.begin(), target_cards.end()))
        permutations.push_back(target_cards);

    for (auto targets : permutations) {
        int cost = get_min_cost(make_pair(r, c), 0, targets, 0);
        if (cost < answer) answer = cost;
    }

    return answer;
}
#include <iostream>

int main() {
    cout << solution({{1, 5, 0, 2},{6, 4, 3, 0},{0, 2, 1, 5},{3, 0, 6, 4}}, 0, 0);
    return 0;
}