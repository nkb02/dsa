1. create a LL from array

/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* head = new Node(arr[0]);
    Node* node = head;
    for(int i = 1 ; i< arr.size(); i++){
        Node* cur = new Node(arr[i]);

        node->next = cur;
        node = node->next;
    }
    return head;
}

2. delete a node 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
            node-> val = node ->next-> val;
            node-> next = node->next->next; 
    }
};

3. Insert Node At The Beginning

/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* insertAtFirst(Node* list, int newValue) {
    // Write your code here
    Node* head =new Node(newValue, list);
    return head;
}


4. Count nodes of linked list

int length(Node *head)
{
    //Write your code here
    Node* temp;;
    temp = head;
    if(head->next == NULL) return 1;
    if(head == NULL) return 0;
    int xnt = 1;
    while(temp->next != NULL){
        temp = temp->next;
        xnt++;
    }
    return xnt;
}

5. Search in a Linked List

int searchInLinkedList(Node<int> *head, int k) {
    if(head == NULL) return 0;
    
    while(head != NULL){
        if(head -> data == k)
            return 1;
        head = head->next;
    }
    return 0;
}

6. Introduction To Doubly Linked List

/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node* constructDLL(vector<int>& arr) {
    // Write your code here

    Node* head = new Node(arr[0]);
    Node* cur = head;

    int n =arr.size();
    for(int i = 1; i < n ; i++){
        Node* temp = new Node(arr[i]);
        cur->next = temp;
        temp->prev= cur;
        cur = cur->next;
    } 

    return head;
}


7. Insert at end of Doubly Linked List
/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * insertAtTail(Node *head, int k) {
    Node* temp = head;
    Node* node = new Node(k);
    if(head == NULL)
        return node;
    
    while(temp-> next!= NULL){
        temp = temp-> next;
    }
    temp->next = node;
    node ->prev = temp;
    return head;

}


8. Delete Last Node of a Doubly Linked List

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {
    Node* temp = head;
    if(temp == NULL){
        return temp;
    }
    if(temp->next == NULL)
        return NULL;
    Node* prev;
    while(temp->next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    prev->next = NULL;
    delete temp;
    return head;

}


9. Reverse A Doubly Linked List

Node* reverseDLL(Node* head)
{   
    // Write your code here   
    // Node* cur;

    while(head != NULL){
        Node* next = head->next;
        Node* prev = head->prev;
        head->next = prev;
        head->prev = next;
        if(head->prev == NULL) return head;
        head = head->prev;
    }
    return head;

    
}

// recursively

Node* reverseDLL(Node* head)
{
    // Base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursive calls
    Node * temp = reverseDLL(head->next);
    
    temp->prev = NULL;
    head->next->next = head;
    head->prev = head->next ;
    head->next = NULL;
    
    return temp;
}

// =============== STEP 6.3 ============================== //

10.  Middle of the Linked List

ListNode* middleNode(ListNode* head) {
        // tortoise tech
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)   {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

11. Reverse a LL 

# iterative 


Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node* newHead = NULL;
    while(head != NULL){
        Node* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;

    }
    return newHead; 
}

12. Reverse a LL 
    #recurusive
 
 ListNode* reverseList(ListNode* &head) {

        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }

13. cycle detection 

// optimal with O(1) space

bool detectCycle(Node *head)
{
    if(!head || !head->next) return false;

        Node * fast = head;
        Node * slow = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }
        return false;
}

14. starting point of a cycle


Node *firstNode(Node *head)
{
 
    if(!head || !head->next) return false;

        Node * fast = head;
        Node * slow = head;
        Node * entry = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;

             if(slow == fast) {
               while (slow != entry) {
                 slow = slow->next;
                 entry = entry->next;
               }
               return slow;
             }
        }
        return NULL;
 
}

15.  Palindrome Linked List

Approach:

* Following are the steps to this approach:-

    1. Find the middle element of the linked list.  
    2. Reverse a linked list from the next element of the middle element. 
    3. Iterate through the new list until the middle element reaches the end of the list.
    4. Use a dummy node to check if the same element exists in the linked list from the middle element.

 ListNode* reverseList(ListNode* head){
        ListNode* pre =NULL, *next = NULL;
        while(head){
            next= head-> next;
            head->next = pre;
            pre= head;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode * slow = head;
        ListNode * fast = head;
        // findign middle node
        while(fast->next && fast->next->next  ){
            fast= fast->next->next;
            slow = slow->next;
        }

        slow->next= reverseList(slow->next);
        slow = slow -> next;

        while(slow){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }



================ HARD ==============================

1. ROTATE BY K TIMES 

=> Steps to the algorithm:-

* Calculate the length of the list.
* Connect the last node to the first node, converting it to a circular linked list.
* Iterate to cut the link of the last node and start a node of k%length of the list rotated list.

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head || !head->next || k == 0) return head;

     int cnt = 1;
     Node* cur = head;
     while(cur->next && cnt++)
          cur = cur-> next;
     
     cur->next = head;
     // made it a circular LL
     k = k% cnt;
     int end = cnt - k;
     while(end--) cur = cur->next;

     head = cur->next;
     cur->next = NULL;
     return head;
     
}

2. Clone a  Ll 


Approach:
* The optimisation will be in removing the extra spaces, i.e, the hashmap used in brute force. This approach can be broken down into three steps. 

* Create deep nodes of all nodes. Instead of storing these nodes in a hashmap, we will point it to the next of the original nodes.
* Take a pointer, say itr, point it to the head of the list. This will help us to point random pointers as per the original list. This can be achieved by itr->next->random = itr->random->next
* Use three pointers. One dummy node whose next node points to the first deep node. itr pointer at the head of the original list and fast which is two steps ahead of the itr. This will be used to separate the original linked list with the deep nodes list.


Node* copyRandomList(Node* head) {
     Node* temp = head;
  //step 1
    while(temp != NULL) {
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
  //step 2
    Node* itr = head;
    while(itr != NULL) {
        if(itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
  //step 3
    Node* dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node* fast;
    while(itr != NULL) {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;

}

3. flattening the LinkedList

Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}