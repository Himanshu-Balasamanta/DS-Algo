/**
 * https://leetcode.com/problems/sort-an-array/
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    vector<int>a;

    //in the array from [st,en], take st and sort the array wrt st. finally put st at the required place.
    void partition(int st, int en){
        //if the array to be sorted has size 1, where will we shift the partition element?
        if(st >= en)return;
        int h = en, l = st + 1, p = st;
        //[l,h]... the array we are to sort wrt st, and finally shift st
        while(h >= l){
            //not <= sign as otherwise, h may go below p, in case p has the smallest element.
            while(a[h] > a[p])h--;
            //the >= sign is necessary, as it has to cover all elements that the previous loop may loose.
            //Doing this will ensure the external loop continues after the swap
            while(l <= en && a[l] <= a[p])l++;
            if(l <= h)
                swap(a[l],a[h]);
        }
        //h goes till p at the most
        swap(a[h],a[p]);
        partition(st,h - 1);
        partition(h + 1,en);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        a = nums;
        n = a.size();
        partition(0,n - 1);
        return a;
    }
};

int main()
{
    int n, i;
    vector<int>a = {5,2,3,1}; //{11,10,4,2,1,-3,-6};//{-4,2,6,-1,-7,8,-3,-1,13};
    Solution s = Solution();
    a = s.sortArray(a);
    for(int v = 0; v < a.size(); v++)cout<<a[v]<<' ';
    cout<<'\n';
}