/**
 * 
 * !!!THIS CODE IS FAULTY!!!
 * 
 *  You are given a 2-D matrix A of n rows and m columns where A[i][j] denotes the calories burnt. 
 * Two persons, a boy and a girl, start from two corners of this matrix. 
 * The boy starts from cell (1,1) and needs to reach cell (n,m).
 * On the other hand, the girl starts from cell (n,1) and needs to reach (1,m).
 * The boy can move right and down. The girl can move right and up.
 * As they visit a cell, the amount in the cell A[i][j] is added to their total of calories burnt. 
 * You have to maximize the sum of total calories burnt by both of them under the condition that 
 * they shall meet only in one cell and the cost of this cell shall not be included in either of their total.
 */
#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int> >a,bt,gt,bs,gs;
int setBoyTo(int y, int x){
    if(bt[y][x] != 0)return bt[y][x];
    if(y == 0 && x == 0)return bt[y][x] = a[y][x];
    if(y == 0)return bt[0][x] = setBoyTo(y, x - 1) + a[y][x];
    if(x == 0)return bt[y][0] = setBoyTo(y - 1, x) + a[y][x];
    return bt[y][x] = max(bt[y - 1][x],bt[y][x - 1]) + a[y][x];
}

int setGirlTo(int y, int x){
    if(gt[y][x] != 0)return gt[y][x];
    if(y == n - 1 && x == 0)return gt[y][x] = a[y][x];
    if(y == n - 1)return gt[n - 1][x] = setGirlTo(y, x - 1) + a[y][x];
    if(x == 0)return gt[y][0] = setGirlTo(y + 1, x) + a[y][x];
    return gt[y][x] = max(gt[y + 1][x],gt[y][x - 1]) + a[y][x];
}

int setBoyFrom(int y, int x){
    if(bs[y][x] != 0)return bs[y][x];
    if(y == n - 1 && x == m - 1)return bs[y][x] = a[y][x];
    if(y == n - 1)return bs[y][x] = setBoyFrom(y,x + 1) + a[y][x];
    if(x == m - 1)return bs[y][x] = setBoyFrom(y + 1,x) + a[y][x];
    return bs[y][x] = max(setBoyFrom(y, x + 1),setBoyFrom(y + 1, x)) + a[y][x];
}

int setGirlFrom(int y, int x){
    if(gs[y][x] != 0)return gs[y][x];
    if(y == 0 && x == m - 1)return gs[y][x] = a[y][x];
    if(y == 0)return gs[y][x] = setGirlFrom(y,x + 1) + a[y][x];
    if(x == m - 1)return gs[y][x] = setGirlFrom(y - 1,x) + a[y][x];
    return gs[y][x] = max(setGirlFrom(y, x + 1),setGirlFrom(y - 1, x)) + a[y][x];
}

int main()
{
    int i,j;
    cin>>n>>m;
    a = bt = gt = bs = gs = vector<vector<int> >(n,vector<int>(m));
    for(i = 0; i != n; i++)
        for(j = 0; j != m; j++)
            cin>>a[i][j];
    setBoyTo(n - 1,m - 1);
    setGirlTo(0,m - 1);
    setBoyFrom(0,0);
    setGirlFrom(n - 1, 0);
    int mx = 0;
    for(i = 0; i != n; i++)
        for(j = 0; j != m; j++){
            int tot = 0;
            if(i != 0)tot += bt[i-1][j];
            if(i != n - 1)tot += bs[i + 1][j];
            if(j != 0) tot += gt[i][j-1];
            if(j != m - 1)tot += gs[i][j + 1];
            mx = max(mx,tot);
            tot = 0;
            if(i != 0)tot += gt[i-1][j];
            if(i != n - 1)tot += gs[i + 1][j];
            if(j != 0) tot += bt[i][j-1];
            if(j != m - 1)tot += bs[i][j + 1];
        }
    cout<<mx;
}