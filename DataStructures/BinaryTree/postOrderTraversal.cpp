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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        vector<int>a;
        if(!root)return a;
        TreeNode* nde;
        while(!st.empty()){
            int f = 0;
            nde = st.top();
            if(nde->right){
                st.push(nde->right);
                f = 1;
            }
            if(nde->left){
                st.push(nde->left);
                f |= 2;
            }
            if(f == 0){
                nde = st.top();
                st.pop();
                a.push_back(nde->val);
                if(st.empty())return a;
                while(st.top()->left == nde || st.top()->right == nde){
                    nde = st.top();
                    st.pop();
                    a.push_back(nde->val);
                    if(st.empty())return a;
                }
            }
        }
        return a;
    }
};