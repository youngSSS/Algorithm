#include <vector>
#include <iostream>

using namespace std;

vector< vector< vector<int> > > rotate_key(vector<vector<int>> key) {
    vector< vector< vector<int> > > result;
    int key_size = key.size();
    result.push_back(key);

    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < key_size; x++) {
            for (int y = 0; y < key_size; y++) {
                int nx = -y + key_size - 1;
                int ny = x;
                key[nx][ny] = result[i][x][y];
            }
        }
        result.push_back(key);
    }

    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int k_size = key.size();
    int l_size = lock.size();
    int ans_cnt = 0;
    vector< vector< vector<int> > > keys = rotate_key(key);
    vector< vector<int> > extended_lock(2 * k_size + l_size - 2, vector<int>(2 * k_size + l_size - 2, 2));

    for (int x = k_size - 1; x < k_size - 1 + l_size; x++) {
        for (int y = k_size - 1; y < k_size - 1 + l_size; y++)
            extended_lock[x][y] = lock[x - k_size + 1][y - k_size + 1];
    }

    for (const auto& lock_row : lock) {
        for (auto l : lock_row)
            if (l == 0) ans_cnt += 1;
    }

    for (auto k : keys) {
        int lx_start = 0;
        int ly_start = 0;

        while (lx_start + (k_size - 1) < extended_lock.size()) {
            while (ly_start + (k_size - 1) < extended_lock.size()) {

                int cnt = 0;
                for (int x = 0; x < k_size; x++) {
                    for (int y = 0; y < k_size; y++) {
                        if (k[x][y] == 1 && extended_lock[lx_start + x][ly_start + y] == 0) cnt += 1;
                        else if (k[x][y] == 1 && extended_lock[lx_start + x][ly_start + y] == 1) {
                            cnt = -1;
                            break;
                        }
                    }

                    if (cnt == -1) break;
                }

                if (cnt == ans_cnt) return true;

                ly_start += 1;
            }

            lx_start += 1;
            ly_start = 0;
        }
    }

    return false;
}

int main() {
    cout << solution({{0, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    return 0;
}