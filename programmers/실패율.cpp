#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer, check(501, 0);
    vector<pair<float, int>> ans;

    sort(stages.begin(), stages.end());

    int count = 1;
    int done = 0;
    for (int i = 0; i < stages.size(); i++) {
        int now, next;
        if (i == stages.size() - 1) {
            now = stages[i];
            next = stages[i - 1];
        }
        else {
            now = stages[i];
            next = stages[i + 1];
        }

        if (now == N + 1) break;

        if (now == next) {
            count += 1;
            if (i == stages.size() - 1)
                ans.push_back(make_pair((float) -count / (stages.size() - done), now));
        }
        else {
            ans.push_back(make_pair((float) -count / (stages.size() - done), now));
            done += count;
            count = 1;
        }
    }

    sort(ans.begin(), ans.end());

    for (auto a : ans) {
        check[a.second] = 1;
        answer.push_back(a.second);
    }

    for (int i = 1; i < N + 1; i++) {
        if (check[i] == 0) answer.push_back(i);
    }

    return answer;
}

int main() {
    solution(1, {1});
    return 0;
}