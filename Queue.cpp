#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

//Make a queue using Linked List
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = tail = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void pop(){
        if(head == NULL){
            cout<<"The Queue is empty :" <<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(empty()){
            cout<<" LL is empty :\n";
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }
};

//Circular Queue
class CircularQueue{
public:
    int* arr;
    int CurrSize, cap;
    int f, r;

    CircularQueue(int size){
        cap = size;
        arr = new int(cap);
        CurrSize = 0;
        f = 0; 
        r = -1;
    }

    void push(int data){
        if(CurrSize == cap){
            cout<<"The Queue is not empty :" <<endl;
            return;
        }
        r = (r + 1)%cap;
        arr[r] = data;
        CurrSize++;
    }

    void pop(){
        if(empty()){
            cout<<"The Queue is empty" <<endl;
            return;
        }
        f = (f + 1)%cap;
        CurrSize--;
    }

    int front(){
        if(empty()){
            cout<<"The Queue is empty" <<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return CurrSize == 0;
    }

    void print(){
        for(int i = 0; i < cap; i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }
};

//Implementation Stack using queue
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
            
    }
        
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    
        q1.push(x);
    
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
        
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
        
    int top() {
        return q1.front();
    }
        
    bool empty() {
        return q1.empty();
    }
};

//Implementation of queue using Stack
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
            
    }
        
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    
        s1.push(x);
    
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
        
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
        
    int peek() {
        return s1.top();
    }
        
    bool empty() {
        return s1.empty();
    }
};

//Find the first unique character in the string using queue
int firstUniqChar(string s) {
    unordered_map<char, int> m;
    queue<int> q;

    for(int i = 0; i<s.size(); i++){
        if(m.find(s[i]) == m.end()){
            q.push(i);
        }

        m[s[i]]++;
    }

    while(q.size() > 0 && m[s[q.front()]] > 1){
        q.pop();
    }

    return q.empty() ? -1 : q.front();
}

//Sliding Window Maximum (using dequeue)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    //First Window
    for(int i = 0; i<k; i++){
        while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
    dq.push_back(i);    
    }

    for(int i = k; i<nums.size(); i++){
        ans.push_back(nums[dq.front()]);

        //remove part which is not belongs to the current window
        while(dq.size() > 0 && dq.front() <= i - k){
            dq.pop_front();
        }

        //remove the smaller values
        while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    return ans;
} 
int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

   cout<<"Functions of Queue :" <<endl;
    while(!q.empty()){
        cout<< q.front() <<" ";
        q.pop();
    }
    cout<<endl;

    cout<<"Functions of Deque :" <<endl;
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    cout<<dq.front() <<endl;

    dq.push_front(4);

    cout<<dq.front() <<endl;

    dq.pop_front();

    cout<<dq.back() <<endl;
    
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);

    while(!cq.empty()){
        cout<<cq.front()<<" ";
        cq.pop();
    }
    cout<< endl;
    //cq.print();
}