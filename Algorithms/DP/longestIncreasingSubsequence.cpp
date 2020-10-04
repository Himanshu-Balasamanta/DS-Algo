/**
 * https://leetcode.com/problems/longest-increasing-subsequence/
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size(), i, j, mx = 0;
        vector<int>longestTillNow(n,1);
        for(i = 0; i != n; i++){
            for(j = 0; j < i; j++){
                if(a[j] < a[i])
                    longestTillNow[i] = max(longestTillNow[i],longestTillNow[j] + 1);
            }
            mx = max(mx,longestTillNow[i]);
        }
        return mx;
    }
};

int main()
{
    int n, i;
    cin>>n;
    vector<int>a(n);
    for(i = 0; i != n; i++)cin>>a[i];
    Solution s = Solution();
    cout<<s.lengthOfLIS(a)<<'\n';
}