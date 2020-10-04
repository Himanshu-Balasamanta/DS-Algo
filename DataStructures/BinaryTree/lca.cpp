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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,TreeNode*>mp;
        stack<TreeNode*>st;
        st.push(root);
        TreeNode* nde;
        while(!st.empty()){
            nde = st.top();
            st.pop();
            if(nde->left){
                mp.insert(make_pair(nde->left,nde));
                st.push(nde->left);
            }
            if(nde->right){
                mp.insert(make_pair(nde->right,nde));
                st.push(nde->right);
            }
        }
        set<TreeNode*>se;
        nde = p;
        while(nde != root){
            se.insert(nde);
            nde = mp[nde];
        }
        nde = q;
        while(nde != root){
            if(se.find(nde) != se.end())return nde;
            nde = mp[nde];
        }
        return root;
    }
};