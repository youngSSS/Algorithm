#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <cstring>

using namespace std;

int N, L, R;
int map[50][50];
int is_visit[50][50], is_road[50][50];
int row_road[50][50], col_road[50][50];
vector< pair<int, int> > pos;

int build_road();
int move_people();
void dfs(int row, int col);
void change_population();

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    }

    printf("%d", move_people());

    return 0;
}

int move_people() {
    int move_cnt = 0;

    while (true) {
        memset(is_road, 0, sizeof(is_road));
        memset(is_visit, 0, sizeof(is_visit));
        memset(row_road, 0, sizeof(row_road));
        memset(col_road, 0, sizeof(col_road));

        if (build_road() == 0) return move_cnt;

        move_cnt++;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (is_road[i][j] == 1 && is_visit[i][j] == 0) {
                    dfs(i, j);
                    change_population();
                }
            }
        }
    }
}

void dfs(int row, int col) {
    int up = row - 1, down = row + 1, left = col - 1, right = col + 1;

    is_visit[row][col] = 1;
    pos.push_back({row, col});

    // up
    if (up >= 0 && is_visit[up][col] == 0 && col_road[up][col] == 1) dfs(up, col);
    // down
    if (down < N && is_visit[down][col] == 0 && col_road[row][col] == 1) dfs(down, col);
    // left
    if (left >= 0 && is_visit[row][left] == 0 && row_road[row][left] == 1) dfs(row, left);
    // right
    if (right < N && is_visit[row][right] == 0 && row_road[row][col] == 1) dfs(row, right);
}

void change_population() {
    int avg = 0;
    for (int i = 0; i < pos.size(); i++)
        avg += map[pos[i].first][pos[i].second];

    avg = avg / pos.size();

    for (int i = 0; i < pos.size(); i++)
        map[pos[i].first][pos[i].second] = avg;

    pos.clear();
    pos.resize(0);
}

int build_road() {
    int ret_val = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // check right side
            if (j + 1 < N) {
                int gap = abs(map[i][j] - map[i][j + 1]);
                if (L <= gap && gap <= R) {
                    row_road[i][j] = 1;
                    is_road[i][j] = 1;
                    ret_val = 1;
                }
            }
            // check down side
            if (i + 1 < N) {
                int gap = abs(map[i][j] - map[i + 1][j]);
                if (L <= gap && gap <= R) {
                    col_road[i][j] = 1;
                    is_road[i][j] = 1;
                    ret_val = 1;
                }
            }
        }
    }

    return ret_val;
}