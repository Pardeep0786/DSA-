#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// To make a Node
class Node {
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

// Make a linked list
class List {
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    // Push the elements in front of the linked list
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }

    }

    // Push the elements at the end of the linked list
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delet the element from the front
    void pop_front(){
        if(head == NULL){
            cout<<"The List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    // Delet the element at the end
    void pop_back(){
        if(head == NULL){
            cout<<"The list is empty\n";
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // Insert the element in the linked list
    void Insert(int val, int Pos){
        if(Pos < 0){
            cout<<"Invalid Position";
            return;
        }
        if(Pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < Pos - 1; i++){
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Search the element in the linked list
    int Search(int key){
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Print the elements of the linked list
    void PrintLL(){
        Node* temp = head;

        while (temp != NULL){
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

//To make the structure of node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//To check the Cycle is exist or not
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* Slow = head;
        ListNode* Fast = head;
    
        while(Fast != NULL && Fast->next != NULL){
            Slow = Slow->next;
            Fast = Fast->next->next;
    
            if(Slow == Fast){
                return true;
            }
        }
        return false;
    }
};
//Detect the Cycle and return the begining indext of Cycle
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* Slow = head;
        ListNode* Fast = head;
        bool IsCycle = false;
    
    while(Fast != NULL && Fast->next != NULL){
        Slow = Slow->next;
        Fast = Fast->next->next;
    
        if(Slow == Fast){
            IsCycle = true;
            break;
        }
    
    }
    
    if(!IsCycle){
        return NULL;
    }
            
    Slow = head;
    while(Slow != Fast){
        Slow = Slow->next;
        Fast = Fast->next;
        }
        
        return Slow;
    }
};

//Return the middle node of linked list
class Solution3 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
    
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
    
        return slow;
    }
};

//To reverse the Linked list
class Solution4 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
    
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
    
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// Merge two Sorted list using Recursion
class Solution5 {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }
    
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }else{
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

//To make the structure of Linked list
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode* random;
        
    LLNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//To make a copy of link list and return its new head 
class Solution6 {
public:
    LLNode* copyRandomList(LLNode* head) {
        if(head == NULL){
            return NULL;
        }
    
        unordered_map <LLNode*, LLNode*> m;
    
        LLNode* newhead = new LLNode(head->val);
        LLNode* oldTemp = head->next;
        LLNode* newTemp = newhead;
        m[head] = newhead;
    
        while(oldTemp != NULL){
            LLNode* copynode = new LLNode(oldTemp->val);
            m[oldTemp] = copynode;
            newTemp->next = copynode;
    
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
    
        oldTemp = head, newTemp = newhead;
        while(oldTemp != NULL){
            
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newhead;
    }
};

//Doubly Linked List
//To make the structure of node 
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

//To create the doubly Linked list
class DoublyLinkedList{
    Node* head;
    Node* tail;
public:
    //To add the element in the front of doubly linked list
    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    //To delete the element at the end of the doubly linked list    
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;

        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
    }

    //To delete the element in the front of the doubly linked list
    void pop_front(){
        Node* temp = head;
        head = head->next;

        if(head != NULL){
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    //To delete the element at the end of the doubly linked list
    void pop_back(){
        Node* temp = tail;
        tail = tail->prev;

        if(tail != NULL){
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }

    //To print the elements of the doubly linked list
    void Print(){
        Node* temp = head;

        while(temp != NULL){
            cout<< temp->data <<"<=>";
            temp = temp->next;
        }
        cout<<"NULL \n";
    }
};
