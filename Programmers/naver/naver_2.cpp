#include <vector>
#include <algorithm>

using namespace std;

//struct tree {
//    int x;
//    tree * l;
//    tree * r;
//};

int is_visited[50001] = {0, };
int answer;

void dfs(tree * T, int count) {
    int cur_node = T->x;

    if (is_visited[cur_node] == 1) return;

    is_visited[cur_node] = 1;
    count += 1;

    if (T->l != NULL) dfs(T->l, count);
    if (T->r != NULL) dfs(T->r, count);

    is_visited[cur_node] = 0;

    if (count > answer) answer = count;
}

int solution(tree * T) {
    dfs(T, 0);
    return answer;
}


int main() {
    return 0;
}
