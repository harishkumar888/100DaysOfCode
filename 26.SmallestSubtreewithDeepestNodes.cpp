/*

866. Smallest Subtree with all the Deepest Nodes

Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible.

Return the node with the largest depth such that it contains all the deepest nodes in it's subtree.

Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation:

We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.

Note:

The number of nodes in the tree will be between 1 and 500.

*/

#include <algorithm>
#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root){
    return !root ? 0 : max(depth(root->left), depth(root->right))+1;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int d = depth(root->left) - depth(root->right);
    return !d ? root : subtreeWithAllDeepest(d>0 ? root->left : root->right);
}

int main() {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  cout << subtreeWithAllDeepest(root)->val;

  return 0;
}