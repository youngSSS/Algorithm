#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string &T) {
    vector< pair<int, string >> t_shirts;
    string ans = "";

    for (int i = 0; i < T.size(); i++) {
        char c = T[i];
        string s;
        s += c;

        if (s == "S")
            t_shirts.push_back(make_pair(1, "S"));
        else if (s == "M")
            t_shirts.push_back(make_pair(2, "M"));
        else
            t_shirts.push_back(make_pair(3, "L"));

    }

    sort(t_shirts.begin(), t_shirts.end());

    for (int i = 0; i < T.size(); i++)
        ans += t_shirts[i].second;

    return ans;
}

int main() {
    string a = "MSSLS";
    cout << solution(a);
    return 0;
}
