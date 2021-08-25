#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

vector<string> combinations;

void combination(string order, vector<int> visit, int depth, int number_to_pick) {
    if (number_to_pick == 0) {
        string temp = "";
        for (int i = 0; i < order.size(); i++) {
            if (visit[i] == 1) temp += order[i];
        }
        combinations.push_back(temp);
        return;
    }

    if (depth == order.size()) return;
    else {
        visit[depth] = 1;
        combination(order, visit, depth + 1, number_to_pick - 1);
        visit[depth] = 0;
        combination(order, visit, depth + 1, number_to_pick);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> map;
    unordered_map<int, priority_queue< pair<int, string> >> answer_map;

    for (auto order : orders) {
        for (auto num_of_course : course) {
            combinations.clear();
            vector<int> visit(order.length(), 0);
            sort(order.begin(), order.end());
            combination(order, visit, 0, num_of_course);
            for (auto comb : combinations) {
                if (map.find(comb) == map.end()) map[comb] = 1;
                else map[comb] += 1;
            }
        }
    }

    for (auto & iter : map) {
        if (iter.second > 1)
            answer_map[iter.first.length()].push(make_pair(iter.second, iter.first));
    }


    for (auto & iter : answer_map) {
        int max = iter.second.top().first;
        while (!iter.second.empty()) {
            if (iter.second.top().first < max) break;
            answer.push_back(iter.second.top().second);
            iter.second.pop();
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}