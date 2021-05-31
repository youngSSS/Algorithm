#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> delete_item;
    string answer = "";
    int cnt = 0;
    // insert, delete 등의 시간복잡도 줄이기 위해
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(i);
    }
    // k의 iterator
    auto kit = s.find(k);

    for(int i=0;i<cmd.size();i++) {

        if(cmd[i][0] == 'D'){
            int x = stoi(cmd[i].substr(2));
            for(;x>=1;x--)
                kit++;
        }
        if(cmd[i][0] == 'U'){
            int x = stoi(cmd[i].substr(2));
            for(;x>=1;x--)
                kit--;
        }
        if(cmd[i][0] == 'C'){
            int flag = 0;
            auto now_it = kit;
            kit++;
            if(kit == s.end()){
                kit = now_it;
                kit --;
            }
            int value = *kit;
            delete_item.push_back(*now_it);
            s.erase(*now_it);
        }
        if(cmd[i][0] == 'Z') {
            int value = *kit;
            s.insert(delete_item.back());
            delete_item.pop_back();
            kit = s.find(value);
        }
    }

    for(int i=0;i<n;i++)
        answer+='O';
    for(int i=0;i<delete_item.size();i++){
        answer[delete_item[i]]='X';
    }

    return answer;
}

int main() {
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;

    return 0;
}
