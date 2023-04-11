#include <string>
#include <vector>
#include <queue>

using namespace std;
using piii = pair< int, pair<int, int> >;

vector<int> update_table(int a, int b, vector<int> cycle_table) {
    int update_value, target_value;

    if (a < b) {
        update_value = cycle_table[a];
        target_value = cycle_table[b];
    }
    else {
        update_value = cycle_table[b];
        target_value = cycle_table[a];
    }

    for (int & i : cycle_table) {
        if (i == target_value) i = update_value;
    }

    return cycle_table;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue< piii, vector<piii>, greater<piii> > cost_list;
    vector<int> cycle_table;
    int region_a, region_b, cost;

    cycle_table.resize(n);
    for (int i = 0; i < n; i++)
        cycle_table[i] = i;

    for (int i = 0; i < costs.size(); i++)
        cost_list.push(make_pair(costs[i][2], make_pair(costs[i][0], costs[i][1])));

    while (!cost_list.empty()) {
        piii temp = cost_list.top();
        cost = temp.first;
        region_a = temp.second.first;
        region_b = temp.second.second;
        cost_list.pop();

        if (cycle_table[region_a] != cycle_table[region_b]) {
            answer += cost;
            cycle_table = update_table(region_a, region_b, cycle_table);
        }
    }

    return answer;
}