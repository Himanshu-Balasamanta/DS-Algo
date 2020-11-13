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
#define deb(x) cout<<#x<<' '<<x<<'\n';
#define debarr(v) cout<<#v<<" : ";for(int ieieou = 0;ieieou != (int)v.size(); ieieou++)cout<<ieieou<<":"<<v[ieieou]<<", ";cout<<'\n';
#define printArr(v){for(auto x : v){cout<<x<<' ';};cout<<'\n';}

int Xor(int x){
    switch(x % 4){
        case 0: return x;
        case 1: return 1;
        case 2: return x + 1;
        default: return 0;
    }
}

void solve()
{
    
}

int main()
{
    io;
    fix(10);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}