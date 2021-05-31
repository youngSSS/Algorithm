#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

pii left, right;
unordered_map<int, pii> get_cord;

string get_hand(pii dest, string hand) {
    int left_dist = abs(left.first - dest.first) + abs(left.second - dest.second);
    int right_dist = abs(right.first - dest.first) + abs(right.second - dest.second);

    if (left_dist < right_dist) return "L";
    else if (left_dist > right_dist) return "R";
    else return hand == "left" ? "L" : "R";
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    string dest = "";

    int num = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            get_cord[num] = make_pair(i, j);
            num += 1;
        }
    }
    get_cord[0] = make_pair(3, 1);

    left = make_pair(3, 0);
    right = make_pair(3, 2);

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 2 || numbers[i] == 0) {
            if (get_hand(get_cord[numbers[i]], hand) == "L") {
                left = get_cord[numbers[i]];
                answer += "L";
            }
            else {
                right = get_cord[numbers[i]];
                answer += "R";
            }

        }
        else if (numbers[i] % 3 == 1) {
            left = get_cord[numbers[i]];
            answer += "L";
        }
        else if (numbers[i] % 3 == 0) {
            right = get_cord[numbers[i]];
            answer += "R";
        }
    }

    return answer;
}