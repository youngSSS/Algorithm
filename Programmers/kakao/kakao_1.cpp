#include <string>
#include <vector>
#include <iostream>

using namespace std;

string eng[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string num[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < 10; i++) {
        int pos = 0;
        while ( (pos = s.find(eng[i], pos)) != string::npos ) {
            s.replace(pos, eng[i].length(), num[i]);
            pos += 1;
        }
    }
    return stoi(s);
}