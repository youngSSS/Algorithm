#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> dist(100001, 1e9);
    priority_queue< pair<int, int> > pq;

    pq.push(make_pair(0, n));
    dist[n] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (cost > dist[pos]) continue;

        for (int i = 0; i < 3; i++) {
            int next_pos = pos;
            int next_cost = cost;

            if (i == 0) {
                next_pos -= 1;
                next_cost += 1;
            }
            else if (i == 1) {
                next_pos += 1;
                next_cost += 1;
            }
            else if (i == 2) {
                next_pos *= 2;
            }

            if (0 <= next_pos && next_pos <= 100000 && next_cost < dist[next_pos]) {
                pq.push(make_pair(-next_cost, next_pos));
                dist[next_pos] = next_cost;
            }
        }
    }

    printf("%d", dist[k]);

    return 0;
}