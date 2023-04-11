#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	unordered_map <string, int> hash_map;
	unordered_map <string, int>::iterator iter;
	int answer = 1;

	for (int i = 0; i < clothes.size(); i++) {
		if (hash_map.find(clothes[i][1]) == hash_map.end()) hash_map[clothes[i][1]] = 1;	
		else hash_map[clothes[i][1]]++;
	}

	for (iter = hash_map.begin(); iter != hash_map.end(); iter++)
		answer *= (iter->second + 1);

	

	return answer - 1;
}