unordered_map<int, long long> facto;

long long get_facto(int a) {
	if (facto[a] != 0) return facto[a];

	long long value = 1;
	for (int i = 2; i <= a; i++)
		value *= i;

	facto[a] = value;
	return facto[a];
}

int countTeams(vector<int> skills, int minPlayers, int minLevel, int maxLevel) {
	int ans = 0;
	int count = 0;

	for (int skill : skills) {
		if (minLevel <= skill && skill <= maxLevel) count += 1;
	}

	for (int i = minPlayers; i <= count; i++)
		ans += (get_facto(count)) / (get_facto(i) * get_facto(count - i));

	return ans;
}