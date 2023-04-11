#include <string>
#include <vector>

using namespace std;

int change_word(char now, char target) {
    int forward = target - now;
    int backward = now - target + 26;

    if (forward < backward) return forward;
    else return backward;
}

pair<int, int> next_pos(string name, string target_name, int pos) {
    int next_pos_1, next_pos_2;
    int cnt_1 = 0, cnt_2 = 0;

    next_pos_1 = pos;
    while (name[next_pos_1] == target_name[next_pos_1]) {
        next_pos_1 += 1;
        cnt_1++;
        if (next_pos_1 == name.size()) next_pos_1 = 0;
    }

    next_pos_2 = pos;
    while (name[next_pos_2] == target_name[next_pos_2]) {
        next_pos_2 -= 1;
        cnt_2++;
        if (next_pos_2 == -1) next_pos_2 = name.size() - 1;
    }

    if (cnt_1 <= cnt_2) return {next_pos_1, cnt_1};
    else return {next_pos_2, cnt_2};
}

int solution(string name) {
    int answer = 0;
    string initial_name(name.size(), 'A');
    pair<int, int> temp;
    int pos = 0, cnt;

    while (true) {
        answer += change_word(initial_name[pos], name[pos]);
        initial_name[pos] = name[pos];

        if (initial_name == name) break;

        temp = next_pos(initial_name, name, pos);
        pos = temp.first;
        cnt = temp.second;

        answer += cnt;
    }

    return answer;
}