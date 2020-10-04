/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int>a(n + 1);
        a[1] = 1; a[2] = 2;
        for(int i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        return a[n];
    }
};

int main()
{
    int n; cin>>n;
    Solution sol = Solution();
    cout<<sol.climbStairs(n);
}