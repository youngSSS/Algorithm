#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<string> queue;
    unordered_map<string, int> visit;
    int word_size = begin.size();

    for (auto word : words) visit[word] = 0;
    queue.push(begin);

    while (!queue.empty()) {
        int q_size = queue.size();
        answer += 1;

        while (q_size) {
            string now_word = queue.front();
            visit[now_word] = 1;
            queue.pop();
            q_size -= 1;

            for (auto word : words) {
                if (visit[word] == 1) continue;

                int count = 0;
                for (int i = 0; i < word_size; i++) {
                    if (now_word[i] != word[i]) count += 1;
                    if (count > 1) break;
                }

                if (count == 1) {
                    queue.push(word);
                    if (target == word) return answer;
                }
            }
        }
    }

    return 0;
}