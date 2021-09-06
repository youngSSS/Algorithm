#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Trie {
    unordered_map<char, Trie*> next;
    int count = 0;

    void insert(string word, int idx) {
        int word_len = word.size();
        count += 1;

        if (idx < word_len) {
            char w = word[idx];
            if (next[w] == nullptr) next[w] = new Trie();
            next[w]->insert(word, idx + 1);
        }
    }

    int find(string word, int idx) {
        if (word.size() == idx || word[idx] == '?') return this->count;

        char w = word[idx];
        if (next[w] == nullptr) return 0;
        return next[w]->find(word, idx + 1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    unordered_map<int, Trie*> trie;
    unordered_map<int, Trie*> reverse_trie;

    for (string word : words) {
        int w_size = word.size();
        if (trie[w_size] == nullptr) {
            trie[w_size] = new Trie();
            reverse_trie[w_size] = new Trie();
        }
        trie[w_size]->insert(word, 0);
        reverse(word.begin(), word.end());
        reverse_trie[w_size]->insert(word, 0);
    }

    for (string q : queries) {
        Trie* t = trie[q.size()];

        if (t == nullptr) {
            answer.push_back(0);
            continue;
        }

        if (q[0] == '?') {
            t = reverse_trie[q.size()];
            reverse(q.begin(), q.end());
        }

        answer.push_back(t->find(q, 0));
    }

    return answer;
}

int main() {
    solution({"a", "ab", "ac", "abcd", "e", "f"}, {"?", "??", "????", "a?", "ab??"});
    return 0;
}