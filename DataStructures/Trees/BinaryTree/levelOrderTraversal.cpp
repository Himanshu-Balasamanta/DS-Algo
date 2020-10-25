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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        vector<vector<int>>ret;
        vector<int>a;
        if(!root)return ret;
        que.push(root);
        while(!que.empty()){
            int z = que.size();
            a.clear();
            while(z--){
                TreeNode* nde = que.front();
                que.pop();
                a.push_back(nde->val);
                if(nde->left)que.push(nde->left);
                if(nde->right)que.push(nde->right);
            }
            ret.push_back(a);
        }
        return ret;
    }
};