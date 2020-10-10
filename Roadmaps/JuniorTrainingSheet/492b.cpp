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
    int n, l, i, j;
    cin>>n>>l;
    vector<int>a(n);
    setprecision(11);
    fixed;
    for(i = 0; i != n; i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end());
    a.insert(a.begin(),-1 * a[0]);
    a.push_back(2 * l - a[a.size() - 1]);
    int mn = 0;
    for(i = 1; i <= n + 1; i++){
        mn = max(mn,a[i] - a[i - 1]);
    }
    double d = ((double)mn)/2;
    cout<<fixed<<d;
}