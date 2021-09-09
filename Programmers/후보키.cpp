#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> keys;

void combination(vector<string> combination_target, vector<int> visit, int depth, int number_to_pick) {
    if (number_to_pick == 0) {
        string temp;
        for (int i = 0; i < combination_target.size(); i++) {
            if (visit[i] == 1) temp += combination_target[i];
        }
        keys.push_back(temp);
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

int solution(vector<vector<string>> relation) {
    unordered_map<string, int> map;
    unordered_map<int, unordered_map<int, int>> dup_check;
    int total_key_count = 0;

    for (vector<string> r : relation) {
        int temp_total_key_count = 0;

        for (int i = 1; i <= r.size(); i++) {
            vector<int> visit(r.size(), 0);
            keys.clear();
            combination(r, visit, 0, i);

            for (int j = 0; j < keys.size(); j++) {
                string key = keys[j];

                if (total_key_count == 0) temp_total_key_count += 1;

                map[key] += 1;

                if (map[key] > 1 && dup_check[i][j] == 0) {
                    dup_check[i][j] = 1;
                    total_key_count -= 1;
                }
            }

            for (auto a : keys) {
                cout << a << " ";
//                cout << "(" << dup_check[a] << ")" << " ";
            }

            cout << endl;
        }

        if (total_key_count == 0)
            total_key_count = temp_total_key_count;
        cout << total_key_count << endl;

    }

    return total_key_count;
}

int main() {
    cout << solution({{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}});
    return 0;
}