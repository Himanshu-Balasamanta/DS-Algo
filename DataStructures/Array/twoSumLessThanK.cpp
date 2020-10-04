/**
 * https://leetcode.com/problems/two-sum-less-than-k/
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n = a.size();
        //search for last int lesser than k
        //for each int in array lesser than equal to this, find the greatest int that will give sum < k
        int i, l = 0, h = n - 1, m, e, s = -1, ans = -1;
        if(a[l] >= k){
            return -1;
        }
        else if(a[h] < k){
            e = h;
        }
        else{
            while(l + 1 < h){
                m = (l + h)/2;
                if(a[m] < k)l = m;
                else h = m;
            }
            e = l;
        }
        for(i = e; i > s; i--){
            l = 0, h = i - 1;
            if(a[l] + a[i] >= k)continue;
            else if(a[h] + a[i] < k){
                ans = max(ans, a[i] + a[h]);
                s = h;
            }
            else{
                while(l < h - 1){
                    m = (l + h)/2;
                    if(a[m] + a[i] < k)l = m;
                    else h = m;
                }
                ans = max(ans, a[l] + a[i]);
                s = max(s,l);
            }
        }
        return ans;
    }
};

int main()
{
    int n, i, k;
    cin>>n;
    vector<int>a(n);
    for(i = 0; i != n; i++){
        cin>>a[i];
    }
    cin>>k;
    Solution s = Solution();
    cout<<s.twoSumLessThanK(a,k)<<'\n';
}