#include <string>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;


vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
	vector<int> answer;
	map<string, int> counter;
	map<string, int> result;
	set<string> checker;

	for (int i = 0; i < report.size(); i++)
	{
		if (checker.find(report[i]) == checker.end())
		{
			checker.insert(report[i]);
			string a = report[i].substr(0, report[i].find(' '));
			string b = report[i].substr(report[i].find(' '));
			counter[b] += 1;
		}
	}
	checker.clear();
	for (int i = 0; i < report.size(); i++)
	{
		if (checker.find(report[i]) == checker.end())
		{
			checker.insert(report[i]);
			string a = report[i].substr(0, report[i].find(' '));
			string b = report[i].substr(report[i].find(' '));
			if (counter[b] >= k)
			{
				result[a] += 1;
			}
		}
	}
	for (int i = 0; i < id_list.size(); i++)
	{
		answer.push_back(result[id_list[i]]);
	}

	return answer;
}