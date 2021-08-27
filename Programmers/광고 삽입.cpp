#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<int> time(360000, 0);
    queue<int> q;
    int play = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
    int adv = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));
    long long sum = 0, max;

    for (string log : logs) {
        int h1 = stoi(log.substr(0, 2));
        int m1 = stoi(log.substr(3, 2));
        int s1 = stoi(log.substr(6, 2));
        int h2 = stoi(log.substr(9, 2));
        int m2 = stoi(log.substr(12, 2));
        int s2 = stoi(log.substr(15, 2));

        int log_start = h1 * 3600 + m1 * 60 + s1;
        int log_end = h2 * 3600 + m2 * 60 + s2;

        for (int i = log_start; i < log_end; i++)
            time[i] += 1;
    }

    for (int i = 0; i < adv; i++) {
        sum += time[i];
        q.push(i);
    }
    max = sum;

    int pos = 0;
    for (int i = adv; i < play; i++) {
        sum -= time[q.front()];
        sum += time[i];
        q.pop();
        q.push(i);

        if (sum > max) {
            max = sum;
            pos = i - adv + 1;
        }
    }

    int s = pos % 60; pos /= 60;
    int m = pos % 60; pos /= 60;
    int h = pos;

    if (h < 10) answer += "0";
    answer += to_string(h);
    answer += ":";

    if (m < 10) answer += "0";
    answer += to_string(m);
    answer += ":";

    if (s < 10) answer += "0";
    answer += to_string(s);

    return answer;
}

int main() {
    cout << solution("50:00:00", "50:00:00", {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"});
    return 0;
}