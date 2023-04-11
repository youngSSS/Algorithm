#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector< vector<pair<int, int> > > graph;

vector<int> disktra(int start, int n) {
    vector<int> dist(n, 2 * 1e9);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now]) continue;

        for (auto & neighbor : graph[now]) {
            int next = neighbor.first;
            int next_cost = cost + neighbor.second;

            if (next_cost < dist[next]) {
                pq.push(make_pair(-next_cost, next));
                dist[next] = next_cost;
            }
        }
    }

    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<int> answers(n, 0);

    graph.resize(n);

    for (auto fare : fares) {
        graph[fare[0] - 1].push_back(make_pair(fare[1] - 1, fare[2]));
        graph[fare[1] - 1].push_back(make_pair(fare[0] - 1, fare[2]));
    }

    for (int node = 0; node < n; node++) {
        vector<int> cost = disktra(node, n);

        if (node == s - 1) {
            for (int i = 0; i < n; i++)
                answers[i] += cost[i];
        }

        answers[node] += (cost[a - 1] + cost[b - 1]);
    }

    sort(answers.begin(), answers.end());

    return answers[0];
}