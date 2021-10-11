#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> graph;
unordered_map<string, int> earn, final_earn;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	answer.reserve(enroll.size());

	for (int i = 0; i < enroll.size(); i++)
		graph[enroll[i]] = referral[i];

	for (int i = 0; i < seller.size(); i++) {
		int money = amount[i] * 100;
		string e = seller[i];
		while (e != "-" && money > 0) {
			final_earn[e] += money - money / 10;
			money /= 10;
			e = graph[e];
		}
	}

	for (string& e : enroll)
		answer.push_back(final_earn[e]);

	return answer;
}