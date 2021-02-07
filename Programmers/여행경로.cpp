#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map < string, queue<string> > path;
unordered_map < string, priority_queue < string, vector<string>, greater<string> > > temp_path;
vector<string> answer;

int dfs(string start, int ticket_cnt) {
    string dest;

    if (ticket_cnt == 0) return 0;

    while (!path[start].empty()) {
        dest = path[start].front();
        path[start].pop();
    
        answer.push_back(dest);
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << " ";
        cout << endl;
        if (dfs(dest, ticket_cnt - 1) == 0)
            return 0;

        answer.erase(answer.begin() + answer.size() - 1);
        path[start].push(dest);
    }
    
    return 1;
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map < string, priority_queue < string, vector<string>, greater<string> > >::iterator iter;

    for (int i = 0; i < tickets.size(); i++) 
        temp_path[tickets[i][0]].push(tickets[i][1]);

    for (iter = temp_path.begin(); iter != temp_path.end(); iter++) {
        while (!iter->second.empty()) {
            path[iter->first].push(iter->second.top());
            iter->second.pop();
        }
    }

    answer.push_back("ICN");
    dfs("ICN", tickets.size());

    return answer;
}