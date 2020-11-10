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
    ll n, i, j, x, y;
    cin>>n;
    ll sum = 0;
    vll a(n + 1);
    vvi ret;
    for(i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
    }
    if(sum % n != 0){
        cout<<"-1\n";
        return;
    }
    sum /= n;
    for(i = 2; i <= n; i++){
        if(a[i] <= sum)continue;
        if(a[i] < i)continue;
        ll q = (a[i] / i);
        vi temp = {(int)i,1,(int)q};
        ret.push_back(temp);
        a[1] += q * i;
        a[i] -= q * i;
    }
    for(i = 2; i <= n; i++){
        if(a[i] > sum){
            ll q = sum - (i % sum);
            vi temp = {1,(int)i,(int)q};
            a[i] += q;
            a[1] -= q;
            ret.push_back(temp);
            
        }
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