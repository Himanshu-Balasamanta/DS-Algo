#include<bits/stdc++.h>
using namespace std;

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
    int n, m, i, j;
    string s, t;
    cin>>s>>t;
    n = s.length(), m = t.length();
    vvi len(n + 1,vi(m + 1)), inc(n + 1,vi(m + 1));
    V<V<pair<int,int>>>prev(n + 1, V<pair<int,int>>(m + 1));
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]){
                len[i][j] = len[i - 1][j - 1] + 1;
                inc[i][j] = 1;
                prev[i][j] = make_pair(i - 1,j - 1);
            }
            else{
                if(len[i - 1][j] > len[i][j - 1]){
                    len[i][j] = len[i - 1][j];
                    prev[i][j] = make_pair(i - 1,j);
                }
                else{
                    len[i][j] = len[i][j - 1];
                    prev[i][j] = make_pair(i,j - 1);
                }
            }
        }
        //debarr(maxSubseqDP[i]);
    }
    string ret = "";
    int nn = n, mm = m;
    while(len[nn][mm]){
        if(inc[nn][mm])ret += s[nn - 1];
        auto p = prev[nn][mm];
        nn = p.first, mm = p.second;
    }
    reverse(ret.begin(),ret.end());
    cout<<ret;
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}