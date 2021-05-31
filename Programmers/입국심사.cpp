#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    long long min = 1, middle, max;

    sort(times.begin(), times.end());
    max = times[times.size() - 1] * n;
    answer = max;

    while (true) {
        long long count = 0;
        middle = (min + max) / 2;

        for (auto time : times)
            count += middle / time;

        if (count < n) {
            if (min == middle) min += 1;
            else min = middle;
        }
        else if (count > n) {
            if (max == middle) max -= 1;
            else max = middle;
            answer = (answer > middle) ? middle : answer;
        }
        else {
            answer = (answer > middle) ? middle : answer;
            max = middle;
        }

        if (min > max || middle == (min + max) / 2) break;
    }

    return answer;
}

int main() {
    cout << solution(2, {1, 2});
}