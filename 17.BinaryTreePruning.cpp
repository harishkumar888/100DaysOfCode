/*
814. Binary Tree Pruning

We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Note:

The binary tree will have at most 100 nodes.
The value of each node will only be 0 or 1.

*/

#include <iostream>
#include <ostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    friend ostream& operator<<(ostream& os, const TreeNode* root){
        if(!root) return os;
        os<<root->val << " ";
        if(root->left) os<<root->left << " ";
        if(root->right) os<<root->right << " ";
        return os;
    }
};


TreeNode* pruneTree(TreeNode* root) {
    if(!root) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(!root->left && !root->right && root->val == 0)return nullptr;
    return root;
}

int main(){
    TreeNode* tr = new TreeNode(1);
    tr->left = new TreeNode(1);
    tr->left->left = new TreeNode(1);
    tr->left->left->left = new TreeNode(0);
    tr->left->right = new TreeNode(1);
    tr->right = new TreeNode(0);
    tr->right->left = new TreeNode(0);
    tr->right->right = new TreeNode(1);

    cout << tr << endl;

    pruneTree(tr);

    cout << tr << endl;

    return 0;
}