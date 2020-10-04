/**
 * https://leetcode.com/problems/sort-an-array/
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int>a;

    void mergeSort(int st, int en){
        if(st >= en)return;
        int m = (st + en)/2;
        vector<int>b,c;
        if(m > st){
            mergeSort(st,m);
            b = vector<int>(m - st + 1);
        }
        if(en > m + 1){
            mergeSort(m + 1, en);
            c = vector<int>(en - m);
        }
        int i = 0, j = 0;
        
    }

    vector<int> sortArray(vector<int>& nums) {
        a = nums;
    }
};

int main()
{
    vector<int>a={};
    Solution s = Solution();
    a = s.sortArray(a);
}