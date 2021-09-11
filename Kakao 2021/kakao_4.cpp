#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_score = 0;
vector<int> answer = { -1 };
vector<int> now_info(11);

void dfs(int idx, int rest, vector<int>& info)
{
	if (rest == 0)
	{
		int s1 = 0, s2 = 0;
		for (int i = 0; i < 11; i++)
		{
			if (now_info[i] > info[i])s1 += 10 - i;
			else if (now_info[i] <= info[i] && info[i] != 0) s2 += 10 - i;
		}
		if (s1 - s2 > max_score)
		{
			cout << s1 - s2 << endl;
			max_score = s1 - s2;
			answer = now_info;
		}
	}
	if (idx == 11)
	{
		return;
	}
	for (int i = 0; i <= rest; i++)
	{
		now_info[idx] = i;
		dfs(idx + 1, rest - i, info);
		now_info[idx] = 0;
	}
}

vector<int> solution(int n, vector<int> info)
{
	dfs(0, n, info);
	return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_score = 0;
vector<int> answer = { -1 };
vector<int> now_info(11);

void dfs(int idx, int rest, vector<int>& info)
{
	if (rest == 0)
	{
		int s1 = 0, s2 = 0;
		for (int i = 0; i < 11; i++)
		{
			if (now_info[i] > info[i])s1 += 10 - i;
			else if (now_info[i] <= info[i] && info[i] != 0) s2 += 10 - i;
		}
		if (s1 - s2 > max_score)
		{
			max_score = s1 - s2;
			answer = now_info;
		}
		else if (s1 - s2 > 0 && s1 - s2 == max_score)
		{
			for (int i = 10; i >= 0; i--)
			{
				cout << i << answer[i] << now_info[i] << endl;
				if (answer[i] < now_info[i])
				{
					answer = now_info;
					break;
				}
				else if (answer[i] > now_info[i])
				{
					break;
				}
			}
		}
		return;
	}
	if (idx == 11)
	{
		return;
	}
	for (int i = 0; i <= rest; i++)
	{
		now_info[idx] = i;
		dfs(idx + 1, rest - i, info);
		now_info[idx] = 0;
	}
}

vector<int> solution(int n, vector<int> info)
{
	dfs(0, n, info);
	return answer;
}