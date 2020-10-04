/**
 *  Given a cost matrix Cost[][] where Cost[i][j] denotes the Cost of visiting cell with coordinates (i,j),
 *  find a min-cost path to reach a cell (x,y) from cell (0,0) under the condition that
 *  you can only travel one step right or one step down. (We assume that all costs are positive integers)
 */
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >a;

int minCost(int n, int m){
    if(n == 0 && m == 0)return a[0][0];
    if(n == 0)return a[0][m - 1] + a[n][m];
    if(m == 0)return a[n - 1][0] + a[n][m];

    int mn = a[n][m] + min(minCost(n - 1,m), minCost(n,m - 1));
    cout<<"For "<<n + 1<<' '<<m + 1<<" the min is "<<mn<<'\n';
    return mn;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    a = vector<vector<int> >(n,vector<int>(m,0));
    for(i = 0; i != n; i++)
        for(j = 0; j != m; j++)
            cin>>a[i][j];
    cout<<minCost(n - 1,m - 1);
}