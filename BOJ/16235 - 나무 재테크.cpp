#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using pii = pair<int, int>;

int N, M, K, year = 1;
int map[11][11], energy[11][11] = {0, };
vector<int> tree_age[11][11];
int tree_cnt[11][11] = {0, };

void spring();
void summer(int x, int y, int pos);
void fall();
void winter();
void propagation(int x, int y);

int main() {
    fill(map[0], map[11], 5);

    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            scanf("%d", &energy[i][j]);
    }
    for (int i = 0; i < M; i++) {
        int x, y, age;
        scanf("%d %d %d", &x, &y, &age);
        tree_age[x][y].push_back(age);
        tree_cnt[x][y]++;
    }

    for (int i = 0; i < K; i++) {
        spring();
        fall();
        winter();
        year++;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            ans += tree_cnt[i][j];
    }

    printf("%d", ans);

    return 0;
}

void spring() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            int size = tree_age[i][j].size();
            sort(tree_age[i][j].begin(), tree_age[i][j].end());

            for (int k = 0; k < size; k++) {
                int need_energy = tree_age[i][j][k];
                if (need_energy <= map[i][j]) {
                    map[i][j] -= need_energy;
                    tree_age[i][j][k]++;
                }
                else {
                    summer(i, j, k);
                    break;
                }
            }

        }
    }
}

void summer(int x, int y, int pos) {
    for (int i = pos; i < tree_age[x][y].size(); i++) {
        map[x][y] += tree_age[x][y][i] / 2;
        tree_cnt[x][y]--;
    }

    tree_age[x][y].erase(tree_age[x][y].begin() + pos, tree_age[x][y].begin() + tree_age[x][y].size());
}

void fall() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (tree_cnt[i][j] != 0) {
                int size = tree_cnt[i][j];
                for (int k = 0; k < size; k++)
                    if (tree_age[i][j][k] % 5 == 0) propagation(i, j);
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            map[i][j] += energy[i][j];
    }
}

void propagation(int x, int y) {
    if (x - 1 > 0 && y - 1 > 0) {
        tree_cnt[x - 1][y - 1]++;
        tree_age[x - 1][y - 1].push_back(1);
    }
    if (x - 1 > 0) {
        tree_cnt[x - 1][y]++;
        tree_age[x - 1][y].push_back(1);
    }
    if (x - 1 > 0 && y + 1 <= N) {
        tree_cnt[x - 1][y + 1]++;
        tree_age[x - 1][y + 1].push_back(1);
    }
    if (y - 1 > 0) {
        tree_cnt[x][y - 1]++;
        tree_age[x][y - 1].push_back(1);
    }
    if (y + 1 <= N) {
        tree_cnt[x][y + 1]++;
        tree_age[x][y + 1].push_back(1);
    }
    if (x + 1 <= N && y - 1 > 0) {
        tree_cnt[x + 1][y - 1]++;
        tree_age[x + 1][y - 1].push_back(1);
    }
    if (x + 1 <= N) {
        tree_cnt[x + 1][y]++;
        tree_age[x + 1][y].push_back(1);
    }
    if (x + 1 <= N && y + 1 <= N) {
        tree_cnt[x + 1][y + 1]++;
        tree_age[x + 1][y + 1].push_back(1);
    }
}