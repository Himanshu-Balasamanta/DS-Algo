#include<bits/stdc++.h>
using namespace std;

vector<int>a,tree;

void build(int node, int strt, int end){
    if(strt == end){
        tree[node] = a[strt];
        return;
    }
    int mid = (strt + end) / 2;
    build(node * 2,strt,mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void update(int node,int strt,int end, int ind, int val){
    if(strt == end){
        a[ind] = val;
        tree[node] = val;
        return;
    }
    int mid = (strt + end) / 2;
    if(ind <= mid)update(node * 2, strt, mid,ind, val);
    else update(node * 2 + 1,mid + 1, end, ind, val);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int Xor(int node,int strt,int end, int fir,int lst){
    if(lst < strt || fir > end)return 0;
    if(fir <= strt && lst >= end)return tree[node];
    int mid = (strt + end) / 2;
    return Xor(node * 2,strt, mid, fir, lst) ^ Xor(node * 2 + 1,mid + 1, end, fir, lst);
}

int main()
{
    a = {0,1,2,3,4,5,6,7,8,9,10};
    tree = vector<int>(a.size() * 4);
    build(1,0,a.size() - 1);
    cout<<(Xor(1,0,a.size() - 1,2,6))<<'\n';
    update(1,0,a.size() - 1,4,32);
    cout<<(Xor(1,0,a.size() - 1,2,6))<<'\n';
}