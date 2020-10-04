#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size(), i;
        vector<int>b(n + 3);
        for(i = 0; i != n; i++)
            b[i + 3] = max(b[i + 1],b[i]) + a[i];//, cout<<b[i + 3]<<' ';
        return max(b[n + 1],b[n + 2]);
    }
};

int main()
{
    int n, i;cin>>n;
    vector<int>a(n);
    for(i = 0; i != n; i++)cin>>a[i];
    Solution s = Solution();
    cout<<s.maxProfit(a)<<'\n';
}