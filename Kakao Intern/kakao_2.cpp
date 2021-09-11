#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(int x,int y,int d,vector<string>& places, vector<vector<int>>& visit){
    if(d>2)
        return 0;
    if(d!=0 && places[x][y] == 'P')
        return 1;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx<5 && ny<5 && places[nx][ny]!='X' && visit[nx][ny]==0){
            visit[nx][ny] = 1;
            int value = dfs(nx,ny,d+1,places,visit);
            visit[nx][ny] = 0;
            if(value == 1){
                return 1;
            }
        }
    }
    return 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i=0;i<5;i++){
        int ans = 1;
        vector<vector<int>> visit(5,vector <int>(5,0));
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k] == 'P'){
                    visit[j][k] = 1;
                    int value = dfs(j,k,0,places[i], visit);
                    visit[j][k] = 0;
                    if(value == 1){
                        ans = 0;
                    }
                }
            }
        }
        answer.push_back(ans);

    }
    return answer;
}

int main() {
    vector<int> answer = solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});

    for (auto ans : answer)
        cout << ans << " ";

    return 0;
}