#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map< string, vector<string> > path;
map< string, vector<int> > is_visited;
vector<string> answer;

int dfs(string start, int total_dest_cnt) {
    int dest_cnt = path[start].size();
    int ret_val;

    answer.push_back(start);

    if (answer.size() == total_dest_cnt) return 1;

    for (int i = 0; i < dest_cnt; i++) {
        if (is_visited[start][i] == 0) {
            is_visited[start][i] = 1;
            ret_val = dfs(path[start][i], total_dest_cnt);

            if (ret_val == 1) return 1;

            is_visited[start][i] = 0;
            answer.pop_back();
        }
    }

    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {

    for (auto & ticket : tickets) {
        path[ticket[0]].push_back(ticket[1]);
        is_visited[ticket[0]].push_back(0);
    }

    for (auto & path_item : path)
        sort(path_item.second.begin(), path_item.second.end());

    dfs("ICN", tickets.size() + 1);

    return answer;
}

int main() {
    solution({{"ICN", "A"}, {"A", "B"}, {"A", "C"}, {"C", "A"}, {"B", "D"}});

    for (int  i = 0; i < answer.size(); i++) {
        cout << answer[i] << " " ;
    }
}