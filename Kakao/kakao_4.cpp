#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    vector<vector<pair<int, int>>> normal_graph(n), trap_graph(n);

    map<int, int> tmap;
    for(int i=0;i<traps.size();i++){
        tmap[traps[i]-1] = i;
    }

    start -= 1;
    end -= 1;
    set<int> trap_check;

    // normal_graph[자신] = { (자신의 이웃1, 비용), (자신의 이웃2, 비용), ... }
    for(int i=0;i<roads.size();i++){
        normal_graph[roads[i][0]-1].push_back(make_pair(roads[i][1]-1, roads[i][2]));
        trap_graph[roads[i][1]-1].push_back(make_pair(roads[i][0]-1, roads[i][2]));
    }

    vector<vector<int>> dist(n);
    for(int i=0;i<n;i++) {
        for (int j = 0; j < pow(2, traps.size()); j++)
            dist[i].push_back(1e9);
    }
    dist[start][0] = 0;

    // (dist, (node, trap))
    // trap은 함정이 어디어디 발동되어 있는지에 대한 정보
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(start, 0)));

    while (!pq.empty()){
        int now_dist = -pq.top().first;
        int now_node = pq.top().second.first;
        int now_trap = pq.top().second.second;
        pq.pop();

        if(dist[now_node][now_trap]<now_dist)
            continue;

        for(int i=0;i<normal_graph[now_node].size();i++){
            // now_node의 neighbor
            int next = normal_graph[now_node][i].first;
            // start -> now_node -> neighbor 비용
            int cost = normal_graph[now_node][i].second + now_dist;
            int ch1 = 0, ch2 = 0;

            // ch는 해당 노드의 함정이 발동되어 있는지에 대한 여부를 확인한다.

            // 현재 노드가 함정인 경우
            if(tmap.find(now_node) != tmap.end()){
                ch1 = now_trap & (1 << tmap[now_node]);
            }
            // 다음 노드가 함정인 경우
            if(tmap.find(next) != tmap.end()){
                ch2 = now_trap & (1 << tmap[next]);
            }

            // now_node, next 모두 함정을 발동시킨 경우
            // 둘 다 함정을 발동 시키지 않은 경우 normal_graph를 이용한다.
            if((ch1==0 && ch2==0) || (ch1>0 && ch2>0)) {
                int next_trap = now_trap;
                if(tmap.find(next) != tmap.end()){
                    next_trap = next_trap ^ (1 << tmap[next]);
                }
                if (cost < dist[next][next_trap]) {
                    dist[next][next_trap] = cost;
                    pq.push(make_pair(-cost, make_pair(next, next_trap)));
                }
            }
        }
        for(int i=0;i<trap_graph[now_node].size();i++) {
            int next = trap_graph[now_node][i].first;
            int cost = trap_graph[now_node][i].second + now_dist;
            int ch1 = 0, ch2 = 0;
            if(tmap.find(now_node) != tmap.end()){
                ch1 = now_trap & (1 << tmap[now_node]);
            }
            if(tmap.find(next) != tmap.end()){
                ch2 = now_trap & (1 << tmap[next]);
            }
            if((ch1==0 && ch2!=0) || (ch1!=0 && ch2==0)) {
                int next_trap = now_trap;
                if(tmap.find(next) != tmap.end()){
                    next_trap = next_trap ^ (1 << tmap[next]);
                }
                if (cost < dist[next][next_trap]) {
                    dist[next][next_trap] = cost;
                    pq.push(make_pair(-cost, make_pair(next, next_trap)));
                }
            }
        }
    }
    int ans = 1e9;
    for(int i=0;i<pow(2, traps.size());i++){
        if(ans>dist[end][i]){
            ans = dist[end][i];
        }
    }
    return ans;
}

int main() {
    cout << solution(3, 1, 3, {{1, 2, 2}, {3, 2, 3}}, {2}) << endl;
    cout << solution(4, 1, 4, {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}}, {2, 3});

    return 0;
}