#include <vector>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

bool min_check(vector<int> answer, int comb) {
    for (auto used_comb : answer) {
        if ((used_comb & comb) == used_comb) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> answer;
    int tuple_cnt = relation.size();
    int attr_cnt = relation[0].size();

    for (int comb = 1; comb < pow(2, attr_cnt); comb++) {
        set<string> s;

        for (int x = 0; x < tuple_cnt; x++) {
            string value = "";
            for (int y = 0; y < attr_cnt; y++) {
                if (comb & (1 << y)) value += relation[x][y];
            }
            s.insert(value);
        }

        if (s.size() == tuple_cnt && min_check(answer, comb))
            answer.push_back(comb);
    }


    return answer.size();
}

int main() {
    cout << solution({{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}});
    return 0;
}