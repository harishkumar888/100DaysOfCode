/*

83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    friend ostream& operator<<(ostream & os, ListNode* inp)
    {
        while(inp){
            os << inp->val << " ";
            inp = inp->next;
        }
        return os;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr) return nullptr;
    ListNode* prev_node = head;
    ListNode* cur_node = head->next;
    while(cur_node){
        if(cur_node->val==prev_node->val){
            prev_node->next = cur_node->next;
        }
        else
            prev_node = cur_node;
        cur_node = cur_node->next;
    }
    return head;
}

int main(){
    ListNode* inp = new ListNode(1);
    inp->next =  new ListNode(1);
    inp->next->next =  new ListNode(2);

    cout << "Input linked list: " << inp << endl;

    ListNode* res = deleteDuplicates(inp);

    cout << "Linked list without duplicates: " << res << endl;

    return 0;
}
