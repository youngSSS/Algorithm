#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

struct pinfo {
    int pid;
    int buy_count;
    int rebuy_count;
    int total_count;
};

bool cmp(const pinfo& p1, const pinfo& p2){
    double r1;
    if(p1.buy_count > 0)
        r1 = double(p1.rebuy_count)/double(p1.buy_count);
    else
        r1 = 0.0;
    double r2;
    if(p2.buy_count > 0)
        r2 = double(p2.rebuy_count)/double(p2.buy_count);
    else
        r2 = 0.0;

    if (abs(r1-r2) < 0.000001){
        if(p1.total_count > p2.total_count){
            return true;
        }
        else if(p1.total_count < p2.total_count){
            return false;
        }
        else{
            if(p1.pid<p2.pid){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else if(r1>r2){
        return true;
    }
    else return false;
}

vector<string> solution(vector<string> records, int k, string date) {
    vector<string> answer;
    map<pair<int,int>, int> buying_info;
    map<int, pinfo> pmap;
    vector<pinfo> p_list;

    int year, month, day;
    int check = 0;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    int base_date = year * 30 * 12 + month * 30 + day;

    for(int i=0; i<records.size(); i++){
        int year, month, day, pid, uid;
        sscanf(records[i].c_str(), "%d-%d-%d uid%d pid%d", &year, &month, &day, &uid, &pid);
        int convert_date = year * 30 * 12 + month * 30 + day;

        if(base_date >= convert_date && base_date - convert_date<k){
            buying_info[make_pair(pid, uid)] += 1;
            pmap[pid].pid = pid;

            if(buying_info[make_pair(pid, uid)] == 1)
                pmap[pid].buy_count += 1;
            if(buying_info[make_pair(pid, uid)] == 2)
                pmap[pid].rebuy_count += 1;

            pmap[pid].total_count += 1;
            check += 1;
        }
    }

    if(check == 0){
        answer.push_back("no result");
        return answer;
    }

    for(auto iter = pmap.begin(); iter != pmap.end(); iter++){
        p_list.push_back(iter->second);
    }

    sort(p_list.begin(), p_list.end(), cmp);
    for(int i=0;i<p_list.size();i++){
        answer.push_back("pid"+to_string(p_list[i].pid));
        cout<<p_list[i].pid<<endl;
    }

    return answer;
}