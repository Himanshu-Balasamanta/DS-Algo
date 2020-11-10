#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fix(n) cout << fixed << setprecision(n)

#define ll long long
#define all(v) v.begin(),v.end()
#define V vector
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int ieieou = 0;ieieou != (int)v.size(); ieieou++)cout<<ieieou<<":"<<v[ieieou]<<", ";cout<<'\n';

void solve()
{
    int n, i, j, y, z, stand = 0, left = 1, right = 2;
    cin>>n;
    vi x(n),h(n);
    V<pair<int,int>>tree(n);
    for(i = 0; i != n; i++){
        cin>>y>>z;
        tree[i] = make_pair(y,z);
    }
    sort(all(tree));
    for(i = 0; i != n; i++){
        x[i] = tree[i].first;
        h[i] = tree[i].second;
    }
    x.insert(x.begin(),INT_MIN);h.insert(h.begin(),0);
    x.push_back(INT_MAX);h.push_back(0);
    debarr(x);debarr(h);
    vvi dp(n + 1,vi(3));
    for(i = 1; i <= n; i++){
        //
        dp[i][stand] = *max_element(all(dp[i - 1]));
        //
        dp[i][left] = max(dp[i - 1][stand],dp[i - 1][left]) + (h[i] < x[i] - x[i - 1] - 1);
        dp[i][left] = max(dp[i][left],dp[i - 1][right] + (x[i] - x[i - 1] - 1 > h[i] + h[i - 1]));
        //
        dp[i][right] = dp[i][stand] + (h[i] < x[i + 1] - x[i] - 1);
        debarr(dp[i]);
    }
    cout<<*max_element(all(dp[n]));
}

int main()
{
    io;
    fix(10);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}