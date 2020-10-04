/**
 * in array, determine the max number that has frequency in array equal to itself.
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size(), i;
        vector<int>a(n + 1);
        for(int d : arr)
            if(d <= n)
                a[d]++;
        for(i = n; i >= 0; i--){
            if(a[i] == i)return i;
        }
        return -1;
    }
};

int main()
{}