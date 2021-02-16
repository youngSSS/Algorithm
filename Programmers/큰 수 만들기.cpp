#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start = 0;
    int target_idx, target_value;
    int eliminate_cnt;

    while (k != 0) {
        target_idx = start;
        target_value = number[target_idx];
        for (int i = start + 1; i < start + k + 1; i++) {
            if (target_value < number[i]) {
                target_idx = i;
                target_value = number[target_idx];
            }
        }

        if (start + k + 1 == number.size()) {
            answer.push_back(number[target_idx]);
            k = -1;
            break;
        }

        eliminate_cnt = target_idx - start;
        k -= eliminate_cnt;

        start = target_idx + 1;

        answer.push_back(number[target_idx]);
    }

    if (k == 0) {
        for (int i = start; i < number.size(); i++)
            answer.push_back(number[i]);
    }

    return answer;
}