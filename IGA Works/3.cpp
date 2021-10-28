#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

unordered_map<string, int> visit;
string prisoner;

int n, m;
int prisoner_cnt = 0;
int case_cnt = 0;

int get_pos(int x, int y) {
	return x * m + y;
}

void arrange_criminals(string prison, int x, int y, int cnt) {
	visit[prisoner] = 1;

	printf("%d\n", cnt);

	if (cnt >= prisoner_cnt) {
		if (cnt != prisoner_cnt) {
			prisoner_cnt = cnt;
			case_cnt = 0;
		}

		case_cnt += 1;
	}

	// Left
	for (int ny = y - 1; ny >= 0; ny--) {
		int pos = get_pos(x, ny);

		if (prison[pos] == '1') break;
		prison[pos] = '2';
	}

	// Right
	for (int ny = y + 1; ny < m; ny++) {
		int pos = get_pos(x, ny);

		if (prison[pos] == '1') break;
		prison[pos] = '2';
	}

	// Up
	for (int nx = x - 1; nx >= 0; nx--) {
		int pos = get_pos(nx, y);

		if (prison[pos] == '1') break;
		prison[pos] = '2';
	}

	// Down
	for (int nx = x + 1; nx < n; nx++) {
		int pos = get_pos(nx, y);

		if (prison[pos] == '1') break;
		prison[pos] = '2';
	}

	for (int nx = 0; nx < n; nx++) {
		for (int ny = 0; ny < m; ny++) {
			int pos = get_pos(nx, ny);

			if (prison[pos] == '0') {
				prison[pos] = '3';
				prisoner[pos] = '1';
				if (visit[prisoner] == 0)
					arrange_criminals(prison, nx, ny, cnt + 1);
				prison[pos] = '0';
				prisoner[pos] = '0';
			}
		}
	}
}

int main() {
	vector<string> input = { "01010101",
							 "00000100",
							 "10100101",
							 "00000000",
							 "00010000",
							 "00000101",
							 "01000000",
							 "00001010" };
//	vector<string> input = { "0000",
//							 "0000",
//							 "0000",
//							 "0000" };
//	vector<string> input = { "1110",
//							 "0000",
//							 "0100",
//							 "1110" };

	string prison;
	for (string& i : input) prison += i;
	prisoner.resize(prison.size(), '0');

	n = input.size();
	m = input[0].size();

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			int pos = get_pos(x, y);
			if (prison[pos] == '0') {
				prison[pos] = '3';
				prisoner[pos] = '1';
				if (visit[prisoner] == 0)
					arrange_criminals(prison, x, y, 1);
				prison[pos] = '0';
				prisoner[pos] = '0';
			}
		}
	}

	cout << prisoner_cnt << endl;
	cout << case_cnt << endl;

	printf("최대 %d 명, %d 가지\n", prisoner_cnt, case_cnt);

	return 0;
}
