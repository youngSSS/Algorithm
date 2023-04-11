#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string banned = "~!@#$%^&*()=+[{]}:?,<>/";
    ssize_t pos;

    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    for (char c : banned) {
        while ((pos = new_id.find(c)) != string::npos)
            new_id = new_id.substr(0, pos) + new_id.substr(pos + 1);
    }

    while ((pos = new_id.find("..")) != string::npos)
        new_id = new_id.substr(0, pos) + new_id.substr(pos + 1);

    if (new_id[0] == '.') new_id = new_id.substr(1);
    if (new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);

    if (new_id.length() == 0) new_id = "a";

    if (new_id.length() > 15) {
        if (new_id[14] == '.') new_id = new_id.substr(0, 14);
        else new_id = new_id.substr(0, 15);
    }

    while (new_id.length() < 3)
        new_id += new_id[new_id.length() - 1];

    return new_id;
}

int main() {
    cout << solution("...!@BaT#*..y.abcdefghijklm");
    return 0;
}