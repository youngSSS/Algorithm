#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector< vector< pair<int, int> > > graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a - 1].push_back(make_pair(b - 1, w));
        graph[b - 1].push_back(make_pair(a - 1, w));
    }

    int start, end;
    scanf("%d %d", &start, &end);
    start -= 1;
    end -= 1;

    int answer = 0;
    int left = 1, right = 1e9;
    while (left <= right) {
        int param = (left + right) / 2;
        int visit[10000] = {0, };
        queue<int> q;

        q.push(start);
        visit[start] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            if (now == end) {
                answer = param;
                break;
            }

            for (auto neighbor : graph[now]) {
                int next = neighbor.first;
                int next_weight = neighbor.second;

                if (visit[next] == 0 && next_weight >= param) {
                    visit[next] = 1;
                    q.push(next);
                }
            }
        }

        if (answer == param) left = param + 1;
        else right = param - 1;
    }

    printf("%d", answer);

    return 0;
}