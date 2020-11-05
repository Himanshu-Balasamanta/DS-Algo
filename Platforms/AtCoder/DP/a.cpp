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
    int n, i, ans = 0;
    cin>>n;
    vi a(n), cost(n);
    for(i = 0; i != n; i++){
        cin>>a[i];
        if(i){
            cost[i] = cost[i - 1] + abs(a[i] - a[i - 1]);
        }
        if(i > 1){
            cost[i] = min(cost[i], cost[i - 2] + abs(a[i] - a[i - 2]));
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