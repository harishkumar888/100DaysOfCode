/*
919. Complete Binary Tree Inserter

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.

Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
Example 2:

Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]

Note:

The initial given tree is complete and contains between 1 and 1000 nodes.
CBTInserter.insert is called at most 10000 times per test case.
Every value of a given or inserted node is between 0 and 5000.

*/

#include <iostream>
#include <queue>

using namespace std;


//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {
public:
    TreeNode* head;
    queue<TreeNode*> q;
    CBTInserter(TreeNode* root) {
        head = root;
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        int ans=0;
        q = queue<TreeNode*>();
        q.push(head);
        while(true){
            TreeNode* next = q.front();
            q.pop();
            if(next->left != NULL && next->right != NULL){
                q.push(next->left);
                q.push(next->right);
            }
            else{
                if(next->left == NULL){
                    next->left = node;
                }else{
                    next->right = node;
                }
                ans = next->val;
                break;
            }
        }
        return ans;
    }
    
    TreeNode* get_root() {
        return head;
    }
    
};

/*class CBTInserter {
public:
    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size();++i) {
            if (tree[i]->left) tree.push_back(tree[i]->left);
            if (tree[i]->right) tree.push_back(tree[i]->right);
        }
    }

    int insert(int v) {
        int N = tree.size();
        TreeNode* node = new TreeNode(v);
        tree.push_back(node);
        if (N % 2)
            tree[(N - 1) / 2]->left = node;
        else
            tree[(N - 1) / 2]->right = node;
        return tree[(N - 1) / 2]->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }
};
*/

int main(){
    TreeNode* root = new TreeNode(1);
    root->left =  new TreeNode(2);
    root->right =  new TreeNode(3);
    root->left->left =  new TreeNode(4);
    root->left->right =  new TreeNode(5);
    root->right->left =  new TreeNode(6);
    CBTInserter obj = CBTInserter(root);

    cout << obj.insert(7) << " ";
    cout << obj.insert(8);

    TreeNode* param_2 = obj.get_root();

    return 0;
}