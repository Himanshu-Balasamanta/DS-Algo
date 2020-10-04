/**
 * doesnt work.
 */
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>que;
        vector<int>a;
        int z = 1, i, x;
        if(!root)return true;
        que.push(root);
        TreeNode* nde;
        while(!que.empty()){
            x = z;
            a.clear();
            while(x--){
                if(que.front()->left)que.push(que.front()->left),a.push_back(que.front()->left->val);
                if(que.front()->right)que.push(que.front()->right),a.push_back(que.front()->right->val);
                que.pop();
            }
            z = a.size();
            if(z%2)return false;
            x = z/2;
            for(i = 0; i != x; i++){
                if(a[i] != a[z - 1 + i])return false;
            }
        }
        return true;
    }
};