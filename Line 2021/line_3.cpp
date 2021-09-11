#include <string>
#include <vector>
#include <iostream>

using namespace std;

int value[101];
int job_time[101];

vector<int> solution(vector<vector<int> > jobs) {
	vector<int> answer;
	int now_job = jobs[0][2];
	int st_time = jobs[0][0];

	value[now_job] += jobs[0][3];
	job_time[now_job] += jobs[0][1];
	answer.push_back(now_job);

	for (int i = 1; i < jobs.size(); i++) {
		if (jobs[i][0] > st_time + job_time[now_job]) {
			st_time = st_time + job_time[now_job];
			value[now_job] = 0;
			job_time[now_job] = 0;

			int max_val = 0;
			int idx = 0;
			for (int j = 1; j <= 100; j++) {
				if (value[j] > max_val) {
					max_val = value[j];
					idx = j;
				}
			}
			now_job = idx;

			if (now_job != 0) {
				answer.push_back(idx);
			}
			else {
				now_job = jobs[0][2];
				answer.push_back(now_job);
			}
			cout << now_job << endl;
		}
		value[jobs[0][2]] += jobs[i][3];
		job_time[jobs[0][2]] += jobs[i][1];

	}

	value[now_job] = 0;
	job_time[now_job] = 0;

	while (now_job != 0) {
		int max_val = 0;
		int idx = 0;

		for (int i = 1; i <= 100; i++) {
			if (value[i] > max_val) {
				max_val = value[i];
				idx = i;
			}
		}
		now_job = idx;
		answer.push_back(idx);
		value[now_job] = 0;
		job_time[now_job] = 0;
		cout << now_job << endl;
	}
	return answer;
}