#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long food_length = food_times.size();
    long long clock = 0;
    set<int> s;
    unordered_map<int, int> map;

    for (int f : food_times) {
        s.insert(f);
        map[f] += 1;
    }

    long long total_loop_cnt = 0;
    long long total_food_cnt = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        long long loop_cnt = *iter - total_loop_cnt;
        long long food_cnt = map[*iter];

        total_loop_cnt += loop_cnt;
        total_food_cnt += food_cnt;

        clock += (loop_cnt * food_length);
        food_length -= food_cnt;

        if (clock <= k && total_food_cnt == food_times.size()) return -1;

        if (clock >= k) {
            food_length += food_cnt;
            clock -= (loop_cnt * food_length);

            long long multiply = (k - clock) / food_length;
            long long past_clock = clock + (multiply * food_length);

            int food_idx = 0;
            int clock_cnt = 0;
            while (true) {
                if (food_times[food_idx] >= *iter) {
                    if (past_clock + clock_cnt == k) return food_idx + 1;
                    clock_cnt += 1;
                }
                food_idx += 1;
            }
        }
    }

    return -1;
}

int main() {
    cout << solution({1,1,1,1}, 4);
    return 0;
}