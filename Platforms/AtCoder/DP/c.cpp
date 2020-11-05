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
    int n, i, j, k;
    cin>>n;
    vvi a(n,vi(3)), dp(n,vi(3));
    for(i = 0; i != n; i++){
        for(j = 0; j != 3; j++){
            cin>>a[i][j];
            if(i == 0)dp[i] = a[i];
            else
            for(k = 0; k != 3; k++){
                if(k == j)continue;
                dp[i][j] = max(dp[i - 1][k] + a[i][j], dp[i][j]);
            }
        }
    }
    cout<<*max_element(all(dp[n - 1]))<<'\n';

}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}