/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n, int k) {
        vector<vector<int> >a(max(3,n + 1),vector<int>(max(3,k + 1),0));
        int tot = 0;
        a[1][1] = 1; a[2][1] = 1;a[2][2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1;j <= k; j++){
                a[i][j] = a[i - 1][j - 1] + a[i - 2][j - 1];
            }
        }
        for(int i = 0; i != k; i++)tot += a[n][i];
        return tot;
    }
};

int main()
{
    int n, k; cin>>n>>k;
    Solution sol = Solution();
    cout<<sol.climbStairs(n,k);
}