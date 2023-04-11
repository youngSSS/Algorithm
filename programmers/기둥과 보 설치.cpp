#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> pillar(1000, vector<int>(1000 ,0));
vector<vector<int>> bo(1000, vector<int>(1000 ,0));

int build_pillar(int x, int y) {
    int nx = x > 0 ? x - 1 : 0;
    if (y == 0 || (bo[x][y] == 1 || bo[nx][y] == 1) || pillar[x][y - 1] == 1) pillar[x][y] = 1;
    if (pillar[x][y] == 1) return 1;
    return 0;
}

int build_bo(int x, int y) {
    int nx = x > 0 ? x - 1 : 0;
    if ((pillar[x][y - 1] == 1 || pillar[x + 1][y - 1] == 1) || (bo[nx][y] == 1 && bo[x + 1][y] == 1)) bo[x][y] = 1;
    if (bo[x][y] == 1) return 1;
    return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (vector<int> build : build_frame) {
        int x = build[0];
        int y = build[1];
        int structure_type = build[2];
        int build_type = build[3];

        if (build_type == 1) {
            if (structure_type == 0) build_pillar(x, y);
            else build_bo(x, y);
        }

        else {
            if (structure_type == 0) {
                int bx[4] = {0, -1, 0, -1};
                int by[4] = {0, 0, 1, 1};
                int px = 0, py = 1;

                pillar[x][y] = 0;

                for (int i = 0; i < 4; i++) {
                    int nx = x + bx[i];
                    int ny = y + by[i];

                    if (0 <= nx && nx <= n && 0 <= ny && ny <= n) {
                        if (bo[nx][ny] == 1) {
                            bo[nx][ny] = 0;

                            if (build_bo(nx, ny) == 0) {
                                pillar[x][y] = 1;
                                bo[nx][ny] = 1;
                                break;
                            }

                            bo[nx][ny] = 1;
                        }
                    }
                }

                if (pillar[x][y] == 0) {
                    int nx = x + px;
                    int ny = y + py;

                    if (pillar[nx][ny] == 1) {
                        pillar[nx][ny] = 0;

                        if (build_pillar(nx, ny) == 0) pillar[x][y] = 1;

                        pillar[nx][ny] = 1;
                    }
                }
            }

            else {
                int px[4] = {0, 0, 1, 1};
                int py[4] = {0, -1, 0, -1};
                int bx[2] = {-1, 1};
                int by[2] = {0, 0};

                bo[x][y] = 0;

                for (int i = 0; i < 4; i++) {
                    int nx = x + px[i];
                    int ny = y + py[i];

                    if (0 <= nx && nx <= n && 0 <= ny && ny <= n) {
                        if (pillar[nx][ny] == 1) {
                            pillar[nx][ny] = 0;

                            if (build_pillar(nx, ny) == 0) {
                                bo[x][y] = 1;
                                pillar[nx][ny] = 1;
                                break;
                            }

                            pillar[nx][ny] = 1;
                        }
                    }

                }

                if (bo[x][y] == 0) {
                    for (int i = 0; i < 2; i++) {
                        int nx = x + bx[i];
                        int ny = y + by[i];

                        if (0 <= nx && nx <= n && 0 <= ny && ny <= n) {
                            if (bo[nx][ny] == 1) {
                                bo[nx][ny] = 0;

                                if (build_bo(nx, ny) == 0) {
                                    bo[x][y] = 1;
                                    bo[nx][ny] = 1;
                                    break;
                                }

                                bo[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (pillar[x][y] == 1) answer.push_back({x, y, 0});
            if (bo[x][y] == 1) answer.push_back({x, y, 1});
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
//    solution(5, {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}});
    solution(5, {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}});
    return 0;
}