#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    vector< pair<int, string> > num_pairs;

    for (auto number : numbers) {
        string temp = to_string(number);
        int add_idx = 0;

        while (temp.length() < 4) {
            temp += temp[add_idx];
            add_idx += 1;
        }

        num_pairs.push_back(make_pair(stoi(temp), to_string(number)));
    }

    sort(num_pairs.begin(), num_pairs.end(), greater<>());

    for (const auto& num_pair : num_pairs)
        answer += num_pair.second;

    if (answer[0] == '0') answer = "0";

    return answer;
}