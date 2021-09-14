#include <stdio.h>

int N, M, ans = 1;
int map[50][50] = {0, };
int robot_x, robot_y, robot_dir;
int is_cleaned[50][50] = {0, };

void clean();
int rotation(int);
int go_back(int);
int clean_left(int);

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &robot_x, &robot_y, &robot_dir);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);
    }

    is_cleaned[robot_x][robot_y] = 1;
    clean();

    printf("%d", ans);

    return 0;
}

void clean() {
    // rotation count
    int r_cnt = 0;

    while(true) {
        // direction after rotation
        int left_dir = rotation(robot_dir);

        // Case : clean up left side
        if (clean_left(left_dir))
            r_cnt = 0;

            // Case : just rotate
        else {
            robot_dir = left_dir;
            r_cnt += 1;

            if (r_cnt == 4) {
                // Case : backward
                if (go_back(robot_dir))
                    r_cnt = 0;

                    // Case : end
                else break;
            }
        }
    }
}

int rotation(int dir) {
    if (dir == 0) return 3;
    else if (dir == 1) return 0;
    else if (dir == 2) return 1;
    else if (dir == 3) return 2;
}

int go_back(int dir) {
    if (dir == 0) {
        if (robot_x + 1 < N && map[robot_x + 1][robot_y] == 0) {
            robot_x += 1;
            return 1;
        }
    }
    else if (dir == 1) {
        if (robot_y - 1 >= 0 && map[robot_x][robot_y - 1] == 0){
            robot_y -= 1;
            return  1;
        }
    }
    else if (dir == 2) {
        if (robot_x - 1 >= 0 && map[robot_x - 1][robot_y] == 0){
            robot_x -= 1;
            return 1;
        }
    }
    else if (dir == 3) {
        if (robot_y + 1 < M && map[robot_x][robot_y + 1] == 0){
            robot_y += 1;
            return 1;
        }
    }

    return 0;
}

int clean_left(int dir) {
    if (dir == 0) {
        if (robot_x - 1 >= 0 && map[robot_x - 1][robot_y] == 0 && is_cleaned[robot_x - 1][robot_y] == 0) {
            robot_dir = dir;
            robot_x = robot_x - 1;
            is_cleaned[robot_x][robot_y] = 1;
            ans++;
            return 1;
        }
    }
    else if (dir == 1) {
        if (robot_y + 1 < M && map[robot_x][robot_y + 1] == 0 && is_cleaned[robot_x][robot_y + 1] == 0){
            robot_dir = dir;
            robot_y = robot_y + 1;
            is_cleaned[robot_x][robot_y] = 1;
            ans++;
            return 1;
        }
    }
    else if (dir == 2) {
        if (robot_x + 1 < N && map[robot_x + 1][robot_y] == 0 && is_cleaned[robot_x + 1][robot_y] == 0){
            robot_dir = dir;
            robot_x = robot_x + 1;
            is_cleaned[robot_x][robot_y] = 1;
            ans++;
            return 1;
        }
    }
    else if (dir == 3) {
        if (robot_y - 1 >= 0 && map[robot_x][robot_y - 1] == 0 && is_cleaned[robot_x][robot_y - 1] == 0){
            robot_dir = dir;
            robot_y = robot_y - 1;
            is_cleaned[robot_x][robot_y] = 1;
            ans++;
            return 1;
        }
    }

    return 0;
}