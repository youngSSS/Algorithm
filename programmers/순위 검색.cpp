#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> data[3][2][2][2];
    unordered_map<string, int> mapper;

    mapper["cpp"] = 0;
    mapper["java"] = 1;
    mapper["python"] = 2;
    mapper["backend"] = 0;
    mapper["frontend"] = 1;
    mapper["junior"] = 0;
    mapper["senior"] = 1;
    mapper["chicken"] = 0;
    mapper["pizza"] = 1;
    mapper["-"] = 3;

    for (string i : info) {
        vector<int> keys;
        int cur, prev = 0;

        while ((cur = i.find(" ", prev)) != string::npos) {
            keys.push_back(mapper[i.substr(prev, cur - prev)]);
            prev = cur + 1;
        }
        keys.push_back(stoi(i.substr(prev)));

        data[keys[0]][keys[1]][keys[2]][keys[3]].push_back(keys[4]);
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    sort(data[i][j][k][l].begin(), data[i][j][k][l].end());

    for (string q : query) {
        vector<int> keys, values;
        int ans = 0, cur, prev = 0;

        while ((cur = q.find(" ", prev)) != string::npos) {
            string item = q.substr(prev, cur - prev);
            if (item != "and") keys.push_back(mapper[item]);
            prev = cur + 1;
        }
        keys.push_back(stoi(q.substr(prev)));

        int a1 = keys[0], a2 = keys[0];
        int b1 = keys[1], b2 = keys[1];
        int c1 = keys[2], c2 = keys[2];
        int d1 = keys[3], d2 = keys[3];

        if (a1 == 3) {a1 = 0; a2 = 2;}
        if (b1 == 3) {b1 = 0; b2 = 1;}
        if (c1 == 3) {c1 = 0; c2 = 1;}
        if (d1 == 3) {d1 = 0; d2 = 1;}

        for (int i = a1; i <= a2; i++) {
            for (int j = b1; j <= b2; j++) {
                for (int k = c1; k <= c2; k++) {
                    for (int l = d1; l <= d2; l++) {
                        if (data[i][j][k][l].empty()) continue;

                        auto iter = lower_bound(data[i][j][k][l].begin(), data[i][j][k][l].end(), keys[4]);

                        if (iter != data[i][j][k][l].end())
                            ans += data[i][j][k][l].size() - (iter - data[i][j][k][l].begin());
                    }
                }
            }
        }

        answer.push_back(ans);
    }

    return answer;
}

int main() {
    solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"}, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});
    return 0;
}