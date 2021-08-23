#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int parent[200];

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
    fill_n(parent, n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int conn;
            scanf("%d", &conn);
            if (conn == 1) _union(i, j);
        }
    }

    vector<int> travel;
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        travel.push_back(a - 1);
    }

    sort(travel.begin(), travel.end());
    travel.erase(unique(travel.begin(), travel.end()), travel.end());

    for (int i = 0; i < travel.size() - 1; i++) {
        if (find(travel[i]) != find(travel[i + 1])) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}