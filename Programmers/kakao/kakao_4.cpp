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
            int next = normal_graph[now_node][i].first;
            int cost = normal_graph[now_node][i].second + now_dist;
            int ch1 = 0, ch2 = 0;
            if(tmap.find(now_node) != tmap.end()){
                ch1 = now_trap & (1 << tmap[now_node]);
            }
            if(tmap.find(next) != tmap.end()){
                ch2 = now_trap & (1 << tmap[next]);
            }
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