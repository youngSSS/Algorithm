#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> rotated_key(key.size());
    vector<int> bit_key[4];
    vector<int> bit_lock;

    for (int i = 0; i < key.size(); i++) {
        for (int j = key.size() - 1; j >= 0; j--)
            rotated_key[i].push_back(key[j][i]);
    }

    for (int i = 0; i < key.size(); i++) {
        int value1 = 0, value2 = 0;
        for (int j = 0; j < key[i].size(); j++) {
            if (key[i][j] == 1) value1 += pow(2, key[i].size() - j - 1);
            if (rotated_key[i][j] == 1) value2 += pow(2, key[i].size() - j - 1);
        }
        bit_key[0].push_back(value1 * pow(2, lock.size() - key.size()));
        bit_key[2].push_back(value2 * pow(2, lock.size() - key.size()));
    }
    for (int i = key.size() - 1; i >= 0; i--) {
        int value1 = 0, value2 = 0;
        for (int j = key[i].size() - 1; j >= 0; j--) {
            if (key[i][j] == 1) value1 += pow(2, j);
            if (rotated_key[i][j] == 1) value2 += pow(2, j);
        }
        bit_key[1].push_back(value1 * pow(2, lock.size() - key.size()));
        bit_key[3].push_back(value2 * pow(2, lock.size() - key.size()));
    }

    for (int i = 0; i < 2 * lock.size() - key.size(); i++) {
        for (int j = 0; j < 4; j++) bit_key[j].push_back(0);
    }

    for (int j = 0; j < lock.size(); j++) {
        int value = 0;
        for (int i = 0; i < lock[j].size(); i++) {
            if (lock[j][i] == 1) value += pow(2, lock.size() - i - 1);
        }
        bit_lock.push_back(value);
    }

    for (auto & i : bit_key) {
        for (int k : i) {
            bitset<3> t(k);
            cout << t << endl;
        }
        cout << endl;
    }

    vector<int> temp[4];
    temp[0] = bit_key[0];
    temp[1] = bit_key[1];
    temp[2] = bit_key[2];
    temp[3] = bit_key[3];
    for (int z = 0; z < key.size() - 1; z++) {
        for (int m = 0; m < 4; m++) {
            temp[m].erase(temp[m].begin());
            temp[m].push_back(0);
        }

        cout << "SDF " << z << endl;
        for (auto & i : temp) {
            for (int k : i) {
                bitset<3> t(k);
                cout << t << endl;
            }
            cout << endl;
        }

        for (int i = 0; i < key.size(); i++) {
            int cnt = 15, rotated_cnt = 15;
            for (int l = 0; l < bit_lock.size(); l++) {
                for (int j = 0; j < 4; j++) {
                    if (((temp[j][l] << i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        cnt &= ~(1 << j);
                    if (((temp[j][l] << i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        rotated_cnt &= ~(1 << j);
                    cout << cnt << " " << rotated_cnt << endl;
                    cout << bitset<4>(cnt) << " " << bitset<4>(rotated_cnt) << endl;
                }
                if (cnt == 0 && rotated_cnt == 0) break;
            }
            if (cnt != 0 || rotated_cnt != 0) {
                cout << "!!!!!" << cnt << " " << rotated_cnt << endl;
                cout << bitset<4>(cnt) << " " << bitset<4>(rotated_cnt) << endl;
                return true;
            }
        }
        for (int i = 0; i < key.size(); i++) {
            int cnt = 15, rotated_cnt = 15;
            for (int l = 0; l < bit_lock.size(); l++) {
                for (int j = 0; j < 4; j++) {
                    if (((temp[j][l] >> i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        cnt &= ~(1 << j);
                    if (((temp[j][l] >> i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        rotated_cnt &= ~(1 << j);
                }
                if (cnt == 0 && rotated_cnt == 0) break;
            }
            if (cnt != 0 || rotated_cnt != 0) return true;
        }
    }

    for (int i = 0; i < key.size(); i++) {
        int cnt = 15, rotated_cnt = 15;
        for (int l = 0; l < bit_lock.size(); l++) {
            for (int j = 0; j < 4; j++) {
                if (((bit_key[j][l] << i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                    cnt &= ~(1 << j);
                if (((bit_key[j][l] << i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                    rotated_cnt &= ~(1 << j);
            }
            if (cnt == 0 && rotated_cnt == 0) break;
        }
        if (cnt != 0 || rotated_cnt != 0) return true;
    }
    for (int i = 0; i < key.size(); i++) {
        int cnt = 15, rotated_cnt = 15;
        for (int l = 0; l < bit_lock.size(); l++) {
            for (int j = 0; j < 4; j++) {
                if (((bit_key[j][l] >> i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                    cnt &= ~(1 << j);
                if (((bit_key[j][l] >> i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                    rotated_cnt &= ~(1 << j);
            }
            if (cnt == 0 && rotated_cnt == 0) break;
        }
        if (cnt != 0 || rotated_cnt != 0) return true;
    }

    for (int z = 0; z < lock.size(); z++) {
        for (int m = 0; m < 4; m++)
            bit_key[m].insert(bit_key[m].begin(), 0);

        for (int i = 0; i < key.size(); i++) {
            int cnt = 15, rotated_cnt = 15;
            for (int l = 0; l < bit_lock.size(); l++) {
                for (int j = 0; j < 4; j++) {
                    if (((bit_key[j][l] << i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        cnt &= ~(1 << j);
                    if (((bit_key[j][l] << i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        rotated_cnt &= ~(1 << j);
                }
                if (cnt == 0 && rotated_cnt == 0) break;
            }
            if (cnt != 0 || rotated_cnt != 0) return true;
        }
        for (int i = 0; i < key.size(); i++) {
            int cnt = 15, rotated_cnt = 15;
            for (int l = 0; l < bit_lock.size(); l++) {
                for (int j = 0; j < 4; j++) {
                    if (((bit_key[j][l] >> i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        cnt &= ~(1 << j);
                    if (((bit_key[j][l] >> i) ^ bit_lock[l]) != pow(2, bit_lock.size()) - 1)
                        rotated_cnt &= ~(1 << j);
                }
                if (cnt == 0 && rotated_cnt == 0) break;
            }
            if (cnt != 0 || rotated_cnt != 0) return true;
        }
    }

    return false;
}

int main() {
    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    return 0;
}