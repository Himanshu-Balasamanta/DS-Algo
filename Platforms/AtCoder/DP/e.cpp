#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int ieie = 0;ieie != (int)v.size(); ieie++)cout<<ieie<<":"<<v[ieie]<<", ";cout<<'\n';

void solve()
{
    ll n, W, i, j, k, mx = 1e5;
    cin>>n>>W;
    vector<vll> dp(n + 1, vll(mx + 1,W + 1));
    vll w(n + 1), v(n + 1);
    for(i = 1; i <= n; i++){
        cin>>w[i]>>v[i];
    }
    dp[0][0] = 0;
    for(i = 1; i <= n; i++){
        for(j = 0; j <= mx; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= v[i] && dp[i - 1][j - v[i]] < W && dp[i - 1][j - v[i]] + w[i] <= W){
                //cout<<i<<' '<<j<<'\n';
                dp[i][j] = min(dp[i][j],dp[i - 1][j - v[i]] + w[i]);
            }
        }
        //debarr(dp[i]);
    }
    for(i = mx; i >= 0; i--){
        if(dp[n][i] <= W){
            cout<<i<<'\n';
            return;
        }
    }
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}