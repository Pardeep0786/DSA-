#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

//Vector-Based Stack Implementation
class Stack{
    vector<int> v;
public:
    void push(int val){
        v.push_back(val);
    }

    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size() - 1];
    }

    bool empty(){
        return v.size() == 0;
    }
};

//List-Based Stack Implementation
class Stack2{
    list<int> ll;
public:
    void push(int val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }
};

//Valid Parathensis
class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(int i = 0; i< str.size(); i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            }else{
                if(st.size() == 0){
                    return false;
                }
                if(st.top() == '(' && str[i] == ')' ||
                st.top() == '{' && str[i] == '}' ||
                st.top() == '[' && str[i] == ']'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

//Previous High in the Satck
vector<int> StackPrevHigh (vector<int> price){
    vector<int> ans(price.size(), 0);
    stack<int> s;

    for(int i = 0; i < price.size(); i++){
        while(s.size() > 0 && price[s.top()] <= price[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = i + 1;
        }else{
            ans[i] = i - s.top();
        }
        s.push(i);
    }
    for(int val : ans){
        cout<< val <<" ";
    }
    cout<< endl;
}

//Next Greater
vector<int> nextGreter(vector<int> arr){
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i = arr.size() - 1; i >= 0; i--){
        while(s.size() > 0 && s.top() <= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for(int val : ans){
        cout<< val << " ";
    }
    cout<<endl;
}

//Find the next greater element for nums1 in nums2
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map <int, int> m;
    stack<int> s;

    for(int i = nums2.size()-1; i>=0; i--){
        while(s.size() > 0 && s.top() <= nums2[i]){
            s.pop();
        }

        if(s.empty()){
            m[nums2[i]] = -1;
        }else{
            m[nums2[i]] = s.top();
        }

        s.push(nums2[i]);
    }

    vector<int> ans;
    for(int i = 0; i < nums1.size(); i++){
        ans.push_back(m[nums1[i]]);
    }
    
    return ans;
}

//Previous Lower Element
vector<int> PrevSmallerEl(vector<int> arr){
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for(int i = 0; i < arr.size(); i++){
        while(s.size() > 0 && s.top() >= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }
    return ans;
}

//To get the minimum value from the stack
class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {
            
    }
        
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        }else{
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }
        
    void pop() {
        s.pop();
    }
        
    int top() {
        return s.top().first;
    }
        
    int getMin() {
        return s.top().second;
    }
};

//Min Stack for better space complexity
class MinStack2 {
public:
    stack<long long int> s;
    long long int minVal;
    MinStack2() {
            
    }
        
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        }else{
            if(val < minVal){
                s.push((long long) 2*val - minVal);
                minVal = val;
            }else{
                s.push(val);
            }
        }
    }
        
    void pop() {
        if(s.top() < minVal){
            minVal = 2*minVal - s.top();
        }
            
        s.pop();
            
    }
        
    int top() {
        if(s.top() < minVal){
            return minVal;
        }else{
            return s.top();
        }
    }
        
    int getMin() {
        return minVal;
    }
};

//Find the area of rectangel in Histogram
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    stack<int> s;

    //right smaller
    for(int i = n-1; i >= 0; i--){
        while(s.size() > 0 && heights[s.top()] >= heights[i]){
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    //left smaller
    for(int i = 0; i < n; i++){
        while(s.size() > 0 && heights[s.top()] >= heights[i]){
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }

    return ans;
}

//Next Greater in circular vecotr
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
    
        for(int i = 2*n-1; i >= 0; i--){
            while(s.size() > 0 && nums[s.top()] <= nums[i%n]){
                s.pop();
            }
    
            ans[i%n] = s.empty() ? -1 : nums[s.top()];
    
            s.push(i%n);
        }
        return ans;
    }
};

//To get the value of celebrity 
int getCelebrity(vector<vector<int>> arr){
    int n = arr.size();
    stack<int> s;

    for(int i = 0; i < n; i++){
        s.push(i);
    }

    while(s.size() > 1){
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();
    
    if(arr[i][j] == 0){
        s.push(i);
    }else{
        s.push(j);
    }
    }

    int celb = s.top();

    for(int i = 0; i < n; i++){
        if((i != celb) && (arr[i][celb] == 0 || arr[celb][i] == 1)){
            return -1;
        }
    }
    return celb;
}
int main() {
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int ans = getCelebrity(arr);

    cout<< "Celebrity is : " <<ans;
    cout<<endl;
}