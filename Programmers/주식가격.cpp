#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int>  st;
    int         top;

    answer.resize(prices.size());

    for (int t = 0; t < prices.size(); t++) {

        if (st.empty()) st.push(t);

        else {
            top = st.top();
            while (prices[top] > prices[t]) {
                answer[top] = t - top;
                st.pop();

                if (st.empty()) break;

                top = st.top();
            }
            st.push(t);
        }
    }

    while (!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }

    return answer;
}

int main() {
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> answer = solution(prices);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];

    return 0;
}
