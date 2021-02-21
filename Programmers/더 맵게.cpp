#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue< int, vector<int>, greater<int> > pq;

    for (int & i : scoville)
        pq.push(i);

    if (pq.top() >= K) return 0;

    while (pq.size() > 1) {
        int min = pq.top();
        pq.pop();
        int second_min = pq.top();
        pq.pop();

        pq.push(min + second_min * 2);
        answer++;

        if (pq.top() >= K) break;
        if (pq.size() == 1) return -1;
    }

    return answer;
}