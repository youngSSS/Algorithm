#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int winner_check(vector<vector<int> >& board) {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
		if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
	}
	if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
	if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

	int flag = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0) {
				flag = 0;
				break;
			}
		}
	}
	if (flag) return 3;

	return 0;
}

int dfs(vector<vector<int> >& board, int turn) {
	int winner = winner_check(board);
	if (winner != 0) return winner;

	int next = turn == 1 ? 2 : 1;
	int flag = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0) {
				board[i][j] = turn;
				int result = dfs(board, next);
				board[i][j] = 0;
				if (result == turn) return turn;
				else if (result == 3) flag = 1;
			}
		}
	}

	if (flag) return 3;

	return next;
}

string solution(vector<vector<int> >& board) {
	int p1 = 0, p2 = 0;

	for (auto& row : board) {
		for (auto v : row) {
			if (v == 1) p1 += 1;
			else if (v == 2) p2 += 1;
		}
	}

	int turn;
	if (p1 > p2) turn = 2;
	else turn = 1;

	int result = dfs(board, turn);

	if (turn == 1) {
		if (result == 1) return "W";
		else if (result == 2) return "L";
	}
	else {
		if (result == 1) return "L";
		else if (result == 2) return "W";
	}

	return "D";
}

int main() {
	vector<vector<int> > board(3, vector<int>(3, 0));

	for (int i = 0; i < 3; i++)
		scanf("%d %d %d", &board[i][0], &board[i][1], &board[i][2]);

//	board = {
//		{ 1, 2, 0 },
//		{ 0, 1, 0 },
//		{ 0, 0, 0 }
//	};

	cout << solution(board);

	return 0;
}
