#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy=new ListNode(-1);
    ListNode *temp=dummy;
    int carry=0;

    while(l1!=NULL || l2!= NULL || carry) {
        int value=carry;
        if(l1!=NULL) {
            value += l1->val;
            l1 = l1->next;
        }
            
        if(l2!=NULL) {
            value += l2->val;
            l2=l2->next;
        }
            
        carry=value/10;
        ListNode* newNode=new ListNode(value%10);
        temp->next=newNode;
        temp=temp->next;
            
    }
       
    return dummy->next;
}

 void printLinkedList(ListNode* head) {
    while(head != NULL) {
        cout<<head->val<<'\n';
        head=head->next;
    }
    return;
 }

 int main() {
    ListNode* head = new ListNode(1);
    ListNode *second = new ListNode(2);
    head->next=second;
    ListNode *third = new ListNode(3);
    second->next=third;

    cout<<"First Linked List"<<'\n';
    printLinkedList(head);    

	ListNode* head1 = new ListNode(3);
    ListNode *second1 = new ListNode(2);
    head1->next=second1;
    ListNode *third1 = new ListNode(1);
    second1->next=third1;

    cout<<"Second LinkedList"<<'\n';
    printLinkedList(head1);

    ListNode* merged = addTwoNumbers(head,head1);

    cout<<"Merged Linked List"<<'\n';
    printLinkedList(merged);
    
    return 0;
 }
