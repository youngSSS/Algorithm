int len;
string answer;

bool check_good(string& s) {
	int z_cnt = 0, one_cnt = 0;

	cout << "CHECK : " << s << endl;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') z_cnt += 1;
		else one_cnt += 1;

		if (z_cnt > one_cnt) return false;
	}

	return true;
}

void find_good(int start, string& s, int cnt, vector<pair<int, int>>& idx) {
	int z_cnt = 0, one_cnt = 0;

	if (cnt == 2) {
		int s1 = idx[0].first;
		int e1 = idx[0].second;
		int s2 = idx[1].first;
		int e2 = idx[1].second;

		string new_s = s.substr(0, s1) + s.substr(s2, e2 - s2 + 1) + s.substr(s1, e1 - s1 + 1) + s.substr(e2 + 1);

		bool flag = check_good(new_s);
		if (flag == false) {
			cout << "Not Good: " << new_s << endl;
			return;
		}

		cout << "Answer: " << answer << endl;
		cout << "New   : " << new_s << endl;

		for (int i = 0; i < s.size(); i++) {
			if (i == s1 || i == s2) cout << "[";
			cout << s[i];
			if (i == e1 || i == e2) cout << "]";
			cout << ", ";
		}
		cout << endl;

		// if (answer < new_s) answer = new_s;

		for (int i = 0; i < answer.size(); i++) {
			if (answer[i] < new_s[i]) {
				answer = new_s;
				break;
			}
			else if (answer[i] > new_s[i]) break;
		}

		return;
	}

	for (int i = start; i < len; i++) {
		if (s[i] == '0') z_cnt += 1;
		else one_cnt += 1;

		if (z_cnt == one_cnt) {
			cout << start << ", " << i << endl;
			idx.push_back(make_pair(start, i));
			find_good(i + 1, s, cnt + 1, idx);
			idx.pop_back();
		}

		if (z_cnt > one_cnt) break;
	}
}

string largestMagical(string binString) {
	cout << binString << endl;

	answer = binString;
	len = binString.size();
	for (int i = 0; i < len; i++) {
		vector<pair<int, int>> idx;
		cout << "START: " << i << endl;
		find_good(i, binString, 0, idx);
	}

	return answer;
}