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

vvi to,from;
string s, t;

void solve()
{
    to = from = vvi(256);
    string x;
    cin>>s>>t;
    int i, j, q;
    cin>>q;
    for(i = 0; i != q; i++){
        cin>>x;
        from[x[0]].push_back(x[3]);
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