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
    int n, m, k, i, j, x, y, z;
    cin>>n>>m;
    vvi ans(n + 1,vi(n + 1, INT_MAX / 5));
    for(i = 0; i <= n; i++)ans[i][i] = 0;
    for(i = 0; i != m; i++){
        cin>>x>>y>>z;
        ans[x][y] = z;
        ans[y][x] = z;
    }
    for(k = 0; k <= n; k++){
        for(i = 0; i <= n; i++){
            for(j = 0; j <= n; j++){
                if(ans[i][j] > ans[i][k] + ans[k][j])
                    ans[i][j] = ans[i][k] + ans[k][j];
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(ans[i][j] == INT_MAX)
                cout<<"INF ";
            else
                cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}