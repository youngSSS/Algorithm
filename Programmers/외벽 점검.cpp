#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    vector< vector<int> > dist_permutation;

    int weak_size = weak.size();
    for (int i = 0; i < weak_size; i++)
        weak.push_back(weak[i] + n);

    sort(weak.begin(), weak.end());

    dist_permutation.push_back(dist);
    while (next_permutation(dist.begin(), dist.end()))
        dist_permutation.push_back(dist);

    for (vector<int> permutation : dist_permutation) {
        for (int i = 0; i < weak_size; i++) {
            int start = weak[i];
            int end = weak[i + weak_size - 1];

            for (int j = 0; j < permutation.size(); j++) {
                int ability = permutation[j];
                int next_pos = start + ability;

                if (next_pos >= end) {
                    answer = answer > j + 1 ? j + 1 : answer;
                    break;
                }

                start = weak[upper_bound(weak.begin(), weak.end(), next_pos) - weak.begin()];
            }
        }
    }

    if (answer == 1e9) return -1;

    return answer;
}

int main() {
    cout << solution(12, {1, 5, 6, 10}, {1, 2, 3, 4});
    return 0;
}