#include <stdio.h>

int N, M;
int map[51][51] = {0, };
int house_cnt;
int house_x[100], house_y[100];
int chicken_cnt = 0;
int chicken_x[13], chicken_y[13];
int open_x[13], open_y[13];
int is_visited[13] = {0, };
int min_dist = 10000000;

void pick_chicken(int cnt, int pos);
void chicken_distance();

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                house_x[house_cnt] = i;
                house_y[house_cnt] = j;
                house_cnt++;
            }
            else if (map[i][j] == 2) {
                chicken_x[chicken_cnt] = i;
                chicken_y[chicken_cnt] = j;
                chicken_cnt++;
            }
        }
    }

    pick_chicken(0, 0);

    printf("%d", min_dist);

    return 0;
}

void pick_chicken(int cnt, int pos) {
    if (cnt == M) {
        chicken_distance();
        return;
    }

    for (int i = pos; i < chicken_cnt; i++) {
        if (is_visited[i] == 0) {
            open_x[cnt] = chicken_x[i];
            open_y[cnt] = chicken_y[i];
            is_visited[i] = 1;
            pick_chicken(cnt + 1, i + 1);
            is_visited[i] = 0;
        }
    }
}

void chicken_distance() {
    int temp_min_final = 0;
    for (int i = 0; i < house_cnt; i++) {
        int temp_min = 10000000;
        for (int j = 0; j < M; j++) {
            int temp_x, temp_y;
            if (house_x[i] > open_x[j]) temp_x = house_x[i] - open_x[j];
            else temp_x = open_x[j] - house_x[i];
            if (house_y[i] > open_y[j]) temp_y = house_y[i] - open_y[j];
            else temp_y = open_y[j] - house_y[i];

            if (temp_min > temp_x + temp_y) temp_min = temp_x + temp_y;
        }
        temp_min_final += temp_min;
    }
    if (min_dist > temp_min_final) min_dist = temp_min_final;
}