/**
 *  Given a cost matrix Cost[][] where Cost[i][j] denotes the Cost of visiting cell with coordinates (i,j),
 *  find a min-cost path to reach a cell (x,y) from cell (0,0) under the condition that
 *  you can only travel one step right or one step down. (We assume that all costs are positive integers)
 */
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >a,b;

int minCost(int n, int m){
    if(b[n][m] != 0)return b[n][m];
    if(n == 0 && m == 0){
        b[0][0] = a[0][0];
        return a[0][0];
    }
    if(n == 0)
        return b[0][m] = minCost(0,m - 1) + a[n][m];
    if(m == 0)return b[n][m] = minCost(n - 1, m) + a[n][m];
    int mn = a[n][m] + min(minCost(n - 1,m), minCost(n,m - 1));
    b[n][m] = mn;
    return mn;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    a = b = vector<vector<int> >(n,vector<int>(m,0));
    for(i = 0; i != n; i++)
        for(j = 0; j != m; j++)
            cin>>a[i][j];
    cout<<minCost(n - 1,m - 1)<<'\n';
    for(i = 0; i != n; i++){
        for(j = 0; j != m; j++)
            cout<<b[i][j]<<' ';
        cout<<'\n';
    }
}