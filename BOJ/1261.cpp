#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    priority_queue< pair< int, pair<int, int> > > pq;
    int maze[101][101], dist[101][101];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;

    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
            dist[i][j] = 1e8;
        }
    }

    pq.push(make_pair(0, make_pair(0, 0)));
    dist[0][0] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cost > dist[x][y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
                int next_cost = cost + maze[nx][ny];

                if (next_cost < dist[nx][ny]) {
                    pq.push(make_pair(-next_cost, make_pair(nx, ny)));
                    dist[nx][ny] = next_cost;
                }
            }
        }
    }

    printf("%d", dist[n - 1][m - 1]);

    return 0;
}