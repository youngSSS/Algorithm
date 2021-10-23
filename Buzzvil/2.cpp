int programmerStrings(string s) {
	unordered_map<char, int> comp, target;
	int left, right;

	comp['p'] = 1;
	comp['r'] = 3;
	comp['o'] = 1;
	comp['g'] = 1;
	comp['a'] = 1;
	comp['m'] = 2;
	comp['e'] = 1;

	int cnt = 0, idx = 0;
	while (cnt < 10) {
		char t = s[idx];

		if (comp.find(t) != comp.end()) {
			if (target[t] < comp[t]) {
				target[t] += 1;
				cnt += 1;
			}
		}

		idx += 1;
	}
	left = idx - 1;

	target.clear();
	cnt = 0;
	idx = s.size() - 1;
	while (cnt < 10) {
		char t = s[idx];

		if (comp.find(t) != comp.end()) {
			if (target[t] < comp[t]) {
				target[t] += 1;
				cnt += 1;
			}
		}

		idx -= 1;
	}
	right = idx + 1;

	return right - left - 1;
}