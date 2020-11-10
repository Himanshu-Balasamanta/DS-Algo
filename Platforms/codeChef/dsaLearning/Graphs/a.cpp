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

vvi friends;
vi mrk;

int rec(int x){
    if(mrk[x])return 0;
    mrk[x] = 1;
    int fri = 1;
    for(int y : friends[x]){
        fri += rec(y);
    }
    return fri;
}

void solve()
{
    int n, m, i, j, x, y, z, k = 0;
    ll ans = 1, pro;
    cin>>n>>m;
    friends = vvi(n + 1);
    for(i = 0; i != m; i++){
        cin>>x>>y;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }
    mrk = vi(n + 1);
    for(i = 1; i <= n; i++){
        if(mrk[i])continue;
        k++;
        pro = (ll)rec(i);
        ans *= pro;
        ans = ans % ((ll)1e9 + 7);
    }
    cout<<k<<' '<<ans<<'\n';
}

int main()
{
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}