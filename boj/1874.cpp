#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string ans = "";
    vector<int> stack, targets(n, 0);

    for (int i = 0; i < n; i++)
        scanf("%d", &targets[i]);

    int target_idx = 0;
    for (int i = 1; i <= n; i++) {
        stack.push_back(i);
        ans += "+\n";

        while (target_idx < n && stack.back() == targets[target_idx]) {
            ans += "-\n";
            stack.pop_back();
            target_idx += 1;
        }

        if (target_idx >= n) break;
    }

    if (target_idx == n) printf("%s", ans.c_str());
    else printf("NO\n");

    return 0;
}