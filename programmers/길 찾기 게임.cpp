#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> pre, post;

typedef struct Tree {
    int x, y, id;
    Tree * left, * right;

    void insert(int a, int b, int tree_id) {
        Tree * target = a < x ? left : right;

        if (target == nullptr) {
            if (a < x) {
                left = new Tree();
                left->x = a;
                left->y = b;
                left->id = tree_id;
            }
            else {
                right = new Tree();
                right->x = a;
                right->y = b;
                right->id = tree_id;
            }

        }
        else target->insert(a, b, tree_id);
    }

} Tree;

void dfs(Tree * tree) {
    if (tree == nullptr) return;

    pre.push_back(tree->id);

    dfs(tree->left);
    dfs(tree->right);

    post.push_back(tree->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    unordered_map<int, vector<int>> map;
    Tree * tree = new Tree();

    for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i] = {-nodeinfo[i][1], nodeinfo[i][0], i + 1};
    sort(nodeinfo.begin(), nodeinfo.end());

    tree->x = nodeinfo[0][1];
    tree->y = -nodeinfo[0][0];
    tree->id = nodeinfo[0][2];

    for (int i = 1; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][1];
        int y = -nodeinfo[i][0];
        int tree_id = nodeinfo[i][2];

        tree->insert(x, y, tree_id);
    }

    dfs(tree);
    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

int main() {
    solution({{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}});
    return 0;
}