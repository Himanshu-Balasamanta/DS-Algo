
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& a, int tar) {
        sort(a.begin(),a.end());
        int i, j, k, l, m, u, n = a.size(), mn = INT_MAX, val;
        for(i = 0; i < n - 2; i++){
            j = i + 1, k = n - 1;
            while(j < k){
                if(mn > abs(a[j] + a[k] + a[i] - tar)){
                    val = a[j] + a[k] + a[i];
                    mn = abs(a[j] + a[k] + a[i] - tar);
                }
                while(a[j] + a[k] + a[i] > tar){k--;if(k <= j)break;}
                while(a[j] + a[k] + a[i] < tar){j++;if(k<= j)break;}
                if(a[i] + a[j] + a[k] == tar) return tar;
            }
        }
        return val;
    }
};

int main()
{
    int  tar = 4;
    vector<int>a= {-1, 1, 4, 7,10};
    Solution s = Solution();
    cout<<s.threeSumClosest(a,tar);
}