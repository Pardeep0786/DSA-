#include <iostream>
using namespace std;

// To make the structure of node
class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

//To make the circular Linked list
class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){
        head = tail = NULL;
    }

    //Add the element at the front of the linked list
    void IAhead(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    //Add the element at the end of the linked list
    void IAtail(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //Delete the element from the begning of the linked list
    void Dlhead(){
        if(head == NULL) return;
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
        
    }

    //Delete the element from the end of the linked list
    void Dltail(){
        if(head == NULL) return;
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = tail;
            Node* prev = head;

            while(prev->next != tail){
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }
};

//Flatten the Doubly Linked List
class DNode {
public:
    int val;
    DNode* prev;
    DNode* next;
    DNode* child;
};
class Solution {
public:
    DNode* flatten(DNode* head) {
        if(head == NULL) {
            return head;
        }    
        DNode* curr = head;
    
        while(curr != NULL){
            if(curr->child != NULL){
                DNode* next = curr->next;
                    
                curr->next = flatten(curr->child);
                    
                curr->next->prev = curr;
                curr->child = NULL;
    
                while(curr->next != NULL){
                    curr = curr->next;
                }
    
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }
    
            curr = curr->next;
        }
        return head;
    }
};

//To make the structure of ListNode
struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//To reverse nodes in k-Group
class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        // To check the k nodes are exist or note
        while(count < k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }
        //recursively call the rest of node
        ListNode* prevNode = reverseKGroup(temp, k);
    
        //reverse the k Nodes
        temp = head, count = 0;
        while(count < k){
            ListNode* next = temp->next;
            temp->next = prevNode;
    
            prevNode = temp;
            temp = next;
                
            count++;
        }
        return prevNode;
    }
};

//Swap the nodes in Pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
    
        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;
    
        while(first != NULL && sec != NULL){
            ListNode* third = sec->next;
    
            sec->next = first;
            first->next = third;
    
            if(prev != NULL){
                prev->next = sec;
            }else{
                head = sec;
            }
    
            //Updation
            prev = first;
            first = third;
            if(third != NULL){
                sec = third->next;
            }else{
                sec = NULL;
            }
        }
        return head;
    }
};