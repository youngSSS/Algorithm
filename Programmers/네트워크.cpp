#include <vector>
#include <iostream>

using namespace std;

int is_visit[200] = {0, };

int dfs(int n, vector<vector<int>> computers, int start) {
    vector<int> will_visit;
    is_visit[start] = 1;

    for (int i = 0; i < n; i++) {
        if (i != start && computers[start][i] == 1 && is_visit[i] == 0)
            will_visit.push_back(i);
    }

    for (int i = 0; i < will_visit.size(); i++)
        if (is_visit[will_visit[i]] == 0) dfs(n, computers, will_visit[i]);

    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++)
        if (is_visit[i] == 0) answer += dfs(n, computers, i);

    return answer;
}