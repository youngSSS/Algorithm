#include <stdio.h>

int N;
int info_x[20], info_y[20], info_d[20], info_g[20];
int map[101][101] = {0, };
int dragon_x[11000], dragon_y[11000];
int start_x, start_y, end_x, end_y;
int point_cnt;
int max_x = 0, max_y = 0;
int ans = 0;

void dragon(int);
void check_max(int x, int y);
void zero_generation(int turn);
void add_point(int x, int y);
void calculate();

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d %d %d %d", &info_x[i], &info_y[i], &info_d[i], &info_g[i]);

    for (int i = 0; i < N; i++) {
        point_cnt = 0;

        // start point
        start_x = info_x[i];
        start_y = info_y[i];
        end_x = start_x;
        end_y = start_y;

        add_point(start_x, start_y);

        // make zero generation line
        zero_generation(i);

        // make dragon curve
        dragon(info_g[i]);
    }

    calculate();

    return 0;
}

void calculate() {
    for (int j = 0; j < max_y; j++) {
        for (int i = 0; i < max_x; i++) {
            if (map[j][i] != 0 && map[j][i + 1] != 0) {
                if (map[j + 1][i] != 0 && map[j + 1][i + 1] != 0)
                    ans++;
            }
        }
    }
    printf("%d", ans);
}

void check_max(int x, int y) {
    if (x > max_x) max_x = x;
    if (y > max_y) max_y = y;
}

void dragon(int generation) {
    for (int i = 1; i <= generation; i++) {
        int n_end_x, n_end_y;
        int temp_point_cnt = point_cnt;

        for (int j = 0; j < temp_point_cnt; j++) {
            int x = dragon_x[j];
            int y = dragon_y[j];

            if (x != end_x || y != end_y) {
                int temp_x = x - end_x;
                int temp_y = y - end_y;

                x = -temp_y + end_x;
                y = temp_x + end_y;

                add_point(x, y);

                if (temp_x + end_x == start_x && temp_y + end_y == start_y) {
                    n_end_x = x;
                    n_end_y = y;
                }
            }
        }

        end_x = n_end_x;
        end_y = n_end_y;
    }
}

void zero_generation(int turn) {
    if (info_d[turn] == 0) end_x = start_x + 1;
    else if (info_d[turn] == 1)  end_y = start_y - 1;
    else if (info_d[turn] == 2)  end_x = start_x - 1;
    else if (info_d[turn] == 3)  end_y = start_y + 1;

    add_point(end_x, end_y);
}

void add_point(int x, int y) {
    map[y][x]++;
    dragon_x[point_cnt] = x;
    dragon_y[point_cnt] = y;
    point_cnt++;
    check_max(x, y);
}