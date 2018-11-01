/*

24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs_naive(ListNode* head){
    // Doesn't work for odd nuber of elements
    if(!head || !head->next) return head;
    ListNode* one = head;
    ListNode* two = head->next;
    ListNode* nextOne = two->next;
    ListNode* prev = two;
    head = two;
    while(one && two){
        prev = one;
        one->next = nextOne;
        two->next = one;
        one = nextOne;
        two = nextOne != NULL ? nextOne->next : NULL;
        nextOne = two != NULL ? two->next : NULL;
        if(prev)prev->next = two;
    }
    return head;
}

ListNode* swapPairs_alt(ListNode* head){
    // Could cause memory leak issue.
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    while(head && head->next){
        ListNode* nn = head->next->next;
        prev->next = head->next;
        head->next->next = head;
        head->next = nn;
        prev = head;
        head = nn;
    }
    return dummy->next;
}

ListNode* swapPairs(ListNode* head){
    ListNode **p = &head, *ptr = NULL;
    while((*p) && (*p)->next){
        ptr = (*p)->next->next;
        (*p)->next->next = (*p);
        (*p) = (*p)->next;
        (*p)->next->next = ptr;
        p = &((*p)->next->next);
    }
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before swapping" << endl;
    ListNode* dupHead = head;
    while(dupHead){
        cout << dupHead->val << "->";
        dupHead = dupHead->next;
    }
    cout << endl;

    head = swapPairs(head);

    while(head){
        cout << head->val << "->";
        head = head->next;
    }
    return 0;
}