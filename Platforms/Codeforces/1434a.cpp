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

void solve()
{
    int i, j, k, n, m, str[6];
    for(i = 0; i != 6; i++){
        cin>>str[i];
    }
    cin>>n;
    vvi mn(n,vi(6)),mx(n,vi(6));
    vi a(n);
    cin>>a[0];
    for(i = 0; i != 6; i++){
        mx[0][i] = mn[0][i] = a[0] - str[i];
    }
    for(i = 1; i != n; i++){
        cin>>a[i];
        for(j = 0; j != 6; j++){
            mx[i][j] = mn[i][j] = a[i];
            for(k = 0; k != 6; k++){
                
            }
        }
    }

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