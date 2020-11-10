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
    int n, i, j, x;
    cin>>n;
    vi a(n + 1), mxd(n + 1), lp(n + 1), ans(n + 1, -1);
    for(i = 1; i <= n; i++){
        cin>>a[i];
        mxd[a[i]] = max(i - lp[a[i]], mxd[a[i]]);
        lp[a[i]] = i;
    }
    for(i = 1; i <= n; i++){
        mxd[i] = max(n + 1 - lp[i], mxd[i]);
        lp[i] = n + 1;
    }

    for(i = 1; i <= n; i++){
        if(mxd[i] >= 0 && ans[mxd[i]] == -1){
            ans[mxd[i]] = i;
        }
    }
    for(i = 1; i <= n; i++){
        if(ans[i] == -1 && ans[i - 1] > -1 || ans[i - 1] > -1 && ans[i - 1] < ans[i])
            ans[i] = ans[i - 1];
    }
    for(i = 1; i <= n; i++)cout<<ans[i]<<' ';
    cout<<'\n';
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