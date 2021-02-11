#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    priority_queue< pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>> > tel_list;
    unordered_map<string, int> phone_hash;
    unordered_map<int, int> size_hash;
    unordered_map<int, int>::iterator iter;
    int size;
    string phone;


    for (int i = 0; i < phone_book.size(); i++)
        tel_list.push({phone_book[i].size(), phone_book[i]});

    while (!tel_list.empty()) {
        size = tel_list.top().first;
        phone = tel_list.top().second;
        tel_list.pop();

        for (iter = size_hash.begin(); iter != size_hash.end(); iter++) {
            int comp_size = iter->first;
            string comp_phone = phone.substr(0, comp_size);
            if (phone_hash.find(comp_phone) != phone_hash.end()) return false;
        }

        if (size_hash.find(size) == size_hash.end())
            size_hash[size] = 1;
        phone_hash[phone] = 1;
    }

    return true;
}