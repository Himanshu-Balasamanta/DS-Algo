#include<bits/stdc++.h>
using namespace std;
int dfs(int p,vector<int>a){
    if(p==-1){
        return 0;
    }
    vector<int>a0,a1;
    for(int e:a){
        if((e>>p)&1){a1.push_back(e);}
        else a0.push_back(e);
    }
    int ans=1<<p;
    if(a0.empty())return dfs(p-1,a1);
    if(a1.empty())return dfs(p-1,a0);
    return min(dfs(p-1,a0),dfs(p-1,a1))+ans;
}
int main()
{
    int n,mx=0,m;cin>>n;
    vector<int>a(n);
    while(n--){
        cin>>a[n];
    }
    cout<<dfs(29,a);
}