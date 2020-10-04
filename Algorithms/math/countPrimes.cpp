/**
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int i, j;
        vector<bool>p(n + 1,true);
        int prime = 0;
        for(i = 2; i * i <= n; i++){
            if(p[i]){
                prime++;
                for(j = i * i; j <= n; j += i){
                    p[j] = false;
                }
            }
        }
        for(;i != n; i++)if(p[i])prime++;
        return prime;
    }
};

int main()
{
    int n; cin>>n;
    Solution s = Solution();
    cout<<s.countPrimes(n)<<'\n';
}