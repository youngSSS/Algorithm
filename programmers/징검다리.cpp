#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 1e9;
    int left = 1, right = distance;

    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    while (left <= right) {
        int mid = (left + right) / 2;
        int start = 0, end = 1, rock_cnt = 0;

        while (end < rocks.size()) {
            int gap = rocks[end] - rocks[start];

            if (gap >= mid) start = end;
            else rock_cnt += 1;

            end += 1;
        }

        if (start + 1 != end) rock_cnt -= 1;

        if (rock_cnt > n) right = mid - 1;
        else {
            left = mid + 1;
            answer = mid;
        }
    }

    return answer;
}

int main() {
    cout << solution(25, {2, 14, 11, 21, 17}, 2);
    return 0;
}