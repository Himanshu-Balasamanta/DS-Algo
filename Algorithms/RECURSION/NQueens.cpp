#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<vector<int>>ret;
    vector<int>pos,plu,minu,col;
    int n;
    bool rec(int jj){
        if(jj == n){
            ret.push_back(pos);
            return true;
        }
        for(int i = 0; i != n; i++){
            if(plu[jj + i] == -1 && minu[jj - i + 3*n] == -1 && col[i] == -1){
                plu[jj + i] = minu[jj - i + 3*n] = col[i] = 1;
                pos[jj] = i;
                rec(jj + 1);
                pos[jj] = -1;
                plu[jj + i] = minu[jj - i + 3*n] = col[i] = -1;
            }
        }
        return false;
    }

    vector<vector<int> > solveNQueens(int A) {
        n = A;
        pos = col = vector<int>(n, -1);
        plu = minu = vector<int>(6*n, -1);
        for(int i = 0; i != n; i++){
            if(plu[0 + i] == -1 && minu[0 - i + 3*n] == -1 && col[i] == -1){
                plu[0 + i] = minu[0 - i + 3*n] = col[i] = 1;
                pos[0] = i;
                rec(1);
                plu[0 + i] = minu[0 - i + 3*n] = col[i] = -1;
            }
        }
        
        string s(n,'.');
        vector<string>ss(n,s);
        vector<vector<string>>sss;
        for(vector<int> r : ret){
            vector<string>cc(ss.begin(),ss.end());
            for(int i = 0; i != n; i++){
                cc[i][r[i]] = 'Q';
            }
            sss.push_back(cc);
        }
        return ret;
        /*
        return sss;
        */
    }
};

int main()
{
    int n = 4;
    Solution s = Solution();
    for(auto r : s.solveNQueens(n)){
        for(int a : r){
            cout<<a<<' ';
        }
        cout<<'\n';
    }
}