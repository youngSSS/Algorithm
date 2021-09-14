#include <stdio.h>

int N, M, max = 0;
int paper[501][501] = {0, };
int is_visited[501][501];

void dfs(int, int, int, int);
void* memcpy(void *dest, void *src, size_t count){
    for(size_t i = 0; i < count; i++)
        *((char*)dest + i) = *((char*)src + i);
    return dest;
}

int main() {
    int is_visited_initializer[501][501] = {0, };

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            scanf("%d", &paper[i][j]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            memcpy(is_visited, is_visited_initializer, sizeof(is_visited_initializer));
            is_visited[i][j] = 1;
            dfs(i, j, paper[i][j], 1);
        }
    }

    printf("%d", max);

    return 0;
}

void dfs(int x, int y, int value, int cnt) {
    if (cnt == 4) {
        if (value > max) max = value;
        is_visited[x][y] = 0;
        return;
    }

    // up
    if (x - 1 > 0 && is_visited[x - 1][y] == 0) {
        is_visited[x - 1][y] = 1;
        dfs(x - 1, y, value + paper[x - 1][y], cnt + 1);
    }

    // down
    if (x + 1 <= N && is_visited[x + 1][y] == 0) {
        is_visited[x + 1][y] = 1;
        dfs(x + 1, y, value + paper[x + 1][y], cnt + 1);
    }

    // right
    if (y + 1 <= M && is_visited[x][y + 1] == 0) {
        is_visited[x][y + 1] = 1;
        dfs(x, y + 1, value + paper[x][y + 1], cnt + 1);
    }

    // left
    if (y - 1 > 0 && is_visited[x][y - 1] == 0) {
        is_visited[x][y - 1] = 1;
        dfs(x, y - 1, value + paper[x][y - 1], cnt + 1);
    }
}