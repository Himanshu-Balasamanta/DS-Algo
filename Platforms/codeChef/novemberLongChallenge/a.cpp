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
    int n, sum = 0, i, j;
    cin>>n;
    vi a(n);
    for(i = 0; i != n; i++){
        cin>>a[i];
        sum += a[i];
    }
    vvi dp(n + 1,vi(sum + 1));
    dp[0][0] = 1;
    for(i = 1; i <= n; i++){
        for(j = 0; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - a[i - 1] >= 0)dp[i][j] |= dp[i - 1][j - a[i - 1]];
        }
    }
    for(i = (sum + 1)/2; i <= sum; i++){
        if(dp[n][i]){
            cout<<i<<'\n';break;
        }
    }
}

int main()
{
    io;
    fix(10);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}