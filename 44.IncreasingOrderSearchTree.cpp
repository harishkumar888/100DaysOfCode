/*
897. Increasing Order Search Tree

Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* increasingBST(TreeNode* root) {
    TreeNode* new_node = root;
    stack<TreeNode*> s;
    vector<int> vec;
    while(new_node){
        if(new_node->left)
            new_node = new_node->left;
        else
            break;
    }
    
    TreeNode* cur = root;
    while(!s.empty() || cur != nullptr){
        while(cur != nullptr){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        vec.push_back(cur->val);
        cur = cur->right;
    }
    new_node = cur = new TreeNode(vec[0]);
    for(int i=1; i<vec.size(); ++i){
        cur->right = new TreeNode(vec[i]);
        cur = cur->right;
    }
    return new_node;
}
    
int main() {
  TreeNode* root = new TreeNode(1);
  root->left =  new TreeNode(2);
  root->right =  new TreeNode(3);

  increasingBST(root);
  return 0;
}
