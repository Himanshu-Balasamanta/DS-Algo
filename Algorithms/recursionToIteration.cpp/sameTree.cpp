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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*>one,two;
        TreeNode* a, *b;
        if(!p && !q)return true;
        if(!p || !q)return false;
        one.push(p);two.push(q);
        while(!one.empty()){
            if(one.top()->val != two.top()->val)return false;
            a = one.top();b = two.top();
            one.pop();two.pop();
            if(a->left && b->left){
                one.push(a->left);
                two.push(b->left);
            }
            else if(a->left || b->left)return false;
            if(a->right && b->right){
                one.push(a->right);
                two.push(b->right);
            }
            else if(a->right || b->right)return false;
        }
        return true;
    }
};