#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

int n, m;

vi par;

int findpar(int x){
    if(x == par[x])return x;
    par[x] = findpar(par[x]);
    return par[x];
}

int main()
{
    int i, x, y, z, ans = 0;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>arr = vector<pair<int,pair<int,int>>>(m);
    par = vi(n + 1);
    for(i = 0; i <= n; i++)par[i] = i;
    for(i = 0; i != m; i++){
        cin>>x>>y>>z;
        arr[i] = make_pair(z,make_pair(x,y));
    }
    sort(arr.begin(),arr.end());
    for(i = 0; i != m; i++){
        x = arr[i].second.first;
        y = arr[i].second.second;
        z = arr[i].first;
        if(findpar(x) != findpar(y)){
            ans += z;
            par[y] = findpar(x);
        }
    }
    cout<<ans<<'\n';
}