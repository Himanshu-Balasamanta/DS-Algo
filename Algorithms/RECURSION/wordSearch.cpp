#include <bits/stdc++.h>
using namespace std;

vector<vector<char>>mat;
string s;

int xx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int yy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool test(int ii, int jj){
    if(ii >= mat.size() || ii < 0 || jj < 0 || jj >= mat[0].size())return false;
    return true;
}

bool rec(int ind, int ii, int jj, int dir){
    if(test(ii,jj)== false)return false;
    if(ind >= s.length())return true;
    if(s[ind] != mat[ii][jj])return false;
    return rec(ind + 1, ii + yy[dir], jj + xx[dir],dir);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m, i, j;
        char c;
        cin>>n>>m;
        mat = vector<vector<char>>(n,vector<char>(m,'h'));
        for(i = 0; i != n;i++){
            for(j = 0; j != m;){
                cin>>c;
                if(c == ' ')continue;
                else{
                    mat[i][j] = c;
                    j++;
                }
            }
            //for(j = 0; j != m;j++)cout<<mat[i][j]<<' ';
            //cout<<'\n';
        }
        for(i = 0; i != n;i++){
            cout<<'\n';
            for(j = 0; j != m;j++)cout<<mat[i][j]<<' ';}
            cout<<'\n';
        cin>>s;
        for(i = 0; i != n; i++){
            for(j = 0; j != m; j++){
                if(mat[i][j] == s[0]){
                    cout<<i<<' '<<j<<' ';
                    for(int k = 0; k != 8; k++){
                        if(rec(0,i,j,k)){
                            cout<<i<<' '<<j<<'\n';
                        }
                    }
                }
            }
        }
    }
}