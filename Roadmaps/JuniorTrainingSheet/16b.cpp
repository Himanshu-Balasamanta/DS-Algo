#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

int main()
{
    int x, y, n, m, i;
    cin>>n>>m;
    vector<pair<int,int>>a(m);
    for(i = 0; i != m; i++){
        scanf("%d %d",&x,&y);
        a[i] = make_pair(y,x);
    }
    sort(a.rbegin(),a.rend());
    long long ans = 0;
    for(i = 0;i != m; i++){
        x = min(n,a[i].second);
        ans += (ll)(x*a[i].first);
        n -= x;
    }
    cout<<ans;
}