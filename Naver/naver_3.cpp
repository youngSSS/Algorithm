#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    int cnt = 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++) {
        cnt += abs(A[i] - (i + 1));
    }

    return cnt;
}

int main() {
    return 0;
}
