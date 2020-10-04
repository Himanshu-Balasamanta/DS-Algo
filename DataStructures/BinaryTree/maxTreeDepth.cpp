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
    int maxDepth(TreeNode* root) {
        int mx = 0;
        stack<TreeNode*>st;
        if(root == nullptr)return 0;
        st.push(root);
        TreeNode *nde;
        while(!st.empty()){
            while(st.top()->left)
                st.push(st.top()->left);
            while(st.top()->right == nullptr){
                mx = max(mx,(int)st.size());
                nde = st.top();
                st.pop();
                if(st.empty())return mx;
                while(st.top()->right == nde){
                    nde = st.top();
                    st.pop();
                    if(st.empty())return mx;
                }
            }
            st.push(st.top()->right);
        }
        return mx;
    }
};