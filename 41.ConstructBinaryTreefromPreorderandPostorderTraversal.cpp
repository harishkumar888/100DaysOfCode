/*
889. Construct Binary Tree from Preorder and Postorder Traversal

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161372/Logical-Thinking-with-Code



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

static int preStart;

TreeNode* recursive_helper(vector<int>& pre, vector<int>& post, int postStart, int postEnd){
    if(postStart > postEnd || preStart >= pre.size())
        return nullptr;

    TreeNode* node = new TreeNode(pre[preStart]);
    preStart++;

    int pi=0;
    for(;pi<pre.size();++pi){
        if(pre[pi] == post[pi])
            break;
    }

    node->left = recursive_helper(pre, post, postStart, pi);
    node->right = recursive_helper(pre, post, pi+1, postEnd-1);
    return node;
}

TreeNode* constructFromPrePost(vector<int>&pre, vector<int>& post) {
    preStart=0;
    return recursive_helper(pre, post, 0, post.size());
}

TreeNode* constructFromPrePost_alt(vector<int>& pre, vector<int>& post){
    vector<TreeNode*> s;
    s.push_back(new TreeNode(pre[0]));
    for(int i=1, j=0; i<pre.size(); ++i){
        TreeNode* node = new TreeNode(pre[i]);
        while(s.back()->val == post[j])
            s.pop_back(), j++;
        if(s.back()->left == nullptr)
            s.back()->left = node;
        else
            s.back()->right = node;
        s.push_back(node);
    }
    return s[0];
}

int main(){
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};
    TreeNode* res = constructFromPrePost_alt(pre, post);
    return 0;
}