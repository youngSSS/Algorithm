#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int x = 0, y = 0;

		for (int i = 0; i < n / 2; i++, x++, y++) {
			int len = n - 2 * i;
			for (int j = 0; j < len - 1; j++) {
				int ny = y + j;
				rotate_target(matrix, x, ny, y, y + len - 1, n - 1);
			}
		}
	}

	void rotate_target(vector<vector<int>>& matrix, int x, int y, int s, int e, int l) {
		int x1 = y, y1 = e;
		int x2 = y1, y2 = l - x1;
		int x3 = y2, y3 = s;

		int temp = matrix[x][y];
		matrix[x][y] = matrix[x3][y3];
		matrix[x3][y3] = matrix[x2][y2];
		matrix[x2][y2] = matrix[x1][y1];
		matrix[x1][y1] = temp;
	}
};