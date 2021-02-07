#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> map;

    for (int i = 0; i < participant.size(); i++) {
        if (map.find(participant[i]) == map.end()) map[participant[i]] = 1;
        else map[participant[i]]++;
    }

    for (int i = 0; i < completion.size(); i++) {
        if (map[completion[i]] == 1) map.erase(completion[i]);
        else map[completion[i]]--;
    }

    answer = map.begin()->first;

    return answer;
}