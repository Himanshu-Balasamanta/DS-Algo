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
    int n, i, q;
    cin>>n>>q;
    int a[n + 1], b[n + 1], x, y, p[n + 1],mi[n + 1];
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(mi,0,sizeof(mi));
    memset(b,0,sizeof(b));
    for(i = 1; i <= n; i++)scanf("%d",b + i);
    for(i = 0; i != q; i++){
        scanf("%d %d",&x, &y);
        p[x]++;mi[y]--;
    }
    for(i = 1; i <= n; i++){
        a[i] = a[i - 1] + p[i] + mi[i - 1];
        //cout<<a[i]<<' ';
    }
    sort(a + 1,a + n + 1);
    sort(b + 1, b + n + 1);
    ll sum = 0;
    for(i = 1; i <= n; i++){
        sum += (ll)b[i] * (ll)a[i];
    }
    cout<<sum;
}