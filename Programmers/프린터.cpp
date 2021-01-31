#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int turn = 0;
    pair<int, int> doc;
    queue< pair<int, int> > documents;
    priority_queue< int, vector<int>, less<int> > prio;

    for (int i = 0; i < priorities.size(); i++) {
        documents.push({priorities[i], i});
        prio.push(priorities[i]);
    }

    while (true) {
        doc = documents.front();
        documents.pop();

        if (doc.first == prio.top()) {
            turn++;
            prio.pop();
            if (doc.second == location) return turn;
        }
        else documents.push(doc);
    }
}