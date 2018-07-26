/*



*/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
    stack<TreeNode*> node_stack;
    
    BSTIterator(TreeNode *root){
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !node_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        int next_num=-1;
        if(!node_stack.empty()){
            TreeNode* top_node = node_stack.top();
            node_stack.pop();
            pushAll(top_node->right);
            next_num = top_node->val;
        }
        return next_num;
    }
    
    void pushAll(TreeNode* root){
        while(root != nullptr){
            node_stack.push(root);
            root = root->left;
        }
    }
};

int main(){
    TreeNode* my_tree = new TreeNode(2);
    BSTIterator i = BSTIterator(my_tree);
    while(i.hasNext()){
        i.next();
    }
    return 0;
}