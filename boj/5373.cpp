#include <stdio.h>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int T, n;
string rotation[1000];
char U[3][3], D[3][3], F[3][3], B[3][3], L[3][3], R[3][3];
vector<char> printing;

void rotate_cube(char face, char dir);
void rotate_face(char face, char dir);

int main() {
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        memset(U, 'w', sizeof(U));
        memset(D, 'y', sizeof(D));
        memset(F, 'r', sizeof(F));
        memset(B, 'o', sizeof(B));
        memset(L, 'g', sizeof(L));
        memset(R, 'b', sizeof(R));

        scanf("%d", &n);

        for (int i = 0; i < n; i ++) {
            cin >> rotation[i];
            rotate_cube(rotation[i][0], rotation[i][1]);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                printing.push_back(U[i][j]);
        }
    }

    for (int i = 0; i < printing.size(); i++) {
        if (i % 3 == 0 && i != 0) printf("\n");
        printf("%c", printing[i]);
    }

    return 0;
}

void rotate_face(char face, char dir) {
    char temp[3][3];

    if (face == 'U') {
        memcpy(temp, U, sizeof(U));

        if (dir == '+') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    U[i][j] = temp[k][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    U[j][i] = temp[i][k];
            }
        }
    }

    else if (face == 'D') {
        memcpy(temp, D, sizeof(D));

        if (dir == '+') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    D[i][j] = temp[k][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    D[j][i] = temp[i][k];
            }
        }
    }

    else if (face == 'F') {
        memcpy(temp, F, sizeof(F));

        if (dir == '+') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    F[i][j] = temp[k][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    F[j][i] = temp[i][k];
            }
        }
    }

    else if (face == 'B') {
        memcpy(temp, B, sizeof(B));

        if (dir == '+') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    B[i][j] = temp[k][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    B[j][i] = temp[i][k];
            }
        }
    }

    else if (face == 'L') {
        memcpy(temp, L, sizeof(L));

        if (dir == '+') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    L[i][j] = temp[k][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    L[j][i] = temp[i][k];
            }
        }
    }

    else if (face == 'R') {
        memcpy(temp, R, sizeof(R));

        if (dir == '+') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    R[i][j] = temp[k][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0, k = 2; j < 3; j++, k--)
                    R[j][i] = temp[i][k];
            }
        }
    }
}

void rotate_cube(char face, char dir) {
    char temp1[3][3], temp2[3][3], temp3[3][3], temp4[3][3];

    rotate_face(face, dir);

    if ((face == 'U' && dir == '+') || (face == 'D' && dir == '-')) {
        if (face == 'U') {
            for (int i = 0; i < 3; i++) {
                temp1[0][i] = R[0][i];
                temp2[0][i] = F[0][i];
                temp3[0][i] = L[0][i];
                temp4[0][i] = B[0][i];
            }

            for (int i = 0; i < 3; i++) {
                R[0][i] = temp4[0][i];
                F[0][i] = temp1[0][i];
                L[0][i] = temp2[0][i];
                B[0][i] = temp3[0][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                temp1[2][i] = R[2][i];
                temp2[2][i] = F[2][i];
                temp3[2][i] = L[2][i];
                temp4[2][i] = B[2][i];
            }

            for (int i = 0; i < 3; i++) {
                R[2][i] = temp4[2][i];
                F[2][i] = temp1[2][i];
                L[2][i] = temp2[2][i];
                B[2][i] = temp3[2][i];
            }
        }
    }

    else if ((face == 'U' && dir == '-') || (face == 'D' && dir == '+')) {
        if (face == 'U') {
            for (int i = 0; i < 3; i++) {
                temp1[0][i] = L[0][i];
                temp2[0][i] = F[0][i];
                temp3[0][i] = R[0][i];
                temp4[0][i] = B[0][i];
            }

            for (int i = 0; i < 3; i++) {
                L[0][i] = B[0][i];
                F[0][i] = temp1[0][i];
                R[0][i] = temp2[0][i];
                B[0][i] = temp3[0][i];
            }
        }

        else {
            for (int i = 0; i < 3; i++) {
                temp1[2][i] = L[2][i];
                temp2[2][i] = F[2][i];
                temp3[2][i] = R[2][i];
                temp4[2][i] = B[2][i];
            }

            for (int i = 0; i < 3; i++) {
                L[2][i] = temp4[2][i];
                F[2][i] = temp1[2][i];
                R[2][i] = temp2[2][i];
                B[2][i] = temp3[2][i];
            }
        }
    }

    else if ((face == 'F' && dir == '+') || (face == 'B' && dir == '-')) {
        if (face == 'F') {
            for (int i = 0; i < 3; i++) {
                temp1[i][0] = R[i][0];
                temp2[0][i] = D[0][i];
                temp3[i][2] = L[i][2];
                temp4[2][i] = U[2][i];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                R[i][0] = temp4[2][i];
                D[0][i] = temp1[j][0];
                L[i][2] = temp2[0][i];
                U[2][i] = temp3[j][2];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                temp1[i][2] = R[i][2];
                temp2[2][i] = D[2][i];
                temp3[i][0] = L[i][0];
                temp4[0][i] = U[0][i];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                R[i][2] = temp4[0][i];
                D[2][i] = temp1[j][2];
                L[i][0] = temp2[2][i];
                U[0][i] = temp3[j][0];
            }
        }
    }

    else if ((face == 'F' && dir == '-') || (face == 'B' && dir == '+')) {
        if (face == 'F') {
            for (int i = 0; i < 3; i++) {
                temp1[i][2] = L[i][2];
                temp2[0][i] = D[0][i];
                temp3[i][0] = R[i][0];
                temp4[2][i] = U[2][i];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                L[i][2] = temp4[2][j];
                D[0][i] = temp1[i][2];
                R[i][0] = temp2[0][j];
                U[2][i] = temp3[i][0];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                temp1[i][0] = L[i][0];
                temp2[2][i] = D[2][i];
                temp3[i][2] = R[i][2];
                temp4[0][i] = U[0][i];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                L[i][0] = temp4[0][j];
                D[2][i] = temp1[i][0];
                R[i][2] = temp2[2][j];
                U[0][i] = temp3[i][2];
            }
        }
    }

    else if ((face == 'L' && dir == '+') || (face == 'R' && dir == '-')) {
        if (face == 'L') {
            for (int i = 0; i < 3; i++) {
                temp1[i][0] = F[i][0];
                temp2[i][0] = D[i][0];
                temp3[i][2] = B[i][2];
                temp4[i][0] = U[i][0];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                F[i][0] = temp4[i][0];
                D[i][0] = temp1[i][0];
                B[i][2] = temp2[j][0];
                U[i][0] = temp3[j][2];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                temp1[i][2] = F[i][2];
                temp2[i][2] = D[i][2];
                temp3[i][0] = B[i][0];
                temp4[i][2] = U[i][2];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                F[i][2] = temp4[i][2];
                D[i][2] = temp1[i][2];
                B[i][0] = temp2[j][2];
                U[i][2] = temp3[j][0];
            }
        }
    }

    else if ((face == 'L' && dir == '-') || (face == 'R' && dir == '+')) {
        if (face == 'L') {
            for (int i = 0; i < 3; i++) {
                temp1[i][2] = B[i][2];
                temp2[i][0] = D[i][0];
                temp3[i][0] = F[i][0];
                temp4[i][0] = U[i][0];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                B[i][2] = temp4[j][0];
                D[j][0] = temp1[i][2];
                F[i][0] = temp2[i][0];
                U[i][0] = temp3[i][0];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                temp1[i][0] = B[i][0];
                temp2[i][2] = D[i][2];
                temp3[i][2] = F[i][2];
                temp4[i][2] = U[i][2];
            }

            for (int i = 0, j = 2; i < 3; i++, j--) {
                B[i][0] = temp4[j][2];
                D[j][2] = temp1[i][0];
                F[i][2] = temp2[i][2];
                U[i][2] = temp3[i][2];
            }
        }
    }
}