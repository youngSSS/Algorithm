#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
using pis = pair<int, string>;
using pii = pair<int, int>;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> total_plays;
    unordered_map< string, priority_queue< pii, vector<pii>, less<pii> > > plays_per_genres;
    priority_queue< pis, vector<pis>, less<pis> > pq;

    for (int i = 0; i < genres.size(); i++) {
        if (total_plays.find(genres[i]) == total_plays.end())  {
            priority_queue< pii, vector<pii>, less<pii> > temp_pq;
            total_plays[genres[i]] = plays[i];
            plays_per_genres[genres[i]] = temp_pq;
        }
        else total_plays[genres[i]] += plays[i];
        plays_per_genres[genres[i]].push({plays[i], i});
    }

    for (unordered_map<string, int>::iterator iter = total_plays.begin(); iter != total_plays.end(); iter++)
        pq.push({iter->second, iter->first});

    while (!pq.empty()) {
        string genre = pq.top().second;


        for (int i = 0; i < 2; i++) {
            vector<int> temp;
            pii comp = plays_per_genres[genre].top();
            plays_per_genres[genre].pop();

            if (plays_per_genres[genre].empty()) {
                answer.push_back(comp.second);
                break;
            }

            while (comp.first == plays_per_genres[genre].top().first) {
                temp.push_back(comp.second);
                comp = plays_per_genres[genre].top();
                plays_per_genres[genre].pop();
            }
            temp.push_back(comp.second);

            if (temp.size() >= 2) {
                answer.push_back(temp[temp.size() - 1]);
                if (i == 0)
                    answer.push_back(temp[temp.size() - 2]);
                break;
            }

            answer.push_back(comp.second);
        }


        pq.pop();
    }

    return answer;
}
