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

vll mm;

vll findInbase(ll n, ll k){
    if(n == 0){
        return mm;
    }
    mm.push_back(n%k);
    findInbase(n/k,k);
}

ll decode(vll a, ll k){
    ll ans = 0, p = 1;
    for(ll i = 0; i != a.size(); i++){
        ans += a[i] * p;
        p *= k;
    }
    return ans;
}

void modify(vll& ans){
    
}

void solve()
{
    ll n, k, i, j, l, h, propose;
    cin>>n>>k;
    mm.clear();
    vll mx = findInbase(n,k);
    vll ans = mx;
    ll r = 0;
    while(r == 0) {
        propose = decode(ans,k);
        print(propose);
        cout.flush();
        cin>>r;
        modify(ans);
    }

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