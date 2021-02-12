#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 0 - 일반학생 & lost 학생, 1 - reserve 학생
    int students[31] = {0, };
    int answer = 0;
    vector<int> real_lost;

    for (int i = 0; i < reserve.size(); i++)
        students[reserve[i]] = 1;

    for (int i = 0; i < lost.size(); i++) {
        if (students[lost[i]] == 1) students[lost[i]] = 0;
        else real_lost.push_back(lost[i]);
    }

    for (int i = 0; i < real_lost.size(); i++) {
        int front = real_lost[i] - 1;
        int back = real_lost[i] + 1;

        if (0 < front && students[front] == 1){
            students[front] = 0;
            answer++;
        }
        else if (back <= n && students[back] == 1) {
            students[back] = 0;
            answer++;
        }
    }

    answer += n - real_lost.size();

    return answer;
}

#include <iostream>

int main() {
    cout << solution(3, {1, 2}, {2, 3});
}