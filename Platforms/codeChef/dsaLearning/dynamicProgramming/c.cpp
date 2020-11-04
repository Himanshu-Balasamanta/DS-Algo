#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';


vi prime;
vvi db;

void prep(){
    ll i, j, mx = 1e5;
    vector<bool> p(mx + 1, true);
    prime = vi(mx + 1);
    db = vvi (mx + 1,vi(6));
    for(i = 2; i <= mx; i++){
        if(p[i]){
            for(j = i; j <= mx; j += i){
                p[j] = false;
                prime[j]++;
            }
        }
    }
    for(i = 1; i <= mx; i++){
        if(prime[i] <= 5)
            db[i][prime[i]] = 1;
        for(j = 1; j <= 5; j++){
            db[i][j] += db[i - 1][j];
        }
    }
}

void solve()
{
    ll x, y, k;
    cin>>x>>y>>k;
    cout<<db[y][k] - db[x - 1][k]<<'\n';
}

int main()
{
    prep();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}