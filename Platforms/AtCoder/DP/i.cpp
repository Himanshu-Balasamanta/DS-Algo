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

void solve()
{
    int n, i, h, j;
    cin>>n;
    h = (n + 1)/2;
    V<double>a(n + 1);
    V<V<double>>headProbForNCoins(n + 1,V<double>(n + 1,0.00));
    headProbForNCoins[0][0] = 1.00000;

    for(i = 1; i <= n; i++){
        cin>>a[i];
        headProbForNCoins[i][0] = headProbForNCoins[i - 1][0] * (1.0000 - a[i]);
    }
    double x;
    for(j = 1; j <= n; j++){
        for(i = j; i <= n; i++){
            headProbForNCoins[i][j] = headProbForNCoins[i - 1][j - 1] * a[i] + headProbForNCoins[i - 1][j] * (1.000 - a[i]);
        }
    }
    x = 0.00000;
    for(i = h; i <= n; i++)
        x += headProbForNCoins[n][i];
    cout<<x<<'\n';
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