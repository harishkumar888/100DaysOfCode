/*

257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

*/


#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// This iterative approach has some bugs.
// ex: [1,2,3,4,5,6] gives incorrect results
vector<string> binaryTreePaths_incorrect(TreeNode* root) {
    if(!root) return {};
    vector<string> res;
    string cur_str = std::to_string(root->val);
    stack<TreeNode*> tr_stack;
    tr_stack.push(root);
    int count = 0;
    while(!tr_stack.empty()){
        TreeNode* cur_node = tr_stack.top();
        tr_stack.pop();
        string prev_str = cur_str;
        if(count != 0) cur_str += "->" + std::to_string(cur_node->val);
        if(cur_node->right || cur_node->left) {
            if(cur_node->right) tr_stack.push(cur_node->right);
            if(cur_node->left) tr_stack.push(cur_node->left);
        }
        else{
            res.push_back(cur_str);
            cur_str = prev_str;
        }
        count++;
    }
    return res;
}

void binaryTreePaths_helper(TreeNode* root, string s, vector<string>& res){
  if(!root) return;
  if(root->left && root->right){
    binaryTreePaths_helper(root->left, s+"->"+std::to_string(root->left->val), res);
    binaryTreePaths_helper(root->right, s+"->"+std::to_string(root->right->val), res);
  }
  else if(root->left){
    binaryTreePaths_helper(root->left, s+"->"+std::to_string(root->left->val), res);
  }
  else if(root->right){
    binaryTreePaths_helper(root->right, s+"->"+std::to_string(root->right->val), res);
  }
  else{
    res.push_back(s);
  }
}

vector<string> binaryTreePaths(TreeNode* root){
  if(!root) return {};
  string s = std::to_string(root->val);
  vector<string> res;
  binaryTreePaths_helper(root, s, res);
  return res;
}

int main() {
  TreeNode* tr = new TreeNode(1);
  tr->left = new TreeNode(2);
  tr->left->left = new TreeNode(4);
  tr->left->right = new TreeNode(5);
  tr->right = new TreeNode(3);
  tr->right->left = new TreeNode(6);

  vector<string> ans = binaryTreePaths(tr);

  for(auto elem:ans)
    cout << elem << " ";

  return 0;
}
