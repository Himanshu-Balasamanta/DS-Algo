/**
 * https://leetcode.com/problems/container-with-most-water/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
    }
};

int main()
{
    int n, i;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i != n; i++)
        cin >> a[i];
    //
    Solution sol = Solution();
    cout << sol.maxArea(a) << '\n';
}