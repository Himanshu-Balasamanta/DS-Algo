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
    int n, W, i, j, k;
    cin>>n>>W;
    vll w(n + 1), v(n + 1);
    vector<vll> dp(n + 1, vll(W + 1));
    for(i = 1; i <= n; i++){
        cin>>w[i]>>v[i];
        for(j = 1; j <= W; j++){
            dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            if(j >= w[i])
                dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
        }
        debarr(dp[i]);
    }
    cout<<dp[n][W]<<'\n';
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}