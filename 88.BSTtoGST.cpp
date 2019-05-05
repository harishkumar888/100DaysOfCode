/*
5050. Binary Search Tree to Greater Sum Tree

Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree
that are greater than or equal to node.val.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Note:

The number of nodes in the tree is between 1 and 100.
Each node will have value between 0 and 100.
The given tree is a binary search tree.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bstToGst(TreeNode* root) {
    vector<int> org;
    bstValues(root, org);
    replaceValues(root, org);
    return root;
}

void bstValues(TreeNode* root, vector<int>& org){
    if(root == nullptr)
        return;
    bstValues(root->left, org);
    org.push_back(root->val);
    bstValues(root->right, org);
}

int greaterSum(vector<int>& org, int num){
    int gSum = 0;
    auto it = lower_bound(org.begin(), org.end(), num);
    for(;it != org.end(); ++it)
        gSum += *it;
    return gSum;
}

void replaceValues(TreeNode* root, vector<int>& org){
    if(root == nullptr)
        return;
    replaceValues(root->left, org);
    root->val = greaterSum(org, root->val);
    replaceValues(root->right, org);
}

int main(){
    TreeNode* root;
    bstToGst(root);
}