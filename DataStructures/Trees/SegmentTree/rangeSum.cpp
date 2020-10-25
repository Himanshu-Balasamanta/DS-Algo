#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int l, r;
    Node* left, *right;
    Node(int lft,int ryt) : l(lft), r(ryt), val(0) {}
};

class NumArray {
public:

    vector<int>a;
    Node* root;
    NumArray(vector<int>& a) {
        this->a = a;
        int sz = a.size(), i;
        if(sz == 0)return;
        root = new Node(0, sz - 1);
        stack<Node*>st;
        Node* nde;
        st.push(root);
        while(!st.empty()){
            nde = st.top();
            st.pop();
            if(nde->l == nde->r){
                nde->val = a[nde->l];
                continue;
            }
            nde->left = new Node(nde->l, (nde->l + nde->r)/2);
            nde->right = new Node((nde->l + nde->r)/2 + 1, nde->r);
            st.push(nde->left);
            st.push(nde->right);
        }
        rec(root);
    }

    void rec(Node* nde){

        if(nde->l == nde->r)return;
        rec(nde->left);
        rec(nde->right);
        nde->val = nde->left->val + nde->right->val;
    }
    
    void update(int i, int val) {
        
        a[i] = val;
        Node* nde = root;
        stack<Node*>st;
        while(nde){
            st.push(nde);
            if((nde->l + nde->r)/2 >= i)nde = nde->left;
            else nde = nde->right;
        }
        st.top()->val = a[i];
        int sum = a[i];
        st.pop();
        while(!st.empty()){
            nde = st.top();
            st.pop();
            sum = 0;
            if(nde->left)sum += nde->left->val;
            if(nde->right)sum += nde->right->val;
            nde->val = sum;
        }
    }
    
    int sumRange(int i, int j) {
        Node* nde = root;
        int sum = 0;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            nde = st.top();
            st.pop();
            if(nde->l >= i && nde->r <= j)sum += nde->val;
            else if(nde->l > j || nde->r < i)continue;
            else st.push(nde->left),st.push(nde->right);
        }
        return sum;
    }
};

int main()
{
    vector<int>a = {1,3,5};
    NumArray* obj = new NumArray(a);
    int param_2 = obj->sumRange(0,2);
    obj->update(1,2);
    cout<<param_2;
    cout<<'\n'<<obj->sumRange(0,2);
}