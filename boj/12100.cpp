#include <stdio.h>

int N, max = 0;
int original_board[21][21];

void* memcpy(void *dest, void *src, size_t count);
void start(int tmp[][21], int);
void up(int tmp[][21], int);
void down(int tmp[][21], int);
void right(int tmp[][21], int);
void left(int tmp[][21], int);

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            scanf("%d", &original_board[i][j]);
    }

    int tmp[21][21];
    memcpy(tmp, original_board, sizeof(original_board));
    start(tmp, 0);

    printf("%d", max);

    return 0;
}

void* memcpy(void *dest, void *src, size_t count){
    for(size_t i = 0; i < count; i++)
        *((char*)dest + i) = *((char*)src + i);
    return dest;
}

void start(int board[21][21], int move_cnt) {
    up(board, move_cnt);
    down(board, move_cnt);
    right(board, move_cnt);
    left(board, move_cnt);
}

// 세로줄 단위로 봐야한다
void up(int tmp[][21], int move_cnt) {
    int temp_max = 0;
    int board[21][21];
    memcpy(board, tmp, sizeof(original_board));

    move_cnt++;

    for (int j = 1; j <= N; j++) {

        // 0 뒤로 빼기
        for (int i = 1; i <= N; i++) {
            if (board[i][j] == 0) {
                if (i + 1 > N)
                    break;

                for (int k = i + 1; k <= N; k++) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            // i가 마지막 블록인 경우
            if (i + 1 > N)
                break;

            // 위 아래가 같은 경우 = 더해지는 경우
            if (board[i][j] == board[i + 1][j]) {
                board[i][j] = board[i][j] * 2;
                board[i + 1][j] = 0;
                i += 1;
            }
        }

        // 0 뒤로 빼기
        for (int i = 1; i <= N; i++) {
            if (board[i][j] == 0) {
                if (i + 1 > N)
                    break;

                for (int k = i + 1; k <= N; k++) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }

        // 제일 큰 값 확인
        for (int i = 1; i <= N; i++) {
            if (board[i][j] > temp_max)
                temp_max = board[i][j];
        }
    }

    if (temp_max > max)
        max = temp_max;

    if (move_cnt == 5)
        return;
    else
        start(board, move_cnt);
}

// 세로줄 단위로 봐야한다
void down(int tmp[][21], int move_cnt) {
    int temp_max = 0;
    int board[21][21];
    memcpy(board, tmp, sizeof(original_board));

    move_cnt++;

    for (int j = 1; j <= N; j++) {

        // 0 뒤로 빼기
        for (int i = N; i >= 1; i--) {
            if (board[i][j] == 0) {
                if (i - 1 < 1)
                    break;

                for (int k = i - 1; k >= 1; k--) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }

        for (int i = N; i >= 1; i--) {
            // i가 마지막 블록인 경우
            if (i - 1 < 1)
                break;

            // 위 아래가 같은 경우 = 더해지는 경우
            if (board[i][j] == board[i - 1][j]) {
                board[i][j] = board[i][j] * 2;
                board[i - 1][j] = 0;
                i -= 1;
            }
        }

        // 0 뒤로 빼기
        for (int i = N; i >= 1; i--) {
            if (board[i][j] == 0) {
                if (i - 1 < 1)
                    break;

                for (int k = i - 1; k >= 1; k--) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }

        // 제일 큰 값 확인
        for (int i = 1; i <= N; i++) {
            if (board[i][j] > temp_max)
                temp_max = board[i][j];
        }
    }

    if (temp_max > max)
        max = temp_max;

    if (move_cnt == 5)
        return;
    else
        start(board, move_cnt);
}

// 가로줄 단위로 봐야한다
void right(int tmp[][21], int move_cnt) {
    int temp_max = 0;
    int board[21][21];
    memcpy(board, tmp, sizeof(original_board));

    move_cnt++;

    for (int i = 1; i <= N; i++) {

        // 0 뒤로 빼기
        for (int j = N; j >= 1; j--) {
            if (board[i][j] == 0) {
                if (j - 1 < 1)
                    break;

                for (int k = j - 1; k >= 1; k--) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }

        for (int j = N; j >= 1; j--) {
            // i가 마지막 블록인 경우
            if (j - 1 < 1)
                break;

            // 위 아래가 같은 경우 = 더해지는 경우
            if (board[i][j] == board[i][j - 1]) {
                board[i][j] = board[i][j] * 2;
                board[i][j - 1] = 0;
                j -= 1;
            }
        }

        // 0 뒤로 빼기
        for (int j = N; j >= 1; j--) {
            if (board[i][j] == 0) {
                if (j - 1 < 1)
                    break;

                for (int k = j - 1; k >= 1; k--) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }

        // 제일 큰 값 확인
        for (int j = 1; j <= N; j++) {
            if (board[i][j] > temp_max)
                temp_max = board[i][j];
        }
    }

    if (temp_max > max)
        max = temp_max;

    if (move_cnt == 5)
        return;
    else
        start(board, move_cnt);
}

// 가로줄 단위로 봐야한다
void left(int tmp[][21], int move_cnt) {
    int temp_max = 0;
    int board[21][21];
    memcpy(board, tmp, sizeof(original_board));

    move_cnt++;

    for (int i = 1; i <= N; i++) {

        // 0 뒤로 빼기
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 0) {
                if (j + 1 > N)
                    break;

                for (int k = j + 1; k <= N; k++) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }

        for (int j = 1; j <= N; j++) {
            // i가 마지막 블록인 경우
            if (j + 1 > N)
                break;

            // 위 아래가 같은 경우 = 더해지는 경우
            if (board[i][j] == board[i][j + 1]) {
                board[i][j] = board[i][j] * 2;
                board[i][j + 1] = 0;
                j += 1;
            }
        }

        // 0 뒤로 빼기
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 0) {
                if (j + 1 > N)
                    break;

                for (int k = j + 1; k <= N; k++) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }

        // 제일 큰 값 확인
        for (int j = 1; j <= N; j++) {
            if (board[i][j] > temp_max)
                temp_max = board[i][j];
        }
    }

    if (temp_max > max)
        max = temp_max;

    if (move_cnt == 5)
        return;
    else
        start(board, move_cnt);
}