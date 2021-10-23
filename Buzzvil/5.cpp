int check(int len, vector<vector<int>>& samples) {

	int c_start = 0, c_end = len - 1;
	while (c_end < samples.size()) {

		int r_start = 0, r_end = len - 1;
		while (r_end < samples.size()) {

			int flag = 0;
			for (int x = r_start; x <= r_end; x++) {
				for (int y = c_start; y <= c_end; y++) {
					if (samples[x][y] == 0) {
						flag = 1;
						break;
					}
				}

				if (flag == 1) break;
			}

			if (flag == 0) return len;

			r_start += 1;
			r_end += 1;
		}

		c_start += 1;
		c_end += 1;
	}

	return 0;
}

int largestArea(vector<vector<int>> samples) {
	for(int i = samples.size(); i > 0; i--) {
		int ret_val = check(i, samples);
		if (ret_val != 0) return ret_val;
	}

	return 0;
}