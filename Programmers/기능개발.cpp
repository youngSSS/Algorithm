#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int ans = 0;
    int start = 0;
    int flag = 0;

    while (start < progresses.size()) {

        for (int i = start; i < progresses.size(); i++)
            progresses[i] += speeds[i];

        while (progresses[start] >= 100 && start < progresses.size()) {
            ans += 1;
            start += 1;
            flag = 1;
        }

        if (flag) {
            answer.push_back(ans);
            ans = 0;
            flag = 0;
        }

    }

    return answer;
}