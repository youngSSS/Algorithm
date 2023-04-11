#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
 public:
	string answer;
	int max_len = 0;

	string longestPalindrome(string s) {
		if (s.size() <= 1) return s;

		for (int i = 0; i < s.size(); i++) {
			expand(s, i, i);
			expand(s, i, i + 1);
		}

		return answer;
	}

	void expand(string& s, int left, int right) {
		while (0 <= left && right < s.size() && s[left] == s[right]) {
			left -= 1;
			right += 1;
		}
		left += 1;
		right -= 1;

		if (max_len < right - left + 1) {
			max_len = right - left + 1;
			answer = s.substr(left, max_len);
		}
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->longestPalindrome("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx");
	return 0;
}