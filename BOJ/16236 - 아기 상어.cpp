#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int, int>;

int N, map[20][20];
pii shark_pos;
int shark_size = 2, shark_upgrade_cnt = 0;
int fish_size_cnt[7] = { 0, }, fish_cnt = 0;
int is_visit[20][20] = { 0, };

int dining();
int bfs(int a, int b);

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) shark_pos = { i, j };
            else if (map[i][j] != 0) {
                fish_size_cnt[map[i][j]]++;
                fish_cnt++;
            }
        }
    }

    printf("%d", dining());

    return 0;
}

int dining() {
    int dining_time = 0;

    while (true) {
        int break_condition = 0;
        int temp;

        // Case : No eatable fish, Call mom shark
        if (shark_size > 7 && fish_cnt == 0) break;

            // Case : No eatable fish, Call mom shark
        else if (shark_size <= 7) {
            for (int i = 1; i < shark_size; i++)
                if (fish_size_cnt[i] != 0) {
                    break_condition = 1;
                    break;
                }
            if (break_condition == 0) break;
        }

        // Case : Let's eat fish
        memset(is_visit, 0, sizeof(is_visit));
        temp = bfs(shark_pos.first, shark_pos.second);

        if (temp == -1) return dining_time;
        else dining_time += temp;
    }

    return dining_time;
}

int bfs(int a, int b) {
    int ans_time = -1, ans_x = 30, ans_y = 30;
    queue< pair<pii, int> > q;
    q.push({ { a, b }, 0 });
    is_visit[a][b] = 1;

    while (!q.empty()) {
        pii pos = q.front().first;
        int x = pos.first, y = pos.second;
        int time = q.front().second;
        q.pop();

        if (time == ans_time) break;

        // Up
        if (x - 1 >= 0 && is_visit[x - 1][y] == 0) {
            if (map[x - 1][y] <= shark_size) {
                // Eatable fish
                if (0 < map[x - 1][y] && map[x - 1][y] < shark_size) {
                    // Minimum time
                    if (ans_time == -1) ans_time = time + 1;

                    if (x - 1 < ans_x) {
                        ans_x = x - 1;
                        ans_y = y;
                    }
                    else if (x - 1 == ans_x) {
                        if (y < ans_y) ans_y = y;
                    }
                }

                q.push({{x - 1, y}, time + 1});
                is_visit[x - 1][y] = 1;
            }
        }

        // Left
        if (y - 1 >= 0 && is_visit[x][y - 1] == 0) {
            if (map[x][y - 1] <= shark_size) {
                if (0 < map[x][y - 1] && map[x][y - 1] < shark_size) {
                    if (ans_time == -1) ans_time = time + 1;

                    if (x < ans_x) {
                        ans_x = x;
                        ans_y = y - 1;
                    }
                    else if (x == ans_x) {
                        if (y - 1 < ans_y) ans_y = y - 1;
                    }
                }

                q.push({ { x, y - 1 }, time + 1 });
                is_visit[x][y - 1] = 1;
            }
        }

        // Right
        if (y + 1 < N && is_visit[x][y + 1] == 0) {
            if (map[x][y + 1] <= shark_size) {
                if (0 < map[x][y + 1] && map[x][y + 1] < shark_size) {
                    if (ans_time == -1) ans_time = time + 1;

                    if (x < ans_x) {
                        ans_x = x;
                        ans_y = y + 1;
                    }
                    else if (x == ans_x) {
                        if (y + 1 < ans_y) ans_y = y + 1;
                    }
                }

                q.push({ { x, y + 1 }, time + 1 });
                is_visit[x][y + 1] = 1;
            }
        }

        // Down
        if (x + 1 < N && is_visit[x + 1][y] == 0) {
            if (map[x + 1][y] <= shark_size) {
                if (0 < map[x + 1][y] && map[x + 1][y] < shark_size) {
                    if (ans_time == -1) ans_time = time + 1;

                    if (x + 1 < ans_x) {
                        ans_x = x + 1;
                        ans_y = y;
                    }
                    else if (x + 1 == ans_x) {
                        if (y < ans_y) ans_y = y;
                    }
                }

                q.push({ { x + 1, y }, time + 1 });
                is_visit[x + 1][y] = 1;
            }
        }
    }

    fish_cnt -= 1;
    fish_size_cnt[map[ans_x][ans_y]] -= 1;

    map[ans_x][ans_y] = 9;
    map[shark_pos.first][shark_pos.second] = 0;

    shark_pos = { ans_x, ans_y };
    shark_upgrade_cnt += 1;

    if (shark_upgrade_cnt == shark_size) {
        shark_size += 1;
        shark_upgrade_cnt = 0;
    }

    return ans_time;
}