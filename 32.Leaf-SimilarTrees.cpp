/*
872. Leaf-Similar Trees

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar. 

Note:

Both of the given trees will have between 1 and 100 nodes.

*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void leafVec(TreeNode* root, vector<int>& res){
    if(root == nullptr) return;
    if(!root->left && !root->right)
        res.push_back(root->val);
    leafVec(root->left, res);
    leafVec(root->right, res);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> res1, res2;
    leafVec(root1, res1);
    leafVec(root2, res2);
    return res1 == res2;
}

int main(){
    TreeNode* root1 = [3,5,1,6,2,9,8,null,null,7,4];
    TreeNode* root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8];
    leafSimilar(root1, root2);
    return 0;
}
