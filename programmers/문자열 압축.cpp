#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int l = 1; l <= s.length() / 2; l++) {
        string answer_word = "", compress_word = s.substr(0, l);
        int compress_cnt = 1, compress_idx = l;

        while (true) {
            string target_word = s.substr(compress_idx, l);

            if (compress_word == target_word) {
                compress_cnt += 1;
            }
            else {
                if (compress_cnt > 1) answer_word += to_string(compress_cnt);
                answer_word += compress_word;
                compress_word = target_word;
                compress_cnt = 1;
            }

            compress_idx += l;

            if (compress_idx >= s.length()) {
                if (compress_cnt > 1) answer_word += to_string(compress_cnt);
                answer_word += compress_word;
                break;
            }
        }

        if (answer > answer_word.length()) answer = answer_word.length();
    }

    return answer;
}

int main() {
    cout << solution("aabbaccc"	);
    return 0;
}