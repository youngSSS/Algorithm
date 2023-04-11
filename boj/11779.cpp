#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, m, start, dest;
    scanf("%d %d", &n, &m);

    vector< pair<int, int> > graph[n + 1];
    pair<int, int> dist[n + 1];
    priority_queue< pair<int, int> > pq;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
    }
    fill(dist, dist + n + 1, make_pair(1e9, 0));

    scanf("%d %d", &start, &dest);

    pq.push(make_pair(0, start));
    dist[start] = make_pair(0, 0);

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now].first) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int next_cost = cost + graph[now][i].second;
            int next = graph[now][i].first;

            if (next_cost < dist[next].first) {
                pq.push(make_pair(-next_cost, next));
                dist[next] = make_pair(next_cost, now);
            }
        }
    }

    vector<int> path;
    path.push_back(dest);
    int p = dist[dest].second;
    while (p != 0) {
        path.push_back(p);
        p = dist[p].second;
    }

    printf("%d\n%d\n", dist[dest].first, path.size());
    int size = path.size();
    for (int i = 0; i < size; i++) {
        printf("%d ", path.back());
        path.pop_back();
    }

    return 0;
}