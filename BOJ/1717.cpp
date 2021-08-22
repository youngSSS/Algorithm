#include <cstdio>
#include <vector>

using namespace std;

int parent[1000001];

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (parent[x] == parent[y]) {
        parent[y] = x;
        parent[x] -= 1;
    }
    else if (parent[x] < parent[y]) parent[y] = x;
    else if (parent[x] > parent[y]) parent[x] = y;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    fill_n(parent, n + 1, -1);

    int cmd, x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &cmd, &x, &y);

        if (cmd == 0) _union(x, y);
        else if (find(x) == find(y)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}