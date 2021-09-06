#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid;
    unordered_map<string, string> map;

    for (string r : record) {
        vector<string> items;
        string temp;
        stringstream ss(r);

        while (getline(ss, temp, ' '))
            items.push_back(temp);

        if (items[0] == "Enter") {
            map[items[1]] = items[2];
            uid.push_back(items[1]);
            answer.push_back("님이 들어왔습니다.");
        }
        else if (items[0] == "Leave") {
            uid.push_back(items[1]);
            answer.push_back("님이 나갔습니다.");
        }
        else map[items[1]] = items[2];
    }

    for (int i = 0; i < answer.size(); i++)
        answer[i] = map[uid[i]] + answer[i];

    return answer;
}

int main() {

}