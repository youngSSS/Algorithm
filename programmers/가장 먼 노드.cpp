#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<int> nodes;
bool comp(int a, int b) {
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dist = -1;

    vector<vector<int>> edges;
    vector<int> is_visited(n + 1, 0);
    queue<int> queue;

    nodes.resize(n + 1);
    edges.resize(n + 1);
    is_visited[1] = 1;
    queue.push(1);

    for (auto e : edge) {
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }

    while (!queue.empty()) {
        int q_size = queue.size();
        dist += 1;

        while (q_size) {
            int cur_node = queue.front();
            queue.pop();
            q_size -= 1;

            nodes[cur_node] = dist;

            for (auto neighbor : edges[cur_node]) {
                if (is_visited[neighbor] == 0) {
                    is_visited[neighbor] = 1;
                    queue.push(neighbor);
                }
            }
        }
    }
    sort(nodes.begin(), nodes.end(), comp);

    int max = nodes[0];
    for (auto node : nodes) {
        if (max > node) break;
        answer += 1;
    }

    return answer;
}

int main() {
    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}