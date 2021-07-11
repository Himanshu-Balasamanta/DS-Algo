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
#define deb(x) cout<<#x<<' '<<x<<'\n'
#define debarr(v) cout<<#v<<" : ";for(int ieieou = 0;ieieou != (int)v.size(); ieieou++)cout<<ieieou<<":"<<v[ieieou]<<", ";cout<<'\n';
#define printArr(v){for(auto x : v){cout<<x<<' ';};cout<<'\n';}
#define print(x) cout<<x<<'\n'
#define println() cout<<'\n'

inline void printList(initializer_list<int> l){for(int x : l)cout<<x<<' ';cout<<'\n';}

void solve()
{
    ll i, n, sum = 0, av, plus, normal;
    cin>>n;
    vll a(n);
    for(ll& x : a){
        cin>>x;
        sum += x;
    }
    av = sum / n;
    plus = sum - av * n;
    normal = n - plus;
    print(plus * normal);
}
int main()
{
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("/home/new_developer/JAVA/Some JAVA/input", "r", stdin);
        // for writing output to output.txt
        freopen("/home/new_developer/JAVA/Some JAVA/output", "w", stdout);
    #endif
    io;
    fix(10);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}