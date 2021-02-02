#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int word_len = begin.size();
    int is_visit[50] = {0, };
    int exist_flag = 0;
    queue< int > Q;
    string temp_begin, comp;

    for (int i = 0; i < word_len; i++) {
        temp_begin = begin;
        temp_begin.erase(i, 1);

        for (int j = 0; j < words.size(); j++) {
            if (target == words[j]) exist_flag = 1;

            comp = words[j];
            comp.erase(i, 1);

            if (temp_begin == comp) {
                Q.push(j);
                is_visit[j] = 1;
            }
        }

        // No Answer
        if (exist_flag == 0) return 0;
    }

    while (!Q.empty()) {

        int word_idx;
        int q_size = Q.size();
        answer++;

        while (q_size != 0) {
            word_idx = Q.front();
            Q.pop();
            q_size--;

            if (target == words[word_idx]) return answer;

            for (int i = 0; i < word_len; i++) {
                temp_begin = words[word_idx];
                temp_begin.erase(i, 1);

                for (int j = 0; j < words.size(); j++) {
                    if (is_visit[j] == 0) {
                        comp = words[j];
                        comp.erase(i, 1);

                        if (temp_begin == comp) {
                            Q.push(j);
                            is_visit[j] = 1;
                        }
                    }
                }
            }
        }

    }

    return answer;
}