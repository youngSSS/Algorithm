#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int r = 2; // 선택할 원소 개수
	vector<vector<int>> combinations;
	// visit 배열은 {0, 0, 1, 1} 처럼 sorting 되어 있어야 함
	vector<int> visit(nums.size() - r, 0);
	for(int i = 0; i < r; i++) visit.push_back(1);

	do {
		vector<int> comb;
		for (int i = 0; i < nums.size(); i++) {
			if (visit[i]) comb.push_back(nums[i]);
		}
		combinations.push_back(comb);
	} while (next_permutation(visit.begin(), visit.end()));
}