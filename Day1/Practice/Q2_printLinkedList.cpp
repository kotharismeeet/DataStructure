#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 void printLinkedList(ListNode* head) {
    while(head != NULL) {
        cout<<head->val<<'\n';
        head=head->next;
    }
    return;
 }

 int main() {
    ListNode* head = new ListNode(5);
    ListNode *second = new ListNode(3);
    head->next=second;
    ListNode *third = new ListNode(1);
    second->next=third;
    ListNode *fourth = new ListNode(2);
    third->next=fourth;
    ListNode *fifth = new ListNode(4);
    fourth->next = fifth;
    fifth->next=NULL;
    
    printLinkedList(head);
    cout<<"Time Complexity O(N) and Space Complexity O(1)"<<'\n';
    return 0;
 }