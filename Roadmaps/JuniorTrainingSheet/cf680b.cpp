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
    int n, i, j, en, st, x,c = 0;
    cin>>n>>x;
    vi a(n);x--;
    for(i = 0; i != n; i++){
        cin>>a[i];
    }
    int y = min(x, n - 1 - x);
    i = x - 1, j = x + 1;
    if(a[x])c++;
    st = x - y, en = x + y;
    for(; i >= st; i--, j++){
        if(a[i] == 1 && a[j] == 1)c += 2;
    }
    for(;i >= 0; i--){
        c += a[i];
    }
    for(; j < n; j++){
        c += a[j];
    }
    cout<<c;
}