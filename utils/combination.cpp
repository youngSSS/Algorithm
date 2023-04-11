#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > answer;

void combination(vector<int> combination_target, vector<int> visit, int depth, int number_to_pick) {
    // CASE: 조합 결과 찾음
    if (number_to_pick == 0) {
        // is_visited 배열의 값이 1인 idx의 combination_target 값들이 조합 결과
        vector<int> temp;
        for (int i = 0; i < combination_target.size(); i++) {
            if (visit[i] == 1) temp.push_back(combination_target[i]);
        }
        answer.push_back(temp);
        return;
    }

    if (depth == combination_target.size()) return;
    else {
        visit[depth] = 1;
        combination(combination_target, visit, depth + 1, number_to_pick - 1);

        visit[depth] = 0;
        combination(combination_target, visit, depth + 1, number_to_pick);
    }
}

int main() {
    combination({1, 2, 3, 4}, {0, 0, 0, 0}, 0, 3);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }
}