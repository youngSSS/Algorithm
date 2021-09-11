#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

int comp_nick()
{

}


int solution(vector<string> nicks, vector<string> emails)
{
	int answer = -1;
	unordered_map<int, set<string>> nick_map;
	unordered_map<int, pair<string, pair<string, set<string>>>> email_map;

	for (int idx = 0; idx < nicks.size(); idx++)
	{
		for (int i = 0; i <= 2; i++)
		{
			vector<int> visit(nicks[idx].size(), 1);
			for (int j = 0; j < i; j++) visit[j] = 0;
			do
			{
				string temp = "";
				for (int k = 0; k < nicks[idx].size(); k++)
				{
					if (visit[k]) temp += nicks[idx][k];
				}
				nick_map[idx].insert(temp);
			} while (next_permutation(visit.begin(), visit.end()));
		}
	}

	for (int idx = 0; idx < emails.size(); idx++)
	{
		auto iter = find(emails[idx].begin(), emails[idx].end(), '@');
		string id = emails[idx].substr(0, iter - emails[idx].begin());
		string server = emails[idx].substr(iter - emails[idx].begin() + 1);

		cout << id << " " << server << endl;
		email_map[idx].first = id;
		email_map[idx].second.first = server;

		for (int i = 1; i <= 1; i++)
		{
			vector<int> visit(emails[idx].size(), 1);
			for (int j = 0; j < i; j++) visit[j] = 0;
			do
			{
				string temp = "";
				for (int k = 0; k < emails[idx].size(); k++)
				{
					if (visit[k]) temp += emails[idx][k];
				}
				email_map[idx].second.second.insert(temp);
			} while (next_permutation(visit.begin(), visit.end()));
		}
	}

	return answer;
}

int main()
{
	cout << solution({ "imhero111", "moneyman", "hero111", "imher1111", "hro111", "mmoneyman", "moneymannnn" },
			{ "superman5@abcd.com", "batman432@korea.co.kr", "superman@abcd.com", "supertman5@abcd.com",
			  "superman@erty.net", "batman42@korea.co.kr", "batman432@usa.com" });
	return 0;
}