#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define V vector
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int ieieou = 0;ieieou != (int)v.size(); ieieou++)cout<<ieieou<<":"<<v[ieieou]<<", ";cout<<'\n';

int n, m;
vvi from, to;
vi mrk, len;

int rec(int x){
    if(mrk[x]){
        return len[x];
    }
    mrk[x] = 1;
    int mxlen = -1;
    for(int y : to[x]){
        mxlen = max(mxlen,rec(y));
    }
    len[x] = mxlen + 1;
    return len[x];
}

void solve()
{
    cin>>n>>m;
    from = to = vvi(n + 1);
    int i, j, x, y;
    for(i = 0; i != m; i++){
        cin>>x>>y;
        from[x].push_back(y);
        to[y].push_back(x);
    }
    mrk = len = vi(n + 1);
    for(i = 1; i <= n; i++){
        if(mrk[i])continue;
        rec(i);
    }
    cout<<*max_element(all(len));
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}