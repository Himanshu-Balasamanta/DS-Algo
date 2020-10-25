#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>a;
        if(!root)return a;
        st.push(root);
        TreeNode* nde;
        //
        while(!st.empty()){
            while(st.top()->left != nullptr){
                st.push(st.top()->left);
            }
            nde = st.top();
            st.pop();
            a.push_back(nde->val);
            //
            while(nde->right == nullptr){
                if(st.empty())return a;
                nde = st.top();
                st.pop();
                a.push_back(nde->val);
            }
            if(nde && nde->right)
            st.push(nde->right);
        }
        return a;
    }
};