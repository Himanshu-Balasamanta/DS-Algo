#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

vvi a;
vi mrk,level;
int n;

void dfs(int strt){
    int dist = 0, ele = strt;
    for(int x : a[strt]){
        if(mrk[x])continue;
        mrk[x] = 1;
        level[x] = level[strt] + 1;
        dfs(x);
    }
}

void findFarthest(int strt){
    level = mrk = vi(n + 1);
    mrk[strt] = 1;
    dfs(strt);
}

void solve(){
    int x, y, i;
    cin>>n;
    a = vvi(n + 1);
    for(i = 1; i != n; i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    findFarthest(1);
    int mxi = max_element(all(level)) - level.begin();
    findFarthest(mxi);
    int mx = *max_element(all(level));
    cout<<(mx + 1)/2<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}