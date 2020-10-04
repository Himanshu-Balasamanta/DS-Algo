/**
 * https://leetcode.com/problems/container-with-most-water/
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& a) {
        long long int l = 0, h = a.size() - 1, mx = 0, mn;
        mn = (a[l] < a[h]) ? l : h;
        mx = a[mn] * (h - l);
        while(l < h){
            if(mn == l){
                while(a[l] <= a[h]){
                    if(l == h)return mx;
                    if(mx < (h - l)*a[l]){
                        mn = l, mx = (h - l)*a[l];
                    }
                    l++;
                }
                mn = h;
            }
            else{
                while(a[h] <= a[l]){
                    if(l == h)return mx;
                    if(mx < (h - l)*a[h]){
                        mn = h, mx = (h - l)*a[h];
                    }
                    h--;
                }
                mn = l;
            }
        }
    }
};

int main()
{
    Solution s = Solution();
    vector<int>a = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(a);
}