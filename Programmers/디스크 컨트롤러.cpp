#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int current_time = 0;
    priority_queue< vector<int>, vector< vector<int> >, greater< vector<int> > > ready_q, run_q;

    for (int i = 0; i < jobs.size(); i++)
        ready_q.push(jobs[i]);

    while (!ready_q.empty() || !run_q.empty()) {
        while (!ready_q.empty() && ready_q.top()[0] <= current_time) {
            run_q.push({ready_q.top()[1], ready_q.top()[0]});
            ready_q.pop();
        }

        if (!run_q.empty() && run_q.top()[1] <= current_time) {
            answer += current_time - run_q.top()[1] + run_q.top()[0];
            current_time += run_q.top()[0];
            run_q.pop();
        }
        else
            current_time++;
    }

    return answer / jobs.size();
}