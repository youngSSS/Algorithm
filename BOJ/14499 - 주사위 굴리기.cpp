#include <stdio.h>

int N, M, x, y, K;
int map[20][20] = {0, };
int command[1000];
int cube_num[6] = {0, };
char cube_dir[6] = {'U', 'D', 'F', 'B', 'L', 'R'};


int move_check(int move_dir);
void move(int move_dir);

int main() {
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);

    for(int i = 0; i < K; i++)
        scanf("%d", &command[i]);

    for (int i = 0; i < K; i++) {
        if (move_check(command[i])) {
            move(command[i]);
        }
    }

    return 0;
}

int move_check(int move_dir) {
    if (move_dir == 1) {
        if (y + 1 < M) {
            y += 1;
            return 1;
        }
    }
    else if (move_dir == 2) {
        if (y - 1 >= 0) {
            y -= 1;
            return 1;
        }
    }
    else if (move_dir == 3) {
        if (x - 1 >= 0) {
            x -= 1;
            return 1;
        }
    }
    else if (move_dir == 4) {
        if (x + 1 < N) {
            x += 1;
            return 1;
        }
    }

    return 0;
}

void move(int move_dir) {
    // East
    if (move_dir == 1) {
        for (int i = 0; i < 6; i++) {
            if (cube_dir[i] == 'U')
                cube_dir[i] = 'R';
            else if (cube_dir[i] == 'D')
                cube_dir[i] = 'L';
            else if (cube_dir[i] == 'L') {
                cube_dir[i] = 'U';
                printf("%d\n", cube_num[i]);
            }
            else if (cube_dir[i] == 'R') {
                cube_dir[i] = 'D';
                if (map[x][y] == 0)
                    map[x][y] = cube_num[i];
                else {
                    cube_num[i] = map[x][y];
                    map[x][y] = 0;
                }
            }
        }
    }

        // West
    else if (move_dir == 2) {
        for (int i = 0; i < 6; i++) {
            if (cube_dir[i] == 'U')
                cube_dir[i] = 'L';
            else if (cube_dir[i] == 'D')
                cube_dir[i] = 'R';
            else if (cube_dir[i] == 'L'){
                cube_dir[i] = 'D';
                if (map[x][y] == 0)
                    map[x][y] = cube_num[i];
                else {
                    cube_num[i] = map[x][y];
                    map[x][y] = 0;
                }
            }
            else if (cube_dir[i] == 'R'){
                cube_dir[i] = 'U';
                printf("%d\n", cube_num[i]);
            }
        }
    }

        // North
    else if (move_dir == 3) {
        for (int i = 0; i < 6; i++) {
            if (cube_dir[i] == 'U')
                cube_dir[i] = 'B';
            else if (cube_dir[i] == 'D')
                cube_dir[i] = 'F';
            else if (cube_dir[i] == 'F'){
                cube_dir[i] = 'U';
                printf("%d\n", cube_num[i]);
            }
            else if (cube_dir[i] == 'B'){
                cube_dir[i] = 'D';
                if (map[x][y] == 0)
                    map[x][y] = cube_num[i];
                else {
                    cube_num[i] = map[x][y];
                    map[x][y] = 0;
                }
            }
        }
    }

        // South
    else if (move_dir == 4) {
        for (int i = 0; i < 6; i++) {
            if (cube_dir[i] == 'U')
                cube_dir[i] = 'F';
            else if (cube_dir[i] == 'D')
                cube_dir[i] = 'B';
            else if (cube_dir[i] == 'F'){
                cube_dir[i] = 'D';
                if (map[x][y] == 0)
                    map[x][y] = cube_num[i];
                else {
                    cube_num[i] = map[x][y];
                    map[x][y] = 0;
                }
            }
            else if (cube_dir[i] == 'B'){
                cube_dir[i] = 'U';
                printf("%d\n", cube_num[i]);
            }
        }
    }
}