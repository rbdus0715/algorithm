#include <iostream>
using namespace std;

struct TreeNode {
    int x;
    TreeNode* parent;
    vector<TreeNode*> children;
}

void print(TreeNode* root) {
    cout << root->x << endl;
    for(int i=0; i<root->children.size(); i++)
        print(root->children[i]);
}

int height(TreeNode* root) {
    int h = 0;
    for(int i=0; i<root->children.size(); i++)
        h = max(h, 1 + height(root->children[i]));
    
    return h;
}
