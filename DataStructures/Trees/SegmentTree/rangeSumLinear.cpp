#include<bits/stdc++.h>
using namespace std;

vector<int>a,tree;

int build(int node, int strt, int end){
    if(strt == end){
        return tree[node] = a[strt];
    }
    int mid = (strt + end)/2;
    int l = build(node * 2,strt,mid);
    int r = build(node * 2 + 1,mid + 1, end);
    return tree[node] = l + r;
}

void update(int node,int strt,int end,int ind, int val){
    if(strt == end){
        a[ind] = val;
        tree[node] = val;
        return ;
    }
    int mid = (strt + end) / 2, ret;
    if(ind <= mid)
        update(node * 2,strt, mid,ind,val);
    else
        update(node * 2 + 1,mid + 1,end,ind,val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int sum(int node, int strt, int end, int beg,int lst){
    if(strt > lst || end < beg)return 0;
    if(strt >= beg && end <= lst)return tree[node];
    int mid = (strt + end) / 2;
    int ret = sum(node * 2, strt,mid,beg,lst) + sum(node * 2 + 1,mid + 1, end,beg,lst);
    return ret;
}

int main()
{
    a = {1,2,3,4,5,6,7,8,9,10};
    tree = vector<int>(4 * a.size());
    build(1,0,a.size() - 1);
    cout<<(sum(1,0,a.size() - 1,2,6))<<'\n';
    update(1,0,a.size() - 1,4,32);
    cout<<(sum(1,0,a.size() - 1,2,6))<<'\n';
}