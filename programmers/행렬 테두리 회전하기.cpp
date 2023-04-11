#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	vector<vector<int>> matrix(rows, vector<int>(columns));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			matrix[i][j] = columns * i + j + 1;
	}

	for (auto query : queries) {
		int x1 = query[0] - 1;
		int y1 = query[1] - 1;
		int x2 = query[2] - 1;
		int y2 = query[3] - 1;

		int x, y, min = 1e9;
		int tmp = matrix[x1][y1];

		y = y1;
		for (x = x1; x < x2; x++) {
			matrix[x][y] = matrix[x + 1][y];
			if (min > matrix[x][y]) min = matrix[x][y];
		}

		x = x2;
		for (y = y1; y < y2; y++) {
			matrix[x][y] = matrix[x][y + 1];
			if (min > matrix[x][y]) min = matrix[x][y];
		}

		y = y2;
		for (x = x2; x > x1; x--) {
			matrix[x][y] = matrix[x - 1][y];
			if (min > matrix[x][y]) min = matrix[x][y];
		}

		x = x1;
		for (y = y2; y > y1; y--) {
			matrix[x][y] = matrix[x][y - 1];
			if (y == y1 + 1) matrix[x][y] = tmp;
			if (min > matrix[x][y]) min = matrix[x][y];
		}

		answer.push_back(min);
	}

	return answer;
}

int main() {
	solution(6, 6, {{2,2,5,4}, {3,3,6,6}, {5,1,6,3}});
}