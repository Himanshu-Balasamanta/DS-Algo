#include<bits/stdc++.h>
using namespace std;

int main()
{
    int mat[5][5], tot = 0, mx[5][5], i, j;
    queue<pair<int, int> >q;
    q.push(make_pair(0,0));
    mx[0][0] = mat[0][0];
    while(!q.empty()){
        pair<int,int>p = q.front();
        q.pop();
        if(p.first == 4)continue;
        
    }
}