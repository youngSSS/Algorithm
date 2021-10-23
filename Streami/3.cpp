#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
	int len = A.size();

	unordered_map<int, vector<int>> amap, bmap;

	for (int i = 0; i < len; i++) {
		amap[A[i]].push_back(i);
		bmap[B[i]].push_back(i);
	}

	int ans = 100001;
	for (int i = 1; i < 100001; i++) {
		auto a_item = amap.find(i);
		auto b_item = bmap.find(i);

		if (a_item != amap.end() && b_item != bmap.end()) {
			int flag = 0;
			for (int idx : a_item->second) {
				bool find_flag = binary_search(b_item->second.begin(), b_item->second.end(), idx);
				if (find_flag) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				ans = i;
				break;
			}
		}
		else {
			ans = i;
			break;
		}
	}

	return ans;
}

int main() {
	vector<int> a, b;
	for (int i = 1; i < 100001; i++) {
		a.push_back(i);
		b.push_back(i);
	}

	cout << solution(a, b);

	return 0;
}