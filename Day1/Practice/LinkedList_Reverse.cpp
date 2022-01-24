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

ListNode* reverseList(ListNode* head) {
    ListNode *prev=NULL;
    while(head!=NULL) {
        ListNode *temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;            
    }
    return prev;
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

    cout<<"Before Reversal"<<'\n';
    printLinkedList(head);
    head=reverseList(head);
    cout<<"After Reversal"<<'\n';
    printLinkedList(head);

    return 0;
}