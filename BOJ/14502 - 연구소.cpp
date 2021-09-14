#include <stdio.h>
#include <iostream>

using namespace std;

int N, M, _max = 0;
int zero_cnt = 0, two_cnt = 0;
int map[9][9] = {0, };
int zero_pos_row[65], zero_pos_col[65];
int two_pos_row[65], two_pos_col[65];

int temp_zero_cnt;
int temp_map[9][9];

void virus(int, int);
void* memcpy(void *dest, void *src, size_t count) {
    for (size_t i = 0; i < count; i++)
        *((char*)dest + i) = *((char*)src + i);
    return dest;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 0) {
                zero_pos_row[zero_cnt] = i;
                zero_pos_col[zero_cnt] = j;
                zero_cnt++;
            }
            else if (map[i][j] == 2) {
                two_pos_row[two_cnt] = i;
                two_pos_col[two_cnt] = j;
                two_cnt++;
            }
        }
    }

    for (int i = 0; i < zero_cnt; i++) {
        map[zero_pos_row[i]][zero_pos_col[i]] = 1;

        for (int j = i + 1; j < zero_cnt; j++) {
            map[zero_pos_row[j]][zero_pos_col[j]] = 1;

            for (int k = j + 1; k < zero_cnt; k++) {
                map[zero_pos_row[k]][zero_pos_col[k]] = 1;

                memcpy(temp_map, map, sizeof(map));
                temp_zero_cnt = zero_cnt;

                for (int n = 0; n < two_cnt; n++)
                    virus(two_pos_row[n], two_pos_col[n]);
                if (temp_zero_cnt > _max)
                    _max = temp_zero_cnt;

                map[zero_pos_row[k]][zero_pos_col[k]] = 0;
            }
            map[zero_pos_row[j]][zero_pos_col[j]] = 0;
        }
        map[zero_pos_row[i]][zero_pos_col[i]] = 0;
    }

    printf("%d", _max - 3);

    return 0;
}

void virus(int x, int y) {
    // up
    if (x - 1 > 0) {
        if (temp_map[x - 1][y] == 0) {
            temp_map[x - 1][y] = 2;
            temp_zero_cnt--;
            virus(x - 1, y);
        }
    }

    // down
    if (x + 1 <= N) {
        if (temp_map[x + 1][y] == 0) {
            temp_map[x + 1][y] = 2;
            temp_zero_cnt--;
            virus(x + 1, y);
        }
    }

    // right
    if (y + 1 <= M) {
        if (temp_map[x][y + 1] == 0) {
            temp_map[x][y + 1] = 2;
            temp_zero_cnt--;
            virus(x, y + 1);
        }
    }

    // left
    if (y - 1 > 0) {
        if (temp_map[x][y - 1] == 0) {
            temp_map[x][y - 1] = 2;
            temp_zero_cnt--;
            virus(x, y - 1);
        }
    }
}