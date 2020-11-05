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
    int n, k, i, j, x, p;
    cin>>n>>k;
    vi a(n), cost(n);
    for(i = 0; i != n; i++){
        cin>>a[i];
        if(i == 0)continue;
        cost[i] = INT_MAX;
        for(j = 1; j <= k; j++){
            if(i - j < 0)break;
            cost[i] = min(cost[i], cost[i - j] + abs(a[i] - a[i - j]));
        }
    }
    cout<<cost[n - 1]<<'\n';
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}