#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end(), greater<>());

    for (int i = 0; i < citations.size(); i++) {
        if (i + 1 == citations[i]) return i + 1;
        else if (i + 1 > citations[i]) return i;
    }

    if (citations[0] != 0) return citations.size();

    return 0;
}