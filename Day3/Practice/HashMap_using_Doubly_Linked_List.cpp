class MyHashMap {

    // In progress has too many errors
public:
    
    struct ListNode() {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int x) : val(x),next(null){}
    };
    
    MyHashMap() {
      ListNode* head=new ListNode(-1);
      ListNode* tail=head;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        
    } 
    
    void put(int key, int value) {
        // For std::map linear , NlogN in worst case 
        // O(N) For singly Linked List
        // theta(N) and O(N*N) for Doubly Linked List
        ListNode* traversal=head;
        bool found=false;
        while(traversal != tail) {
            if(traversal->key == key) {
                traversal->val = value;
                found=true;
                break;
            }
        }
        if(!found) {
            ListNode* newNode=new ListNode(value);
            this.tail->next=newNode;
            this.head=insertionList(this.head);
        }
        
    }
    
    ListNode* middleNode(ListNode* first,ListNode* last) {
        ListNode* slow=first;
        ListNode* fast=first;
        while(fast != last && fast->next != last) {
            slow=slow->next;
            fast=fast->next->next;
        } 
        return slow;
    }
    
    int get(int key) {
        // For map O(1)
        // O(N) for singly Linked List
        // O(NlogN) using binary search in Sorted Doubly LinkedList
        ListNode* first=head,last=tail;
        while(first!=last) {
            ListNode* mid=middleNode(first,last);
            if(mid->key == key) {
                return mid->val;
            }
            else if(mid->key > key) {
                last=mid->prev;
            }
            else first=mid->next;
        }
        
    }
    
    void remove(int key) {
       // For map map.size()+last-first
       // O(N) for singly Linked List
        // O(NlogN) using binary search in Sorted Doubly LinkedList
        ListNode* first=head,last=tail;
        while(first!=last) {
            ListNode* mid=middleNode(first,last);
            if(mid->key == key) {
                // delete mid
                return;
                break;
            }
            else if(mid->key > key) {
                last=mid->prev;
            }
            else first=mid->next;
        }
        return;        
    }
    
};