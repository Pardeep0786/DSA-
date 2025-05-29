#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode(int val){
            val = val;
            left = right = NULL;
        }
};

//To find the lowest common ancestor in the binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL){
        return NULL;
    }

    if(root->val == p->val || root->val == q->val){
        return root;
    }

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if(leftLCA && rightLCA){
        return root;
    }else if(leftLCA != NULL){
        return leftLCA;
    }else{
        return rightLCA;
    }
}

//Construct a Tree from preorder and inorder traversal
int search(vector<int>& inorder, int left, int right, int val){
    for(int i = left; i <= right; i++){
        if(inorder[i] == val){
            return i;
        }
    }
    return -1;
}

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
    if(left > right){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[preIdx]);

    int inIdx = search(inorder, left, right, preorder[preIdx]);
    preIdx++;

    root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
    root->right = helper(preorder, inorder, preIdx, inIdx+1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIdx = 0;
    return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
}

//Print the element of the Binary Tree form top view
int TopView(TreeNode* root){
    queue<pair<TreeNode*, int>> q;
    map<int, int> m;

    q.push({root, 0});

    while(q.size() > 0){
        TreeNode* curr = q.front().first;
        int currHd = q.front().second;
        q.pop();

        if(m.find(currHd) == m.end()){
            m[currHd] = curr->val;
        }

        if(curr->left != NULL){
            q.push({curr->left, currHd-1});
        }

        if(curr->right != NULL){
            q.push({curr->right, currHd+1});
        }
    }
}

//knth level of the Binary Tree
void knthLevel(TreeNode* root, int k){
    if(root == NULL){
        return;
    }

    if(k == 1){
        cout<< root->val <<endl;
        return;
    }

    knthLevel(root->left, k-1);
    knthLevel(root->right, k-1);
}

//Transform to Sum Tree
int SumTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = SumTree(root->left);
    int rightSum = SumTree(root->right);

    root->val += leftSum + rightSum;

    return root->val;
}

//Binary Tree Path
class Solution {
public:
    void TreePaths(TreeNode* root, string path, vector<string>& ans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }
    
        if(root->left){
            TreePaths(root->left, path+"->"+to_string(root->left->val), ans);
        }
        if(root->right){
            TreePaths(root->right, path+"->"+to_string(root->right->val), ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);
        TreePaths(root, path, ans);
        return ans;
    }
};

//Max width in complete binary Tree
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while(q.size() > 0){
            int currLvlSiz = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for(int i = 0; i < currLvlSiz; i++){
                auto curr = q.front();
                q.pop();

            if(curr.first->left){
                q.push({curr.first->left, curr.second*2+1});
            }

            if(curr.first->right){
                q.push({curr.first->right, curr.second*2+2});
            }
            }
        }
        return maxWidth;
    }
};

//Morris Inorder Traversal in Binary Tree
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* IP = curr->left;
                while(IP->right != NULL && IP->right != curr){
                    IP = IP->right;
                }
                if(IP->right == NULL){
                    IP->right = curr;
                    curr = curr->left;
                }else{
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

//Flatten Binary Tree to Linked List
class Solution {
public:
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};