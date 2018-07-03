/*
19. Remove Nth Node From End of List
DescriptionHintsSubmissionsDiscussSolution
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

*/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

ListNode* removeNthFromEnd_naive(ListNode* head, int n) {
    ListNode* node = head;
    int i=0, count=0;

    // Count the number of nodes
    while(node){
        count++;
        node = node->next;
    }
    node = head;
    
    if(count>n){
        for(i=0; i<count-n-1; ++i){
            node = node->next;
        }
        node->next = node->next->next;
    }
    else{
        // If the first element needs to be removed
        head = node->next;
    }
    
    return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode *slow=head, *fast=head;
    while(n-->0) fast=fast->next; // fast pointer is exactly n steps ahead of slow.
    if(fast==nullptr) return head->next; // The head needs to be removed.
    
    fast = fast->next;

    while(fast!=nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next; // The node after the slow needs to be removed.
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    ListNode* node = head;

    cout << "Before removing elements.\n" ;
    while(node){
        cout << node->val << " ";
        node = node->next;
    }

    node = removeNthFromEnd(head, n);

    cout << "\nAfter removing the " << n << "th element.\n" ;
    while(node){
        cout << node->val << " ";
        node = node->next;
    }

    return 0;
}