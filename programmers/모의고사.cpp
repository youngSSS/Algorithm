#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans_cnt[3] = {0, };
    int ans_list[3][10] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int per_1 = 0, per_2 = 0, per_3 = 0;
    int mod_1 = 5, mod_2 = 8, mod_3 = 10;
    int _max = 0;

    for (int i = 0; i < answers.size(); i++, per_1++, per_2++, per_3++) {
        per_1 %= mod_1;
        per_2 %= mod_2;
        per_3 %= mod_3;

        if (answers[i] == ans_list[0][per_1]) ans_cnt[0]++;
        if (answers[i] == ans_list[1][per_2]) ans_cnt[1]++;
        if (answers[i] == ans_list[2][per_3]) ans_cnt[2]++;
    }

    for (int i = 0; i < 3; i++)
        if (ans_cnt[i] > _max) _max = ans_cnt[i];

    for (int i = 0; i < 3; i++)
        if (ans_cnt[i] == _max) answer.push_back(i + 1);

    return answer;
}