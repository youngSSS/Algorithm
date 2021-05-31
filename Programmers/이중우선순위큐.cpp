#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> data;

    for (auto cmd : operations) {

        if (cmd[0] == 'I') {
            int value = stoi(cmd.substr(2, cmd.size()));
            data.push_back(value);
            sort(data.begin(), data.end());
        }

        else if (cmd[0] == 'D' && cmd[2] == '1') {
            if (!data.empty()) data.pop_back();
        }

        else {
            if (!data.empty()) data.erase(data.begin());
        }

    }

    if (data.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }

    else {
        answer.push_back(data[data.size() - 1]);
        answer.push_back(data[0]);
    }

    return answer;
}