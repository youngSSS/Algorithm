#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string p) {

    if (p.empty()) return "";

    string answer = "";
    string u = "", v = "";
    int open_cnt = 0, close_cnt = 0;
    int valid_flag = 1;

    int idx = 0;
    while (true) {
        if (p[idx] == '(') open_cnt += 1;
        else close_cnt += 1;
        if (open_cnt != close_cnt) idx += 1;
        else break;
    }

    u = p.substr(0, idx + 1);
    v = p.substr(idx + 1);

    for (char c : u) {
        if (c == '(') open_cnt -= 1;
        else close_cnt -= 1;
        if (open_cnt > close_cnt) {
            valid_flag = 0;
            break;
        }
    }

    if (valid_flag == 1) {
        answer = u + solution(v);
    }
    else {
        answer = "(" + solution(v) + ")";
        u = u.substr(1, u.length() - 2);
        for (char & c : u) {
            if (c == '(') c = ')';
            else c = '(';
        }
        answer += u;
    }

    return answer;
}