#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

vector<vll> mat;

pair<ll,ll>rec(int ii, int jj, int sz){
    if(sz == 1)return make_pair(mat[ii][jj],mat[ii][jj]);
    pair<ll,ll> tl, br, bl, tr;
    tl = rec(ii,jj, sz/2);
    tr = rec(ii, jj + sz/2, sz/2);
    bl = rec(ii + sz/2, jj, sz/2);
    br = rec(ii + sz/2, jj + sz/2, sz/2);
    ll mx = max(max(tl.second,tr.second),max(bl.second,br.second));
    ll sum = tl.first + tr.first + bl.first + br.first + mx;
    return make_pair(sum,mx);
}

int main()
{
    int n, i, j, l;
    cin>>n;
    l = (int)sqrt(n);
    mat = vector<vll>(l,vll(l));
    for(i = 0; i != l; i++){
        for(j = 0; j != l; j++){
            cin>>mat[i][j];
        }
    }
    pair<ll,ll>ret = rec(0,0,l);
    cout<<ret.first;
}
