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

 void deleteNode(ListNode* node) {
        node->val = node->next->val;
        
        node->next = node->next->next;
        return;
}

int main() {
	ListNode* head = new ListNode(1);
	ListNode *second = new ListNode(2);
	head->next=second;
	ListNode *third = new ListNode(3);
	second->next=third;

	deleteNode(second);
	printLinkedList(head);
	return 0;
}