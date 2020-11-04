#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

void solve(){
    ll x, mod = 1e9 + 9;
    cin>>x;
    vll a(x + 1);
    a[0] = 1;
    for(ll i = 0; i <= x; i++){
        if(i >= 2)a[i] += a[i - 2];
        if(i >= 3)a[i] += a[i - 3];
    }
    cout<<a[x] % mod<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}