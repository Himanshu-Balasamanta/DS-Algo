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
    int n, i,j, x;
    vi a(6);
    for(i = 0; i != 6; i++)cin>>a[i];
    cin>>n;
    vi b(n);
    for(i = 0; i != n; i++)cin>>b[i];
    sort(all(a));
    sort(all(b));
    int mn = INT_MAX, mx = 0;
    for(i = 0; i != n; i++){
        for(j = 0; j != 6; j++){
            if(b[i] <= a[j])break;
            mn = min(mn,b[i] - a[j]);
            mx = max(mx,b[i] - a[j]);
        }
    }
    cout<<mx - mn;
}