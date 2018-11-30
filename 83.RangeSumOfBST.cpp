/*
938. Range Sum of BST

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;
    
    if(root != NULL)
    {
        bool KleinerR = root->val <= R;
        bool GroesserL = root->val >= L;
            
        if(GroesserL && KleinerR)
        {
            sum = root->val;
        }
        
        if(KleinerR)
            sum = sum + rangeSumBST(root->right, L, R);
        
        if(GroesserL)
            sum = sum + rangeSumBST(root->left, L, R);
    }
    
    return sum;
}

int rangeSumBST_naive(TreeNode* root, int L, int R) {
    int res = 0;
    stack<TreeNode*> s;
    while(root != NULL || !s.empty()){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
        TreeNode* top = s.top();
        s.pop();
        if(top->val >= L && top->val <= R){
            res += top->val;
        }
        root = top->right;
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    cout << rangeSumBST(root, 7, 15);
    return 0;
}