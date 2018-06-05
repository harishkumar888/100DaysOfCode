/*
Leetcode problem
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* head = res;
    int quotient=0;
    int carry=0;
    while(l1 != NULL || l2 != NULL){
      int x = (l1 != NULL) ? l1->val : 0;
      int y = (l2 != NULL) ? l2->val : 0;
      int summ = x+y+carry;
      carry = summ/10;
      res->next = new ListNode(summ%10);
      res = res->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    if(carry>0)
      res->next = new ListNode(carry);
    return head->next;
}

int main() {
  //Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  //Output: 7 -> 0 -> 8
  
  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  ListNode* ans = addTwoNumbers(l1, l2);

  cout << "The output is: ";
  while(ans){
    cout << ans->val;
    ans=ans->next;
  }
  
}