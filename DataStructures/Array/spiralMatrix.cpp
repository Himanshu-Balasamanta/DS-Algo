/**
 * https://leetcode.com/problems/spiral-matrix/
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), i = 0, j = -1;
        vector<int>a;
        if(n == 0)return a;
        int m = mat[0].size();
        int bounce[4] = {m,n,-1,-1};
        int num = m*n, point = 0;
        while(num > 0){
            //if now i am heaing in x dir
            if(point % 2 == 0){
                if(point % 4 == 0){
                    j++;
                    while(j < bounce[point] && num > 0){
                        a.push_back(mat[i][j]);
                        num--;
                        j++;
                    }
                    j--;
                    bounce[3]++;
                    point++;
                    point %= 4;
                }
                //for coming back on x dir 
                else{
                    j--;
                    cout<<bounce[point]<<' ';
                    while(j > bounce[point] && num > 0){
                        a.push_back(mat[i][j]);
                        j--;
                        num--;
                    }
                    j++;
                    bounce[1]--;
                    point++;
                    point %= 4;
                }
            }
            else{
                //downward on y dir
                if(point % 4 == 1){
                    i++;
                    while(i < bounce[point] && num > 0){
                        a.push_back(mat[i][j]);
                        i++;
                        num--;
                    }
                    i--;
                    bounce[0]--;
                    point++;
                    point %= 4;
                }
                else{
                    i--;
                    while(i > bounce[point] && num > 0){
                        a.push_back(mat[i][j]);
                        i--;
                        num--;
                    }
                    i++;
                    bounce[2]++;
                    point++;
                    point %= 4;
                }
            }
        }
        return a;
    }
};

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > a(n,vector<int>(m));
    for(i = 0; i != n; i++)
        for(j = 0; j != m; j++)
            cin>>a[i][j];
    Solution s = Solution();
    vector<int>b = s.spiralOrder(a);
    cout<<'\n';
    for(int c : b)
        cout<<c<<' ';
    cout<<'\n';
}