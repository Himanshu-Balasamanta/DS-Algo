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

vvi country, mrk;
map<int,int>mp;
int n, m;

int rec(int x, int y, int str){
    if(x < 0 || y < 0 || x >= n || y >= m)return 0;
    if(mrk[x][y])return 0;
    if(country[x][y] != str)return 0;
    mrk[x][y] = 1;
    int ret = 1;
    ret += rec(x + 1, y, str);
    ret += rec(x - 1, y, str);
    ret += rec(x, y + 1, str);
    ret += rec(x, y - 1, str);
    return ret;
}

void solve()
{
    int i, j, x, y, z;
    cin>>n>>m;
    country = mrk = vvi(n, vi(m));
    for(i = 0; i != n; i++){
        for(j = 0; j != m; j++){
            cin>>country[i][j];
        }
    }
    for(i = 0; i != n; i++){
        for(j = 0; j != m; j++){
            if(mrk[i][j])continue;
            int num = rec(i,j,country[i][j]);
            if(mp[num] == 0)mp[num] = country[i][j];
            else mp[num] = min(mp[num],country[i][j]);
        }
    }
    auto p = *(mp.rbegin());
    cout<<p.second<<' '<<p.first<<'\n';
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