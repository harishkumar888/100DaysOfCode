/*
863. All Nodes Distance K in Binary Tree

We are given a binary tree (with root node root), a target node, and an integer value `K`.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]
Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.

*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value), left(nullptr), right(nullptr){}
};

void dfs(unordered_map<TreeNode*, TreeNode*>& backEdge, TreeNode* root, TreeNode* target){
    if(!root || (root == target)) return;
    if(root->left){
        backEdge[root->left] = root;
        dfs(backEdge, root->left, target);
    }
    if(root->right){
        backEdge[root->right] = root;
        dfs(backEdge, root->right, target);
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    unordered_map<TreeNode*, TreeNode*> backEdge;
    unordered_set<TreeNode*> visited;
    vector<int> res;

    dfs(backEdge, root, target);
    queue<TreeNode*> que;
    que.push(target);

    while(!que.empty() && k>=0){
        int s = que.size();
        while(s--){
            TreeNode* cur = que.front();
            int val = cur->val;
            que.pop();
            visited.insert(cur);
            if(k==0) res.push_back(val);
            if(!visited.count(backEdge[cur]) && backEdge[cur]) que.push(backEdge[cur]);
            if(!visited.count(cur->left) && cur->left) que.push(cur->left);
            if(!visited.count(cur->right) && cur->right) que.push(cur->right);
        }
        k--;
    }

    return res;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode* target = root->left;
    int k = 2;

    vector<int> res = distanceK(root, target, k);

    for(auto elem: res)
        cout << elem << " ";

    return 0;
}