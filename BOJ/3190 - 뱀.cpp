#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 100

int N, K, L;
int map[102][102] = {0, };
int row = 1, col = 1;
int dir_time[100];
char dir_trans[100];

int game_start();
int move(char);
char rotation(char dir, char rotate);

int front = -1;
int rear = -1;
int snake_row[MAX], snake_col[MAX];

int IsEmpty() {
    if (front == rear)
        return true;
    else
        return false;
}
int IsFull(){
    int tmp = (rear + 1) % MAX;
    if (tmp == front)
        return true;
    else
        return false;
}
void enqueue(int row, int col){
    if (IsFull())
        printf("Queue is Full.\n");
    else {
        rear = (rear + 1) % MAX;
        snake_row[rear] = row;
        snake_col[rear] = col;
    }
}
int dequeue_row(){
    if (IsEmpty())
        printf("Queue is Empty.\n");
    else {
        //front = (front + 1) % MAX;
        return snake_row[(front + 1) % MAX];
    }
}
int dequeue_col(){
    if (IsEmpty())
        printf("Queue is Empty.\n");
    else {
        front = (front + 1) % MAX;
        return snake_col[front];
    }
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= N + 1; i++) {
        map[i][0] = 1;
        map[i][N + 1] = 1;
        map[0][i] = 1;
        map[N + 1][i] = 1;
        map[1][1] = 1;
    }

    for (int i = 0; i < K; i++) {
        int tmp_row, tmp_col;
        scanf("%d %d", &tmp_row, &tmp_col);
        map[tmp_row][tmp_col] = 2;
    }

    scanf("%d", &L);

    for (int i = 0; i < L; i++)
        scanf("%d %c", &dir_time[i], &dir_trans[i]);

    printf("%d", game_start());

    return 0;
}

int game_start() {
    int timer = 0, cnt = 0;
    char dir = 'R', rotate;

    enqueue(row, col);

    while (true) {
        timer++;
        if (move(dir) == 1)
            break;
        if (dir_time[cnt] == timer) {
            rotate = dir_trans[cnt];
            dir = rotation(dir, rotate);

            cnt++;
        }
    }

    return timer;
}

char rotation(char dir, char rotate) {
    if (dir == 'R') {
        if (rotate == 'L')
            dir = 'U';
        else
            dir = 'D';
    }

    else if (dir == 'L') {
        if (rotate == 'L')
            dir = 'D';
        else
            dir = 'U';
    }

    else if (dir == 'U') {
        if (rotate == 'L')
            dir = 'L';
        else
            dir = 'R';
    }

    else if (dir == 'D') {
        if (rotate == 'L')
            dir = 'R';
        else
            dir = 'L';
    }

    return dir;
}

int move(char dir) {
    if (dir == 'R') {
        col += 1;

        if (map[row][col] == 0) {
            int tail_row = dequeue_row();
            int tail_col = dequeue_col();

            map[tail_row][tail_col] = 0;

            enqueue(row, col);
            map[row][col] = 1;
            return 0;
        }

        else if (map[row][col] == 2) {
            enqueue(row, col);
            map[row][col] = 1;
            return 2;
        }

        else if (map[row][col] == 1)
            return 1;
    }

    else if (dir == 'L') {
        col -= 1;

        if (map[row][col] == 0) {
            int tail_row = dequeue_row();
            int tail_col = dequeue_col();
            map[tail_row][tail_col] = 0;

            enqueue(row, col);
            map[row][col] = 1;
            return 0;
        }

        else if (map[row][col] == 2) {
            enqueue(row, col);
            map[row][col] = 1;
            return 2;
        }

        else if (map[row][col] == 1)
            return 1;
    }

    else if (dir == 'U') {
        row -= 1;

        if (map[row][col] == 0) {
            int tail_row = dequeue_row();
            int tail_col = dequeue_col();
            map[tail_row][tail_col] = 0;

            enqueue(row, col);
            map[row][col] = 1;
            return 0;
        }

        else if (map[row][col] == 2) {
            enqueue(row, col);
            map[row][col] = 1;
            return 2;
        }

        else if (map[row][col] == 1)
            return 1;
    }

    else if (dir == 'D') {
        row += 1;

        if (map[row][col] == 0) {
            int tail_row = dequeue_row();
            int tail_col = dequeue_col();
            map[tail_row][tail_col] = 0;

            enqueue(row, col);
            map[row][col] = 1;
            return 0;
        }

        else if (map[row][col] == 2) {
            enqueue(row, col);
            map[row][col] = 1;
            return 2;
        }

        else if (map[row][col] == 1)
            return 1;
    }
}