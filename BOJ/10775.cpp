#include <cstdio>
#include <vector>

using namespace std;

int parent[100001];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main() {
    int g, p, ans = 0;
    scanf("%d %d", &g, &p);

    vector<int> gates(p);
    for (int i = 0; i < p; i++)
        scanf("%d", &gates[i]);

    for (int i = 0; i < g + 1; i++)
        parent[i] = i;

    for (auto gate : gates) {
        int t = find(gate);
        if (t == 0) break;
        _union(t, t - 1);
        ans += 1;
    }

    printf("%d", ans);

    return 0;
}