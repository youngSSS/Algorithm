#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Trie {
    unordered_map<char, Trie*> next;
    int count = 0;

    void insert(const char * key) {
        count += 1;

        if (*key != '\0') {
            if (next[*key] == nullptr) next[*key] = new Trie();
            next[*key]->insert(key + 1);
        }
    }

    int find(const char * key) {
        if (*key == '\0' || *key == '?') return this->count;

        if (next[*key] == nullptr) return 0;
        return next[*key]->find(key + 1);
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
        trie[w_size]->insert(word.c_str());
        reverse(word.begin(), word.end());
        reverse_trie[w_size]->insert(word.c_str());
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

        answer.push_back(t->find(q.c_str()));
    }

    return answer;
}

int main() {
    solution({"a", "ab", "ac", "abcd", "e", "f"}, {"?", "??", "????", "a?", "ab??"});
    return 0;
}