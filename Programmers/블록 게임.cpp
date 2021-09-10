#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dexp[4] = {-1, 1, -5, 5};

vector<int> shapes = {4320, 4236, 4230, 4992, 4544};
vector<vector<int>> dir = {{1, 2}, {-1}, {1}, {-1, -2}, {-1, 1}};
vector<int> x_range = {0, 1, 1, 0, 0};
pair<int, int> remove_shape[5][4] = {
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
        {{0, 0}, {1, 0}, {1, -1}, {1, -2}},
        {{0, 0}, {1, 0}, {1, -1}, {1, 1}}
};

vector<vector<int>> visit(50, vector<int>(50, 0));
unordered_map<int, priority_queue<int>> map;

int dfs(vector<vector<int>> board, int x, int y, int shape, int exp, int idx) {
    int b_size = board.size();
    int nx, ny, nexp;

    visit[x][y] = 1;
    map[y].push(x);
    shape += pow(2, exp);

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        nexp = exp + dexp[i];

        if (0 <= nx && nx < b_size && 0 <= ny && ny < b_size) {
            if (board[nx][ny] == idx && visit[nx][ny] == 0)
                shape |= dfs(board, nx, ny, shape, nexp, idx);
        }
    }

    return shape;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int shape;

    for (int i = 0; i < board.size(); i++) {
        vector<int> visit_x, visit_y;

        for (int j = 0; j < board[i].size(); j++) {

            if (visit[i][j] == 0 && board[i][j] != 0) {
                map.clear();
                shape = dfs(board, i, j, 0, 12, board[i][j]);

                auto iter = find(shapes.begin(), shapes.end(), shape);
                if (iter != shapes.end()) {
                    int shape_idx = iter - shapes.begin();
                    int flag = 0;

                    for (auto dir_y : dir[shape_idx]) {
                        int ny = j + dir_y;

                        for (int k = 0; k <= i + x_range[shape_idx]; k++) {
                            if (board[k][ny] != 0) {
                                flag = 1;
                                break;
                            }
                        }

                        if (flag) break;
                    }

                    if (flag == 0) {
                        for (auto pos : remove_shape[shape_idx])
                            board[i + pos.first][j + pos.second] = 0;
                        j = -1;
                        answer += 1;

                        for (int k = 0; k < visit_x.size(); k++)
                            visit[visit_x[k]][visit_y[k]] = 0;

                        visit_x.clear();
                        visit_y.clear();

                    }
                    else {
                        for (auto pos : remove_shape[shape_idx]) {
                            visit_x.push_back(i + pos.first);
                            visit_y.push_back(j + pos.second);
                        }
                    }

                }
            }
        }
    }

    return answer;
}

int main() {
//    cout << solution({
//        {0,0,0,0,0,0,0,0,0,0},
//        {0,0,0,0,0,0,0,0,0,0},
//        {0,0,0,0,0,0,0,0,0,0},
//        {0,0,0,0,0,0,0,0,0,0},
//        {0,0,0,0,0,0,4,0,0,0},
//        {0,0,0,0,0,4,4,0,0,0},
//        {0,0,0,0,3,0,4,0,0,0},
//        {0,0,0,2,3,0,0,0,5,5},
//        {1,2,2,2,3,3,0,0,0,5},
//        {1,1,1,0,0,0,0,0,0,5}}) << endl;
//    cout << solution({
//        {0, 0, 1, 1, 1},
//        {0, 0, 0, 1, 0},
//        {3, 0, 0, 2, 0},
//        {3, 2, 2, 2, 0},
//        {3, 3, 0, 0, 0}}) << endl;
//    cout << solution({
//        {0, 2, 0, 0},
//        {1, 2, 0, 4},
//        {1, 2, 2, 4},
//        {1, 1, 4, 4}}) << endl;
//    cout << solution({
//        {0,0,0,0,0,0,0,0,0,0},
//        {0,0,0,2,2,0,0,0,0,0},
//        {0,0,0,2,1,0,0,0,0,0},
//        {0,0,0,2,1,0,0,0,0,0},
//        {0,0,0,0,1,1,0,0,0,0},
//        {0,0,0,0,0,0,0,0,0,0}}) << endl;
    cout << solution({
                             {0, 0, 0, 0, 0},
                             {1, 0, 0, 2, 0},
                             {1, 2, 2, 2, 0},
                             {1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0}}) << endl;
    return 0;
}