#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n, m, i, j, p, c = 0;
    vector<vector<char>>grid;
        //
        vector<vector<bool>>mark;

    bool isValid(int i, int j){
        if(mark[i][j] || grid[i][j] == '0')return false;
        if(i >= n || i < 0 || j >= m || j < 0)return false;
        mark[i][j] = true;
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        this->grid = grid;
        if(n==0)return 0;
        m = grid[0].size();
        //
        mark = vector<vector<bool>>(n,vector<bool>(m,false));
        //
        int q;
        queue<int>quei,quej;
        for(i = 0; i != n; i++){
            for(j = 0; j != m; j++){
                if(grid[i][j] == '0' || mark[i][j])continue;
                mark[i][j] = true;
                quei.push(i);
                quej.push(j);
                while(!quei.empty()){
                    p = quei.front();
                    q = quej.front();
                    quei.pop();quej.pop();
                    if(isValid(p - 1, q))quei.push(p - 1),quej.push(q);
                    if(isValid(p + 1, q))quei.push((p + 1)),quej.push(q);
                    if(isValid(p, q + 1))quei.push(p),quej.push(q + 1);
                    if(isValid(p, q - 1))quei.push(p),quej.push(q - 1);
                }
                c++;
            }
        }
        return c;
    }
};

int main()
{}