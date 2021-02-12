#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int yellow_row, yellow_col;
    int target;

    target = (brown - 4) / 2;

    for (int i = 1; i <= target / 2; i++) {
        yellow_row = i;
        yellow_col = target - i;
        if (yellow_row * yellow_col == yellow) break;
    }

    answer.push_back(yellow_col + 2);
    answer.push_back(yellow_row + 2);

    return answer;
}