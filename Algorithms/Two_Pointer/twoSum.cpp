/**
 * https://leetcode.com/problems/two-sum/
 * Soln is incorrect, as input is not sorted
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int tar) {
        int i, n = a.size(), j, x, l, u, m;
        vector<int>b;
        i = 0, j = n - 1;
        while(j > i){
            if(a[i] + a[j] < tar)i++;
            else if(a[i] + a[j] > tar)j--;
            else{
                b.push_back(i);
                b.push_back(j);
                return b;
            }
        }
        return b;
    }
};

int main()
{
    vector<int>a = {3,2,4};
    Solution s = Solution();
    a = s.twoSum(a,6);
    cout<<a[0]<<' '<<a[1];
}
