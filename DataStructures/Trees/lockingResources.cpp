#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

struct Node{
    int val = 0;
    bool isLocked = false;
    int blocked = 0;
    vector<Node*> children;
    Node* parent;
    Node(int x) : val(x), isLocked(false), blocked(0){};
};
int n;
Node* root;
unordered_map<int,Node*>mp;

void buildTree(){
    cout<<"enter no of nodes: ";
    cin>>n;
    int x, y;
    for(int i = 1; i < n; i++){
        cin>>x>>y;
        if(mp[x] == nullptr){
            mp[x] = new Node(x);
        }
        if(mp[y] == nullptr){
            mp[y] = new Node(y);
        }
        mp[x]->children.push_back(mp[y]);
        mp[y]->parent = mp[x];
    }
}

bool lock(int x){
    Node* node = mp[x];
    Node *ptr = node;
    if(node->blocked != 0 || node->isLocked)return false;
    while(ptr){
        if(ptr->isLocked)return false;
        ptr = ptr->parent;
    }
    node->isLocked = true;
    ptr = node->parent;
    while(ptr){
        ptr->blocked++;
        ptr = ptr->parent;
    }
    return true;
}

bool unlock(int x){
    Node* node = mp[x];
    Node* ptr = node->parent;
    if(!node->isLocked)return false;
    node->isLocked = false;
    while(ptr){
        ptr->blocked--;
        ptr = ptr->parent;
    }
    return true;
}

int main()
{
    buildTree();
    for(int i = 2; i <= n; i++)cout<<mp[i]->parent->val<<' ';cout<<'\n';
    int q;
    cout<<"Tree is built, enter no of queries : ";
    cin>>q;
    cout<<'\n';
    while(q--){
        int c;
        int x;
        cin>>c>>x;
        if(c == 1){
            cout<<lock(x)<<'\n';
        }
        if(c == 2){
            cout<<unlock(x)<<'\n';
        }
    }
}