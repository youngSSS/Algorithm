#include <cstdio>
#include <vector>

using namespace std;

int parent[500000];

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

int _union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return 1;

    if (parent[x] == parent[y]) {
        parent[y] = x;
        parent[x] -= 1;
    }
    else if (parent[x] < parent[y]) parent[y] = x;
    else if (parent[x] > parent[y]) parent[x] = y;

    return 0;
}

int main() {
    int n, m, answer = 0;

    scanf("%d %d", &n, &m);
    fill_n(parent, n, -1);

    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);

        if (_union(x, y)) {
            answer = i + 1;
            break;
        }
    }

    printf("%d", answer);

    return 0;
}