vector<string> braces(vector<string> values) {
	vector<string> ans;

	for (string& value : values) {
		stack<char> s;
		int flag = 0;

		for (char c : value) {
			if (c == '[' || c == '{' || c == '(') s.push(c);
			else {
				if (s.empty()) {
					flag = 1;
					break;
				}

				char b = s.top();
				s.pop();

				if (b == '[' && c == ']') continue;
				if (b == '{' && c == '}') continue;
				if (b == '(' && c == ')') continue;

				flag = 1;
				break;
			}
		}

		if (flag == 0 && s.empty()) ans.push_back("YES");
		else ans.push_back("NO");
	}

	return ans;
}