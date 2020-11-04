#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

void solve()
{
    ll n, i, x;
    cin>>n;
    vll a(n + 1),dp(n + 1);
    for(i = 1; i <= n; i++){
        cin>>a[i];
        dp[i] = a[i - 1] <= a[i] ? dp[i - 1] + 1 : 1;
    }
    x = 0;
    for(i = 1; i <= n; i++){
        x += dp[i];
    }
    cout<<x<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}