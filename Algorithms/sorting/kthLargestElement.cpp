/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        multiset<int>s;
        int i, j, n = 0;
        for(int d : a){
            s.insert(d);
            n++;
            if(n > k){
                s.erase(s.begin());
                n--;
            }
        }
        return *s.begin();
    }
};

int main()
{
    vector<int>a= {3,2,3,1,2,4,5,5,6};
    Solution s = Solution();
    cout<<s.findKthLargest(a,4);
}