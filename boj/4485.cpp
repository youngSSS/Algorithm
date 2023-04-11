#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<string> answers;

    for (int num = 1; ; num++) {
        scanf("%d", &n);
        if (n == 0) break;

        vector< vector<int> > cave(n, vector<int>(n, 0));
        vector< vector<int> > dist(n, vector<int>(n, 1e9));
        priority_queue< pair< int, pair<int, int> > > pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int rupee;
                scanf("%d", &rupee);
                cave[i][j] = rupee;
            }
        }

        pq.push(make_pair(-cave[0][0], make_pair(0, 0)));
        dist[0][0] = cave[0][0];

        while (!pq.empty()) {
            int cost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (cost > dist[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    int next_cost = cost + cave[nx][ny];

                    if (next_cost < dist[nx][ny]) {
                        dist[nx][ny] = next_cost;
                        pq.push(make_pair(-next_cost, make_pair(nx, ny)));
                    }
                }
            }
        }

        answers.push_back("Problem " + to_string(num) + ": " + to_string(dist[n - 1][n - 1]));
    }

    for (auto answer : answers)
        printf("%s\n", answer.c_str());

    return 0;
}