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
    cin>>n>>m;
    V<vll>pathsTillPoint(n, vll(m));
    V<string>grid(n);
    for(i = 0; i < n; i++)cin>>grid[i];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(grid[i][j] == '#');
            else if(i == 0 && j == 0){
                pathsTillPoint[0][0] = 1;
            }
            else if(i == 0){
                pathsTillPoint[i][j] = pathsTillPoint[i][j - 1];
            }
            else if(j == 0){
                pathsTillPoint[i][j] = pathsTillPoint[i - 1][j];
            }
            else{
                pathsTillPoint[i][j] = pathsTillPoint[i - 1][j] + pathsTillPoint[i][j - 1];
            }
            pathsTillPoint[i][j] = pathsTillPoint[i][j] % ((ll)1e9 + 7);
        }
    }
    cout<<pathsTillPoint[n - 1][m - 1];
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}